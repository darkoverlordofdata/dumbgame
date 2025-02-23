// #pragma once
// #include "corefw/cfstring.h"
// #include "corefw/class.h"
// #include "corefw/corefw.h" // IWYU pragma: keep

// typedef struct __PetData* PetDataRef;
// extern CFClassRef PetData;

// // typedef enum PetType: unsigned int {
// //         PetBrainWorm
// // } PetType;


// // // max 1024 bytes
// // struct pet_data {
// //         PetType type;
// //         char name[20];
// //         long        age;     
// //         long        hunger;
// //         long        happiness;
// //         long        money;

// // };

// struct __PetData {
//         struct __CFObject obj;
//         struct pet_data data;
// };

// PetDataRef method Ctor(PetDataRef, char*);
// void method Save(PetDataRef);
// void method Restore(PetDataRef);

// static inline PetDataRef NewPetData(CFStringRef name)
// {
//         return Ctor((PetDataRef)CFCreate(PetData), CFStringC(name));
// }