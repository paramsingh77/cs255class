#include <iostream>
using namespace std;

const int MAX = 5;

class Queue
{
    int *arr;
    int rear;
    int front;
    int sizeOfArr;

public:
    Queue();
    bool enqueue(int item);
    bool dequeue(int &item);
    bool IsFull() const;
    bool IsEmpty() const;
    void Print() const;
};

Queue::Queue() : front(0), rear(0)
{
    sizeOfArr = 7;
    arr = new int[sizeOfArr];
}

bool Queue::enqueue(int item)
{
    bool success = false;
    if (!IsFull())
    {
        success = true;
        rear = (rear + 1) % 7;
        arr[rear] = item;
    }
    return success;
}

bool Queue::dequeue(int &item)
{
    bool success = false;
    if (!IsEmpty())
    {
        success = true;
        front = (front + 1) % 7;
        item = arr[front];
    }
    return success;
}

bool Queue::IsEmpty() const
{
    bool success = false;
    if (front == rear)
    {
        cout << "Queue is Empty" << endl;
        success = true;
    }
    else
    {
        success = false;
    }
    return success;
}

bool Queue::IsFull() const
{
    bool success = false;
    // if (rear - front == sizeOfArr - 1)
    // {
    //     success = true;
    //     cout << "Queue is FUll" << endl;
    // }

    if ((rear + 1) % sizeOfArr == front)
    {
        cout << "Queue is full" << endl;
        success = true;
    }

    // cout << "----------------------" << endl;
    // cout << "[F: ";
    // for (int i = front+1; i < rear+1; i++)
    //     cout << arr[i+1 % MAX] << " _ ";
    // cout << " :B]" << endl;
    // cout << "----------------------" << endl;

    return success;
}

void Queue::Print() const
{
    cout << "------------------------" << endl;
    cout << " [F: ";
    // for (int i = front+1; i < rear; i++)
    // {
    //     cout << arr[(i+1)%7];
    //     cout << "--";
    // }

    int i = front + 1;

    do
    {
        cout << arr[i] << "-";
        i = (i + 1) % 7;
    } while (i != (rear + 1) % 7);

    cout << " :B]" << endl;
    cout << "-----------------------" << endl;
}

int main()
{
    Queue q1;
    // int size;
    // cout << "Enter the size of array: ";
    // cin >> size;
    // int element;

    // for (int i = 0; i < size; i++)
    // {
    //     cout << "Enter the " << i << " element of array: ";
    //     cin >> element;
    //     q1.enqueue(element);
    //     q1.Print();
    // }
    int e;
    q1.enqueue(6);
    q1.enqueue(5);
    q1.enqueue(4);
    q1.dequeue(e);
    q1.enqueue(2);
    q1.enqueue(1);
    q1.dequeue(e);
    q1.enqueue(5);
    q1.enqueue(6);

    q1.Print();

    return 0;
}