#ifndef Queue_h
#define Queue_h

#include <stdbool.h>
#include "DualyLinkedList.h"

//////////////////////////////////////////////////
typedef enum QueueOption {
    QUEUE_OPTION_NONE,
    QUEUE_OPTION_WITH_ELEMENT
} QUEUE_OPTION_e;

typedef struct Queue {
    DLL_t *list;
} Queue_t;

//////////////////////////////////////////////////
Queue_t *createQueue(void);
bool destroyQueue(Queue_t *Q, QUEUE_OPTION_e option);
bool clearQueue(Queue_t *Q, QUEUE_OPTION_e option);
bool enQueue(Queue_t *Q, void *element);
void *deQueue(Queue_t *Q);
bool isEmptyQueue(Queue_t *Q);
void *findElementOnQueue(Queue_t *Q, int (*comp)(void*, void*), void *element);
void *findMinOnQueue(Queue_t *Q, int (*comp)(void*, void*));
void *findMaxOnQueue(Queue_t *Q, int (*comp)(void*, void*));

#endif
