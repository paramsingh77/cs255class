#include <iostream>
using namespace std;

class Complex
{
    int a;
    int b;

public:
    void print()
    {
        cout << a << " " << b << endl;
    }

    void setData(int x, int y)
    {
        a = x;
        b = y;
    }

    Complex operator-();
};

Complex Complex::operator-(){
    Complex temp;
    temp.a = -a;
    temp.b = -b;
    return temp;
}

int main()
{
    Complex c1;
    c1.setData(5,6);
    Complex c2;
    c2 = -c1; //c1.operator-();
    c2.print();
    return 0;
}