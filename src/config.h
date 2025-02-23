#pragma once
#include "corefw/cfstring.h"
#include "corefw/class.h"
#include "corefw/corefw.h" // IWYU pragma: keep
#include <stdint.h>
#include "menu.h"
#include "wasm4.h"

typedef struct __Config* ConfigRef;
extern CFClassRef Config;

typedef struct __Game* GameRef;

struct __Config {
    struct __CFObject obj;

    uint8_t*   data;
    long    x;
    long    y;    
    uint32_t width;
    uint32_t height;
    uint32_t flags;
    int     tick;
};

typedef struct { int x, y; } iVec2;

typedef struct { char *str; int strlen; int offset_px; } Keyboard_Row;

static Keyboard_Row keyboard[] = {
  {"qwertyuiop", 10,  5},
  { "asdfghjkl",  9,  8},
  {  "zxcvbnm",   7, 14}
};

typedef struct { int x, y; } Keyplace;

typedef enum {
    Widget_Delete,
    Widget_Clear,
    Widget_Done,
    Widget_Keyboard,
    Widget_COUNT,
} Widget;

typedef enum {
    Modal_Widgets,
    Modal_KeyboardOpen,
    Modal_TypeSomething,
} Modal;

typedef struct {
    Widget w_select; /* selected widget */
    Modal modal;
    Keyplace kb_select;
    char input[4];
    int input_len;
    uint8_t button_cooldown[6];
} State;
  
ConfigRef method Ctor(ConfigRef, GameRef);

void method Initialize(ConfigRef);
void method Update(ConfigRef);
void method Draw(ConfigRef);
void method Move(ConfigRef, long, long);
long method GetWidth(ConfigRef);
long method GetHeight(ConfigRef);

static inline ConfigRef NewConfig(GameRef game)
{
    return Ctor((ConfigRef)CFCreate(Config),game);
}