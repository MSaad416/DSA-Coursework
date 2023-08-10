//
// Created by Saad Iqbal on 2022-11-16.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct BinaryTreeNode{
    int data;
    struct BinaryTreeNode *left;
    struct BinaryTreeNode *right;
} BinaryTreeNode;



BinaryTreeNode * newNode(int data) {
    struct BinaryTreeNode *node = (BinaryTreeNode*) malloc(sizeof(BinaryTreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}




BinaryTreeNode *buildTree(int in[], int start, int end) {

    if (start > end) return NULL;
    BinaryTreeNode *root = newNode(in[start]);
    int x;
    for (x = start; x <= end; x++) {
        if (in[x] > root->data) {break;}
    }
    root->left = buildTree(in, start +1, x-1);
    root->right = buildTree(in, x, end);

    return root;
}

BinaryTreeNode * insert(BinaryTreeNode *node, int data) {
    if(node== NULL) {
        BinaryTreeNode *temp;
        temp = (BinaryTreeNode*) malloc(sizeof(BinaryTreeNode));
        temp->data = data;
        temp->left = temp->right = NULL;
        return temp;
    }
    if (data < node->data)          node->left = insert(node->left, data);
    else if (data > node->data)      node->right = insert(node->right, data);
//    else if (data == node->data) node->left = insert(node->left, data);
    return node;
}


BinaryTreeNode *Merge(BinaryTreeNode *Root1, BinaryTreeNode *Root2) {
    BinaryTreeNode *Root3; // merged tree
    if (Root1 == NULL) return Root2;
    if (Root2 == NULL ) return Root1;

    Root1->data += Root2->data;
    Root1->left = Merge(Root1->left, Root2->left);
    Root1->right = Merge(Root1->right, Root2->right);

    return Root1;
}

//void insertSort(int arr[], int n) {
//    int i, key, j;
//    for (i=1; i < n; i++) {
//        key = arr[i];
//        j = i -1;
//        while (j >= 0 && arr[j] > key) {
//            arr[j+1] = arr[j];
//            j = j - 1;
//        }
//        arr[j+1] = key;
//    }
//}

void printOrder(BinaryTreeNode *node) {
    if (node == NULL) return;
    printOrder(node->left);
    printf("%d ", node->data);
    printOrder(node->right);
}

void actualTree(BinaryTreeNode *t) {
    if (t != NULL) {
        //     PRE ORDER
        printf(":%d - ", t->data);
        actualTree(t->left);
        actualTree(t->right);
    }
}

int main() {
//    BinaryTreeNode *head = newNode(3);
    int in1[] = {3,2,5,1};
    BinaryTreeNode *head = buildTree(in1,0,4-1);
    //
////    BinaryTreeNode *head2 = newNode(4);
    int in2[] = {4,1,7,2,9};
////    int in2[] = {1,9,7,2,4};
    BinaryTreeNode *head2 = buildTree(in2,0,5-1);

    BinaryTreeNode *head3 = Merge(head, head2);

    printOrder(head3);

//
//    int size1 = 4;
//    int listy[size1];
//    //
////    printTree(head, listy, size1);
//    //
//    for (int i=0;i<size1;i++) {
//        printf("%d ", listy[i]);
//    }
//    printf("\n");
//    int size2 = 5;
//    int listy2[size2];
//    //
////    printTree(head2, listy2, size2);

//    for (int i=0;i<size2;i++) {
//        printf("%d ", listy2[i]);
//    }
//
//    //
//    int listy3[size2+size1];
//
//    for (int x=0; x< (size1+size2);x++) {
//        if (x < 0+size1) {
//            listy3[x] = listy[x];
//        } else if (x >= 0+size1) {
//            listy3[x] = listy2[x-size1];
//        }
//    }
//
//
//    printf("\n");
//
//    for (int x=0; x < (size1+size2);x++) {
//        printf(":%d. ", listy3[x]);
//    }
//
//
//    printf("\n");
//
//    insertSort(listy3, size1+size2);
//
//    for (int x=0; x< (size1+size2);x++) {
//        printf("..%d ", listy3[x]);
//    }
//
//
//    BinaryTreeNode *head3 = buildTree(listy3, 0, size1+size2-1);
////
//    printf("\n");
////    printf("%d", head3->data);
//
//    actualTree(head3);


}


/*
 1) Merge(): takes roots of 2 BST, returns the BST in sorted order
 *           that merges node values of both BST
 *
 2) Main(): creates 2 trees and output array of Breathd Traversal of merged BST

 can use : buildtree(), breadthtraverse()
 */



//int *printTree(BinaryTreeNode *t, int list[], int size) {
//    static int index = 0;
//    if (t != NULL) {
//        //     PRE ORDER
////        printf(":%d\n", index);
//        printTree(t->left, list, size);
//        list[index++] = t->data;
//        printTree(t->right, list, size);
//    }
//    if (index == size) index = 0;
//    return list;
//}

//BinaryTreeNode *buildTree(int in[], int size) {
//    BinaryTreeNode *root = newNode(in[0]);
//    for (int x = 1; x < size; x++) {
//        insert(root, in[x]);
//    }
//    return root;
//}





/* Might Need BELOW LATER
 *




 */
