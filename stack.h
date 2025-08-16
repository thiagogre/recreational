#ifndef STACK_H
#define STACK_H
#define LINKED_LIST_IMPLEMENTATION
#include "linked_list.h"

typedef struct StackLIFO {
    Node *head;
} Stack;

void initStack(Stack **stack, Data data);
void push(Stack *stack, Data data);
int pop(Stack *stack, Data *popped);

#define STACK_IMPLEMENTATION
#ifdef STACK_IMPLEMENTATION

inline void initStack(Stack **stack, Data data) {
    Node *newNode = init(data);
    Stack *newStack = (Stack *)malloc(sizeof(struct StackLIFO));
    newStack->head = newNode;
    *stack = newStack;
}

inline void push(Stack *stack, Data data) {
    Node *newNode = init(data);
    newNode->next = stack->head;
    stack->head = newNode;
}

inline int pop(Stack *stack, Data *popped) {
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