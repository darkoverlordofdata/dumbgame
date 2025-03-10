#pragma once
#include "corefw/cfstring.h"
#include "corefw/class.h"
#include "corefw/corefw.h" // IWYU pragma: keep


typedef struct __Pet* PetRef;
extern CFClassRef Pet;
typedef struct __Game*            GameRef;

typedef enum PetType: unsigned int {
    PetBrainWorm
} PetType;

typedef enum PetMood: unsigned int {
    PetMoodNothing,
    PetMoodHappy,
    PetMoodAngry,
    PetMoodSad,
    PetMoodDead
} PetMood;

struct __Pet {
    struct __CFObject obj;
    GameRef     game;
    uint8_t*    data;
    int32_t     x;
    int32_t     y;    
    uint32_t    width;
    uint32_t    height;                                                    
    uint32_t    flags;
};

PetRef method Ctor(PetRef, GameRef);

void method Initialize(PetRef);
void method Update(PetRef);
void method Draw(PetRef);
void method Move(PetRef, long, long);
long method GetWidth(PetRef);
long method GetHeight(PetRef);

static inline PetRef NewPet(GameRef game)
{
    return Ctor((PetRef)CFCreate(Pet), game);
}