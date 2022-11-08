#include<iostream>
using namespace std;
class Node
{
    // data members
    int data; // anytype
    Node *next;
    // Constructors - note: they are private
    Node();
    Node(int d);
    Node(int d, Node *n);
    friend class LinkedList;
};

class LinkedList
{
    Node *head;

public:
    LinkedList();
    bool InsertAtFront(int item);
    bool InsertAtEnd(int item);
    bool InsertInOrder(int item);
    bool Remove(int item);
    void Print() const;
};

Node::Node() : next(nullptr) {}
Node::Node(int d) : data(d), next(nullptr) {}
Node::Node(int d, Node *n) : data(d), next(n) {}
LinkedList::LinkedList() : head(nullptr) {}


bool LinkedList::InsertAtFront(int item)
{ // Insert a node at the front (head) of
    bool success = true;
    head = new Node(item, head);
    return success;
}

bool LinkedList::InsertAtEnd(int item)
{
    bool success = true;
    if (head == nullptr) // empty list
        head = new Node(item, nullptr);
    else
    {
        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = new Node(item, nullptr);
    }
    return success;
}

bool LinkedList::Remove(int item)
{
    bool success = false;
    return success;
}
void LinkedList::Print() const
{
    Node *temp = head; // starts at the beginning of the list
    while (temp != nullptr)
    {                               // loops while we are not at the end
        cout << temp->data << "\t"; // prints current data item
        temp = temp->next;          // moves to next item
    }
}

int main()
{
    LinkedList obj;

   

    obj.InsertAtFront(30);
    obj.Print();
    cout << endl;
    obj.InsertAtFront(15);
    obj.Print();
    cout << endl;
    obj.InsertAtFront(20);
    obj.Print();
    cout << endl;
    obj.InsertAtFront(10);
    obj.Print();
    cout << endl;
    obj.InsertAtFront(50);
    obj.Print();
    cout << endl;
    obj.InsertAtEnd(60);
    obj.Print();
    cout << endl;
    return 0;
}