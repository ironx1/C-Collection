//
// Created by akaan on 6.05.2023.
//

#include "../include/queue.h"
#include <stdlib.h>

static void queue_enqueue(Queue *queue, void *data){
    if(queue == NULL || data == NULL || queue->data == NULL) return;
    queue->data->pushFront(queue->data, data);
}

static void queue_dequeue(Queue *queue){
    if(queue == NULL || queue->data == NULL) return;
    queue->data->popBack(queue->data);
}

static void queue_pushBack(Queue *queue, void *data){
    if(queue == NULL || data == NULL || queue->data == NULL) return;
    queue->data->pushBack(queue->data, data);
}

static void queue_popFront(Queue *queue){
    if(queue == NULL || queue->data == NULL) return;
    queue->data->popFront(queue->data);
}

static void queue_insert(Queue *queue, void *data, uint32_t index){
    if(queue == NULL || data == NULL || queue->data == NULL) return;
    queue->data->insert(queue->data, data, index);
}

static void queue_delete(Queue *queue, uint32_t index){
    if(queue == NULL || queue->data == NULL) return;
    queue->data->delete(queue->data, index);
}

static void *queue_getData(Queue *queue, uint32_t index){
    if(queue == NULL || queue->data == NULL) return NULL;
    return queue->data->getData(queue->data, index);
}

static boolean queue_search(Queue *queue, void *data){
    if(queue == NULL || queue->data == NULL) return 0;
    return queue->data->search(queue->data, data);
}

static uint32_t queue_getLength(Queue *queue){
    if(queue == NULL || queue->data == NULL) return 0;
    return queue->data->length;
}

static void queue_clear(Queue *queue){
    if(queue == NULL || queue->data == NULL) return;
    queue->data->clear(queue->data);
}

static void queue_dtor(Queue *queue){
    if(queue == NULL || queue->data == NULL) return;
    queue->clear(queue);
    free(queue);
}

Queue *init_Queue(){
    Queue *queue = memAllocM(Queue, 1);
    queue->data = init_LinkedList();
    queue->enqueue = queue_enqueue;
    queue->dequeue = queue_dequeue;
    queue->pushBack = queue_pushBack;
    queue->popFront = queue_popFront;
    queue->insert = queue_insert;
    queue->delete = queue_delete;
    queue->getData = queue_getData;
    queue->search = queue_search;
    queue->getLength = queue_getLength;
    queue->clear = queue_clear;
    queue->dtor = queue_dtor;
    return queue;
}