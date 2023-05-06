//
// Created by akaan on 2.05.2023.
//

#ifndef COLLECTIONS_STACK_H
#define COLLECTIONS_STACK_H
#include "LinkedList.h"

typedef struct stack Stack;

struct stack
{
    LinkedList *data;
    void (*push)(Stack *, void *data);
    void (*pop)(Stack *);
    void (*pushBack)(Stack *, void *data);
    void (*insert)(Stack *, void *data, u_int index);
    void (*popBack)(Stack *);
    void (*delete)(Stack *, u_int index);
    void (*clear)(Stack *);
    uint8_t (*search)(Stack *, void *data);
    void *(*peek)(Stack *);
};
Stack *init_Stack();
#endif // COLLECTIONS_STACK_H
