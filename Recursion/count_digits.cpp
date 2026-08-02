//Recursive code to count the digits of the given number.

#include <iostream>
using namespace std;

int count(int n){
    if(n<10){
        return 1;
    }else{
        return 1 + count(n/10);
    }
}

int main() {
    int num;

    cout << "Enter a number: ";
    cin >> num;

    cout << "Counter digits are: " << count(num);
    return 0;
}