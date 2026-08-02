//Recursive code to print the sum of the 1st N Numbers

#include <iostream>
using namespace std;

int sum(int n){
    if(n<0){
        return 0;
    }else{
        return n+sum(n-1);
    }
}

int main() {
    int x;

    cout << "Enter a number: ";
    cin >> x;

    int res;
    res = sum(x);

    cout << "The sum of " << x << " numbers is: " << res;
    return 0;
}