#include<iostream>
using namespace std;

void printArr(int arr[],int size){
    if(size == 0){
       size = 1;
    }

    printArr(arr,size-1);
    cout<<arr[size-1]<<" "<<endl;
   
}

int main(){
    int size = 5;
    int arr[size];
    for(int i = 0 ; i < size ; i++){
        cin>>arr[i];
    }
    printArr(arr,size);
    return 0;
}