#pragma once
#include "corefw/cfstring.h"
#include "corefw/class.h"
#include "corefw/corefw.h" // IWYU pragma: keep
#include "pet.h"
#include "splash.h"

typedef struct __Game* GameRef;
extern CFClassRef Game;

typedef enum GameState: unsigned int {
    GameStateSplashScreen,
    GameStateRunning,
    GameStateEnd
} GameState;

struct __Game {
    struct __CFObject obj;
    CFStringRef title;
    GameState state;
    SplashRef splash;
    PetRef pet;
    bool first;
    unsigned long frameCounter;
    uint8_t previousGamepad;
    CFRandomRef rnd;
};

GameRef method Ctor(GameRef);
void method Start(GameRef);
void method Update(GameRef);
void method Draw(GameRef);

static inline GameRef NewPetData()
{
    return Ctor((GameRef)CFCreate(Game));
}