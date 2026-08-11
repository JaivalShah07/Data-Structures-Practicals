#include <iostream>
#include <cstdlib>
using namespace std;

#define s 20
int queue[s];
int front = -1, rear = -1;

int full() {
    return ((rear + 1) % s == front);
}

int empty() {
    return (front == -1);
}

void enqueue(int x) {
    if (full()) {
        cout << "Cannot add element.\n";
        return;
    }

    if (empty()) {
        front = 0;
        rear = 0;
    } else {
        rear = (rear + 1) % s;
    }

    queue[rear] = x;
    cout << "Successfully inserted " << x << endl;
}

int dequeue() {
    if (empty()) {
        cout << "Queue is empty.\n";
        return -1;
    }

    int x = queue[front];

    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % s;
    }

    return x;
}

void display() {
    if (empty()) {
        cout << "Queue is empty.\n";
        return;
    }

    cout << "Queue elements are:  ";
    int i = front;
    while (true) {
        cout << queue[i] << " ";
        if (i == rear) break;
        i = (i + 1) % s;
    }
    cout << endl;
}

int main() {
    while (1) {
        int choice;

        cout << "1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int ele;
                cout << "Enter element ";
                cin >> ele;
                enqueue(ele);
                break;
            }

            case 2: {
                int val = dequeue();
                if (val != -1) {
                    cout << "Dequeued element: " << val << endl;
                }
                break;
            }

            case 3:
                display();
                break;

            case 4:
                cout << "Exiting program.\n";
                exit(0);

            default:
                cout << "Invalid Choice! Try again.\n";
                break;
        }
    }
    return 0;
}
