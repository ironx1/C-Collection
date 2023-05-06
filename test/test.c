//
// Created by akaan on 3.05.2023.
//

#include "..\include\queue.h"
#include "..\include\allocate.h"
#include <stdlib.h>
#include <stdio.h>

newNumM(int)

int main(void){
    Queue *queue = init_Queue();
    for (int i = 0; i < 50; ++i) {
        queue->enqueue(queue, new_int(i*10));
    }
    queue->clear(queue);
    queue->dtor(queue);
}