#ifndef LINKED_LIST
#define LINKED_LIST

typedef int Data;
typedef struct Node {
    Data data;
    struct Node *next;
} Node;
typedef struct Linked_List {
    Data *vec;
    int length;
} Linked_List;

Node *init(Data data);
Node *append(Node *node, Data data);
int removeNode(Node **node, Data target);
Linked_List *traverse(Node *node);

#ifdef LINKED_LIST_IMPLEMENTATION
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

inline Node *init(Data data) {
    Node *node = (Node *)malloc(sizeof(struct Node));
    if (node == NULL) {
        exit(1);
    }

    node->data = data;
    node->next = NULL;

    return node;
}

#define RELEASE(ptr)                                                           \
    do {                                                                       \
        if ((ptr) != NULL) {                                                   \
            free(ptr);                                                         \
            (ptr) = NULL;                                                      \
        }                                                                      \
    } while (0)

inline Node *append(Node *node, Data data) {
    if (node == NULL) {
        node = init(data);
        return node;
    }

    Node *currentNode = node;
    if (currentNode->next != NULL) {
        return append(currentNode->next, data);
    }

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->next = NULL;
    newNode->data = data;
    currentNode->next = newNode;
    return currentNode;
}

inline int removeNode(Node **head, Data target) {
    if (head == NULL || *head == NULL) {
        return 1;
    }

    Node *current = *head;

    if (current->data == target) {
        *head = current->next;
        RELEASE(current);
        return 0;
    }

    while (current->next != NULL) {
        if (current->next->data == target) {
            Node *node_to_remove = current->next;
            current->next = node_to_remove->next;
            RELEASE(node_to_remove);
            return 0;
        }
        current = current->next;
    }

    return 1;
}

inline Linked_List *traverse(Node *node) {
    Linked_List *linked_list = (Linked_List *)malloc(sizeof(Linked_List));
    Data *vec = (Data *)malloc(sizeof(Data));

    linked_list->vec = vec;
    linked_list->length = 0;
    if (node == NULL) {
        return linked_list;
    }

    int length = 1;
    Node *currentNode = node;
    while (currentNode != NULL) {
        vec = (Data *)realloc(vec, length * sizeof(Data));
        vec[length - 1] = currentNode->data;
        currentNode = currentNode->next;
        linked_list->vec = vec;
        linked_list->length = length;
        length++;
    }

    return linked_list;
}

#endif // LINKED_LIST_IMPLEMENTATION
#endif // LINKED_LIST