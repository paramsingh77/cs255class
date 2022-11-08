#include<iostream>
using namespace std;

void fun(int*q){
    cout<<"Value is accessible";

    delete[]q;
    q = nullptr;
}

int main(){
    // int A[5] = {1,2,3,4,5}; 
    // int *p = A;
    // fun(p);
    // cout<<*p;
    int x = 10;
    int &y = x;
    cout<<++y<<endl;
    cout<<x<<endl;
    cout<<--y<<endl;
    cout<<x<<endl; 
    return 0;
}
