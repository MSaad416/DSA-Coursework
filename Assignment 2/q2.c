// q2.c - Assignment 02 - Muhammad Saad Iqbal
#include <stdio.h>
#include <stdlib.h>

typedef struct BinaryTreeNode { // basic node structure
    int data;
    struct BinaryTreeNode *left;
    struct BinaryTreeNode *right;
} BinaryTreeNode;

// function to create a new node
BinaryTreeNode *newNode(int data) {
    struct BinaryTreeNode *node = (BinaryTreeNode*) malloc(sizeof(BinaryTreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// function to convert a tree into a list through preorder traversal
int *treeToArray(BinaryTreeNode *t, int list[], int size) {
    static int index = 0;
    if (t != NULL) {
        list[index++] = t->data;
        treeToArray(t->left, list, size);
        treeToArray(t->right, list, size);
    }
    if (index == size) index = 0;
    return list;
}

// function to build a tree from an array through preorder traversal
BinaryTreeNode *buildTree(int in[], int start, int end) {
    if (start > end) return NULL;
    int x = (start+end)/2;
    BinaryTreeNode *root = newNode(in[x]);
    if (start == end) return root;
    root->left = buildTree(in, start, x-1);
    root->right = buildTree(in, x+1, end);
    return root;
}

// sorting an array using Insert Sort Algorithm
void insertSort(int arr[], int in) {
    int i, j, input;
    for (i=1; i < in; i++) {
        input = arr[i];
        j = i -1;
        while (j >= 0 && arr[j] > input) {
            arr[j+1] = arr[j];
            j = j - 1;
        }
        arr[j+1] = input;
    }
}

// helper function for BFT
void bTraversalHelper(BinaryTreeNode *head, int level) {
    if (head == NULL) return;
    if (level == 1) printf("%d ", head->data);
    else if (level > 1) {
        bTraversalHelper(head->left, level-1);
        bTraversalHelper(head->right,level-1);
    }
}

// function to print tree through Breadth First Traversal
void breadthTraversal(BinaryTreeNode *head) {
    int height = 4;
    for (int i=1; i<=height;i++) bTraversalHelper(head, i);
}


BinaryTreeNode *Merge(BinaryTreeNode *r1, BinaryTreeNode *r2) {
    // manual size descriptions
    int size1 = 4;
    int size2 = 5;
    // converting Binary trees to a list in a pre-order traversal
    int listy[size1];
    treeToArray(r1, listy, size1);
    int listy2[size2];
    treeToArray(r2, listy2, size2);

    // creating array for merged array
    int listy3[size1+size2];
    // merging two arrays for binary trees
    for (int x=0; x< (size1+size2);x++) {
        if (x < 0+size1) {
            listy3[x] = listy[x];
        } else if (x >= 0+size1) {
            listy3[x] = listy2[x-size1];
        }
    }
    // sorting the merged array
    insertSort(listy3, size1+size2);
    // building binary tree from merged array
    BinaryTreeNode *head3 = buildTree(listy3, 0, size1+size2-1);
    return head3;
}

int main() {
    // building first Binary tree
    int size1 = 4;
    int in1[] = {3,2,1,5};
    BinaryTreeNode *head = buildTree(in1,0,size1-1);
    // building secondary Binary tree
    int size2 = 5;
    int in2[] = {4,1,2,7,9};
    BinaryTreeNode *head2 = buildTree(in2,0,size2-1);

    // printing out the merged binary tree in breadth first traversal order
    BinaryTreeNode *head3 = Merge(head,head2);
    printf("Breadth-first Traversal: ");
    breadthTraversal(head3);

}
