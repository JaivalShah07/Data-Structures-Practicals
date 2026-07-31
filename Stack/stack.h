#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

#define s 100

int empty(int tos)
{
    return (tos == -1);
}

int full(int tos)
{
    return (tos == s - 1);
}

template <typename T>
void push(T stk[], int &tos, T x)
{
    if (!full(tos))
    {
        stk[++tos] = x;
    }
    else
    {
        cout << "The stack is full.\n";
    }
}

template <typename T>
T pop(T stk[], int &tos)
{
    if (!empty(tos))
    {
        return stk[tos--];
    }

    cout << "Cannot pop while stack is empty.\n";
    return T();
}

template <typename T>
T peep(T stk[], int tos)
{
    if (!empty(tos))
    {
        return stk[tos];
    }

    cout << "Cannot peep while stack is empty.\n";
    return T();
}

template <typename T>
void display(T stk[], int tos)
{
    cout << "Stack =\n";

    for (int i = tos; i >= 0; i--)
        cout << stk[i] << endl;
}

#endif