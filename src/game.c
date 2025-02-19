#include "game.h"
#include "pet.h"
#include "wasm4.h"

static struct __CFClass class = {
	.name = "Game",
	.size = sizeof(struct __Game),
};
CFClassRef Game = &class;

extern unsigned long frameCounter;

const int RgbPink   = 0xfea8a8; // #fea8a8 apricot haze
const int RgbYellow = 0xa8fea8; // #a8fea8 creamy mint
const int RgbBlue   = 0xa8a8fe; // #a8a8fe widowmaker
const int RgbBlack  = 0x14080a; // #14080a asphalt

// wormy

bool method Start(GameRef this)
{
    (void*)this;
	PALETTE[0]=RgbPink;
	PALETTE[1]=RgbYellow;
	PALETTE[2]=RgbBlue;
    PALETTE[3]=RgbBlack;
    this->pet = NewPet("frodo");
    Move(this->pet, 80, 25);
    return true;

}
bool method Update(GameRef this)
{
    (void*)this;
    frameCounter++;
    Draw(this);
    return true;

}
bool method Draw(GameRef this)
{
    (void*)this;
    *DRAW_COLORS = 2;

    text("Worm Brain", 10, 10);

    uint8_t gamepad = *GAMEPAD1;
    if (gamepad & BUTTON_1) {
        *DRAW_COLORS = 3;
    }

    Draw(this->pet);


    text("X to Play", 16, 90);
    return true;

}
