#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *link;
};
struct Node *top = NULL;

void Push(int x)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node *));
    temp->data = x;
    temp->link = top;
    top = temp;
}
void Pop()
{

    if (top == NULL)
        return;
    struct Node *temp = top;
    top = temp->link;
    free(temp);
}
int Top()
{
    return top->data;
}
void Print()
{ //test the implementation
    int i;

    printf("Stack: ");
    struct Node *temp = top;
    while (temp != NULL)
    {
        printf(" %d", temp->data);
        temp = temp->link;
    }
    printf("\n");
}
int main()
{
    Push(1);
    Print();
    Push(3);
    Print();
    Push(9);
    Print();
    Pop();
    Print();
    Pop();
    Print();
    Pop();
    Print();
}
/* output:
Stack:  1
Stack:  3 1
Stack:  9 3 1
Stack:  3 1
Stack:  1
Stack:
 */