#include <iostream>
using namespace std;

struct node {
    int data;
    node *left, *right;
};

node *root = NULL;

node* createnode(int value) {
    node *newnode = new node;
    newnode->data = value;
    newnode->left = newnode->right = NULL;
    return newnode;
}

void setLeft(node *parent, node *child) {
    parent->left = child;
}

void setRight(node *parent, node *child) {
    parent->right = child;
}

void insert(int value) {
    node *newnode = createnode(value);

    if (root == NULL) {
        root = newnode;
        return;
    }

    node *current = root;

    while (true) {
        if (value < current->data) {
            if (current->left == NULL) {
                setLeft(current, newnode);
                break;
            }
            current = current->left;
        }
        else {
            if (current->right == NULL) {
                setRight(current, newnode);
                break;
            }
            current = current->right;
        }
    }
}

void inorder(node *ptr) {
    if (ptr != NULL) {
        inorder(ptr->left);
        cout << ptr->data << " ";
        inorder(ptr->right);
    }
}

void preorder(node *ptr) {
    if (ptr != NULL) {
        cout << ptr->data << " ";
        preorder(ptr->left);
        preorder(ptr->right);
    }
}

void postorder(node *ptr) {
    if (ptr != NULL) {
        postorder(ptr->left);
        postorder(ptr->right);
        cout << ptr->data << " ";
    }
}

int main() {
    int choice, value;

    do {
        cout << "\n\n--- Binary Search Tree ---";
        cout << "\n1. Insert";
        cout << "\n2. Inorder";
        cout << "\n3. Preorder";
        cout << "\n4. Postorder";
        cout << "\n5. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                insert(value);
                break;

            case 2:
                cout << "Inorder: ";
                inorder(root);
                break;

            case 3:
                cout << "Preorder: ";
                preorder(root);
                break;

            case 4:
                cout << "Postorder: ";
                postorder(root);
                break;

            case 5:
                cout << "Exiting...";
                break;

            default:
                cout << "Invalid choice!";
        }

    } while (choice != 5);

    return 0;
}