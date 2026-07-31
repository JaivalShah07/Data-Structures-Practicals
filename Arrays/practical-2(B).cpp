#include <iostream>
using namespace std;

void callByValue(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;

    cout << "Inside Call by Value:\n";
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}

void callByReference(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;

    cout << "Inside Call by Reference:\n";
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}

int main()
{
    int x, y;

    cout << "Enter two numbers: ";
    cin >> x >> y;

    cout << "\nBefore Call by Value:\n";
    cout << "x = " << x << " y = " << y << endl;

    callByValue(x, y);

    cout << "After Call by Value:\n";
    cout << "x = " << x << " y = " << y << endl;

    cout << "\nBefore Call by Reference:\n";
    cout << "x = " << x << " y = " << y << endl;

    callByReference(x, y);

    cout << "After Call by Reference:\n";
    cout << "x = " << x << " y = " << y << endl;

    return 0;
}