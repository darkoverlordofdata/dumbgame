#include "game.h"
#include "corefw/object.h"
#include "corefw/random.h"
#include "pet.h"
#include "splash.h"
#include "wasm4.h"

static struct __CFClass class = {
      .name = "Game",
      .size = sizeof(struct __Game),
};
CFClassRef Game = &class;

extern unsigned long frameCounter;

// wormy
GameRef method Ctor(GameRef this) {
    (void *)this;
    this->first = true;
    this->state = GameStateSplashScreen;
    this->frameCounter = 0;
    this->splash = NewSplash();
    return this;
}

void method Start(GameRef this) {
    (void *)this;

    //https://lospec.com/palette-list/ice-cream-gb
    PALETTE[0] = 0xfff6d3;
    PALETTE[1] = 0xf9a875;
    PALETTE[2] = 0xeb6b6f;
    PALETTE[3] = 0x7c3f58;  

}

void method Update(GameRef this) {
    (void *)this;
    this->frameCounter++;

    switch (this->state) {
    case GameStateSplashScreen:
        Update(this->splash);
        uint8_t gamepad = *GAMEPAD1;
        uint8_t pressedThisFrame = gamepad & (gamepad ^ this->previousGamepad);
        if (pressedThisFrame & BUTTON_1) {
            // if (this->first) {
                tracef("%d", (int)this->frameCounter);
                this->rnd = NewRandom(frameCounter);
                this->first = false;
            // }
            this->previousGamepad = gamepad;
            trace("X button was just pressed!");
        }
        break;

    case GameStateRunning:

        break;

    case GameStateEnd:

        break;
    }
}

void method Draw(GameRef this) {
    (void *)this;
    switch (this->state) {
    case GameStateSplashScreen:
        *DRAW_COLORS = 0x0321;
        Draw(this->splash);

        *DRAW_COLORS = 4;
        text("X - Play", 80, 70);
        text("Y - Opts", 80, 85);

        break;

    case GameStateRunning:

        break;

    case GameStateEnd:

        break;
    }
}
