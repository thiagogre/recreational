#include "test_runner.h"
#include <stdlib.h>
#define STACK_IMPLEMENTATION
#include "stack.h"

static int test_push_pop(void) {
    Stack *stack = NULL;
    initStack(&stack, 0);
    ASSERT(stack->head->data == 0);
    ASSERT(stack->head->next == NULL);

    push(stack, 1);
    push(stack, 2);
    ASSERT(stack->head->data == 2);
    ASSERT(stack->head->next->data == 1);
    ASSERT(stack->head->next->next->data == 0);

    Data popped;
    ASSERT(pop(stack, &popped) == 0);
    ASSERT(popped == 2);
    ASSERT(stack->head->data == 1);
    ASSERT(pop(stack, &popped) == 0);
    ASSERT(popped == 1);
    ASSERT(stack->head->data == 0);
    ASSERT(pop(stack, &popped) == 0);
    ASSERT(popped == 0);
    ASSERT(pop(stack, &popped) == 1);
    ASSERT(stack->head == NULL);

    RELEASE(stack);

    return 0;
}

static test_case tests[] = {
    {.name = "Push and Pop", .func = test_push_pop},
};

int main(void) { return RUN_TESTS(tests); }
