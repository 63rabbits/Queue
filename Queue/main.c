#include <unistd.h>
//#define checkMemoryLeak

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include "Queue.h"

//////////////////////////////////////////////////
typedef struct Element {
    int value;
} Element_t;

//////////////////////////////////////////////////
void test(void);
Element_t *createElement(int value);
bool destroyElement(Element_t *element);
int comp(void *elementA, void *elementB);

//////////////////////////////////////////////////
int main(int argc, const char * argv[]) {

#ifdef checkMemoryLeak
    while (true) {
        test();
        sleep(1);
    }
#else
    test();
#endif
    
    return EXIT_SUCCESS;
}

void test() {
    int numOfValues = 15;
    int count = 0;
    
    QUEUE_t *Q = createQueue();
    
    printf("*** enqueue [%s] ***\n", __func__);
    count = 0;
    for (int i=0; i<numOfValues; i++) {
        count++;
        Element_t *element = createElement(i);
        bool check = enQueue(Q, element);
        if (check) {
            printf("enqueue #%4d : %10d\n", count, element->value);
        }
        else {
            printf("error [%s] : could not enqueue value %d.\n", __func__, i);
            destroyElement(element);
        }
    }
    
    printf("*** peek [%s] ***\n", __func__);
    Element_t *head = peekQueue(Q);
    printf("peek value : %d\n", head->value);

    printf("*** find min/max [%s] ***\n", __func__);
    Element_t *min = findMinOnQueue(Q, comp);
    printf("min value : %d\n", min->value);
    Element_t *max = findMaxOnQueue(Q, comp);
    printf("max value : %d\n", max->value);

    Element_t *element = NULL;
    int s1 = 1;
    Element_t *e1 = createElement(s1);
    element = findElementOnQueue(Q, comp, e1);
    if (element != NULL) {
        printf("found value %d.\n", element->value);
    }
    else {
        printf("cound not found value %d. (T^T)\n", s1);
    }
    destroyElement(e1);
    
    int s2 = INT_MAX;
    Element_t *e2 = createElement(s2);
    element = findElementOnQueue(Q, comp, e2);
    if (element != NULL) {
        printf("found value %d.\n", element->value);
    }
    else {
        printf("cound not found value %d. (T^T)\n", s2);
    }
    destroyElement(e2);

    printf("*** dequeue [%s] ***\n", __func__);
    count = 0;
    while (!isEmptyQueue(Q)) {
        count++;
        Element_t *element = deQueue(Q);
        if (element != NULL) {
            printf("dequeue #%4d : %10d\n", count, element->value);
            destroyElement(element);
        }
        else {
            printf("error [%s] : could not dequeue value.\n", __func__);
        }
    }
    
    destroyQueue(Q, QUEUE_OPTION_WITH_ELEMENT);
}

Element_t *createElement(int value) {
    Element_t *element = malloc(sizeof(Element_t));
    if (element == NULL) return NULL;
    element->value = value;
    return element;
}

bool destroyElement(Element_t *element) {
    // Block illegal parameters.
    if (element == NULL) return false;
    free(element);
    return true;
}

int comp(void *elementA, void *elementB) {
    int valueA = ((Element_t *)elementA)->value;
    int valueB = ((Element_t *)elementB)->value;
    return valueA - valueB;
}

