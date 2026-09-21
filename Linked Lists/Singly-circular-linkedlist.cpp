#include <iostream>
using namespace std;

struct node{
    int data;
    struct node *next;
};

node *first = NULL;

node *createNode(int x){
    node *temp = new node;

    temp -> data = x;
    temp -> next = NULL;
    return temp;
}

void insertFirst(int val){
    node *temp; 
    node *x;
    temp = createNode(val);

    if(first == NULL){
        first = temp;
        first->next = first;
    }else{
        x = first;

        while(x->next != first){
            x = x->next;
        }
        temp->next = x->next;
        x->next = temp;
        first = temp;
    }
}

void insertLast(int val){
    node *temp = createNode(val), *x;

    if(first == NULL){
        first = temp;
        first->next = first;
    }else{
        x = first;
        while(x->next != first){
            x = x->next;
        }
        temp->next = x->next;
        x->next = temp;
    }
}

void insertAtPosition(int val, int pos){
    node *temp = createNode(val), *x;

    if(first == NULL){
        first = temp;
        temp->next = first;
        return;
    }

    x=first;
    int i=1;
    while(i < pos-1){
        x = x->next;
        i++;
    }
    temp->next = x->next;
    x->next = temp;
}

void display(){
    node *temp = first;

    if(first == NULL){
        cout << "list empty!";
        return;
    }

    do{
        cout << temp->data << " -> ";
        temp = temp->next;
    }while(temp !=first);
}

void deleteFirst(){
    if(first == NULL){
        cout << "List empty!";
        return;
    }

    node *temp, *x;
    temp = first;
    x = first;

    if(first->next == first){
        first = NULL;
        delete temp;
        return;
    }

    while(x->next != first){
        x = x->next;
    }

    x->next = first->next;
    first = first->next;
    delete temp;
}

void deleteLast(){
    if(first == NULL){
        cout << "List empty!";
        return;
    }

    node *temp, *x;
    x = first;
    
    while(x->next->next != first){
        x = x->next;
    }
    temp = x->next;
    x->next = first;
    delete temp;
}

void deleteAtPosition(int pos) {
    if (first == NULL) {
        cout << "List empty!";
        return;
    }

    if (pos < 1) {
        cout << "Invalid position!";
        return;
    }

    if (pos == 1) {
        deleteFirst();
        return;
    }

    node *x = first;
    int i = 1;

    while (i < pos - 1 && x->next != first) {
        x = x->next;
        i++;
    }

    if (i != pos - 1 || x->next == first) {
        cout << "Invalid position!";
        return;
    }

    node *temp = x->next;

    x->next = temp->next;
    delete temp;

    cout << "Deleted node at position " << pos << "!";
}

int main() {

    while(1){
        int choice;

        cout << "\n\n1. Insert First\n2. Insert Last\n3. Insert at Position\n4. Display\n5. Delete First\n6. Delete Last\n7. Delete At Position\n8. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice){
            case 1: {
                int x;
                cout << "Enter val: ";  
                cin >> x;
                insertFirst(x);
                break;
            }

            case 2: {
                int x;
                cout << "Enter val: ";
                cin >> x;
                insertLast(x);
                break;
            }

             case 3:{
                int x, pos;
                cout << "Enter value: ";
                cin >> x;
                cout << "\nEnter position: ";
                cin >> pos;
                insertAtPosition(x, pos);
                break;
             }
            
            case 4:
                display();
                break;

            case 5:
                deleteFirst();
                cout << "Deleted First!";
                break;

            case 6:
                deleteLast();
                cout << "Deleted last!";
                break;
            
            case 7:{
                int x;
                cout << "Enter pos: ";
                cin >> x;
                deleteAtPosition(x);
                break;
            }
            
            case 8:
                exit(0);
                break;
            
            default:
                exit(0);
                break;
        }
    }
    
    return 0;
}