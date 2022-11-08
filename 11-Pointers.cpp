#include<iostream>
using namespace std;


int main(){
    int a = 5;
    int b= 0;
    int *ptr = &a;
    int *ptr1 = &b;



    cout<<"Address of a is "<ptr<<endl;
    cout<<"Value at "<ptr<< " is " <<*ptr<<endl;
    return 0;
}