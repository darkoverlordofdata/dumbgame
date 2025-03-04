#include "game.h"
#include "config.h"
#include "corefw/object.h"
#include "corefw/random.h"
#include "corefw/printf.h"
#include "menu.h"
#include "pet.h"
#include "splash.h"
#include "wasm4.h"
#include <string.h>

static struct __CFClass class = {
    .name = "Game",
    .size = sizeof(struct __Game),
};
CFClassRef Game = &class;

extern unsigned long frameCounter;

// wormy
GameRef method Ctor(GameRef this) {
    (GameRef)this;
    this->first = true;
    this->state = GameStateSplashScreen;
    this->frameCounter = 0;
    this->splash = NewSplash(this);
    this->menu = NewMenu(this);
    this->config = NewConfig(this);
    diskr(&this->data, sizeof(this->data));
    return this;
}

 
void method Start(GameRef this) {
    (GameRef)this;

    // https://lospec.com/palette-list/ice-cream-gb
    // PALETTE[0] = 0xfff6d3;
    // PALETTE[1] = 0xf9a875;
    // PALETTE[2] = 0xeb6b6f;
    // PALETTE[3] = 0x7c3f58;
}

uint8_t method PressedThisFrame(GameRef this) {
    (GameRef)this;
    uint8_t gamepad = *GAMEPAD1;
    uint8_t pressedThisFrame = gamepad & (gamepad ^ this->previousGamepad);
    this->previousGamepad = gamepad;
    return pressedThisFrame;
}

void method Update(GameRef this) {
    (GameRef)this;
    this->frameCounter++;

    switch (this->state) {
    case GameStateSplashScreen:
        Update(this->splash);
        if (PressedThisFrame(this) & BUTTON_1) {
            this->rnd = NewRandom(frameCounter);
            this->first = false;
            this->state = GameStateInputName;
        }
    break;

    case GameStateInputName:
        Update(this->config);
        break;

    case GameStateRunning:
        Update(this->menu, PressedThisFrame(this));
        Move(this->pet, 80, 35);
    
        switch (this->menu->index) {
        case MenuStateNone:
            break;
        case MenuStateFood:
            break;
        case MenuStateWoke:
            break;
        case MenuStatePlay:
            break;
        case MenuStateVive:
            break;
        case MenuStatePoop:
            break;
        case MenuStateProp:
            break;
        case MenuStateStat:
            break;
        case MenuStateComm:
            break;
        }
        break;

    case GameStateEnd:

        break;
    }
}

void method Draw(GameRef this) {
    (GameRef)this;
    char buf[80];

    switch (this->state) {
    case GameStateSplashScreen:
        *DRAW_COLORS = 0x0321;
        Draw(this->splash);

        *DRAW_COLORS = 4;
        text("X - Play", 80, 70);
        // text("Y - Opts", 80, 85);

        break;

    case GameStateInputName:
        break;

    case GameStateRunning:
    *DRAW_COLORS = 0x0312;
    Draw(this->pet);
    *DRAW_COLORS = 0x0321;
    Draw(this->menu);

    // 160 x 80 @40
    *DRAW_COLORS = 0x0312;
    switch (this->menu->index) {
        case MenuStateNone:
            break;
        case MenuStateFood:
            rect(0,40,160,80);
            break;
        case MenuStateWoke:
            break;
        case MenuStatePlay:
            rect(0,40,160,80);
            break;
        case MenuStateVive:
            rect(0,40,160,80);
            break;
        case MenuStatePoop:
            rect(0,40,160,80);
            break;
        case MenuStateProp:
            rect(0,40,160,80);
            break;
        case MenuStateStat:
            rect(0,40,160,80);

            *DRAW_COLORS = 0x0321;
            snprintf(buf, 80, "name:   %s", this->data.name);
            text(buf, 5, 45);
            snprintf(buf, 80, "age:    %d", this->data.age);
            text(buf, 5, 60);
            snprintf(buf, 80, "hunger: %d", this->data.hunger);
            text(buf, 5, 75);
            snprintf(buf, 80, "joy:    %d", this->data.happiness);
            text(buf, 5, 90);
            snprintf(buf, 80, "$$$:    %d", this->data.money);
            text(buf, 5, 105);

            break;
        case MenuStateComm:
            rect(0,40,160,80);
            break;
        }

        break;

    case GameStateEnd:

        break;
    }
}
