#include <iostream>
using namespace std;

#define s 20
int queue[s];
int front = -1, rear = -1;

int full()
{
    if (rear == s - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int empty()
{
    if (front == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue(int x){
    if (full()){
        exit(0);
    }
    else{
        if (front == -1){
            front = 0;
        }
        queue[rear++] = x;
    }
}

int dequeue(){
    int x;
    if (empty()){
        exit(0);
    }
    else{
        x = queue[front];
        front++;
    }
    return x;
}

int main(){
    while (1){
        int choice;

        cout << "\n1.enqueue\n2.dequeue\n3.display\n4.exit\n";
        cin >> choice;

        switch (choice){
            case 1:
                int ele;
                
                cout << "enter a element to enter in queue :";
                cin >> ele;
                enqueue(ele);
                break;

            case 2:
                cout << "dequeued element: " << dequeue() << endl;
                break;

            case 3:
                cout << "The elements in the queue are: ";
                for (int i = front; i <= rear; i++){
                    cout << queue[i] << " ";
                }
                cout << endl;
                break;

            case 4:
                exit(0);
                break;

            default:
                cout << "Invalid Choice!";
                break;
        }
    }
    return 0;
}