
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;
struct node *head1 = NULL;

void insertfirst(int i) {
    struct node *pn = (struct node*) malloc(sizeof (struct node));
    pn->data = i;
    pn->next = head;
    pn->prev = NULL;
    if (head != NULL) head->prev =pn;
    head = pn;
}


void create() {
    insertfirst(50);
    insertfirst(20);
    insertfirst(10);
}

void createLLE() {
    for (int i=0; i<3; i++) {
        struct node *pn = (struct node*) malloc(sizeof (struct node));
        if (i == 0) {
            pn->data = 36;
        } else if (i == 1) {
           pn->data = 25;
        } else if (i == 2) {
            pn->data = 24;
        }
        pn->next = head1;
        pn->prev = NULL;
        if (head1 != NULL) head1->prev =pn;
        head1 = pn;
    }
}

void display() {
    struct node *front = head;
    struct node *end;

    printf("\nList in forward direction: ");
    while (front != NULL) {
        printf(" %d ", front->data);
        if (front->next != NULL) printf("->");
        end = front;
        front = front->next;
    }
}


void deletefirst() {
    struct node *pn;
    if ( head == NULL) return;
    if (head->next == NULL) {
        head = NULL;
        free(head);
    }
    pn = head;
    head = head->next;
    head->prev = NULL;
    free(pn);
}


void insertpos(int dataValue) {
    struct node *pn = (struct node*) malloc(sizeof (struct node));
    struct node *header = head;
    struct node *temp = header;
    struct node *tail = header;

    pn->data = dataValue;
    pn->next = header;
    pn->prev = NULL;


    if (header== NULL || header->data >= pn->data)
    {
        pn->next = header;
        pn->prev = NULL;
        if (header != NULL) header->prev = pn;
        header = pn;
        tail = pn;
        return;
    }

    while (temp->next != NULL && temp->next->data < pn->data){
        temp = temp->next;
    }

    pn->next = temp->next;
    temp->next->prev = pn;
    temp->next = pn;
    pn->prev = temp;
}


void merge() {
    struct node *hN = head;
    struct node *h1N = head1;
    if (h1N == NULL || hN == NULL) return;
    while (h1N != NULL) {
        insertpos(h1N->data);
        h1N = h1N->next;
    }
}

int main() {
    create();
    display();
    insertfirst(5);
    display();
    deletefirst();
    display();
    insertpos(30);
    display();
    createLLE();
    merge();
    display();
}

