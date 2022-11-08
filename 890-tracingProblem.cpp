#include <iostream>
using namespace std;
class Fraction
{
    int num;
    int den;
    void getNum();
public:
    Fraction() : num(0), den(1) { cout << "No-DATA"<< endl; }
    Fraction(int n) : num(n), den(1) { cout << "DATA-1" << endl; }
    Fraction(int n,int d) : num(n), den(d) { cout << "DATA-2" << endl;
    if(d == 0) 
    d=1;
    den = d;
    }
    int GetNum()const {return num;}
    int GetDen()const {return den;}
    Fraction operator*(const Fraction& f)const{
        cout<<"MULTIPLICATION"<<endl;
        Fraction temp;
        temp.num = num * f.num;
        temp.den = den *f.den;
        return temp;
    }
    friend ostream& operator<<(ostream& os , const Fraction& f);
};

void Fraction:: GetNum(){
    
}

ostream& operator<<(ostream& os , const Fraction& f){
    os<<f.num<<"/"<<f.den;
    return os;
}

int
main()
{
    cout << "*****" << endl;
    Fraction one(3, 4);
    cout << "****" << endl;
    Fraction two(4, 5);
    cout << "****" << endl;
    Fraction three;
    cout << "****" << endl;
    three = one * two; cout<<"pr"<<endl;
    Fraction four(two.GetNum(), two.GetDen());
    cout << "****" << endl;
    Fraction five;
    five = two.GetDen();
    cout << "*****" << endl;
    Fraction six(4, 5);
    cout << "****" << endl;
    cout << one << endl;
    cout << two << endl;
    cout << three << endl;
    cout << four << endl;
    cout << five << endl;
    cout << six << endl;
    cout << "*****" << endl;
    cout << one * six << endl;
    return 0;
}