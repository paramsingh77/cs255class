#include <iostream>
using namespace std;

class Complex
{
    int num;
    int den;

    public:
    // constructors
    void print() const
    {
        cout << num << " / " << den << endl;
    }

    Complex()
    {
    }

    Complex(int x, int y)
    {
        num = x;
        num = y;
        cout << "Values inserted " << endl;
    }

    // methods
    void add(const Complex &right);
    void mult(const Complex &right);
    // Complex addBy(const Complex& right);
};

void Complex::add(const Complex &right)
{
    num = (num * right.den) + (right.num * den);
    den = den * right.den;
}

int main()
{

    Complex c1(5, 6);
    Complex c2(6, 7);
    Complex res;
    res.print();
    res = c1.add(c2);
    res.print();
    return 0;
}
