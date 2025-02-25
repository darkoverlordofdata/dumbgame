#include "corefw/object.h"
#include "corefw/random.h"
#include "menu.h"
#include "wasm4.h"
#include "game.h"
#include <assert.h>

static struct __CFClass class = {
    .name = "Menu",
    .size = sizeof(struct __Menu),
};
CFClassRef Menu = &class;

static const uint8_t food[];
static const uint8_t woke[];
static const uint8_t play[];
static const uint8_t vive[];
static const uint8_t poop[];
static const uint8_t prop[];
static const uint8_t stat[];
static const uint8_t comm[];

/*
 * menu data+callback    10,130     10,50,90,130
 */
static struct __MenuItem m[] = {
    [0]={ .index=0, .x=5, .y=5, .width=26, .height=26, .data=food, .label="food",
        .proc=^(MenuRef this) {
        (MenuRef)this;
    }},
    [1]={ .index=1, .x=45, .y=5, .width=26, .height=26, .data=woke, .label="woke",
        .proc=^(MenuRef this) {
        (MenuRef)this;
    }},
    [2]={ .index=2, .x=85, .y=5, .width=29, .height=26, .data=play, .label="play",
        .proc=^(MenuRef this) {
        (MenuRef)this;
    }},
    [3]={ .index=3, .x=125, .y=5, .width=30, .height=26, .data=vive, .label="vive",
        .proc=^(MenuRef this) {
        (MenuRef)this;
    }},
    [4]={ .index=4, .x=5, .y=129, .width= 28, .height=26, .data=poop, .label="poop",
        .proc=^(MenuRef this) {
        (MenuRef)this;
    }},
    [5]={ .index=5, .x=45, .y=129, .width=30, .height=26, .data=prop, .label="prop",
        .proc=^(MenuRef this) {
        (MenuRef)this;
    }},
    [6]={ .index=6, .x=85, .y=129, .width=32, .height=26, .data=stat, .label="stat",
        .proc=^(MenuRef this) {
        (MenuRef)this;
    }},
    [7]={ .index=7, .x=125, .y=129, .width=31, .height=26, .data=comm, .label="comm",
        .proc=^(MenuRef this) {
        (MenuRef)this;
    }},
};

MenuRef method Ctor(MenuRef this, GameRef game) 
{
    (void *)this; 
    this->game = game;
    this->index = MenuStateNone;
    return this;     
}

void method Start(MenuRef this)
{
    (void *)this; 
}

void method Update(MenuRef this, uint8_t input)
{
    (void *)this; 

    if ( input & BUTTON_1 ) {
        this->active = true;
        m[this->index].proc(this);
    }
    if ( input & BUTTON_LEFT ) {
        this->index--;
    }
    if ( input & BUTTON_RIGHT ) {
        this->index++;
    }
    if (this->index < MenuStateFood) this->index = MenuStateComm;
    if (this->index > MenuStateComm) this->index = MenuStateFood;

}

void method Draw(MenuRef this)
{
    (void *)this; 

    for (long i = 0; i<8; i++) {
        if(i == this->index ) {
            *DRAW_COLORS = 3;
         }else {
            *DRAW_COLORS = 4;
        }
        blit(m[i].data, m[i].x, m[i].y, m[i].width, m[i].height, BLIT_1BPP);
        if (i < 4)
            text(m[i].label, m[i].x, m[i].y+27);
        else
            text(m[i].label, m[i].x, m[i].y-10);
    }
}

