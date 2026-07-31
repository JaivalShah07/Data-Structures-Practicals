#include <iostream>
using namespace std;

void insertion(int arr[1000], int &n){
    int ele, pos;

    cout << "Enter the element to add: ";
    cin >> ele;

    cout << "Enter position: ";
    cin >> pos;

    if(pos<1 || pos>n+1) {
        cout << "Invalid position!";
    }

    for(int j=n;j>=pos;j--){
        arr[j] = arr[j-1];
    }

    arr[pos-1] = ele;
    n++;
}

void deletion(int arr[1000], int &n){
    int ele , flag =0;

    cout << "Enter the element: ";
    cin >> ele;

    for(int i=0;i<n;i++){
        if(ele == arr[i]){
            flag = 1;
            for(int j=i;j<n-1;j++){
                arr[j] = arr[j+1];
            }
            n--;
            i--;
        }
    }

    if(!flag){
        cout << "Value not found!";
    }else {
        cout << "Deleted successfully.";
    }
}

void traverse(int arr[1000], int &n){
    cout << "\nArr = ";
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void searching(int arr[1000], int &n){
    int ele;

    cout << "Enter element to search: ";
    cin >> ele;

    // for(int i=0;i<n;i++){
    //     if(arr[i] == ele){
    //         cout << "\nFound the element at position: " << i+1 << " Index: " << i;
    //         break;
    //     }else{
    //         cout << "\nElement not found in array!";
    //         break;
    //     }
    // }
    
    for(int i=0;i<n;i++){
        if(arr[i] == ele){
            cout << "\nFound the element at position: " << i+1 << " Index: " << i;
            return;
        }
    }
    cout << "\nElement not found in array!";
}

int main() {
    int arr[1000], n;

    cout << "Enter total numbers: ";
    cin >> n;

    cout << "Enter " << n << " numbers: ";
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    int choice;
    bool running=true;

    while(running){
        cout << "\n\n======Array Operations======\n";
        cout << "1. Insertion" << endl;
        cout << "2. Deletion" << endl;
        cout << "3. Searching" << endl;
        cout << "4. Traverse" << endl;
        cout << "5. Exit" << endl;

        cout << "\n\nEnter your choice: ";
        cin >> choice;

        switch(choice){
            case 1:
                insertion(arr, n);
                break;
            case 2:
                deletion(arr, n);
                break;
            case 3:
                searching(arr, n);
                break;
            case 4:
                traverse(arr, n);
                break;
            case 5:
                running = false;
                break;
            default:
                cout << "Invalid Choice!";
                running = false;
                break;
        }
    }
    return 0;
}