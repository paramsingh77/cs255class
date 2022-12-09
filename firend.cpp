#include <iostream>
using namespace std;

class Complex
{
    int num1;
    int num2;

public:
    Complex();
    Complex(int nb1);
    Complex(int nb1,int nb2);

    Complex operator+(const Complex& right)const;
    friend ostream& operator<<(ostream&os , const Complex& right);
    Complex operator++(); //pre increment
    Complex operator++(int); //post increment;
};
Complex::Complex(){
    num1 = 0;
    num2 = 0;
}

Complex::Complex(int nb1){
    num1 = nb1;
    num2 = 0;
}

Complex::Complex(int nb1,int nb2){
    num1 = nb1;
   num2 = nb2;
}

Complex Complex::operator+(const Complex& right)const{
    Complex temp;
    temp.num1 = this->num1 + right.num1;
    temp.num2  = this->num2 + right.num2;
    return temp;
}

ostream& operator<<(ostream&os , const Complex& right){
    os<<right.num1<<endl;
    os<<right.num2<<endl;
    return os;
}

Complex Complex:: operator++(){
   Complex temp;
   temp.num1 = ++num1;
   temp.num2 = ++num2;
   return temp;
}

Complex Complex::operator++(int){
    Complex temp;
    temp.num1 = num1;
    temp.num2 = num2;
    return temp;
}

int main()
{
  
   Complex c1(4, 5);
   Complex c2(5, 6);
   Complex c3 = c2 + c1;
   cout << c3;
   c3++;
   cout<<c3;
   c3 = ++ c2;
   cout<<c3;
   return 0;
}