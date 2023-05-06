//
// Created by akaan on 2.05.2023.
//
#ifdef _WIN32
#include "..\include\stack.h"
#else
#include "../include/stack.h",
#endif
#include <stdlib.h>

static void stack_push(Stack *stack ,void *data){
    isNullM(stack) return;
    isNullM(stack->data) return;
    stack->data->pushFront(stack->data, data);
}

static void stack_pop(Stack *stack){
    isNullM(stack) return;
    isNullM(stack->data) return;
    stack->data->popFront(stack->data);
}

static void stack_pushBack(Stack *stack, void *data){
    isNullM(stack) return;
    isNullM(stack->data) return;
    stack->data->pushBack(stack->data, data);
}

static void stack_insert(Stack *stack, void *data, u_int index){
    isNullM(stack) return;
    isNullM(stack->data) return;
    stack->data->insert(stack->data, data, index);
}

static void stack_popBack(Stack *stack){
    isNullM(stack) return;
    isNullM(stack->data) return;
    stack->data->popBack(stack->data);
}

static void stack_delete(Stack *stack, u_int index){
    isNullM(stack) return;
    isNullM(stack->data) return;
    stack->data->delete(stack->data, index);
}

static void stack_clear(Stack *stack){
    isNullM(stack) return;
    isNullM(stack->data) return;
    stack->data->clear(stack->data);
}

static uint8_t stack_search(Stack *stack, void *data){
    isNullM(stack) return 0;
    isNullM(stack->data) return 0;
    return stack->data->search(stack->data, data);
}

static void *stack_peek(Stack *stack){
    isNullM(stack) return NULL;
    isNullM(stack->data) return NULL;
    return stack->data->head->data;
}

Stack *init_Stack(){
    Stack *stack = memAllocM(Stack, 1);
    stack->data = init_LinkedList();
    stack->push = stack_push;
    stack->pop = stack_pop;
    stack->pushBack = stack_pushBack;
    stack->popBack = stack_popBack;
    stack->insert = stack_insert;
    stack->delete = stack_delete;
    stack->clear = stack_clear;
    stack->search = stack_search;
    stack->peek = stack_peek;
    return stack;
}