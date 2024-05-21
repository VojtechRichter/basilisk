#ifndef BASILISK_TYPES_H
#define BASILISK_TYPES_H

#include <stdint.h>
#include <assert.h>

#ifndef BASILISK_ASSERT
    #define BASILISK_ASSERT(e) \
    assert(e);
#endif // BASILISK_ASSERT

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;

typedef int8_t s8;
typedef int16_t s16;
typedef int32_t s32;

#endif // BASILISK_TYPES_H