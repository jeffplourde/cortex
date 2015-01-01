/* fixture__type.h
 *
 *    Type-definitions for C-language.
 *    This file contains generated code. Do not modify!
 */

#ifndef fixture__type_H
#define fixture__type_H

#include "cortex.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Casting macro's for classes */
#define fixture_Dog(o) ((fixture_Dog)o)

/* Type definitions */
/* ::fixture::color */
CX_BITMASK(fixture_color);
    #define FIXTURE_red (0x1)
    #define FIXTURE_green (0x2)
    #define FIXTURE_blue (0x4)

/* ::fixture::Djinn */
typedef enum fixture_Djinn {
    FIXTURE_Mercury = 0,
    FIXTURE_Venus = 1,
    FIXTURE_Mars = 2,
    FIXTURE_Jupiter = 3
} fixture_Djinn;

/* ::fixture::DogBreed */
typedef enum fixture_DogBreed {
    FIXTURE_GoldenRetriever = 0,
    FIXTURE_Pug = 1,
    FIXTURE_Chihuahua = 2
} fixture_DogBreed;

/*  ::fixture::Dog */
CX_CLASS(fixture_Dog);

CX_CLASS_DEF(fixture_Dog) {
    fixture_DogBreed breed;
    cx_string name;
    cx_uint8 age;
    fixture_Dog lover;
};

typedef cx_uint32 fixture_ints[4];

/*  ::fixture::point2D */
typedef struct fixture_point2D fixture_point2D;

struct fixture_point2D {
    cx_int32 x;
    cx_int32 y;
};

#ifdef __cplusplus
}
#endif
#endif
