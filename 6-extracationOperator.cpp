#include<iostream>
using namespace std;

class Complex{
    int a;
    int b;
    public:
    void print(){
        cout<<a<<" "<<b;
    }

    Complex (int x,int y):a(x),b(y);

    Complex(){};
    friend ostream& operator<<(ostream&,Complex);
    friend istream& operator>>(istream&,Complex);
    int GetNum(){
        return 
    }
};

ostream& operator<<(ostream& cout ,  Complex c){
    cout<<c.a<<" "<<c.b<<endl;
    return cout;
}

istream& operator>>(ostream& cin , Complex c){
    cin>>c.a>>c.b>>endl;
    return cin;
}




int main(){

    return 0;
}