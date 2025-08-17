#ifndef QUEUE_H
#define QUEUE_H

#define LINKED_LIST_IMPLEMENTATION
#include "linked_list.h"
#include <stdlib.h>

typedef struct QueueFIFO {
    Node *head;
    Node *tail;
} QueueFIFO;

void initQueue(QueueFIFO **queue, Data data);
void enqueue(QueueFIFO *queue, Data data);
int dequeue(QueueFIFO *queue, Data *out);

#ifdef QUEUE_IMPLEMENTATION

inline void initQueue(QueueFIFO **queue, Data data) {
    Node *node = init(data);
    QueueFIFO *newQueue = (QueueFIFO *)malloc(sizeof(*newQueue));
    newQueue->head = node;
    newQueue->tail = node;
    *queue = newQueue;
}

inline void enqueue(QueueFIFO *queue, Data data) {
    Node *newNode = init(data);
    if (queue->tail == NULL) {
        queue->head = newNode;
        queue->tail = newNode;
    } else {
        queue->tail->next = newNode;
        queue->tail = newNode;
    }
}

inline int dequeue(QueueFIFO *queue, Data *out) {
    if (queue->head == NULL) {
        return 1;
    }

    Node *temp = queue->head;
    *out = temp->data;
    queue->head = temp->next;

    if (queue->head == NULL) {
        queue->tail = NULL;
    }

    RELEASE(temp);
    return 0;
}

#endif // QUEUE_IMPLEMENTATION
#endif // QUEUE_H
