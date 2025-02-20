#include "corefw/cfstring.h"
#include "wasm4.h"
#include "corefw/corefw.h" // IWYU pragma: keep
#include "splash.h"

static struct __CFClass class = {
	.name = "Splash",
	.size = sizeof(struct __Splash),
};
CFClassRef Splash = &class;

/**
 *  Splash data
 *
 *   w4 png2src --c wormy.png
 *
*/
// splash
// splash
// splash
#define splashWidth 160
#define splashHeight 160
#define splashFlags BLIT_2BPP
const uint8_t splash[6400] = { 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1a,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xea,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x6a,0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0d,0xa9,0xc0,0x00,0x00,0x00,0x6a,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x70,0x00,0x00,0x00,0x00,0xea,0xaa,0x9c,0x00,0x00,0x00,0x6a,0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x35,0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,0xa4,0x00,0x00,0x00,0x02,0xaa,0xaa,0xa9,0x00,0x00,0x00,0xea,0xb0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0xaa,0x90,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3a,0xa8,0x00,0x00,0x00,0x3a,0xaa,0x56,0xaa,0x00,0x00,0x00,0x2a,0xa4,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3a,0xaa,0xa4,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xa4,0x00,0x00,0x03,0xc0,0x00,0x00,0x1a,0xab,0x00,0x00,0x00,0xea,0xa4,0x06,0xaa,0xc0,0x00,0x00,0x66,0xaa,0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x6a,0xaa,0xa8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0xaa,0x00,0x00,0x0a,0x90,0x00,0x00,0x2a,0xa8,0x00,0x00,0x03,0xaa,0xb0,0x0a,0xaa,0x00,0x00,0x00,0xa0,0x6a,0xb0,0x00,0x00,0x00,0x15,0xc0,0x01,0xaa,0xaa,0xa8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0e,0xa9,0x00,0x00,0x3a,0xa0,0x00,0x00,0x2a,0xa4,0x00,0x00,0x02,0xaa,0x00,0x3a,0xa9,0x00,0x00,0x03,0x90,0x1a,0xa0,0x00,0x00,0x00,0xaa,0x80,0x06,0xaa,0xaa,0xa8,0x00,0x01,0x57,0x00,0x00,0x00,0x00,0x00,0x0a,0xa8,0x00,0x00,0x1a,0x90,0x00,0x00,0x2a,0xac,0x00,0x00,0x0a,0xab,0x00,0x3a,0xab,0x00,0x00,0x01,0x80,0x0a,0xa4,0x00,0x00,0x01,0xaa,0xb0,0x1a,0xb0,0x2a,0xa8,0x00,0x1a,0xaa,0x40,0x00,0x00,0x00,0x00,0x3a,0xac,0x00,0x00,0x2a,0x90,0x00,0x00,0xea,0xa0,0x00,0x00,0x2a,0xac,0x00,0x1a,0xa8,0x00,0x00,0x0e,0x40,0x06,0xa8,0x00,0x00,0x01,0xaa,0x80,0xea,0x00,0x2a,0xa8,0x03,0xaa,0xaa,0x80,0x00,0x00,0x00,0x00,0x2a,0xa0,0x00,0x00,0x2a,0x80,0x00,0x00,0xea,0x90,0x00,0x00,0x6a,0x90,0x00,0x1a,0xa4,0x00,0x00,0x0a,0xc0,0x06,0xa9,0x00,0x00,0x01,0xaa,0x83,0xa8,0x00,0x1a,0xa8,0x0e,0xaa,0xaa,0x90,0x00,0x00,0x00,0x00,0xea,0x90,0x00,0x00,0xea,0x80,0x00,0x00,0xea,0x80,0x00,0x03,0xaa,0x40,0x00,0x1a,0xa0,0x00,0x00,0x19,0x00,0x06,0xa9,0x00,0x00,0x02,0xaa,0x8e,0xa0,0x00,0x2a,0xa8,0x3a,0x7e,0xaa,0x90,0x00,0x00,0x00,0x00,0x6a,0x80,0x00,0x00,0x6a,0x40,0x00,0x00,0x6a,0x80,0x00,0x02,0xaa,0xc0,0x00,0x1a,0xa0,0x00,0x00,0x28,0x00,0x0a,0xa9,0x00,0x00,0x02,0xaa,0x4a,0x80,0x00,0x2a,0xa8,0x2b,0x00,0xaa,0x90,0x00,0x00,0x00,0x00,0xaa,0x40,0x00,0x00,0xaa,0x40,0x00,0x00,0xaa,0x80,0x00,0x0e,0xa9,0x00,0x00,0x3a,0x90,0x00,0x00,0x64,0x00,0x0a,0xa9,0x00,0x00,0x0e,0xaa,0xda,0x00,0x00,0x2a,0xa4,0xa4,0x00,0xaa,0x90,0x00,0x00,0x00,0x03,0xaa,0xc0,0x00,0x01,0xaa,0xc0,0x00,0x01,0xaa,0x80,0x00,0x0a,0xa8,0x00,0x00,0x0a,0x90,0x00,0x03,0xa0,0x00,0x1a,0xab,0x00,0x00,0x06,0xaa,0xeb,0x00,0x00,0xea,0xad,0x90,0x00,0xaa,0xb0,0x00,0x00,0x00,0x01,0xaa,0x00,0x00,0x0e,0xaa,0x00,0x00,0x02,0xaa,0x80,0x00,0x3a,0xa4,0x00,0x00,0x3a,0x90,0x00,0x0e,0xb0,0x00,0x2a,0xa8,0x00,0x00,0x0a,0xaa,0xa4,0x00,0x00,0x6a,0xae,0x80,0x03,0xaa,0x80,0x00,0x0f,0x00,0x02,0xaa,0x00,0x00,0x0a,0xaa,0x00,0x00,0x06,0xaa,0x80,0x00,0x2a,0xa0,0x00,0x00,0x1a,0x90,0x00,0x0a,0x40,0x00,0xea,0xa4,0x00,0x00,0x0a,0xaa,0xa0,0x00,0x00,0xaa,0xaa,0xc0,0x01,0xaa,0x80,0x00,0x06,0x00,0x02,0xa9,0x00,0x00,0x39,0xaa,0x00,0x00,0x0a,0x9a,0x80,0x00,0xea,0xa0,0x00,0x00,0xea,0xa0,0x00,0xe9,0x00,0x00,0x6a,0xa0,0x00,0x00,0x2a,0xaa,0x80,0x00,0x00,0xaa,0xa9,0x00,0x02,0xaa,0x40,0x00,0x39,0x00,0x0e,0xab,0x00,0x00,0x29,0xaa,0x00,0x00,0x1a,0xfa,0x80,0x00,0xaa,0x90,0x00,0x00,0x65,0xab,0x01,0xa8,0x00,0x00,0xaa,0xa0,0x00,0x00,0x2a,0xaa,0xc0,0x00,0x01,0xaa,0xa8,0x00,0x02,0xaa,0xc0,0x00,0x28,0x00,0x06,0xa8,0x00,0x00,0x65,0xaa,0x00,0x00,0xe9,0x0a,0x90,0x01,0xaa,0x80,0x00,0x03,0xa0,0x6a,0xaa,0x90,0x00,0x03,0xaa,0x90,0x00,0x00,0xaa,0xa9,0x00,0x00,0x02,0xaa,0xac,0x00,0x0e,0xaa,0x00,0x00,0xe4,0x00,0x06,0xa8,0x00,0x03,0xa1,0xaa,0x00,0x00,0xa8,0x0e,0xac,0x06,0xaa,0x80,0x00,0x02,0x90,0x3a,0xa9,0xc0,0x00,0x01,0xaa,0x80,0x00,0x01,0xaa,0xa8,0x00,0x00,0x02,0xaa,0x90,0x00,0x06,0xaa,0x00,0x00,0xa0,0x00,0x0a,0xa8,0x00,0x02,0xb1,0xaa,0x00,0x01,0xac,0x03,0xaa,0xaa,0xaa,0x80,0x00,0x06,0x80,0x00,0x00,0x00,0x00,0x02,0xaa,0x40,0x00,0x06,0xaa,0xa4,0x00,0x00,0x0e,0xaa,0x80,0x00,0x0a,0xa9,0x00,0x01,0x90,0x00,0x0a,0xa8,0x00,0x06,0x81,0xa9,0x00,0x0e,0x90,0x00,0x1a,0x9f,0xaa,0x40,0x00,0x1a,0xc0,0x00,0x00,0x00,0x00,0x0e,0xaa,0xc0,0x00,0x1a,0xaa,0xa0,0x00,0x00,0x06,0xaa,0xc0,0x00,0x0a,0xa8,0x00,0x0e,0x80,0x00,0x06,0xa8,0x00,0x3a,0x01,0xa9,0x00,0x0a,0x80,0x00,0x00,0x03,0xaa,0x40,0x00,0xea,0x00,0x00,0x00,0x00,0x00,0x06,0xaa,0x00,0x00,0x6b,0xaa,0x90,0x00,0x00,0x0a,0xa9,0x00,0x00,0x0a,0xa8,0x00,0x0a,0xc0,0x00,0x06,0xa8,0x00,0xeb,0x01,0xa9,0x00,0x2a,0xc0,0x00,0x00,0x03,0xaa,0x80,0x03,0xa8,0x00,0x00,0x00,0x00,0x00,0x06,0xaa,0x00,0x01,0xad,0xaa,0x80,0x00,0x00,0x3a,0xa8,0x00,0x00,0x3a,0xa8,0x00,0x19,0x00,0x00,0x0e,0xa9,0x03,0xa4,0x01,0xaa,0x00,0x6b,0x00,0x00,0x00,0x00,0xaa,0xb0,0x06,0xac,0x00,0x00,0x00,0x00,0x00,0x06,0xaa,0x00,0x3a,0xb2,0xaa,0xc0,0x00,0x00,0x1a,0xa4,0x00,0x00,0x0a,0xa8,0x00,0x68,0x00,0x00,0x02,0xaa,0x76,0xa0,0x01,0xaa,0x01,0xa4,0x00,0x00,0x00,0x00,0xaa,0xa7,0x6a,0xb0,0x00,0x00,0x00,0x00,0x00,0x0e,0xaa,0x7d,0xaa,0xc2,0xaa,0x00,0x00,0x00,0x2a,0xa0,0x00,0x00,0x0a,0xab,0x0e,0xac,0x00,0x00,0x03,0xaa,0xaa,0x80,0x00,0xaa,0x9a,0x90,0x00,0x00,0x00,0x00,0xea,0xaa,0xaa,0xc0,0x00,0x00,0x00,0x00,0x00,0x02,0xaa,0xaa,0xa4,0x06,0xa9,0x00,0x00,0x00,0xea,0x90,0x00,0x00,0x06,0xaa,0xaa,0xb0,0x00,0x00,0x00,0x6a,0xa9,0x00,0x00,0xaa,0xaa,0x40,0x00,0x00,0x00,0x00,0x1a,0xaa,0xa4,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xaa,0xaa,0x70,0x0e,0xa8,0x00,0x00,0x00,0x2a,0x80,0x00,0x00,0x02,0xaa,0xa9,0x00,0x00,0x00,0x00,0x3a,0xac,0x00,0x00,0xea,0xab,0x00,0x00,0x00,0x00,0x00,0x0e,0xaa,0x70,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x35,0x5c,0x00,0x00,0xd4,0x00,0x00,0x00,0x03,0xc0,0x00,0x00,0x00,0x6a,0x9c,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x05,0x70,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x09,0x55,0x55,0x58,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x55,0x55,0x55,0x55,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x09,0x55,0x55,0x55,0x55,0x54,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x15,0x55,0x55,0x55,0x55,0x55,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x55,0x55,0x55,0x55,0x55,0x55,0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x09,0x55,0x55,0x55,0x55,0x55,0x55,0x58,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x05,0x55,0x55,0x55,0x55,0x55,0x55,0x54,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x15,0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x40,0x00,0x00,0x00,0x00,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x55,0x5a,0xa5,0x55,0x55,0x6a,0x95,0x55,0x50,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x55,0x6a,0xa9,0x55,0x55,0xaa,0xa5,0x55,0x50,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x05,0x55,0x6a,0xa9,0x55,0x55,0xaa,0xa5,0x55,0x54,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x05,0x55,0x6a,0xa9,0x55,0x55,0xaa,0xa5,0x55,0x54,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x05,0x55,0x6a,0xa9,0x55,0x55,0xaa,0xa5,0x55,0x54,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x15,0x55,0x6a,0xa9,0x55,0x55,0xaa,0xa5,0x55,0x55,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x15,0x55,0x56,0x95,0x55,0x55,0x5a,0x55,0x55,0x55,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x15,0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x15,0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x15,0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x15,0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x15,0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x15,0x55,0x5a,0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x05,0x55,0x56,0x95,0x55,0x55,0x55,0x95,0x55,0x54,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x05,0x55,0x56,0xa5,0x55,0x55,0x5a,0xa5,0x55,0x54,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x05,0x55,0x55,0x69,0x55,0x56,0xaa,0x55,0x55,0x54,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x55,0x55,0x5a,0x95,0x6a,0xa9,0x55,0x55,0x50,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x55,0x55,0x56,0xaa,0xa9,0x55,0x55,0x55,0x50,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x55,0x55,0x55,0x6a,0xa5,0x55,0x55,0x55,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x15,0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x05,0x55,0x55,0x55,0x55,0x55,0x55,0x54,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x55,0x55,0x55,0x55,0x55,0x55,0x50,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x55,0x55,0x55,0x55,0x55,0x55,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x15,0x55,0x55,0x55,0x55,0x55,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x55,0x55,0x55,0x55,0x50,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x55,0x55,0x55,0x55,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xc0,0x01,0x55,0x55,0x55,0x54,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0e,0xac,0x01,0x55,0x55,0x55,0x55,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3a,0xa8,0x01,0x55,0x55,0x55,0x55,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xea,0xab,0x01,0x55,0x15,0x55,0x55,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xaa,0xab,0x01,0x55,0x55,0x55,0x55,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0xaa,0xa9,0x00,0x55,0x55,0x55,0x55,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,0xaa,0xa9,0x00,0x55,0x55,0x55,0x55,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3a,0xaa,0xeb,0x01,0x55,0x55,0x15,0x55,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x2a,0xa8,0x68,0x01,0x55,0x55,0x55,0x55,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x6a,0xac,0x68,0x01,0x55,0x55,0x55,0x55,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xaa,0xb0,0xa4,0x01,0x55,0x55,0x55,0x55,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0xaa,0x43,0xac,0x01,0x55,0x55,0x55,0x55,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0e,0xaa,0x01,0xa0,0x01,0x55,0x55,0x55,0x55,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0a,0xa9,0x02,0x90,0x01,0x55,0x55,0x55,0x55,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1a,0xa8,0x06,0xb0,0x01,0x55,0x55,0x55,0x55,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x2a,0xac,0x0a,0x80,0x01,0x55,0x55,0x55,0x55,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0d,0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x6a,0x90,0x1a,0xc0,0x01,0x55,0x55,0x55,0x55,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x6a,0xa0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xaa,0xb0,0x2a,0x00,0x01,0x55,0x55,0x55,0x55,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0e,0xaa,0xa0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0xaa,0x40,0x6b,0x00,0x01,0x55,0x55,0x55,0x55,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0a,0xaa,0xa0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0xaa,0x00,0xa8,0x00,0x01,0x55,0x55,0x55,0x55,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0a,0xaa,0x90,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,0xa9,0x01,0xac,0x00,0x01,0x55,0x55,0x55,0x55,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0a,0xaa,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0a,0xa8,0x0e,0x90,0x00,0x01,0x55,0x55,0x55,0x55,0x50,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0e,0xa9,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3a,0xa4,0x0a,0x80,0x00,0x01,0x55,0x55,0x55,0x55,0x50,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x2a,0xac,0x1a,0xc0,0x00,0x01,0x55,0x55,0x55,0x55,0x50,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xea,0xa0,0xe9,0x00,0x00,0x01,0x55,0x56,0xa5,0x55,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x6a,0xb0,0xa8,0x00,0x00,0x01,0x55,0x5a,0xa5,0x55,0x50,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xaa,0x81,0xac,0x00,0x00,0x01,0x55,0x5a,0xa5,0x55,0x50,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0xaa,0x4e,0x90,0x00,0x00,0x01,0x55,0x6a,0x95,0x55,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0xaa,0x3a,0x40,0x00,0x00,0x01,0x55,0x6a,0x95,0x55,0x50,0x00,0x00,0x00,0x00,0x00,0x03,0x5c,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0e,0xaa,0xe9,0x00,0x00,0x00,0x01,0x55,0x6a,0xa5,0x55,0x50,0x00,0x00,0x00,0x00,0x03,0x6a,0xaa,0x40,0x00,0x00,0x00,0x01,0xa4,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,0xa9,0xa8,0x00,0x00,0x00,0x00,0x55,0x5a,0xa9,0x55,0x50,0x00,0x00,0x00,0x00,0x36,0xaa,0xaa,0xac,0x00,0x00,0x00,0x0a,0xa8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0a,0xaa,0xa0,0x00,0x00,0x00,0x00,0x55,0x5a,0xaa,0x55,0x40,0x00,0x00,0x00,0x00,0x6a,0x9c,0x0e,0xa8,0x00,0x00,0x00,0x2a,0xa4,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1a,0xaa,0x40,0x00,0x00,0x00,0x00,0x55,0x69,0xaa,0xa5,0x50,0x00,0x00,0x00,0x02,0xaa,0xc0,0x03,0xa9,0x00,0x00,0x00,0x6a,0xac,0x00,0x00,0x00,0x00,0x00,0x03,0x55,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x2a,0xa9,0x00,0x1a,0x9c,0x00,0x00,0x55,0x69,0x6a,0xa9,0x50,0x00,0x00,0x00,0x0a,0xa8,0x00,0x00,0xaa,0x00,0x00,0x03,0xaa,0xa0,0x00,0x00,0x0c,0x00,0x00,0x3a,0xaa,0xb0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x2a,0xac,0x00,0xaa,0xab,0x00,0x00,0x55,0x69,0x5a,0xa9,0x50,0x00,0x00,0x00,0xea,0xa0,0x00,0x00,0xaa,0x00,0x00,0x02,0xaa,0xb0,0x00,0x00,0x6a,0x40,0x00,0xaa,0xaa,0xac,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x6a,0xa0,0x02,0xaa,0xaa,0x00,0x00,0x55,0xa9,0x56,0xaa,0x50,0x00,0x00,0x03,0xaa,0x80,0x00,0x00,0xa9,0x00,0x00,0x0e,0xaa,0x40,0x00,0x02,0xaa,0x80,0x0e,0xaa,0xaa,0xa8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xaa,0xb0,0x06,0xaf,0xaa,0xc0,0x00,0x55,0xa5,0x56,0xaa,0x50,0x00,0x00,0x0e,0xaa,0xc0,0x00,0x00,0xab,0x00,0x00,0x0a,0xaa,0x00,0x00,0x02,0xaa,0x80,0x3a,0xaa,0xaa,0xab,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xaa,0x80,0x0a,0xb0,0x6a,0x40,0x00,0x56,0xa5,0x56,0xaa,0x90,0x00,0x00,0x0a,0xab,0x00,0x00,0x00,0x50,0x00,0x00,0x3a,0xa9,0x00,0x00,0x02,0xaa,0x40,0xea,0xb0,0x6a,0xa9,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xaa,0x80,0x3a,0x80,0x2a,0x40,0x00,0x56,0x95,0x56,0xaa,0x90,0x00,0x00,0x1a,0xa4,0x00,0x00,0x0d,0xc0,0x00,0x00,0x2a,0xa8,0x00,0x00,0x02,0xaa,0x43,0xab,0x00,0x1a,0xa9,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0xaa,0x40,0x1a,0x40,0x2a,0x40,0x00,0x5a,0x95,0x56,0xaa,0x90,0x00,0x00,0x6a,0xa0,0x00,0x00,0x0a,0x90,0x00,0x00,0x2a,0xa4,0x00,0x00,0x06,0xaa,0xce,0xac,0x00,0x3a,0xa9,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0xaa,0xc0,0x1a,0xc0,0x1a,0x40,0x00,0x5a,0x95,0x56,0xaa,0xd0,0x00,0x00,0xaa,0xb0,0x00,0x00,0x1a,0xa0,0x00,0x00,0x6a,0xa0,0x00,0x00,0x06,0xaa,0x0a,0x80,0x00,0x0a,0xa9,0x00,0x00,0x00,0x00,0x00,0x00,0x0e,0xaa,0x00,0x1a,0xc0,0x1a,0x40,0x00,0x1a,0x55,0x5a,0xaa,0x50,0x00,0x01,0xaa,0x80,0x00,0x00,0xea,0xa0,0x00,0x00,0xaa,0xb0,0x00,0x00,0x0a,0xa9,0x29,0x00,0x00,0x3a,0xab,0x00,0x00,0x00,0x00,0x00,0x00,0x06,0xaa,0x00,0x1a,0xc0,0x1a,0x40,0x00,0x6a,0x45,0x5a,0xaa,0x50,0x00,0x0e,0xaa,0xc0,0x00,0x00,0xaa,0xb0,0x00,0x03,0xaa,0x80,0x00,0x00,0x3a,0xa9,0x68,0x00,0x00,0x3a,0xa8,0x00,0x00,0x10,0x00,0x00,0x00,0x06,0xa9,0x00,0x3a,0x40,0x2a,0xc0,0x00,0xa9,0x55,0x5a,0xaa,0x50,0x00,0x0a,0xa9,0x00,0x00,0x01,0xaa,0x40,0x00,0x02,0xaa,0x40,0x00,0x00,0x2a,0xab,0xa0,0x00,0x00,0x1a,0xa8,0x00,0x00,0x60,0x00,0x00,0x00,0x0a,0xab,0x00,0x0a,0x40,0x2a,0xc0,0x00,0xa9,0x55,0x6a,0xa9,0x50,0x00,0x3a,0xab,0x00,0x00,0x0e,0xaa,0xc0,0x00,0x0e,0xaa,0x00,0x00,0x00,0xea,0xaa,0xb0,0x00,0x00,0x2a,0xa4,0x00,0x03,0x90,0x00,0x00,0x00,0x0a,0xa8,0x00,0x0a,0x80,0x2a,0x00,0x01,0xa5,0x55,0x6a,0xa9,0x10,0x00,0x2a,0xa8,0x00,0x00,0x3a,0xa9,0x00,0x00,0x0a,0xaa,0x00,0x00,0x00,0xaa,0xaa,0x40,0x00,0x00,0x2a,0xa0,0x00,0x02,0x80,0x00,0x00,0x00,0x0a,0xa8,0x00,0x0e,0xb0,0x69,0x00,0x06,0x95,0x55,0xaa,0xa5,0x50,0x00,0x2a,0xa4,0x00,0x00,0x2a,0xab,0x00,0x00,0x1a,0xa9,0x00,0x00,0x03,0xaa,0xaa,0x00,0x00,0x00,0x6a,0xa0,0x00,0x0e,0x40,0x00,0x00,0x00,0x0a,0xa8,0x00,0x01,0xa0,0xab,0x00,0x1a,0x55,0x55,0xaa,0xa5,0x50,0x00,0xaa,0xa0,0x00,0x00,0x6a,0xa8,0x00,0x00,0xea,0xab,0x00,0x00,0x02,0xaa,0xa8,0x00,0x00,0x00,0x6a,0x90,0x00,0x0a,0x00,0x00,0x00,0x00,0x0a,0xa8,0x00,0x00,0xab,0xa8,0x03,0xab,0x51,0x55,0xaa,0xa5,0x50,0x02,0xaa,0xa0,0x00,0x01,0xaa,0xac,0x00,0x03,0xaa,0xa8,0x00,0x00,0x0a,0xaa,0xa4,0x00,0x00,0x00,0xaa,0x80,0x00,0x19,0x00,0x00,0x00,0x00,0x0a,0xa8,0x00,0x00,0xea,0xa4,0x36,0xac,0x55,0x56,0xaa,0x95,0x10,0x06,0xaa,0x90,0x00,0x0e,0xaa,0xa0,0x00,0x0e,0x9a,0xa8,0x00,0x00,0x1a,0xaa,0xa0,0x00,0x00,0x00,0xaa,0x80,0x00,0xe8,0x00,0x00,0x00,0x00,0x0a,0xa8,0x00,0x00,0x06,0xaa,0xaa,0xb0,0x55,0x56,0xaa,0x95,0x40,0x1a,0xaa,0x90,0x00,0x3a,0x6a,0xa0,0x00,0x0a,0x8a,0xa8,0x00,0x00,0xea,0xaa,0xb0,0x00,0x00,0x03,0xaa,0x40,0x03,0xac,0x00,0x00,0x00,0x00,0x0a,0xa8,0x00,0x00,0x06,0xaa,0xa7,0x00,0x55,0x56,0xaa,0x95,0x40,0xa8,0xaa,0xb0,0x00,0xeb,0x6a,0xa0,0x00,0xea,0x06,0xab,0x00,0x03,0xa6,0xaa,0x40,0x00,0x00,0x03,0xaa,0x40,0x0e,0xb0,0x00,0x00,0x00,0x00,0x0a,0xa8,0x00,0x00,0x3a,0x80,0x00,0x00,0x55,0x56,0xaa,0x95,0x56,0xa0,0xaa,0xb0,0x01,0xa4,0xea,0xa0,0x01,0xa8,0x06,0xaa,0x00,0x06,0xb6,0xaa,0x00,0x00,0x00,0x03,0xaa,0x80,0x3a,0x40,0x00,0x00,0x00,0x00,0x0a,0xa8,0x00,0x00,0x2a,0x00,0x00,0x00,0x55,0x55,0xaa,0xaa,0xaa,0x40,0xaa,0x90,0x06,0x90,0x2a,0xa8,0x36,0xa0,0x02,0xaa,0x9d,0x6a,0xca,0xab,0x00,0x00,0x00,0x00,0xaa,0x93,0x69,0x00,0x00,0x00,0x00,0x00,0x0a,0xa9,0x00,0x00,0xab,0x00,0x00,0x00,0x55,0x55,0xaa,0xaa,0xab,0x00,0x6a,0xa7,0x6a,0x40,0x1a,0xaa,0xaa,0x40,0x03,0xaa,0xaa,0xa4,0x06,0xa4,0x00,0x00,0x00,0x00,0xea,0xaa,0xac,0x00,0x00,0x00,0x00,0x00,0x06,0xaa,0x00,0x0e,0xa4,0x00,0x00,0x00,0x00,0x00,0x1a,0xaa,0x90,0x00,0xea,0xaa,0xa9,0x00,0x06,0xaa,0xa7,0x00,0x00,0xea,0xaa,0x70,0x03,0x50,0x00,0x00,0x00,0x00,0x06,0xa9,0xc0,0x00,0x00,0x00,0x00,0x00,0x0e,0xaa,0xb0,0xea,0x90,0x00,0x00,0x00,0x00,0x00,0x03,0x5c,0x00,0x00,0x3a,0xaa,0xac,0x00,0x03,0x69,0x40,0x00,0x00,0x0d,0x5c,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0xaa,0xaa,0xaa,0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0e,0xaa,0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x6a,0xaa,0xab,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x36,0xaa,0x70,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00 };

/**
 * Splash 
 * 
 * set the properties of a new Splash
 *
 * @param name
 */
SplashRef method Ctor(SplashRef this)
{
    (SplashRef)this;
    this->x = 0;
    this->y = 0;
    return this;
}


void method Initialize(SplashRef this)
{
    (SplashRef)this;
}

void method Update(SplashRef this)
{
    (SplashRef)this;
}

void method Draw(SplashRef this)
{
    (SplashRef)this;
    // blit(splash, (int32_t)this->x, (int32_t)this->y, splashWidth, splashHeight, splashFlags);
    blit(splash, 0, 0, splashWidth, splashHeight, splashFlags);
}

void method Move(SplashRef this, long x, long y)
{
    (SplashRef)this;
    (long)x;
    (long)y;

    this->x = x;
    this->y = y;
}

long method GetWidth(SplashRef this)
{
    (SplashRef)this;
    return splashWidth;
}
long method GetHeight(SplashRef this)
{
    (SplashRef)this;
    return splashHeight;
}
