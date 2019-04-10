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
} QUEUE_t;

//////////////////////////////////////////////////
QUEUE_t *createQueue(void);
bool destroyQueue(QUEUE_t *Q, QUEUE_OPTION_e option);
bool clearQueue(QUEUE_t *Q, QUEUE_OPTION_e option);
bool enQueue(QUEUE_t *Q, void *element);
void *deQueue(QUEUE_t *Q);
bool isEmptyQueue(QUEUE_t *Q);
void *findElementOnQueue(QUEUE_t *Q, int (*comp)(void*, void*), void *element);
void *findMinOnQueue(QUEUE_t *Q, int (*comp)(void*, void*));
void *findMaxOnQueue(QUEUE_t *Q, int (*comp)(void*, void*));

#endif
