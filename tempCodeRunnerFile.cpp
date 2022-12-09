
#include<iostream>
using namespace std;
template <class T>
class LL;
template <class T>
class Node
{
    T data;
    Node *next;
    Node(T d);
    Node(T d, Node *n);
    friend class LL<T>;
};
template <class T>
class LL
{
    Node<T> *head;
    void Destroy();
    void Copy(const LL &right);

public:
    LL();
    LL(const LL &right);
    ~LL();
    LL &operator=(const LL &right);
    bool Insert(T e);
    void Print() const;
    void Tinker() const;
};
// Node implementation
template <class T>
Node<T>::Node(T d) : data(d), next(nullptr) {}
template <class T>
Node<T>::Node(T d, Node<T> *n) : data(d), next(n) {}
// Linked List Implementation
template <class T>
LL<T>::LL() : head(nullptr) {}
template <class T>
void LL<T>::Copy(const LL<T> &right)
{
    if (right.head == nullptr)
        head = nullptr;
    else
    {
        Node<T> *curRight = right.head;
        Node<T> *curLeft = nullptr;
        head = new Node<T>(curRight->data);
        curLeft = head; // curLeft points to node we just created
        curRight = curRight->next;
        while (curRight != nullptr)
        {
            curLeft->next = new Node<T>(curRight->data);
            curRight = curRight->next;
            curLeft = curLeft->next; // curLeft points to node we just created
        }
    }
}
template <class T>
void LL<T>::Destroy()
{
    while (head != nullptr)
    {
        Node<T> *temp = head;
        head = head->next;
        delete temp;
    }
}
template <class T>
LL<T>::LL(const LL<T> &right)
{
    Copy(right);
}
template <class T>
LL<T>::~LL()
{
    Destroy();
}
template <class T>
LL<T> &LL<T>::operator=(const LL<T> &right)
{
    if (this != &right)
    {
        Destroy();
        Copy();
    }
    return *this;
}
template <class T>
bool LL<T>::Insert(T item)
{
    bool success = true;
    if (head == nullptr || item < head->data)
    {
        head = new Node<T>(item, head);
    }
    else
    {
        Node<T> *temp = head;
        Node<T> *prev = nullptr;
        while (temp != nullptr && item > temp->data)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = new Node<T>(item, temp);
    }
    return success;
}
template <class T>
void LL<T>::Print() const
{
    Node<T> *curr = head;
    while (curr != nullptr)
    {
        cout << curr->data << endl;
        curr = curr->next;
    }
}
template <class T>
void LL<T>::Tinker() const
{ // only to be used as is with 3 items inserted
    if (head == nullptr)
        return;
    cout << head->next->next->data << endl;
}
int main(){
    LL<int> obj;
    obj.Insert(10);
    obj.Print();
    obj.Insert(10);
    obj.Print();
    obj.Insert(10);
    obj.Print();
   
    return 0;
}