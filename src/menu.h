#pragma once
#include "corefw/cfstring.h"
#include "corefw/class.h"
#include "corefw/corefw.h" // IWYU pragma: keep

typedef struct __Menu* MenuRef;
extern CFClassRef Menu;

typedef struct __Game* GameRef;

typedef enum MenuState: int {
    MenuStateNone = -1,
    MenuStateFood = 0,
    MenuStateWoke,
    MenuStatePlay,
    MenuStateVive,
    MenuStatePoop,
    MenuStateProp,
    MenuStateStat,
    MenuStateComm,
} MenuState;

struct __Menu {
    struct __CFObject obj;
    GameRef game;
    bool active;
    MenuState index;
};

typedef void (^MenuHandler)(MenuRef this);

struct __MenuItem {
    MenuState index;
    int32_t x;
    int32_t y;
    uint32_t width;
    uint32_t height;
    const uint8_t* data;
    MenuHandler proc;
    char label[7];

};    


MenuRef method Ctor(MenuRef, GameRef);
void method Start(MenuRef);
void method Update(MenuRef, uint8_t);
void method Draw(MenuRef);

static inline MenuRef NewMenu(GameRef game)
{
    return Ctor((MenuRef)CFCreate(Menu), game);
}