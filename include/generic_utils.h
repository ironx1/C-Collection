#ifndef GENERIC_GENERIC_UTILS_H
#define GENERIC_GENERIC_UTILS_H

#include <stdint.h>

#define isNullM(variable) if (variable == NULL)

#define memAllocM(type, size) (type *)malloc(sizeof(type) * (size))

typedef uint8_t boolean;
typedef int (*funCompare)(void *, void *);
typedef unsigned int u_int;
#endif // GENERIC_GENERIC_UTILS_H