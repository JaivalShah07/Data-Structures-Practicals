//Printing steps for disk transfer in Tower of Hanoi using reursion

#include <iostream>
using namespace std;

void toh(int n, char src, char helper, char dest){

    if(n==1){
        cout << "Move " << n << " from " << src << " to " << dest << endl;
        return;
    }

    toh(n-1,src,dest,helper);
    cout << "Move " << n << " from " << src << " to " << dest << endl;
    toh(n-1,helper, src, dest);
}

int main() {
    int n;
    cout << "Enter number of disks: ";
    cin >> n;
    toh(n,'S','H','D');
    return 0;
}