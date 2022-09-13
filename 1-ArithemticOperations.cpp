#include<iostream>
using namespace std;

class Complex {
    int a;
    int b;
    public:
    void print(){
        cout<<a<<" "<<b<<endl;
    }
    void setData(int x,int y){
        a = x;
        b = y;
    }
    Complex add(const Complex c)const;
};

Complex Complex :: add(const Complex c) 
    {
        Complex temp;
        temp.a = a + c.a;
        temp.b = b + c.b;
        return temp;
    }
int main()
{
    Complex c1,c2,c3;
    c1.setData(5,6);
    c2.setData(6,7);
    c3 = c1.add(c2);
    c3.print();

    return 0;
}