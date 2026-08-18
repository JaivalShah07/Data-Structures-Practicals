//Implementation of priority queue using the array
#include <iostream>
using namespace std;

#define s 20
int queue[s];
int front = -1, rear = -1;

int full() {
    return (rear == s - 1);
}

int empty() {
    return (front == -1 || front > rear);
}

void enqueue(int x) {
    if (full()) {
        cout << "Cannot add element.\n";
        return;
    }
    
    if (front == -1) {
        front = 0;
    }
    queue[++rear] = x;
    cout << "Successfully inserted: " << x << endl;
}

int dequeue() {
    if (empty()) {
        cout << "Queue is empty.\n";
        return -1;
    }

    int min;

    for(int i=0; i<=(rear+1)%s;i++){
        if(queue[i] != -1){
            if(queue[i] < min){
                min = i;
            }
        }else{
            continue;
        }
    }
    int res = queue[min];
    queue[min] = -1;
    return res;
}

void display() {
    if (empty()) {
        cout << "Queue is empty.\n";
        return;
    }
    
    cout << "The elements in the queue are: ";
    for (int i = front; i <= rear; i++) {
        cout << queue[i] << " ";
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