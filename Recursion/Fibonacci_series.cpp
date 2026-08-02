//Recursive code to generate the fibonacci series

#include <iostream>
using namespace std;

int fibonacci(int n){
    if(n == 0){
        return 0;
    }else
    if(n == 1){
        return 1;
    }
    return fibonacci(n-1) + fibonacci(n-2);
}

int main() {
    int x;

    cout << "Enter number: ";
    cin >> x;

    for(int i=0;i<x;i++){
        cout << fibonacci(i) << " ";
    }
    return 0;
}