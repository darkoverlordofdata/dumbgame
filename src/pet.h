#pragma once
#include "corefw/cfstring.h"
#include "corefw/class.h"
#include "corefw/corefw.h" // IWYU pragma: keep


typedef struct __Pet* PetRef;
extern CFClassRef Pet;

typedef enum PetType: unsigned int {
    PetBrainWorm
} PetType;

struct __Pet {
    struct __CFObject obj;
    PetType type;
    CFStringRef name;
    long    x;
    long    y;    
};

PetRef method Ctor(PetRef, char*);

void method Initialize(PetRef);
void method Update(PetRef);
void method Draw(PetRef);
void method Move(PetRef, long, long);
long method GetWidth(PetRef);
long method GetHeight(PetRef);

static inline PetRef NewPet(char* name)
{
    return Ctor((PetRef)CFCreate(Pet), name);
}