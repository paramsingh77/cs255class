#include <iostream>
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
    bool Remove(int item);
    void Print() const;
    bool InsertAtEnd(int item);
    bool InsertInOrder(int item);
};

Node::Node() : next(nullptr) {}
Node::Node(int d) : data(d), next(nullptr) {}
Node::Node(int d, Node *n) : data(d), next(n) {}
LinkedList::LinkedList() : head(nullptr) {}

bool LinkedList::InsertInOrder(int item)
{
    bool success = true;
    if (head == NULL)
        head = new Node(item);

    else
    {
        while (head->next != NULL)
        {
            if (head->next->data > item && head->next != NULL)
            {
                Node *temp = new Node(item);
                head->next = temp;
                temp->next = head->next->next;
            }
            else if (head->next->data > item && head->next == NULL)
            {
                Node *temp = head;
                while (temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = new Node(item);
            }
        }
    }

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
