#include <iostream>
using namespace std;

class Complex
{
    int num1, num2;

public:
    Complex() : num1(0), num2(1) { cout << "NO_DATA"<<endl; };
    Complex(int x, int y) : num1(x) { cout << "DATA-1"<<endl; }
    Complex(int d) : num1(d), num2(0) { cout << "DATA-2"<<endl; }

    friend ostream &operator<<(ostream &, const Complex &);
    friend istream &operator>>(istream &, Complex &);
    Complex &operator=(const Complex &c);
    Complex operator-();
    Complex operator++();
    Complex operator++(int);
};

Complex &Complex::operator=(const Complex &c)
{
    if (this == &c)
    {
        cout << "Entries are same " << endl;
        return *this;
    }
    else
    {
        this->num1 = c.num1;
        this->num2 = c.num2;
    }
    return *this;
}

ostream &operator<<(ostream &os, const Complex &c)
{
    os << c.num1 << " " << c.num2 << endl;
    return os;
}

istream &operator>>(istream &is, Complex &c)
{
    is >> c.num1 >> c.num2;
    return is;
}

Complex Complex::operator-()
{
    Complex temp;
    temp.num1 = -num1;
    temp.num2 = -num2;
    return temp;
}

Complex Complex::operator++()
{
    cout << "Post operator is called"<<endl;
    Complex temp;
   
    temp.num1 = num1;
    temp.num2 = num2 ;
    return temp;
}

Complex Complex::operator++(int)
{
    cout<<"Post fix operator is called "<<endl;
    Complex temp;
    temp.num1 = ++num1;
    temp.num2 = ++num2;
    return temp;
}

int main()
{
    // Complex c1;
    // cin >> c1;
    // cout << c1;
    // c1 = c1;
    // cout << c1;
    Complex c3, c4;
    cin >> c3;
    c4 = ++c3;
    cout<<c4;
    return 0;
}