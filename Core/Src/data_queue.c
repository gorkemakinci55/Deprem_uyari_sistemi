/*
 * data_queue.cpp
 *
 *  Created on: 22 Nov 2020
 *      Author: gorkem.akinci
 */

#include "data_queue.h"
#include "stdio.h"
#include "stdlib.h"


void init_queue(queue* queue) {
    queue->tail = -1;
    queue->head = -1;
    queue->size = 0;
}

void enqueue(queue* myqueue, char value) {


    if(myqueue->tail == -1){

        ++myqueue->tail;
        myqueue->QueueBuffer[myqueue->tail] = value;
        ++myqueue->head;
        ++myqueue->size;
    }
    else{

        ++myqueue->tail;
        myqueue->QueueBuffer[myqueue->tail] = value;
    }
}

char dequeue(queue* myqueue) {
    if (myqueue->head == -1) {
        //error
    }

    if(myqueue->size < 1){
        //error;
    }

    char tmp = myqueue->QueueBuffer[myqueue->head];
    ++myqueue->head;
    --myqueue->size;
    return tmp;

}

void clear_queue(queue* queue){
    for(int i = 0; i < MAX_SIZE_OF_ARRAY; ++i){
        queue->QueueBuffer[i] = 0;
    }
}

int isEmpty( queue* queue)
{
    return (queue->size == 0);
}

int isFull( queue* queue)
{
    return (queue->size == queue->capacity);
}

//void printQueue(queue* queue){
//    for(int i=0; i < queue->size; ++i){
//
//    }
//}



