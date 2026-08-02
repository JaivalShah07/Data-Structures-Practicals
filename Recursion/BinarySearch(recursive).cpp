//Binary Search Program using recursion approach

#include <iostream>
using namespace std;

int binarySearch(int arr[], int left, int right, int key){
    int mid = left + (right - left)/2;

    if(left <= right){
        if(key == arr[mid]){
            return mid;
        }

        if(key < arr[mid]){
            return binarySearch(arr,left,mid-1,key);
        }else{
            return binarySearch(arr,mid+1,right,key);
        }
    }

    return -1;
}

int main() {
    int s, k;

    cout << "Enter the size: ";
    cin >> s;

    int arr[s];

    cout << "Enter " << s << " Elements:";
    for(int i=0;i<s;i++){
        cin >> arr[i];
    }

    cout << "Enter key: ";
    cin >> k;

    int res = binarySearch(arr,0,s-1,k);

    if(res == -1){
        cout << "key not found!";
    }else {
        cout << "Key found at index: " << res;
    }
    return 0;
}