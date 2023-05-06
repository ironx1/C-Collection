#ifndef VECTOR_VECTOR_H
#define VECTOR_VECTOR_H

#include "generic_utils.h"

typedef struct vector Vector;

struct vector {
    void **data;
    int i, length;

    void (*pushBack)(Vector *, void *data);

    void (*pushFront)(Vector *, void *data);

    void (*insert)(Vector *, void *data, uint32_t index);

    void (*popBack)(Vector *);

    void (*clear)(Vector *);

    void (*delete)(Vector *, uint32_t index);

    void (*popFront)(Vector *);

    void *(*getData)(Vector *, uint32_t index);

    boolean (*search)(Vector *, void *data);
};

Vector *init_Vector();

#endif // VECTOR_VECTOR_H