#include "corefw/cfstring.h"
#include "wasm4.h"
#include "corefw/corefw.h" // IWYU pragma: keep
#include "petdata.h"

static struct __CFClass class = {
	.name = "PetData",
	.size = sizeof(struct __PetData),
};
CFClassRef PetData = &class;

PetDataRef method Ctor(PetDataRef this, char* name)
{
    (PetDataRef)this;
    (char*)name;

    this->data.type = PetBrainWorm;
    for (int i=0; i<20; i++) {
        this->data.name[i] = name[i];
        if (name[i] == 0) break;
    }
    return this;
}

void method Save(PetDataRef this)
{
    (PetDataRef)this;
    diskw(&this->data, sizeof(this->data));
}

void method Restore(PetDataRef this)
{
    (PetDataRef)this;
    diskr(&this->data, sizeof(this->data));
}

