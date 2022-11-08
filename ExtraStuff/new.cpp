#include<iostream>
using namespace std;

void funArr(int arr1[], int arr2[],int size,int& newSize,int*&newArr){
    newSize = size*2
    newArr = new int[newSize];
    int count = 0;
    for(int i = 0 ; i < newSize ; i++){
        newArr[i] = arr1[i];
        count++;
    }

    for(int i = count ; i<newSize;i++){
        newArr[i] = arr2[i];
    }
}

int main(){

    return 0;
}