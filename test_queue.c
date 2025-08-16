#include "test_runner.h"
#include <stdlib.h>
#define QUEUE_IMPLEMENTATION
#include "queue.h"

static int test_enqueue_dequeue(void) {
    QueueFIFO *queue = NULL;
    initQueue(&queue, 0);
    ASSERT(queue->head->data == 0);
    ASSERT(queue->head->next == NULL);

    enqueue(queue, 1);
    enqueue(queue, 2);
    ASSERT(queue->head->data == 0);
    ASSERT(queue->head->next->data == 1);
    ASSERT(queue->head->next->next->data == 2);

    Data dequeued;
    ASSERT(dequeue(queue, &dequeued) == 0);
    ASSERT(dequeued == 0);
    ASSERT(queue->head->data == 1);
    ASSERT(dequeue(queue, &dequeued) == 0);
    ASSERT(dequeued == 1);
    ASSERT(queue->head->data == 2);
    ASSERT(dequeue(queue, &dequeued) == 0);
    ASSERT(dequeued == 2);
    ASSERT(dequeue(queue, &dequeued) == 1);
    ASSERT(queue->head == NULL);

    RELEASE(queue);

    return 0;
}

static test_case tests[] = {
    {.name = "Enqueue and Dequeue", .func = test_enqueue_dequeue},
};

int main(void) { return RUN_TESTS(tests); }
