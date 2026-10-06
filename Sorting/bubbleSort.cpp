#include <iostream>
using namespace std;

void Swap(int a, int b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void bubbleSort(int arr[], int size){
    bool swapped;

    for (int i = 0; i < size - 1; i++) {
        swapped = false;
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if (!swapped)
            break;
    }
}

int main(){
    int n;

    cout << "enter size: ";
    cin >> n;

    int arr[n];

    cout << "enter " << n << " elements: ";
    for(int i=0;i<n;i++){
        cin >> arr[n];
    }

    cout << "Before bubble sort: \narr = ";
    for(int j=0;j<n;j++){
        cout << arr[j];
    }

    bubbleSort(arr, n);

    cout << "After Bubble sort: \narr = ";
    for(int k=0;k<n;k++){
        cout << arr[k];
    }
}