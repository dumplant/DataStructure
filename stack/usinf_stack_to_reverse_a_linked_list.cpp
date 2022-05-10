#include <iostream>
#include <stack>
#include <string.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};
Node *head = NULL;

void Reverse()
{
    if (head == NULL)
        return;
    stack<struct Node *> S;
    Node *temp = head;

    while (temp != NULL)
    {
        S.push(temp);
        temp = temp->next;
    }

    temp = S.top();
    head = temp;
    S.pop();
    while (!S.empty())
    {
        temp->next = S.top();
        S.pop();
        temp = temp->next;
    }
    temp->next = NULL;
}

void Insert(int data)
{
    Node *temp = new Node();
    temp->data = data;
    temp->next = NULL;
    if (head == NULL)
        head = temp;
    else
    {
        Node *temp1 = head;
        while (temp1->next != NULL)
            temp1 = temp1->next;
        temp1->next = temp;
    }
}
void Print(struct Node *p)
{
    if (p == NULL)
        return; 
    printf("%d ", p->data);
    Print(p->next); 
}
int main()
{
    head = NULL; 
    Insert(2);   
    Insert(4);
    Insert(6);
    Insert(5);
    Print(head);
    Reverse();
    printf("\nAfter reverse:");
    Print(head);

    return 0;
}

/* output:
2 4 6 5 
After reverse:5 6 4 2  
*/