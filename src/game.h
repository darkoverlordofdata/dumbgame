#pragma once
#include <stdbool.h>
#include "corefw/cfstring.h"
#include "corefw/class.h"
#include "corefw/corefw.h" // IWYU pragma: keep
#include "menu.h"
#include "pet.h"
#include "splash.h"
#include "config.h"
#include "clock.h"

typedef struct __Game* GameRef;
extern CFClassRef Game;

typedef enum GameState: unsigned int {
    GameStateSplashScreen,
    GameStateInputName,
    GameStateRunning,
    GameStateEnd
} GameState;

// max 1024 bytes
struct pet_data {
    uint32_t    magic;
    PetType     type;
    PetMood     mood;
    char        name[20];
    long        age;     
    bool        sick;
    float       hunger;
    float       happiness;
    float       money;
    float       poop;
};

struct __Game {
    struct __CFObject obj;
    CFStringRef         title;
    GameState           state;
    SplashRef           splash;
    MenuRef             menu;
    PetRef              pet;
    ConfigRef           config;
    CFRandomRef         rnd;
    ClockRef            clock;
    bool                first;
    unsigned long       frameCounter;
    bool                isGod;
    bool                autoToilet;
    bool                autoMoney;
    bool                autoTick;
    uint8_t             previousGamepad;
    struct pet_data     data;
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

