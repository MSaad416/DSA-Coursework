// q3.c - Assignment 02 - Muhammad Saad Iqbal
#include <stdio.h>
#include <stdlib.h>

typedef struct Node { // basic node structure
    int data;
    int height;
    struct Node *left;
    struct Node *right;
} Node;

int max (int a, int b) {    // returns bigger integer
    return (a>b)? a:b;
}

int height(Node *n) {   // returns height of given node
    if(n == NULL) return 0;
    return 1+max(height(n->left), height(n->right));
}

// function to create a new node
Node *newNode(int data) {
    struct Node *node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->height = 0;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// function to build specific tree in example
Node *buildTree() {
    Node *head = newNode(12);
    head->left = newNode(8);
    head->right = newNode(18);
    head->left->left = newNode(5);
    head->left->right = newNode(9);
    head->right->left = newNode(17);
    head->left->left->left = newNode(4);
    head->left->left->left->left = newNode(2);
    return head;
}


// right rotate subtree with y
Node *rightRotate(Node *y) {
    Node *x = y->left;
    Node *T2 = x->right;

    // perform rotations
    x->right=y;
    y->left = T2;

    // update heights
    y->height = height(y);
    x->height = height(x);

    return x;
}

// left rotate subtree with x
Node *leftRotate(Node *x) {
    Node *y = x->right;
    Node *T2 = y->left;

    // perform rotations
    y->left = x;
    x->right=T2;

    // update heights
    x->height = height(x);
    y->height = height(y);

    return y;
}

int getBalance(Node *n) {   // determining balance
    if(n==NULL) return 0;
    return height(n->left) - height(n->right);
}

// inserting nodes in order to achieve an AVL tree
Node *insert(Node *node, int data) {
    if (node == NULL) return newNode(data);

    if (data < node->data)          node->left = insert(node->left, data);
    else if (data > node->data)     node->right = insert(node->right, data);
    else                            return node;

    node->height = height(node);

    int balance = getBalance(node);

    if (balance > 1 && data < node->left->data)
        return rightRotate(node);

    if (balance < -1 && data > node->right->data)
        return leftRotate(node);

    if (balance > 1 && data > node->left->data)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && data < node->right->data)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

int isBalanced(Node *root) {
    if (root == NULL) return 1; // balanced
    int lefth, righth;
    // generate heights for left and right subtrees
    lefth = height(root->left);
    righth = height(root->right);
    // ensure height difference is not bigger than 1
    if (abs(lefth-righth) <= 1 && isBalanced(root->left) && isBalanced(root->right)){
        return 1;
    }
    return 0; // if balance conditions not satisfied
}

// function to convert a tree into a list through preorder traversal
int *treeToArray(Node *t, int list[], int size) {
    static int index = 0;
    if (t != NULL) {
        treeToArray(t->left, list, size);
        list[index++] = t->data;
        treeToArray(t->right, list, size);
    }
    if (index == size) index = 0;
    return list;
}

// function to print tree through preorder traversal
void preorderTraversal(Node *head) {
    if(head == NULL) return;
    printf("%d ", head->data);
    preorderTraversal(head->left);
    preorderTraversal(head->right);

}

// function to convert a binary tree to an AVL tree
Node *Rotation(Node *head) {
    int size = 8;
    int list[size];
    treeToArray(head, list, size);
    Node *newHead = NULL;
    for (int i=0;i<size;i++) {
        newHead = insert(newHead, list[i]);
    }
    return newHead;
}

int main() {
    // initialize a tree root
    Node *head = buildTree();
    // traverses in preorder over unbalanced binary tree
    printf("Unmodified Tree: ");
    preorderTraversal(head);
    // 0 represents the tree is not balanced :
    printf("\nTree Balance: %d",isBalanced(head));
    // initialize a new tree that is converted to AVL tree
    Node *newHead = Rotation(head);
    printf("\n");
    // traverses in preorder over AVL tree
    printf("Balanced AVL Tree: ");
    preorderTraversal(newHead);
    // 1 represents the tree is not balanced :
    printf("\nTree Balance: %d",isBalanced(newHead));
}
