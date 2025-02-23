#pragma once
#include "corefw/cfstring.h"
#include "corefw/class.h"
#include "corefw/corefw.h" // IWYU pragma: keep
#include "menu.h"
#include "pet.h"
#include "splash.h"
#include "config.h"

typedef struct __Game* GameRef;
extern CFClassRef Game;

typedef enum GameState: unsigned int {
    GameStateSplashScreen,
    GameStateInputName,
    GameStateRunning,
    GameStateEnd
} GameState;


struct __Game {
    struct __CFObject obj;
    CFStringRef title;
    GameState state;
    SplashRef splash;
    MenuRef menu;
    PetRef pet;
    ConfigRef config;
    bool first;
    unsigned long frameCounter;
    uint8_t previousGamepad;
    CFRandomRef rnd;
    struct pet_data data;
};


GameRef method Ctor(GameRef);
void method Start(GameRef);
void method Update(GameRef);
void method Draw(GameRef);
uint8_t method PressedThisFrame(GameRef);

static inline GameRef NewGame()
{
    return Ctor((GameRef)CFCreate(Game));
}