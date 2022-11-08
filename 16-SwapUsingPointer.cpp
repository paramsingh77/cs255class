#include <iostream>
using namespace std;


void SwapAddressUsingPtr(int *x, int *y)
{

   

    int *temp = x;
    x = y;
    y = temp;

    cout << "After Address of x is " << x << endl;
    cout << "After Address of y is " << y << endl;
    cout << "After value of x is " << *x << endl;
    cout << "After Value of y is " << *y << endl;
}

void SwapValueUsingPtr(int *x, int *y)
{

    

    int temp = *x;
    *x = *y;
    *y = temp;

    cout << "After Address of x is " << x << endl;
    cout << "After Address of y is " << y << endl;
    cout << "After value of x is " << *x << endl;
    cout << "After Value of y is " << *y << endl;
}

int main()
{


    int a = 10, b =15;
    SwapValueUsingPtr(&a, &b);
    cout << endl;
    cout << endl;
    int x = 10, y = 15;
    SwapAddressUsingPtr(&x, &y);
  
    return 0;
}