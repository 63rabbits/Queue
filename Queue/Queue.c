#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include "Queue.h"

//////////////////////////////////////////////////
Queue_t *createQueue() {
    Queue_t *queue = malloc(sizeof(Queue_t));
    if (queue == NULL) return NULL;
    queue->list = createDLList();
    if (queue->list == NULL) {
        free(queue);
    }
    
    return queue;
}

bool destroyQueue(Queue_t *Q, QUEUE_OPTION_e option) {
    // Block illegal parameters.
    if (Q == NULL) return false;
    
    bool result = false;
    
    result = clearQueue(Q, option);
    if (!result) {
        return false;
    }
    result = destroyDLList(Q->list, DLL_OPTION_NONE);
    if (!result) {
        return false;
    }
    free(Q);
    
    return true;
}

bool clearQueue(Queue_t *Q, QUEUE_OPTION_e option) {
    // Block illegal parameters.
    if (Q == NULL) return false;
    
    bool result = false;
    
    DLL_t *list = Q->list;
    if (list != NULL) {
        if (option == QUEUE_OPTION_WITH_ELEMENT) {
            result = clearDLList(list, DLL_OPTION_WITH_ELEMENT);
        }
        else {
            result = clearDLList(list, DLL_OPTION_NONE);
        }
    }
    
    return result;
}

bool enQueue(Queue_t *Q, void *element) {
    // Block illegal parameters.
    if (Q == NULL) return false;
    
    return insertDLList(Q->list, element);
}

void *deQueue(Queue_t *Q) {
    if (Q == NULL) return NULL;
    return pullDLList(Q->list);
}

bool isEmptyQueue(Queue_t *Q) {
    if (Q == NULL) return true;
    return isEmptyDLList(Q->list);
}

void *findElementOnQueue(Queue_t *Q, int (*comp)(void*, void*), void *element) {
    return findElementOnDLList(Q->list, comp, element);
}

void *findMinOnQueue(Queue_t *Q, int (*comp)(void*, void*)) {
    return findMinOnDLList(Q->list, comp);
}

void *findMaxOnQueue(Queue_t *Q, int (*comp)(void*, void*)) {
    return findMaxOnDLList(Q->list, comp);
}
