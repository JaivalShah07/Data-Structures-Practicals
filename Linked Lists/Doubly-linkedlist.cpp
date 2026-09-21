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
    struct node *temp = (struct node*) malloc(sizeof(struct node));

    temp -> data = x;
    temp -> next = NULL;
    temp -> prev = NULL;
    return temp;
}

void insertFirst(int x){
    struct node *temp;
    temp = createNode(x);
}

int main() {
    
    return 0;
}