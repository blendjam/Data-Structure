#include <iostream>
#include "LinkedList.h"
#include "Stack.h"
using namespace std;

char rev(char b)
{
    switch(b)
    {
        case '}':
            return '{';
        case ']':
            return '[';
        case ')':
            return '(';      
    }
}
int main()
{
    string str = "{[]}}{}";
    int len = str.length();
    Stack stack(len);
    int flag = 1;

    for(char c : str)
    {
        if(c == '[' || c == '{' || c == '(')
            stack.push(c);
        else
        {
            if(stack.isEmpty() || stack.pop() != rev(c))
                flag = 0;
        }
    }

    if(flag == 1 && stack.isEmpty())
        cout << "Balanced";
    else
        cout << "Not Balanced";
}
