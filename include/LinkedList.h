#ifndef GENERIC_LINKEDLIST_H
#define GENERIC_LINKEDLIST_H

#include "generic_utils.h"

typedef struct linked_list LinkedList;
typedef struct ll_node LNode;

struct ll_node
{
    void *data;
    LNode *prev, *next;
};

struct linked_list
{
    LNode *head, *tail;
    int length;

    // functions
    void (*pushBack)(LinkedList *, void *data);

    void (*popBack)(LinkedList *);

    void (*pushFront)(LinkedList *, void *data);

    void (*popFront)(LinkedList *);

    void (*insert)(LinkedList *, void *data, uint32_t index);

    void (*delete)(LinkedList *, uint32_t index);

    void (*clear)(LinkedList *);

    void (*deleteNode)(LinkedList *, void *data);

    void *(*getData)(LinkedList *, uint32_t index);

    uint8_t (*search)(LinkedList *, void *data);
};

LinkedList *init_LinkedList();
void free_LinkedList(LinkedList *);
#endif // GENERIC_LINKEDLIST_H