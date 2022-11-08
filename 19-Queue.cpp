#include <iostream>
using namespace std;



class Queue
{
    int *arr;
    int qfront;
    int rear;
    int size;

public:
    Queue();
    bool enqueue(int item);
    bool dequeue(int &item) ;
    bool isEmpty() const;
    bool isFull() const;
    void Print() const;
    bool Front(int &item) const;
};

Queue::Queue() : qfront(0), rear(0)
{
    size = 100001;
    arr = new int[size];
}

bool Queue::enqueue(int item)
{
    bool success = false;
    if (!isFull())
    {
        success = true;
        arr[rear] = item;
        rear++;
    }
    return success;
}

bool Queue::dequeue(int &item) 
{
    bool success = false;
    if (!isEmpty())
    {
        success = true;
        // remove value then move forward
        item = arr[qfront];
        qfront++;
    }
    return success;
}
bool Queue::Front(int &item) const
{
    bool success = false;
    if (!isEmpty())
    {
        success = true;
        item = arr[qfront];
    }
    return success;
}

bool Queue::isEmpty() const
{
    return (qfront == rear);
}

bool Queue::isFull() const
{
    return ( rear - qfront == size - 1);
}

void Queue::Print() const
{
    cout << "----------------------" << endl;
    cout << "[F: ";
    for (int i = qfront; i < rear; i++)
        cout << arr[i] << " _ ";
    cout << " :B]" << endl;
    cout << "----------------------" << endl;
}

int main()
{

    Queue s1;
    int size;
    cout << "Enter the stack size: ";
    cin >> size;
    cout<<endl;
    int element;
    for (int i = 0; i < size; i++)
    {
        cout << "Enter the " << i << " element of queue: ";
        cin>>element;
        s1.enqueue(element);
    }

    for (int i = 0; i < size; i++)
    {
        s1.dequeue(element);
        s1.Print();
    }
    return 0;
}