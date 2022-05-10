#include<stdio.h>
#define MAX_SIZE 101
int A[MAX_SIZE];
int top = -1;

void Push(int x){
    if(top == MAX_SIZE - 1){
        printf("Error: stack overflow\n");
        return;
    }
    A[++top] = x;
}
void Pop(){
    if(top == -1){
        printf("Error: stack is empty\n");
        return;
    }
    top--;
}
int Top(){
    return A[top];
}
void Print(){//test the implementation
    int i;
    printf("Stack: ");
    for(i = 0; i<=top;i++){
        printf(" %d",A[i]);
    }
    printf("\n");
}
int main(){
    Push(1);Print();
    Push(3);Print();
    Push(9);Print();
    Pop();Print();
    Pop();Print();
    Pop();Print();
}

/* output:
Stack:  1    
Stack:  1 3  
Stack:  1 3 9
Stack:  1 3
Stack:  1
Stack: 
*/