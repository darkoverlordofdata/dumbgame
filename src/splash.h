#pragma once
#include "corefw/cfstring.h"
#include "corefw/class.h"
#include "corefw/corefw.h" // IWYU pragma: keep
#include "menu.h"
#include "wasm4.h"

typedef struct __Splash* SplashRef;
extern CFClassRef Splash;

typedef struct __Game* GameRef;

struct __Splash {
    struct __CFObject obj;
    
    GameRef     game;
    uint8_t*    data;
    int32_t     x;
    int32_t     y;    
    uint32_t    width;
    uint32_t    height;                                                    
    uint32_t    flags;
    int         tick;
};

SplashRef method Ctor(SplashRef, GameRef);

void method Initialize(SplashRef);
void method Update(SplashRef);
void method Draw(SplashRef);
void method Move(SplashRef, long, long);
long method GetWidth(SplashRef);
long method GetHeight(SplashRef);

static inline SplashRef NewSplash(GameRef game)
{
    return Ctor((SplashRef)CFCreate(Splash), game);
}