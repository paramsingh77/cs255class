#include<iostream>
using namespace std;

int fact(int n){
    if(n==0 || n==1){
        return 1;
    }

    int subProblem = n*fact(n-1);
    return subProblem;
}

int main(){
    cout<<fact(5);

    return 0;
}