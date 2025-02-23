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
	pool = CFNew(CFRefPool);
    game = NewGame();
    Start(game);

}

void update () {
    Update(game);
    Draw(game);
}
