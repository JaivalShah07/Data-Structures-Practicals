#include <iostream>
using namespace std;

struct node{
    int data;
    struct node *next;
};

node *first = NULL; //Global pointer to point the first node of the list.. first is null then list is empty.

node *createNode(int x){
    struct node *temp = (struct node*) malloc(sizeof(struct node));

    temp -> data = x;
    temp -> next = NULL;

    return temp;
}

void insertFirst(int x){
    struct node* p;
    p = createNode(x);

    if(first == NULL){
        first = p;
    }else{
        p -> next = first; //p points to the current created node so p -> next = p.next means the next node pointer of current node is now pointed by first
        first = p;
    }
}

void insertLast(int x){
    struct node* p;

    if(first == NULL){
        first = createNode(x);
        return;
    }

    p = first;

    while(p->next != NULL){
        p = p -> next;
    }

    p -> next = createNode(x);
}

void insertAtPosition(int x, int pos){
    struct node *temp;
    struct node *newNode = createNode(x);
    if(first == NULL){
        first = newNode;
        return;
    }

    temp = first;

    int i=0;
    while(i<pos-1 && temp->next != NULL){
        temp = temp->next;
        i++;
    }

    newNode -> next = temp -> next;
    temp -> next = newNode;
}

void display(){
    struct node* p;
    p = first;
    while(p != NULL){
        cout << p->data << " -> ";
        p = p -> next;
    }
    cout << endl;
}

void deleteFirst(){
    struct node* temp;
    temp = first;
    first = first -> next;
    free(temp);
}

void deleteLast(){
    struct node* temp;
    struct node* x;
    temp = first;

    while(temp->next->next != NULL){
        temp = temp -> next;
    }

    x = temp -> next;
    temp -> next = NULL;
    free(x);
}

void deleteAtPosition(int pos){
    struct node* temp;
    struct node* x;
    temp = first;
    int i=0;
    while(i < pos-1 && temp -> next != NULL){
        temp = temp -> next;
        i++;
    }

    x = temp -> next;
    temp -> next = x -> next;
    free(x);
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