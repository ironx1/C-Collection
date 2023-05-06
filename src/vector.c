#ifdef _WIN32
#include "..\include\vector.h"
#else
#include "../include/vector.h"
#endif
#include <stdlib.h>

static void vector_pushBack(Vector *vector, void *data) {
    if (vector == NULL)
        return;
    if (vector->data == NULL) {
        vector->data = memAllocM(void*, ++vector->length);
        isNullM(vector->data) return;
        vector->data[vector->i++] = data;
        return;
    }
    vector->data = (void **) realloc(vector->data, ++vector->length * sizeof(void *));
    isNullM(vector->data) return;
    vector->data[vector->i++] = data;
}

static void vector_clear(Vector *vector) {
    isNullM(vector) return;
    isNullM(vector->data) return;
    for (int i = 0; i < vector->length; i++) {
        isNullM(vector->data[i]) continue;
        free(vector->data[i]);
        vector->data[i] = NULL;
    }
    free(vector->data);
    vector->data = NULL;
    free(vector);
    vector = NULL;
}

static void vector_popBack(Vector *vector) {
    isNullM(vector) return;
    isNullM(vector->data) return;
    void **copyVector = memAllocM(void*, --vector->length);
    isNullM(copyVector) {
        perror("Error: ");
        exit(1);
    }
    for (int i = 0; i < vector->length; i++) {
        copyVector[i] = vector->data[i];
    }
    free(vector->data[--vector->i]);
    free(vector->data);
    vector->data = copyVector;
}

static void vector_delete(Vector *vector, uint32_t index) {
    isNullM(vector) return;
    isNullM(vector->data) return;
    if (index >= vector->length)
        return;
    if (index == vector->length - 1) {
        vector->popBack(vector);
        return;
    }
    if (index == 0) {
        vector->popFront(vector);
        return;
    }
    void **copyVector = memAllocM(void*, --vector->length);
    for (int i = 0; i < vector->length; i++) {
        isNullM(vector->data[i]) continue;
        if (i >= index)
            copyVector[i] = vector->data[i + 1];
        else
            copyVector[i] = vector->data[i];
    }
    free(vector->data[index]);
    free(vector->data);
    vector->data = copyVector;
    vector->i--;
}

static void vector_popFront(Vector *vector) {
    isNullM(vector) return;
    isNullM(vector->data) return;
    void **copyVector = memAllocM(void*, --vector->length);
    for (int i = 0; i < vector->length; i++) {
        isNullM(vector->data[i]) continue;
        copyVector[i] = vector->data[i + 1];
    }
    free(vector->data[0]);
    free(vector->data);
    vector->data = copyVector;
    vector->i--;
}

static void *vector_getData(Vector *vector, uint32_t index) {
    isNullM(vector) return NULL;
    isNullM(vector->data) return NULL;
    if (index >= vector->length)
        return NULL;
    for (int i = 0; i < vector->length; i++) {
        if (i == index)
            return vector->data[i];
    }
    return NULL;
}

static boolean vector_search(Vector *vector, void *data) {
    isNullM(vector) return 0;
    isNullM(vector->data) return 0;
    for (int i = 0; i < vector->length; i++) {
        isNullM(vector->data[i]) continue;
        if (vector->data[i] == data) return 1;
    }
    return 0;
}

static void vector_pushFront(Vector *vector, void *data) {
    isNullM(vector) return;
    isNullM(vector->data) {
        vector->data = memAllocM(void*, ++vector->length);
        isNullM(vector->data) return;
        vector->data[vector->i++] = data;
        return;
    }
    vector->data = (void **) realloc(vector->data, ++vector->length * sizeof(void *));
    for (int i = vector->length - 2; i >= 0; i--) {
        vector->data[i + 1] = vector->data[i];
    }
    vector->data[0] = data;
    vector->i++;
}

static void vector_insert(Vector *vector, void *data, uint32_t index) {
    isNullM(vector) return;
    isNullM(vector->data) {
        vector->data = memAllocM(void*, ++vector->length);
        isNullM(vector->data) return;
        vector->data[vector->i++] = data;
        return;
    }
    if (index > vector->length)
        return;
    if (index == 0) {
        vector->pushFront(vector, data);
        return;
    }
    if (index == vector->length) {
        vector->pushBack(vector, data);
        return;
    }
    vector->data = (void **) realloc(vector->data, ++vector->length * sizeof(void *));
    isNullM(vector->data) return;
    for (int j = vector->length - 2; j >= index; j--) {
        vector->data[j + 1] = vector->data[j];
    }
    vector->data[index] = data;
    vector->i++;
}

Vector *init_Vector() {
    Vector *vector = memAllocM(Vector, 1);
    isNullM(vector) {
        perror("Error: ");
        exit(1);
    }
    vector->i = vector->length = 0;
    vector->data = NULL;

    vector->pushBack = vector_pushBack;
    vector->clear = vector_clear;
    vector->popBack = vector_popBack;
    vector->delete = vector_delete;
    vector->popFront = vector_popFront;
    vector->getData = vector_getData;
    vector->search = vector_search;
    vector->pushFront = vector_pushFront;
    vector->insert = vector_insert;
    return vector;
}
