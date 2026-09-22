#include <iostream>
using namespace std;

struct node{
    int data;
    struct node *next;
    struct node *prev;
};

node *first = NULL;
node *last = NULL;

struct node *createNode(int x){
    struct node *temp = new node;

    temp -> data = x;
    temp -> next = NULL;
    temp -> prev = NULL;
    return temp;
}

void insertFirst(int x){
    struct node *newNode;
    newNode = createNode(x);

    if(first == NULL){
        first = newNode;
        last = newNode; 
    }else{
        newNode -> next = first;
        first -> prev = newNode;
        first = newNode;
    }
}

void insertLast(int x){
    struct node *newNode;
    newNode = createNode(x);

    if(first == NULL){
        first = last = newNode;
    }else{
        last -> next = newNode;
        newNode -> prev = last;
        last = newNode;
    }
}

void insertAtPosition(int pos, int x){
    struct node *newNode = createNode(x), *temp;
    temp = first;

    if(pos == 0){
        insertFirst(x);
    }else{
        int i=0;
        while(i != pos-1){
            i++;
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next->prev = newNode;
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void display(char ch){
    struct node *temp;

    if(ch == 'L' || ch == 'l'){
        temp = first;
    }else{
        temp = last;
    }

    while(temp != NULL){
        cout << temp->data << " ";
        if(ch == 'l' || ch == 'L'){
            temp = temp->next;
        }else{
            temp = temp->prev;
        }
    }
}

void deleteFirst(){
    if(first == NULL){
        cout << "Cannot delete in empty LL.";
        return;
    }

    node *temp = first;
    first = first->next;

    if(first == NULL)
        last = NULL;
    else
        first->prev = NULL;

    delete temp;
}

void deleteLast(){
    if(last == NULL){
        cout << "Cannot delete in empty LL.";
        return;
    }

    node *temp = last;
    last = last->prev;

    if(last == NULL)
        first = NULL;
    else
        last->next = NULL;

    delete temp;
}

void deleteAtPosition(int pos){
    if(first == NULL || pos < 0){
        cout << "Invalid position.";
        return;
    }

    node *temp = first;

    for(int i = 0; i < pos && temp != NULL; i++)
        temp = temp->next;

    if(temp == NULL){
        cout << "Invalid position.";
        return;
    }

    if(temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        first = temp->next;

    if(temp->next != NULL)
        temp->next->prev = temp->prev;
    else
        last = temp->prev;

    delete temp;
}

int max(){
    int max = 0;

    node *temp = first;

    while(temp != NULL){
        if(temp->data > max){
            max = temp ->data;
        }
        temp = temp->next;
    }

    return max;
}

int min(){
    int min = max();

    node *temp = first;

    while(temp != NULL){
        if(temp->data < min){
            min = temp ->data;
        }
        temp = temp->next;
    }

    return min;
}

int main() {
    
    while(1){
        int choice;

        cout << "\n\n1. Insert First\n2. Insert Last\n3. Insert at Position\n4. Display\n5. Delete First\n6. Delete Last\n7. Delete At Position\n8. Maximum in LL\n9. Minimum in LL\n10. Exit\n";
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
                insertAtPosition(pos, x);
                break;
             }
            
            case 4:
                char ch;
                cout << "\nEnter direction left or right: ";
                cin >> ch;

                display(ch);
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
                cout << "Enter key: ";
                cin >> x;
                deleteAtPosition(x);
                break;
            }
            
            case 8:
                cout << "Maximum data in LL: " << max();
                break;

            case 9:
                cout << "Minimum data in LL: " << min();
                break;
            
            case 10:
                exit(0);
                break;

            default:
                exit(0);
                break;
        }
    }
    
    return 0;
}