#include <string.h>
#define DYNAMIC_ARRAY_IMPLEMENTATION
#include "dynamic_array.h"
#define LINKED_LIST_IMPLEMENTATION
#include "linked_list.h"
#include "test_runner.h"

#define NODES 10

static int test_append_and_traverse(void) {
    Node *node = NULL;
    DynamicVec vec = create(sizeof(Data));

    for (Data i = 0; i < NODES; i++) {
        Data data = i * 2;
        vec.push(&vec, &data);

        if (i == 0) {
            node = append(NULL, data);
            ASSERT(node != NULL);
            ASSERT(node->data == data);
            ASSERT(node->next == NULL);
        } else {
            append(node, data);
        }
    }

    ASSERT(vec.length == NODES);

    Linked_List *linked_List = traverse(node);
    ASSERT(linked_List != NULL);
    ASSERT(linked_List->length == NODES);

    for (int i = 0; i < linked_List->length; i++) {
        Data expected_data;
        memcpy(&expected_data, (char *)vec.data + i * sizeof(Data),
               sizeof(Data));
        ASSERT(linked_List->vec[i] == expected_data);
    }

    RELEASE(linked_List->vec);
    RELEASE(linked_List);
    RELEASE(node);
    RELEASE(vec.data);

    return 0;
}

static int test_remove_node(void) {
    Node *node = append(NULL, 2);
    append(node, 4);
    append(node, 6);

    ASSERT(removeNode(&node, 4) == 0); // remove middle
    ASSERT(removeNode(&node, 6) == 0); // remove last
    ASSERT(removeNode(&node, 6) == 1); // not found
    ASSERT(removeNode(&node, 2) == 0); // remove head

    RELEASE(node);

    return 0;
}

static test_case tests[] = {
    {"Append and Traverse", test_append_and_traverse},
    {"Remove Node", test_remove_node},
};

int main(void) { return RUN_TESTS(tests); }
