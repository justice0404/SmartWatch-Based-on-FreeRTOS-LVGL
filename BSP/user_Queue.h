#include "main.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define QUEUE_SIZE 7

typedef struct
{
	int8_t front;
	int8_t rear;
	int8_t size;
	uint32_t data[QUEUE_SIZE];
}Queue;

void initQueue(Queue *queue);
bool isQueueEmpty(Queue *queue);
bool isQueueFull(Queue *queue);
void enqueue(Queue *queue, unsigned long item);
uint32_t dequeue(Queue *queue);
