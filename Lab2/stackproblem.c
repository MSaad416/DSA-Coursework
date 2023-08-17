// stackproblem.c - Lab02 - Muhammad Saad, Iqbal

#include <stdio.h>
#include <stdlib.h>

// Definition of stack node
typedef struct _sn {
    struct _sn	*next;
    char nodval;
} StkNode;

#define	SZSTKNODE	(sizeof(struct _sn))
#define SZSTACK 80
int count;

StkNode		*head = NULL;


int push (char n) {
    count++;
    StkNode *p = (StkNode *)malloc(SZSTKNODE);
    if (p == NULL || count > SZSTACK) return 0;
    p->nodval = n;
    p->next = head;
    head = p;
    return  1;
}


void revPrint (StkNode *p) {
    if (p == NULL) {
        return;
    }
    if (p != NULL) putchar(p->nodval);
    revPrint(p->next);
}


int main (void)
{
    char x;
    while (1) {
        x = getchar();
        if (x == '\n') break;
        push(x);
    }
    revPrint(head);
    return 0;
}
