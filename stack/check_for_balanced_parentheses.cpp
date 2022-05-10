#include <iostream>
#include <stack>
#include <string.h>
using namespace std;

bool CheckBalance(char exp[])
{
    stack<char> S;
    // Note: last opened should be first closed {[()]}
    for (int i = 0; i < strlen(exp); i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            S.push(exp[i]);
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (S.empty())
                return false;
            else if ( (exp[i] == ')' && S.top() != '(')|| (exp[i] == '}' && S.top() != '{') || (exp[i] == ']' && S.top() != '['))
                return false;
            else
                S.pop();
        }
    }
    return S.empty() ? true : false;
}

int main()
{
    char exp[101];
    printf("enter the expression:");
    gets(exp);

    if (CheckBalance(exp))
        printf("yes");
    else
        printf("no");
    return 0;
}

/* 
enter the expression:[(){}] 
yes
enter the expression:[(])
no
*/