/*
 * sprite data generated using w4 png2src --c 
 */
 static const uint8_t food[85]  = { 0x00,0x0c,0x00,0x00,0x0e,0x0f,0x01,0xff,0x87,0xc0,0xff,0xe1,0xf8,0x3f,0xf8,0x7e,0x03,0xfe,0x1f,0x80,0xff,0xc7,0xe0,0x3f,0xf7,0xf8,0x0f,0xf9,0xfe,0x03,0xfe,0x7f,0x80,0xff,0x9f,0xe0,0x1f,0xc7,0xf8,0x03,0xf1,0xfe,0x00,0xfc,0x7f,0x80,0x1f,0x1f,0xe0,0x07,0xc7,0xf8,0x03,0xf1,0xfe,0x00,0xfc,0x07,0x80,0x3f,0x01,0xe0,0x1f,0xe0,0x78,0x07,0xf8,0x3e,0x01,0xfe,0x0f,0xc0,0x7f,0x83,0xf0,0x0f,0xc0,0xf8,0x01,0xc0,0x3c,0x00,0x00,0x00,0x00 };
 static const uint8_t woke[85]  = { 0x00,0x1c,0x00,0x03,0xc7,0x0f,0x00,0xf1,0xc3,0xc0,0x3c,0x60,0xf0,0x06,0x00,0x38,0x3d,0x87,0x8e,0x0f,0xbf,0xfe,0xff,0xef,0xff,0xff,0xf7,0xff,0xfb,0x81,0xff,0x3e,0x00,0x7c,0x07,0x80,0x1f,0x00,0xe0,0xf7,0xff,0xf8,0x39,0xff,0xfe,0xfc,0x7f,0xff,0xbc,0x0f,0xff,0xcf,0x03,0xde,0xf0,0x00,0xfb,0xb8,0x01,0xfe,0xcf,0xf8,0x7b,0x37,0xfe,0x1c,0x3f,0xc7,0x80,0x0f,0xf0,0xc0,0x03,0xfe,0x00,0x00,0xff,0x80,0x00,0x3f,0xc0,0x00,0x07,0xe0,0x00 };
 static const uint8_t play[95]  = { 0x00,0x00,0x00,0x00,0x78,0x00,0x00,0x0f,0xf8,0x00,0x00,0x7f,0xc0,0x00,0x0f,0xcf,0x80,0x00,0x7e,0x7c,0x00,0xf1,0xc1,0xc0,0x3f,0xee,0x06,0x07,0xff,0x7c,0x78,0xff,0xfb,0xef,0xcf,0xff,0x0f,0xfc,0x7f,0xf0,0x7f,0x87,0xff,0x03,0xfc,0xff,0xf8,0x0f,0xef,0xff,0xc0,0x00,0xff,0xf8,0x00,0x0f,0xfe,0x00,0x01,0xff,0xc0,0x00,0x1f,0xfe,0x00,0x01,0xff,0xe0,0x00,0xff,0xf8,0x00,0x07,0xff,0x00,0x00,0x1f,0xe0,0x00,0x00,0xfe,0x00,0x00,0x03,0xf0,0x00,0x00,0x1e,0x00,0x00,0x00,0x70,0x00,0x00,0x00 };
 static const uint8_t vive[98]  = { 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xf0,0x00,0x00,0x03,0xc0,0x00,0x00,0x07,0x80,0x00,0x00,0x1f,0x00,0x00,0x70,0x3f,0x00,0x01,0xff,0xfc,0x00,0x0f,0xff,0xf8,0x01,0xff,0xff,0xe0,0x07,0xff,0xef,0x80,0x3c,0x7b,0xff,0x01,0xf1,0xff,0x7c,0x0f,0xc3,0xfd,0xf1,0xfc,0x0f,0xf3,0xc7,0xf8,0x1e,0x07,0x3f,0xf0,0x7c,0x00,0xff,0xc1,0xf8,0x01,0xff,0x07,0xe0,0x07,0xfe,0x7f,0x80,0x1f,0xff,0xfe,0x00,0xff,0xff,0x18,0x07,0xff,0xf8,0x00,0x1f,0xff,0xc0,0x00,0x71,0xf0,0x00,0x00,0x00,0x00,0x00,0x00 };
 static const uint8_t poop[91]  = { 0x00,0x00,0x00,0x00,0x08,0x80,0x00,0x01,0xdc,0x00,0x00,0x7f,0xc0,0x1c,0xff,0xfe,0x1f,0xff,0xf3,0xff,0xff,0xfe,0x0f,0xff,0xf1,0xf1,0xff,0xef,0x1f,0x9f,0xfe,0xf1,0xfd,0xf9,0xef,0x3f,0xdf,0x1f,0xff,0xfd,0xc1,0xff,0xff,0xfc,0x1f,0xff,0xff,0xc7,0xff,0xff,0x1f,0xff,0xff,0xf1,0xff,0x8f,0x1e,0x0f,0xc0,0xf1,0xe0,0x78,0x0f,0x1e,0x00,0x01,0xe1,0xf0,0x00,0x3e,0x1f,0x80,0x3f,0xe1,0xff,0xff,0xfc,0x07,0xff,0xff,0x00,0x1f,0xff,0x80,0x00,0xff,0xf8,0x00,0x00,0x00,0x00 };
 static const uint8_t prop[98]  = { 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xf0,0x00,0x00,0xff,0xfe,0x00,0x0f,0xff,0xff,0xc0,0xff,0xff,0xff,0xc7,0xf0,0x78,0x7f,0xdf,0x19,0xe2,0x3f,0x7c,0x67,0x9c,0x7d,0xf1,0xde,0xff,0xf7,0xc7,0xfb,0xff,0xdf,0x9f,0xee,0xff,0x7f,0x3f,0x03,0xbd,0xfc,0x7c,0x1e,0xf7,0xe1,0xf0,0x73,0x8e,0x07,0xc0,0x1f,0x38,0x1f,0x00,0x78,0xf8,0x7e,0x03,0xe1,0xe1,0xf8,0x0f,0x87,0x8f,0xfc,0x7c,0x1f,0xff,0xff,0xe0,0x7f,0xff,0xff,0x80,0x7f,0x03,0xf8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00 };
 static const uint8_t stat[104] = { 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0c,0x00,0x00,0x00,0x0c,0x00,0x00,0x00,0x1c,0x00,0x00,0x00,0x1c,0x00,0x00,0x03,0x1c,0x00,0x00,0x07,0x9e,0x01,0xfe,0x07,0xce,0x07,0xff,0x13,0xee,0x0f,0xff,0x3b,0xf6,0x1f,0xfe,0x3d,0xfe,0x3f,0xfc,0x7f,0xfe,0x7f,0xf8,0xff,0xfe,0x7f,0xf0,0xff,0xde,0x7f,0xe0,0xfb,0x9f,0x3f,0xe0,0x7b,0xdf,0x3f,0xe0,0x03,0xde,0x3f,0xff,0xc0,0x1c,0x7f,0xff,0xe0,0x1c,0x7f,0xff,0xe0,0x1c,0x1f,0xff,0xe0,0x1c,0x0f,0xff,0xc0,0x00,0x03,0xfe,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00 };
 static const uint8_t comm[101] = { 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0x80,0x00,0x00,0x1f,0x80,0x00,0x01,0xff,0xc0,0x00,0x07,0xff,0xc3,0x80,0x3f,0x8f,0xff,0xf8,0xff,0x07,0xff,0xf1,0xf7,0x27,0xf7,0xf3,0x8e,0x67,0xc1,0xe7,0x01,0xc0,0x01,0xee,0x63,0x03,0x03,0xdf,0xe1,0x8f,0xff,0xbf,0xc7,0x1f,0xff,0x7f,0xff,0x1f,0xfe,0x7f,0xff,0x9f,0xdc,0xfc,0x3f,0x80,0x38,0xff,0xff,0x80,0x60,0xff,0xff,0x81,0xc0,0x3f,0xff,0x8f,0x80,0x00,0x1f,0xff,0x00,0x00,0x1f,0xfc,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00 };
 
 

