// #include <iostream>
// using namespace std;

// class Complex
// {
//     int a;
//     int b;

// public:
//     void print()
//     {
//         cout << a << " " << b;
//     }

//     void setData(int x, int y)
//     {
//         a = x;
//         b = y;
//     }

//     Complex operator+(Complex c){
//         Complex temp;
//         temp.a = a + c.a;
//         temp.b = b + c.b;
//         return temp;
//     }
// };

// Complex Complex:: operator-(const Complex& c)const
// {
//     Complex temp;
//     temp.a = a + c.a;
//     temp.b = b + c.b;
//     return temp;
// }

// int main()
// {
//     Complex c1,c2,c3;
//     c1.setData(4,5);
//     c2.setData(6,8);
//     c3 = c1+c2;
//     c3.print();
//     return 0;
// }


#include<iostream>
using namespace std;

class Complex{
    int a;
    int b;
    public:
    void print(){
        cout<<a<<" "<<b;
    }
    Complex(){
    }
    Complex(int x, int y){
        a = x;
        b = y;
    }

    Complex operator++(){
        Complex temp;
        temp.a = ++a;
        temp.b = ++b;
        return temp;
    }
    Complex operator++(int){
        Complex temp;
        temp.a = a++;
        temp.b = b++;
        return temp;
    }
};


int main(){
    Complex c1(5,6);
    Complex c3(4,5);
    Complex c2 = ++c1;
    c2.print();cout<<endl;
    c3++;
    c3.print();
    return 0;
}