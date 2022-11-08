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

    Complex() : a(1), b(1) {}
    Complex(int x, int y) : a(x), b(y) {}
    Complex(int f) : a(f), b(0) {}

    friend void operator*(Complex c);
    void operator-();
    friend Complex operator+(const Complex &x, const Complex &y);
    friend Complex operator-(const Complex &x, const Complex &y);
    //urninary operator
    friend Complex operator-(const Complex);
    Complex operator>>(const Complex&c);
};

void operator*(Complex c)
{
    cout << c.a * c.b << endl;
}

void Complex::operator-()
{
    a = -a;
    b = -b;
    cout << a << " " << b << endl;
}

Complex operator+(const Complex &x, const Complex &y)
{
    Complex temp;
    temp.a = x.a + y.a;
    temp.b = y.a + y.b;
    return temp;
}

Complex operator-(const Complex &x, const Complex &y)
{
    Complex temp;
    temp.a = x.a - y.a;
    temp.b = x.a - y.b;
    return temp;
}

Complex operator-(const Complex&  c){
    Complex temp;
    temp.a  =  -b;
    temp.b = -b;
    return temp;
}

Complex Complex:: operator>>(const Complex &c){
      Complex temp;
       cin>>temp.a;
       cin>>temp.b;
       return temp;
}
int main()
{
    Complex c1(5, 6);
    Complex c2(4, 5);
    Complex c7;
    *(c1);
    c2.operator-();
    Complex c4 = c1 + c2; // friend function --> operator+(c1,c2);
    c4.print();
    Complex c5 = c1 - c2;
    c5.print();
    cin>>c7;
    return 0;
}