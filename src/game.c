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

float clamp(float val, float minVal, float maxVal)
{
    float min = (val > minVal) ? val : minVal;
    return (min < maxVal) ? min : maxVal;
}
// wormy
GameRef method Ctor(GameRef this) {
    (GameRef)this;
    this->first = true;
    this->state = GameStateSplashScreen;
    this->frameCounter = 0;
    this->autoToilet = true;
    this->autoTick = true;
    this->autoMoney = true;;
    this->isGod = false;
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

    if (this->autoTick) this->tick += 1;
    if (this->autoMoney) this->data.money += 10;
    this->data.hunger -= 3;
    this->data.happiness -= 2;
    if (this->data.sick) {
        this->data.hunger -= 5;
        this->data.happiness -= 2;
    }
    this->data.happiness = clamp(this->data.happiness, 0, 100);
    this->data.hunger = clamp(this->data.hunger, 0, 100);

    if (this->autoToilet) {
        if (this->data.hunger > 90) {
            if (NextDouble() > 0.70)
                this->data.poop++;
        }
        else {
            if (NextDouble() > 0.85)
                this->data.poop++;
        }
    }
    this->data.poop = clamp(this->data.poop, 0, 3);
    if (NextDouble() < (0.1*this->data.poop)) {
        this->data.sick = true;
    }
    if (this->data.mood != PetMoodDead) this->data.age++;


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
    if (this->data.mood == PetMoodDead) return;

    if (this->data.hunger>50 && this->data.happiness>=60) {
        this->data.mood = PetMoodHappy;
    }
    else if (this->data.hunger>=30 && this->data.happiness<30) {
        this->data.mood = PetMoodAngry;
    }
    else if (this->data.hunger<=0 && (!this->isGod)) {
        this->data.mood = PetMoodDead;
    }
    else if (this->data.hunger<30 || this->data.sick) {
        this->data.mood = PetMoodSad;
    }
    else this->data.mood = PetMoodNothing;
    

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
            *DRAW_COLORS = 0x0321;
            snprintf(buf, 80, "%s eats", this->data.name);
            text(buf, 5, 45);
            snprintf(buf, 80, "%06d", timer(this->tick));
            text(buf, 108, 45);

            sprintf(buf, "whale brain  $100");
            text(buf, 5, 60);
            sprintf(buf, "monkey brain $ 80");
            text(buf, 5, 75);
            sprintf(buf, "tuna+Hg      $ 50");
            text(buf, 5, 90);
            break;

        case MenuStateWoke:
            break;

        case MenuStatePlay:
            rect(0,40,160,80);
            *DRAW_COLORS = 0x0321;
            snprintf(buf, 80, "%s play", this->data.name);
            text(buf, 5, 45);
            snprintf(buf, 80, "%06d", timer(this->tick));
            text(buf, 108, 45);

            sprintf(buf, "skiing       $100");
            text(buf, 5, 60);
            sprintf(buf, "martha's     $ 50");
            text(buf, 5, 75);
            sprintf(buf, "epstein's    $ 80");
            text(buf, 5, 90);
            break;

        case MenuStateVive:
            rect(0,40,160,80);
            *DRAW_COLORS = 0x0321;
            snprintf(buf, 80, "%s meds", this->data.name);
            text(buf, 5, 45);
            snprintf(buf, 80, "%06d", timer(this->tick));
            text(buf, 108, 45);

            sprintf(buf, "heroin       $100");
            text(buf, 5, 60);
            sprintf(buf, "invermectin  $ 80");
            text(buf, 5, 75);
            sprintf(buf, "demoic acid  $ 50");
            text(buf, 5, 90);
            break;

        case MenuStatePoop:
            rect(0,40,160,80);
            *DRAW_COLORS = 0x0321;
            snprintf(buf, 80, "%s shit", this->data.name);
            text(buf, 5, 45);
            snprintf(buf, 80, "%06d", timer(this->tick));
            text(buf, 108, 45);

            break;

        case MenuStateProp:
            rect(0,40,160,80);
            *DRAW_COLORS = 0x0321;
            snprintf(buf, 80, "%s", this->data.name);
            text(buf, 5, 45);
            snprintf(buf, 80, "%06d", timer(this->tick));
            text(buf, 108, 45);

            snprintf(buf, 80, "age    %d", this->data.age);
            text(buf, 5, 60);
            snprintf(buf, 80, "hunger %d", this->data.hunger);
            text(buf, 5, 75);
            snprintf(buf, 80, "joy    %d", this->data.happiness);
            text(buf, 5, 90);
            snprintf(buf, 80, "$$$    %d", this->data.money);
            text(buf, 5, 105);
            break;

        case MenuStateStat:
            rect(0,40,160,80);
            *DRAW_COLORS = 0x0321;
            snprintf(buf, 80, "%s", this->data.name);
            text(buf, 5, 45);
            snprintf(buf, 80, "%06d", timer(this->tick));
            text(buf, 108, 45);

            break;

        case MenuStateComm:
            rect(0,40,160,80);
            *DRAW_COLORS = 0x0321;
            snprintf(buf, 80, "%s talk", this->data.name);
            text(buf, 5, 45);
            snprintf(buf, 80, "%06d", timer(this->tick));
            text(buf, 108, 45);

            break;
        }

        break;

    case GameStateEnd:

        break;
    }
}
