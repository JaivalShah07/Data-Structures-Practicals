//Recursive formula to compute the power of number

#include <iostream>
using namespace std;

int power(int a, int n){
    if(n == 0){
        return 1;
    }else if(n==1){
        return a;
    }else {
        return a * power(a, n-1);
    }
}

int main() {
    int base, pow;
    cout << "Enter base number: ";
    cin >> base;

    cout << "Enter power: ";
    cin >> pow;

    cout << base << "^" << pow << " = " << power(base, pow);
    return 0;
}