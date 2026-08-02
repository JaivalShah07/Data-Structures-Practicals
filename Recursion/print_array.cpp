//Recursive code to print an array

#include <iostream>
using namespace std;

void printArray(int arr[], int n, int i=0){
    if (i>n-1){
        return;
    }else{
        cout << arr[i] << " ";
        printArray(arr,n,i+1);
    }
}

int main() {
    int n;
    cout << "Enter the size: ";
    cin >> n;

    int arr[n];
    cout << "Input " << n << " elements: ";
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    cout << "Array = ";
    printArray(arr,n);
    return 0;
}