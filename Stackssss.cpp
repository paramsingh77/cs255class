#include <iostream>
using namespace std;

const int MAX = 5;

class Stack
{
    int top;
    int *arr;
    int max;

public:
    Stack();
    Stack(int size);
    ~Stack();
    bool push(int item);
    bool peek(int &item);
    bool pop(int &item);
    bool isFull();
    bool isEmpty();
    Stack(const Stack& right);
    Stack& operator=(const Stack& right);
    void Print()const;
};

Stack::Stack():top(-1),max(MAX){
    arr = new int[max];
    cout<<"Made"<<endl;
}

Stack::Stack(int size):top(-1),max(size){
    arr = new int[size]; 
}

Stack::~Stack(){
    delete []arr;
    top = -1;
    max = 0;
    cout<<"Deconstructed"<<endl;
}

bool Stack::push(int item){
    bool success = false;
    if(!isFull()){
        arr[++top] = item;
        success = true;
    }
    return success;
}

bool Stack::pop(int &item){
    bool success = false;
    if(!isEmpty()){
        item = arr[top--];
        success = true;
    }
    return success;
}

bool Stack::peek(int &item){
    bool success = true;
    if(!isEmpty()){
        item = arr[top];
         success = true;
    }
   return success;
}

bool Stack::isFull(){
    return top == -1;
}

bool Stack::isEmpty(){
    return top == MAX-1;
}

Stack::Stack(const Stack& right){
    top = right.top;
    max = right.max;
    arr = new int[max];
    for(int i = 0 ; i < top ; i++){
        arr[i] = right.arr[i];
    }
}

Stack& Stack::operator=(const Stack& right){
    if(this!=&right){
        if(arr !=nullptr)
            delete[]arr;

        top = right.top;
        max = right.max;
        arr = new int[max];
        for(int i = 0 ; i < top ; i++){
            arr[i] = right.arr[i];
        }
    }
    return *this;
}

void Stack::Print()const{
    for(int i = top ; i >= 0 ; i--){
        cout<<arr[i]<<endl;
    }
}

int main()
{
    Stack s1(1);
    s1.push(10);
    s1.Print();
    return 0;
}