
#ifndef BST_H
#define BST_H

#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * Binary Search Tree (BST) Implementation Requirements
 *
 * 1. Definition:
 *    - Each node has 'data', 'left', and 'right' pointers.
 *    - BST property: left child < parent < right child.
 *
 * 2. Core operations:
 *    - insert(Tree **root, Data value)
 *        Insert a new value while maintaining the BST property.
 *
 *    - search(Tree *root, Data value)
 *        Return a pointer to the node if found, otherwise NULL.
 *
 *    - delete(Tree **root, Data value)
 *        Remove a node from the BST. Handle all cases:
 *          (a) Leaf node
 *          (b) Node with one child
 *          (c) Node with two children (replace with inorder successor).
 *
 *    - traverse(Tree *root, Order order)
 *        Implement three traversals:
 *          - Inorder
 *          - Preorder
 *          - Postorder
 *
 * 3. Extra functions (stretch goals):
 *    - findMin(Tree *root): return the minimum value node.
 *    - findMax(Tree *root): return the maximum value node.
 *    - height(Tree *root): return the height of the tree.
 *    - countNodes(Tree *root): return the total number of nodes.
 *    - clear(Tree **root): free all nodes from memory.
 *
 * 4. Testing ideas:
 *    - Insert a sequence of numbers, then check traversals.
 *    - Search for elements that exist and elements that don’t.
 *    - Delete nodes in each category (leaf, one child, two children)
 *      and verify the tree structure.
 *    - Check height and node count after operations.
 */

typedef struct TreeNode {
    unsigned int data;
    struct TreeNode *l;
    struct TreeNode *r;
} TreeNode;

typedef enum { INORDER, PREORDER, POSTORDER } TraversalOrder;

void insertNode(TreeNode **root, unsigned int data);
TreeNode *searchNode(TreeNode *root, unsigned int data);
void deleteNode(TreeNode **root, unsigned int data);
void traverseTree(TreeNode *root, TraversalOrder order);
void clearTree(TreeNode **root);

#ifdef BST_IMPLEMENTATION

inline void insertNode(TreeNode **root, unsigned int data) {
    if (root == NULL)
        return;

    if (*root == NULL) {
        *root = (TreeNode *)malloc(sizeof(TreeNode));
        (*root)->data = data;
        (*root)->l = NULL;
        (*root)->r = NULL;
        return;
    }

    if (data < (*root)->data) {
        insertNode(&(*root)->l, data);
    } else if (data > (*root)->data) {
        insertNode(&(*root)->r, data);
    }
}

inline void traverseTree(TreeNode *root, TraversalOrder order) {
    switch (order) {
    case INORDER:
        if (root == NULL) {
            return;
        }

        traverseTree(root->l, order);
        printf("%d ", root->data);
        traverseTree(root->r, order);
        break;
    case PREORDER:
        if (root == NULL) {
            return;
        }

        printf("%d ", root->data);
        traverseTree(root->l, order);
        traverseTree(root->r, order);
        break;
    case POSTORDER:
        if (root == NULL) {
            return;
        }

        traverseTree(root->l, order);
        traverseTree(root->r, order);
        printf("%d ", root->data);
        break;
    default:
        exit(1);
    }
}

inline void clearTree(TreeNode **root) {
    if (*root == NULL) {
        return;
    }

    clearTree(&(*root)->l);
    clearTree(&(*root)->r);
    free(*root);
    *root = NULL;
}

#endif // BST_IMPLEMENTATION
#endif // BST_H