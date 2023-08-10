#include <stdio.h>

// Size can be changed to suit particular problem
#define	STACK_SIZE	100

// These defines are meant to be constant - do not change
#define	EMPTY_INDEX	-1
#define	MAX_INDEX	(STACK_SIZE - 1)

// These defines are meant to assist a reader in understanding behavior.
// You will note use of these manifests in the push(), pop() and tos()
// functions.
#define	RTN_ERROR	0
#define	RTN_OK		1


int  top = EMPTY_INDEX;
int  stack [STACK_SIZE];

int push (int n)
{
    if (top == MAX_INDEX)  return RTN_ERROR;
    stack[++top] = n;
    return  RTN_OK;
}//push()


int  pop (int *value)
{
    if (top == EMPTY_INDEX)  return RTN_ERROR;
    *value = stack[top--];
    return  RTN_OK;
}// pop()


int  tos (int **ptop)
{
    if (top == EMPTY_INDEX) return RTN_ERROR;
    *ptop = &stack[top];
    return  RTN_OK;
} // tos()


int main (void)
{
    int		i;
    int		rslt;
    char		value;
    int		*pi;
    char inArray[100];  // input string buffer set at 100 characters
    int x = 0, set;
    printf("Enter String: ");
    fgets(inArray, 99, stdin);
    do {
        if (inArray[x] == '(' || inArray[x] == '{' || inArray[x] == '[') {
            // if the input element is a parenthesis, push element onto stock
            push(inArray[x]);
        }
        if (inArray[x] == ')' || inArray[x] == '}' || inArray[x] == ']' ) {
            // pop an element and store it for further checks
            char pu = pop(&value);

        }
        x++;
    } while (x < strlen(inArray));

    if (top==EMPTY_INDEX && set) {
        printf("1");    // output 1 for balanced equations
    } else {
        printf("0");
    }('\n');

    return 0;
}//main()

/*
////////////////////////
#include <stdio.h>
#include <string.h>


#define	STACK_SIZE	100


#define	EMPTY_INDEX	-1
#define	MAX_INDEX (STACK_SIZE - 1)

int  top = EMPTY_INDEX;
char  stack [STACK_SIZE];

int push (char n) {                   // function pushes char onto stack
    if (top == MAX_INDEX)  return 0;  // returns 0 if stack is full
    stack[++top] = n;
    return  1;
}


char pop (char *value) {        // function pops last inserted element
    char popped;
    if (top == EMPTY_INDEX)  return 0;
    popped = stack[top];
    *value = stack[top--];
    return  popped;            // if stack is not empty, popped value is returned
}

int main (void) {
    char value, *pi;
    char inArray[100];  // input string buffer set at 100 characters
    int x = 0, set;
    printf("Enter String: ");
    fgets(inArray, 99, stdin);
    do {
        if (inArray[x] == '(' || inArray[x] == '{' || inArray[x] == '[') {
            // if the input element is a parenthesis, push element onto stock
            push(inArray[x]);
        }
        if (inArray[x] == ')' || inArray[x] == '}' || inArray[x] == ']' ) {
            // pop an element and store it for further checks
            char pu = pop(&value);
            // if the last closing brace matches to its corresponding opening brace,
            // then it is a balanced equation
            if (pu == '(' && inArray[x] == ')')         set=1;
            else if (pu == '{' && inArray[x] == '}')    set=1;
            else if (pu == '[' && inArray[x] == ']')    set=1;
            else                                        set = 0;
        }
        x++;
    } while (x < strlen(inArray));

    if (top==EMPTY_INDEX && set) {
        printf("1");    // output 1 for balanced equations
    } else {
        printf("0");
    }
}


*/


