#pragma once
#include "corefw/cfstring.h"
#include "corefw/class.h"
#include "corefw/corefw.h" // IWYU pragma: keep


typedef struct __Clock*     ClockRef;
extern CFClassRef Clock;
typedef struct __Game*      GameRef;

typedef void (^TickHandler)(ClockRef this, GameRef game);

struct __Clock {
    struct __CFObject obj;
    GameRef     game;
    long        tick;
    long        seconds;
    long        minutes;
    long        hours;
    long        times;
    TickHandler onTick;

};


ClockRef method Ctor(ClockRef, GameRef);
void method Tick(ClockRef);
void method SetOnTick(ClockRef, TickHandler);


static inline ClockRef NewClock(GameRef game) 
{
    return Ctor((ClockRef)CFCreate(Clock), game);
}