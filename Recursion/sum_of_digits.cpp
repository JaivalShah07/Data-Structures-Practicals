//Recursive code to print the sum of digits

#include <iostream>
using namespace std;

int sum(int n){
    if(n==0){
        return 0;
    }else if(n<10){
        return n;
    }else{
        return (n%10)+sum(n/10);
    }
}

int main() {
    int num;

    cout << "Enter a number: ";
    cin >> num; 

    cout << "The sum of digits is: " << sum(num);
    return 0;
}