#pragma once
#include "corefw/cfstring.h"
#include "corefw/class.h"
#include "corefw/corefw.h" // IWYU pragma: keep


typedef struct __Pet* PetRef;
extern CFClassRef Pet;
typedef struct __PetDataRef*    PetDataRef;


struct __Pet {
    struct __CFObject obj;
    PetDataRef data;
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