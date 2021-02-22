/*
 * data_queue.h
 *
 *  Created on: 22 Nov 2020
 *      Author: gorkem.akinci
 */

#ifndef INC_DATA_QUEUE_H_
#define INC_DATA_QUEUE_H_
#define MAX_SIZE_OF_ARRAY 200




typedef struct queue{

int tail, head, size;
int capacity;
char QueueBuffer[MAX_SIZE_OF_ARRAY];

}queue;

void clear_queue(queue* queue);
void init_queue(queue* queue);
void enqueue(queue* myqueue, char value);
char dequeue(queue* myqueue);
int isEmpty(queue* myqueue);
int isFull( queue* myqueue);

#endif /* INC_DATA_QUEUE_H_ */
