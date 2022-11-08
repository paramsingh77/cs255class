#include<iostream>
using namespace std;

int fib(int n){
    if(n==0 || n==1)
        return n;

    int subProblemRight = fib(n-1);
    int subProblemLeft = fib(n-2);
    int result = subProblemLeft+subProblemRight;
    return result;
}

int main(){

    cout<<fib(6);
    return 0;
}