#include <iostream>
using namespace std;

const int MAX = 5;
class Stack
{
    int data[MAX]; // array holding the data
    int top;       // index of top item

public:
    Stack();
    bool Push(int item);
    bool Pop(int &item);
    void Print() const;
    bool peek(int &item) const; // it's just looking at peek no touching
    bool IsEmpty() const;
    bool IsFull() const;
};

Stack ::Stack();
bool Stack ::Push(int item){
    bool success = false;

    return success;
}
bool Stack ::Pop(int &item){
    bool sucesss = false;

    return sucesss;
}
void Stack ::Print() const;
bool Stack ::peek(int &item) const{
bool sucess = false;
return sucess;
}// it's just looking at peek no touching{


bool Stack ::IsEmpty() const{
    bool sucess = false;
    return sucess;
}
bool Stack ::xIsFull() const
{
    bool sucess = false;
    return sucess;
}

int main()
{
    return 0;
}