#include<iostream>
using namespace std;

class Complex{
    int num;
    int den;
    public:
    Complex():num(0),den(1){cout<<"NO-DATA"<<endl;}
    Complex(int n):num(n),den(0){cout<<"DATA-1"<<endl;}
    Complex(int n , int d):num(n),den(d){cout<<"DATA-2"<<endl;}
    friend ostream& operator<<(ostream& os , const Complex&);
    friend istream& operator>>(istream& in , Complex&);
};

ostream& operator<<(ostream& os , const Complex& c){
    cout<<c.num <<"/"<<c.den<<endl;
    return os;
}

istream& operator>>(istream& in , Complex&c){
    cin>>c.num>>c.den;
    return in;
}

int main(){
    Complex c1;
    cin>>c1;
    cout<<c1;
    return 0;
}