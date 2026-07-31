//Reversing the array elements using pointers (2-pointer approach)
#include <iostream>
using namespace std;

void Swap(int *a, int * b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void reverseArray(int arr[], int n){
    int *start = arr, *end = arr + (n-1);

    while(start < end){
        Swap(start, end);
        start++;
        end--;
    }
}

int main() {
    int n;

    cout << "Enter the size of array: ";
    cin >> n;


    int arr[n];

    cout << "Enter " << n << " Elements:" << endl;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    reverseArray(arr, n);

    cout << "Reversed Array: ";
    
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    
    return 0;
}