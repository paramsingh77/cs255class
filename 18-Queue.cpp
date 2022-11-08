#include <iostream>
using namespace std;

const int MAX = 5;

class Queue
{
    int data[MAX];
    int front;
    int back;

public:
    Queue();
    bool isEmpty() const;
    bool isFull() const;
    bool Enqe(int e);
    bool Dqe(int &e);
    void print() const;
};

Queue::Queue() : front(0), back(0) {}
bool Queue::isEmpty() const
{
    return (front == back);
}
bool Queue::isFull() const
{
    return back - front == MAX - 1;
}
bool Queue::Enqe(int e)
{
    bool success = false;
    if (!isFull())
    {
        data[back%MAX] = e;
        back++;
        success = true;
    }
    return success;
}
bool Queue::Dqe(int &e) // deuque is done at the back
{
    bool success = false;
    if (!isEmpty())
    {
        e = data[front%MAX];
        front++;
        success = true;
    }
    return success;
}
void Queue::print() const
{
    cout<<"-------------------------------"<<endl;
    cout << "[F "; for (int i = front; i < back; i++)
    {
        cout << data[i%MAX] << "\t";
    }
    cout << ":E] "<<endl;
    cout<<"-------------------------------"<<endl;
}

int main()
{
    Queue q;
    int value;
    for(int i = 0 ; i<MAX+2;i++){
        cout<<"Enter the value into the queue"<<endl;
        cin>>value;
        cou
        q.Enqe(value);
        q.print();
    }
    int removeVal =0;
    for(int i = 0 ; i < MAX+2 ; i++){
        cout<<"Success?"<<q.Dqe(i)<<endl;
        cout<<"removeVal"<<removeVal<<endl;
    }
    return 0;
}