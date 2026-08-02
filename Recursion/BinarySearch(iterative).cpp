//Binary search program using iterative approach

#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int key){
    int mid, left=0, right=size-1;

    while(left <= right){
        mid = (left + (right-left))/2;
        
        if(key == arr[mid]) return mid;

        if(key < arr[mid]){
            right = mid-1;
        }else{
            left = mid+1;
        }
    }

    return -1;
}

int main() {
    int s, k;
    cout << "Enter size: ";
    cin >> s;

    int arr[s];
    cout << "Enter " << s << " elements: ";
    for(int i=0;i<s;i++){
        cin >> arr[i];
    }

    cout << "Enter search key: ";
    cin >> k;

    int res;
    res = binarySearch(arr,s,k);
    if(res == -1){
        cout << "Key Not Found!";
    }else{
        cout << "Key Found at index: " << res;
    }
    return 0;
}