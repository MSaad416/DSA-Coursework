#include <stdio.h>
#include <stdlib.h>

// struct for nodes
typedef struct node	{
    struct node *next;
    int data;
} node;

// global pointers & counter
node *head = NULL;
node *tail = NULL;
int count = 0;

// function to insert element to queue
int qinsert (int in) {
    node *pn = (node*) malloc(sizeof(struct node));
    if (pn == NULL) return 0;   // only proceeds if pointer is created
    pn->data = in;
    pn->next = NULL;
    // connect last node to current node
    if (tail != NULL)	{
        tail->next = pn;
    }
    tail = pn;
    if (head == NULL) head = pn;
    count++;    // for each queue insertion increment element counter
    return 1;
}

// function to print out queue
void qprint () {
    node *pv;
    pv = head;
    printf("Q = [");
    // iterate until last element of queue and print
    while (pv != NULL)	{
        printf ("%d", pv->data);
        if (pv->next!=NULL) {printf (",");}
        pv = pv->next;
    }
    printf("]");
}

// function to reverse order of the first k elements of the queue
void revTillK(int k) {
    node *temp = head;  // temporary head node
    int dataVal;
    for (int j=0; j<k; j++) {   // iterating over k
        temp = head;
        for (int i =0 ; i < (k-j) ; i++) {
            // implementation
            dataVal = temp->data;
            temp->data = temp->next->data;
            temp->next->data = dataVal;
            temp = temp->next;
        }
    }
}

int main() {
    int in = 0, x = 0, k;
    // Taking manual input
    printf("How many integers to be queued: ");
    scanf("%d", &in);
    printf("Enter numbers seperated with a space. Press Enter when done: ");
    for (int a=0; a<in; a++) {
        scanf("%d", &x);
        qinsert(x);
    }
    printf("Enter the k value: ");
    scanf("%d", &k);
    // Reverse elements function called
    revTillK(k-1);
    // Re-ordered queue printed
    qprint();
    return 0;
}
