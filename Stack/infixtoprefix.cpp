#include <iostream>
#include "../stack/stack.h"
using namespace std;

int priority(char op){
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0;
}

int isOperator(char ch){
    if(ch == '+' || ch == '-' || ch == '/' || ch == '*' || ch == '^'){
        return 1;
    }else {
        return 0;
    }
}

int main(){
    char infix[100];
    char prefix[100];
    char stk[100];
    int tos = -1;

    cout << "Enter the infix expression: ";
    cin >> infix;

    cout << infix;
    sizeof(infix);

    //reverse infix expression:
    char temp;
    int size = sizeof(infix) / sizeof(infix[0]);
    int st = 0, end = size-1;

    while(st < end){
        temp = infix[st];
        infix[st] = infix[end];
        infix[end] = temp;

        st++;
        end--;
    }

    cout << infix;
}