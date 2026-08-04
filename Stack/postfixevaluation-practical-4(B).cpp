#include <iostream>
#include "../stack/stack.h"
#include <cmath>
#include <cctype>
#define size 50
char postfix[size];
int stack[size];
int tos = -1;

using namespace std;

int Cal(char op, int op1, int op2){ 
    int r;
    switch(op){
        case '+':
            r = op1 + op2;
            break;
        case '-':
            r = op1 - op2;
            break;
        case '*':
            r = op1 * op2;
            break;
        case '/':
            if(op2 == 0) {
                cout << "Divide by 0 not possible.";
                exit(1);
            }
            r = op1 / op2;
            break;
        case '^':
            r = pow(op1, op2);// using cmath
            break;
        default:
            cout << "Invalid operator!";
            break;
    }

    return r;
}

int main() {
    int i=0, res, op1, op2;

    cout << "Enter postfix expression: ";
    cin.getline(postfix, size);

    while(postfix[i] != '\0'){
        if(isdigit(postfix[i])){ //cctype library is imported to use this isdigit() function...
            push(stack, tos, postfix[i] - '0');
        } else {
            op2 = pop(stack, tos);
            op1 = pop(stack, tos);
            res = Cal(postfix[i], op1, op2);

            push(stack, tos, res);
        }
        i++;
    }

    cout << "Result: " << pop(stack, tos);
    return 0;
}