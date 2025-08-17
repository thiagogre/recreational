#include "test_runner.h"
#include <stdio.h>
#define BST_IMPLEMENTATION
#include "bst.h"

static int test_insert_traverse_clear_node(void) {
    TreeNode *root = NULL;
    insertNode(&root, 10);
    insertNode(&root, 5);
    insertNode(&root, 15);
    insertNode(&root, 2);
    insertNode(&root, 7);
    insertNode(&root, 20);
    ASSERT(root->data == 10);
    ASSERT(root->r->data == 15);
    ASSERT(root->l->data == 5);
    ASSERT(root->l->l->data == 2);
    ASSERT(root->l->r->data == 7);
    ASSERT(root->r->r->data == 20);

    traverseTree(root, PREORDER);
    printf("\n");

    traverseTree(root, INORDER);
    printf("\n");

    traverseTree(root, POSTORDER);
    printf("\n");

    clearTree(&root->l);
    ASSERT(root->data == 10);
    ASSERT(root->l == NULL);
    ASSERT(root->r->data == 15);

    clearTree(&root);
    ASSERT(root == NULL);

    return 0;
}

static test_case tests[] = {
    {.name = "Insert, Traverse and Clear Tree",
     .func = test_insert_traverse_clear_node},
};

int main(void) { return RUN_TESTS(tests); }