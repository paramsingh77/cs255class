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
    bool IsFull() const;
    bool IsEmpty() const;
    bool Enq(int e);
    bool Deq(int &e);
    void Print() const;
};
Queue::Queue() : front(0), back(0) {}
bool Queue::IsFull() const
{
    return back - front == MAX - 1;
}
bool Queue::IsEmpty() const
{
    return front == back;
}
bool Queue::Enq(int e)
{
    bool success = false;
    if (!IsFull())
    {
        data[back % MAX] = e;
        back++;
        success = true;
    }
    return success;
}
bool Queue::Deq(int &e)
{
    bool success = false;
    if (!IsEmpty())
    {
        e = data[front % MAX];
        front++;
        success = true;
    }
    return success;
}
void Queue::Print() const
{
    cout << "----------------------" << endl;
    cout << "[F: ";
    for (int i = front; i < back; i++)
        cout << data[i % MAX] << " _ ";
    cout << " :B]" << endl;
    cout << "----------------------" << endl;
}
int main()
{
    Queue q;
    for (int i = 0; i < MAX + 2; i++)
    {
        int input;
        cout << "Val? ";
        cin >> input;
        cout << "Success: " << q.Enq(input) << endl;
        q.Print();
    }
    for (int i = 0; i < MAX + 2; i++)
    {
        int removalVal = 0;
        cout << "Success: " << q.Deq(removalVal) << endl;
        cout << "Removed: " << removalVal << endl;
        q.Print();
    }
    for (int i = 0; i < MAX + 2; i++)
    {
        int input;
        cout << "Val? ";
        cin >> input;
        cout << "Success: " << q.Enq(input) << endl;
        q.Print();
    }
    return 0;
}