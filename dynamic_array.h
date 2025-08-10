#ifndef DYNAMIC_ARRAY
#define DYNAMIC_ARRAY

#include <stdlib.h>

typedef struct DynamicVec DynamicVec;
typedef void (*PushFunc)(DynamicVec *vec, void *data);
struct DynamicVec {
    void *data;
    int length;
    int capacity;
    size_t data_size;
    PushFunc push;
};

DynamicVec create(size_t data_size);
void push_impl(DynamicVec *vec, void *data);

#ifdef DYNAMIC_ARRAY_IMPLEMENTATION
#include <stdio.h>
#include <string.h>

inline void push_impl(DynamicVec *vec, void *data) {
    if (vec->length == vec->capacity) {
        vec->capacity =
            vec->capacity == 0 ? (int)vec->data_size : vec->capacity * 2;
        vec->data = realloc(vec->data, vec->capacity * vec->data_size);
        if (!vec->data) {
            exit(1);
        }
    }

    memcpy((char *)vec->data + vec->length * vec->data_size, data,
           vec->data_size);
    vec->length++;
}

inline DynamicVec create(size_t data_size) {
    DynamicVec vec = {
        .data = NULL,
        .length = 0,
        .capacity = 0,
        .data_size = data_size,
        .push = push_impl,
    };

    return vec;
}

#endif // DYNAMIC_ARRAY_IMPLEMENTATION
#endif // DYNAMIC_ARRAY