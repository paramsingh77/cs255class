#include<iostream>
using namespace std;


int main(){
    
    int A[5]={2,3,4,5,7};
    int *p = A,*q=&A[4];
    cout<<p<<endl;
    for(int i = 0 ; i < 5 ; i++){
        cout<<*p<<endl;
        p++;
    }
    cout<<p<<endl;
    return 0;
}