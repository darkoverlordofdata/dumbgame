#pragma once
#include "corefw/cfstring.h"
#include "corefw/class.h"
#include "corefw/corefw.h" // IWYU pragma: keep


typedef struct __Splash* SplashRef;
extern CFClassRef Splash;


struct __Splash {
    struct __CFObject obj;
    SplashRef data;
    long    x;
    long    y;    
};

SplashRef method Ctor(SplashRef);

void method Initialize(SplashRef);
void method Update(SplashRef);
void method Draw(SplashRef);
void method Move(SplashRef, long, long);
long method GetWidth(SplashRef);
long method GetHeight(SplashRef);

static inline SplashRef NewSplash()
{
    return Ctor((SplashRef)CFCreate(Splash));
}