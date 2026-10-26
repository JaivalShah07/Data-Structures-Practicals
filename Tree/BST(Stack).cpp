//Traversal of Binary Search Tree using Stack

#include <iostream>
using namespace std;

struct node{
    int data;
    node *left, *right;
};

node *root = NULL;

struct stk {
    node *arr[100];
    int tos = -1;
};

bool isEmpty(stk *s){
    return s->tos == -1;
}

void push(stk *s, node *n){
    if(s->tos == 99){
        cout << "Stack Overflow!";
        return;
    }

    s->arr[++s->tos] = n;
}

node *pop(stk *s){
    if(isEmpty(s)){
        cout << "Stack Underflow!";
        return NULL;
    }

    return s->arr[s->tos--];
}

void setLeft(node *parent, node *child) {
    parent->left = child;
}

void setRight(node *parent, node *child) {
    parent->right = child;
}

node* insert(node *root, int val) {
    node *newNode = new node;
    newNode->data = val;
    newNode->left = newNode->right = NULL;

    if (root == NULL) {
        return newNode;
    }

    node *current = root;

    while (true) {
        if (val < current->data) {
            if (current->left == NULL) {
                setLeft(current, newNode);
                break;
            }
            current = current->left;
        }
        else if (val > current->data) {
            if (current->right == NULL) {
                setRight(current, newNode);
                break;
            }
            current = current->right;
        }
        else {
            delete newNode;
            break;
        }
    }

    return root;
}

void inorder(node *root) {
    stk s;
    s.tos = -1;
    node *current = root;

    while (current != NULL || !isEmpty(&s)) {
        while (current != NULL) {
            push(&s, current);
            current = current->left;
        }

        current = pop(&s);
        cout << current->data << " ";
        current = current->right;
    }
}

void preorder(node *root) {
    if (root == NULL) return;

    stk s;
    s.tos = -1;
    push(&s, root);

    while (!isEmpty(&s)) {
        node *current = pop(&s);
        cout << current->data << " ";

        if (current->right != NULL)
            push(&s, current->right);

        if (current->left != NULL)
            push(&s, current->left);
    }
}

void postorder(node *root) {
    if (root == NULL) return;

    stk s1, s2;
    s1.tos = s2.tos = -1;
    push(&s1, root);

    while (!isEmpty(&s1)) {
        node *current = pop(&s1);
        push(&s2, current);

        if (current->left != NULL)
            push(&s1, current->left);

        if (current->right != NULL)
            push(&s1, current->right);
    }

    while (!isEmpty(&s2))
        cout << pop(&s2)->data << " ";
}

int main() {
    int n, val;

    cout << "Enter number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> val;
        root = insert(root, val);
    }

    cout << "Inorder: ";
    inorder(root);

    cout << "\nPreorder: ";
    preorder(root);

    cout << "\nPostorder: ";
    postorder(root);

    return 0;
}