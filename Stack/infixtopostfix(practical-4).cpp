// Conversion of Infix expression to Postfix expression using the stack.

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

int main() {
    char infix[100];
    char postfix[100];
    char stk[100];
    int tos = -1;
    int j=0;

    cout << "Enter the infix expression: ";
    cin >> infix;

    for(int i=0;infix[i] != '\0'; i++){
        
        char ch = infix[i];

        //if ch is operator..

        if(isOperator(ch)){

            if(empty(tos) || peep(stk, tos) == '(' || priority(ch) > priority(peep(stk, tos))){
                push(stk, tos, ch);
            } else {
                while(!empty(tos) && peep(stk, tos) != '(' && priority(peep(stk, tos)) >= priority(ch)){
                    postfix[j++] = pop(stk , tos);
                }
                push(stk, tos, ch); //pushes the currentlyy scanned operator...
            }
        } else if(ch == '('){
            push(stk, tos, ch);
        } else if(ch == ')'){
            while(peep(stk, tos) != '('){
                postfix[j++] = pop(stk, tos);
            }
            pop(stk, tos); //pops the final '(' after the loop reaches there
        } else {
            postfix[j++] = ch;
        }
    }

    while(!empty(tos)){
        postfix[j++] = pop(stk, tos); //Adds the remaining operators fromm stack to postfix expression..
    }

    postfix[j++] = '\0';

    cout << "\nPostfix: " << postfix;
    return 0;
}