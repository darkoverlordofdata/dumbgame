#pragma once
#include "corefw/cfstring.h"
#include "corefw/class.h"
#include "corefw/corefw.h" // IWYU pragma: keep
#include "pet.h"


typedef struct __Game* GameRef;
extern CFClassRef Game;

struct __Game {
    struct __CFObject obj;
    CFStringRef title;
    PetRef pet;
};

bool method Start(GameRef);
bool method Update(GameRef);
bool method Draw(GameRef);
