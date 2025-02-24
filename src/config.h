/**
 * Config
 *
 * get the pet name
 *
 * @see https://wasm4.org/play/text-input
 */
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
    Widget      w_select; /* selected widget */
    Modal       modal;
    Keyplace    kb_select;
    char        input[6];
    int         input_len;
    uint8_t     button_cooldown[6];
} State;

struct __Config {
    struct __CFObject obj;

    GameRef     game;
    uint8_t*    data;
    int32_t     x;
    int32_t     y;    
    uint32_t    width;
    uint32_t    height;                                                    
    uint32_t    flags;
    int         tick;
    State       state;
};
    
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