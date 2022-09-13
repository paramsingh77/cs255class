#include<iostream>
using namespace std;

class Complex{
    int a;
    int b;
    public:
    void print(){
        cout<<a<<" "<<b<<endl;
    }

    Complex():a(1),b(1){}
    Complex(int x, int y):a(x),b(y){}
    Complex(int f):a(f),b(0){}

    friend void operator*(Complex c);

};

void operator*(Complex c){
        cout<<c.a*c.b<<endl;
}

int main(){
    Complex c1(5,6);
    Complex c2(4,5);
    *(c1);
   
    return 0;
}