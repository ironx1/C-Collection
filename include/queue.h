//
// Created by akaan on 6.05.2023.
//

#ifndef COLLECTIONS_QUEUE_H
#define COLLECTIONS_QUEUE_H
#include "LinkedList.h"
typedef struct queue Queue;

struct queue{
    LinkedList *data;
    void (*enqueue)(Queue *, void *data);
    void (*dequeue)(Queue *);
    void (*pushBack)(Queue *, void *data);
    void (*popFront)(Queue *);
    void (*insert)(Queue *, void *data, uint32_t index);
    void (*delete)(Queue *, uint32_t index);
    void *(*getData)(Queue *, uint32_t index);
    boolean (*search)(Queue *, void *data);
    uint32_t (*getLength)(Queue *queue);
    void (*clear)(Queue *);
    void (*dtor)(Queue *);
};

Queue *init_Queue();
#endif //COLLECTIONS_QUEUE_H
