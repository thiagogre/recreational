#ifndef STACK_H
#define STACK_H
#define LINKED_LIST_IMPLEMENTATION
#include "linked_list.h"

typedef struct StackLIFO {
    Node *head;
} StackLIFO;

void initStack(StackLIFO **stack, Data data);
void push(StackLIFO *stack, Data data);
int pop(StackLIFO *stack, Data *popped);

#define STACK_IMPLEMENTATION
#ifdef STACK_IMPLEMENTATION

inline void initStack(StackLIFO **stack, Data data) {
    Node *newNode = init(data);
    StackLIFO *newStack = (StackLIFO *)malloc(sizeof(struct StackLIFO));
    newStack->head = newNode;
    *stack = newStack;
}

inline void push(StackLIFO *stack, Data data) {
    Node *newNode = init(data);
    newNode->next = stack->head;
    stack->head = newNode;
}

inline int pop(StackLIFO *stack, Data *popped) {
    if (stack == NULL || stack->head == NULL) {
        return 1;
    }

    Node *popped_node = stack->head;
    *popped = popped_node->data;
    stack->head = stack->head->next;
    RELEASE(popped_node);

    return 0;
}

#endif // STACK_IMPLEMENTATION
#endif // STACK_H