//Recursive program to find the maximum number from the array

#include <iostream>
using namespace std;

int maxOfArray(int p[], int n){
    static int max = p[0];
    if(n==-1){
        return max;
    }

    if(p[n]>max){
        max = p[n];
    }
    return maxOfArray(p,n-1);
}

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements: ";
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    cout << "Highest number: " << maxOfArray(arr, n-1);
    return 0;
}