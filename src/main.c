#include <stdbool.h>
#include "corefw/corefw.h" // IWYU pragma: keep
#include "corefw/object.h"
#include "wasm4.h"
#include "game.h"

extern unsigned long frameCounter;

CFRefPoolRef pool = NULL;
GameRef game;

bool first = true;

void start() {
    frameCounter++;
	pool = CFNew(CFRefPool);
    game = CFCreate(Game);
    Start(game);

}

void update () {
    if (first) {
        first = false;
        tracef("%d", (int)frameCounter);

    }
    Update(game);

}
