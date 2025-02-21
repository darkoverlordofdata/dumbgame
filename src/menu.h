#pragma once
#include "corefw/cfstring.h"
#include "corefw/class.h"
#include "corefw/corefw.h" // IWYU pragma: keep
#include "game.h"

typedef struct __Menu* MenuRef;
extern CFClassRef Menu;

typedef enum MenuState: unsigned int {
    MenuStateFood,
    MenuStateLight,
    MenuStatePlay,
    MenuStateHealth,
    MenuStateClean,
    MenuStateMeter,
    MenuStateStatus,
    MenuStateComm,
} MenuState;

struct __Menu {
    struct __CFObject obj;
    GameRef game;
    bool active;
    MenuState index;
};

typedef void (^MenuHandler)(MenuState i);
struct MenuItem {
    MenuState index;
    int32_t x;
    int32_t y;
    uint32_t width;
    uint32_t height;
    const uint8_t* data;
    MenuHandler proc;
};  


MenuRef method Ctor(MenuRef, GameRef);
void method Start(MenuRef);
void method Update(MenuRef);
void method Draw(MenuRef);

static inline MenuRef NewMenu(GameRef game)
{
    return Ctor((MenuRef)CFCreate(Menu), game);
}