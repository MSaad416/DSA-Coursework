// q1.c - Assignment 02 - Muhammad Saad Iqbal
#include <stdio.h>
#include <stdlib.h>


typedef struct BinaryTreeNode { // basic node structure
    char data;
    struct BinaryTreeNode *left;
    struct BinaryTreeNode *right;
} BinaryTreeNode;


// constructor-like function to create new nodes
BinaryTreeNode *newNode(char data){
    BinaryTreeNode *node = (struct BinaryTreeNode *) malloc(sizeof (BinaryTreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// function to print out tree through post order traversal
int *postOrder(BinaryTreeNode *head, int list[]) {
    if(head == NULL) return NULL;
    static int index = 0;
    postOrder(head->left, list);
    postOrder(head->right, list);
    // add traversal element to list
    list[index++] = head->data;
    // returning list containing postorder traversal of tree
    return list;
}

// function to build manually defined tree example
BinaryTreeNode *buildTree() {
    BinaryTreeNode *a,*b,*c,*d,*e,*f,
                   *g,*h,*i,*j,*k;
    a = newNode('A');
    b = newNode('B');
    c = newNode('C');
    d = newNode('D');
    e = newNode('E');
    f = newNode('F');
    g = newNode('G');
    h = newNode('H');
    i = newNode('I');
    j = newNode('J');
    k = newNode('K');
    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    d->left = h;
    d->right = i;
    a->left = b;
    a->right = c;
    e->left = j;
    c->left = f;
    c->right = g;
    g->left = k;
    return a; // returning root node
}

int main() {
    // build example tree
    BinaryTreeNode *root = buildTree();
    int size = 11;
    int list[size];

    postOrder(root, list);
    printf("Post-order Traversal: ");
    // outputting traversal list
    for (int i=0;i<size;i++) {
        printf("%c ",list[i]);
    }

}
