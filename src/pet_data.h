#pragma once
#include "wasm4.h"

typedef enum PetType: unsigned int {
    PetBrainWorm
} PetType;

// max 1024 bytes
struct pet_data {
    PetType type;
    char name[20];
    long    age;   
    long    hunger;
    long    happiness;
    long    money;

};

// void SavePetData(uint32_t len, void* data)
// {
//     diskw(data, len);
// }

// void RestorePetData(uint32_t len, void* data)
// {
//     diskr(data, len);
// }

