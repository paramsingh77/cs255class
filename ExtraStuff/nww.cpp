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
    bool InsertInOrder2(int item);
    bool RemoveFirst();
    void RemoveLast();
};

Node::Node() : next(nullptr) {}
Node::Node(int d) : data(d), next(nullptr) {}
Node::Node(int d, Node *n) : data(d), next(n) {}
LinkedList::LinkedList() : head(nullptr) {}

bool LinkedList::InsertAtFront(int item)
{ // Insert a node at the front (head) of the list
    bool success = true;
    head = new Node(item, head); //////
    return success;
}
bool LinkedList::Remove(int item)
{
    bool success = false;
    return success;
}

bool LinkedList::InsertAtEnd(int item)
{
    bool success = true;
    Node *temp = head;
    if (head == nullptr)
    {
        head = new Node(item, nullptr);
    }
    else
    {
        while (temp->next != nullptr) // i made a mistake hereeeee
            temp = temp->next;

        Node *newtemp = new Node(item);
        temp->next = newtemp;
    }
    return success;
}

bool LinkedList::InsertInOrder2(int item)
{
    bool success = false;
    Node *temp = head;
    Node *prev = head;
    Node *forward = temp;
    if (head == NULL || item < head->data)
    {
        head = new Node(item, head);
    }

    else if (temp != NULL && temp->data > item)
    {
        Node *newHead = new Node(item, head);
    }
    else
    {
        while (forward != NULL && forward->data < item)
        {
            prev = forward;
            forward = forward->next;
        }
        Node *newNode = new Node(item, forward);
        if (prev != nullptr)
        {
            prev->next = newNode;
        }
    }

    return success;
}

bool LinkedList::RemoveFirst()
{
    bool success = true;

    Node *temp = head;

    head = head->next;
    Node *headDelete = head;
    delete headDelete;
    return success;
}

void LinkedList::RemoveLast()
{
    cout << "function called " << endl;
   
    Node *temp = head;
   if(temp == NULL){
    return ;
   }

   else if(temp->next == NULL){
    delete temp;
   }
   else{
    while (temp->next->next!=NULL)
    {
        temp = temp->next;
    }
    Node* toDelete = temp->next;
    delete toDelete;
    temp->next = NULL;
   }
   
}

void LinkedList::Print() const
{
    Node *temp = head; // starts at the beginning of the list
    while (temp != nullptr)
    {
        // loops while we are not at the end
        cout << temp->data << "\t"; // prints current data item
        temp = temp->next;          // moves to next item
    }
}

int main()
{
    LinkedList obj;
    obj.InsertInOrder2(20);
    obj.Print();
    cout << endl;
    obj.InsertInOrder2(10);
    obj.Print();
    cout << endl;
    cout << "REMOVED LAST" << endl;
    obj.RemoveLast();
    obj.Print();
    obj.InsertInOrder2(40);
    obj.Print();
    cout << endl;
    obj.InsertInOrder2(26);
    obj.Print();
    cout << endl;
    obj.InsertInOrder2(30);
    obj.Print();
    cout << endl;
    obj.InsertInOrder2(5);
    obj.Print();
    cout << endl;
    cout << "REMOVED LAST" << endl;
    obj.RemoveLast();
    obj.Print();
    cout << endl;

    // obj.RemoveFirst();
    // obj.Print();
    // cout << endl;
    // obj.InsertInOrder(70);
    // obj.Print();
    // cout << endl;

    // obj.Print();
    return 0;
}