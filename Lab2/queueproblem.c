//queueproblem.c - Lab 02 - Muhammad Saad, Iqbal

#include <stdio.h>
#include <stdlib.h>

#define SZMAX 400

struct node{
    struct node *next;
    int value;
};

struct queue {
    struct node *front;
    struct node *end;
};

struct queue *queueInit(){                                                     //Initializes a given queue
    struct queue *temp = (struct queue*)malloc(sizeof(struct node));
    temp -> front = NULL;
    temp -> end = NULL;
    return temp;
};

void qinsert (struct queue *currQueue, int x)
// Add value n to queue end of queue
{
    // Create node to hold value being added to queue
    struct node	*pnew = (struct node*)malloc(sizeof (struct node));

    if (pnew != NULL)	{
        pnew->value = x;
        pnew->next = NULL;
        // Make current last node point to new node
        if (currQueue->end != NULL)	{
            currQueue->end->next = pnew;
        }
        // and update queue's end pointer
        currQueue->end = pnew;
        // If queue was empty, new node is also new front node
        if (currQueue->front == NULL)	currQueue->front = pnew;


    }
}

void qprint(struct queue *queue){
    struct node *pv = queue -> front;
    int count = 1;
    while(pv!=NULL){
        if(count == 12){
            printf("\n");
            count = 0;
        }
        if (pv->value != ' ') {
            printf("%5d", pv->value);
        }
        pv = pv -> next;
        count++;
    }
}

int main(){
    struct queue *Que1, *Que2, *Que3, *Que4;
    Que1 = queueInit();
    Que2 = queueInit();
    Que3 = queueInit();
    Que4 = queueInit();

    int in[SZMAX];
    int i = 0;
    int run = 1;

    do {
        scanf("%d", &in[i]);
        if (in[i] < 0) {
            run = 0;
        }
        i++;
    } while (run);


    for(int p = 0; p<i && in[i] >= 0; p++){
        int a = in[p] % 4;
        if(a == 0)
            qinsert(Que1, in[p]);
        else if(a == 1)
            qinsert(Que2, in[p]);
        else if(a == 2)
            qinsert(Que3, in[p]);
        else if(a == 3)
            qinsert(Que4, in[p]);
    }

    qprint(Que1);
    printf("\n");
    qprint(Que2);
    printf("\n");
    qprint(Que3);
    printf("\n");
    qprint(Que4);

}