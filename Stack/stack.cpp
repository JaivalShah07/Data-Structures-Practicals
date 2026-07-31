#include <iostream>
#define s 20

using namespace std;
int tos = -1;
int stk[s];

int empty(){
    if(tos == -1){
        return 1;
    }else {
        return 0;
    }
}

int full(){
    if(tos == (s-1)){
        return 1;
    }else {
        return 0;
    }
}

void push(int x){
    if(!full()){
        tos++;
        stk[tos] = x;
    }else {

        cout << "The stack is full.";
        return;
    }
}

int pop(void){
    int x;

    if(!empty()){
        x = stk[tos];
        tos--;
        return x;
    }else {
        cout << "Cannot pop while stack is empty.";
        return 0;
    }
}

int peep(void){
    if(!empty()){
        return stk[tos];
    } else {
        cout << "Cannot peep while stack is empty.";
        return 0;
    }
}

void display(void){
    cout << "Stack = \n";
    for(int i=tos;i>=0;i--){
        cout << stk[i] << "\n";
    }
}

int main() {
    int n, num, x;

    while (1){
        cout << "\n==Stack Operations==\n1. Push\n2. Pop\n3. Peep\n4. Display\n5. Exit\n" << endl;
        cin >> n;

        switch (n){
            case 1:
            cout << "\nEnter number to push: ";
            cin >> num;
            push(num);
            break;

            case 2:
            x = pop();
            cout << "popped: " << x;
            break;

            case 3:
            x = peep();
            cout << "\n" << x;
            break;

            case 4:
            display();
            break;

            case 5:
            return 0;
            break;

            default:
            cout << "Invalid Choice!";
            return 0;
            break;
        }
    }
    return 0;
}