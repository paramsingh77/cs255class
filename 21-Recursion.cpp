#include<iostream>
using namespace std;

int fact(int n){
    if ( n==0|| n == 1){
        return n;
    }
    int subProblem  = fact(n-1);
    int subProblem1 = fact(n-2);
    return subProblem+subProblem1;
    
}

int main(){
    cout<<"Fibbonacci "<<fact(6);
    return 0;
}