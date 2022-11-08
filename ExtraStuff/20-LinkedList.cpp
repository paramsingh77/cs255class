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

bool LinkedList:: InsertInOrder(int item){
    bool success = true;
    if(head == NULL)
        head = new Node(item);

    else{
        
        
            if(head->next->data > item && head->next!=NULL){
                Node* temp = new Node(item);
                head->next = temp;
                temp->next = head->next->next;

            }
            else if(head->next->data > item && head->next==NULL){
                 Node*temp = head;
                 while(temp->next!=NULL){
                    temp=temp->next;
                 }
                 temp->next = new Node(item);
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

int main()
{
    LinkedList obj;
    
    obj.InsertInOrder(20);
    obj.Print();
    cout << endl;
    obj.InsertInOrder(30);
    obj.Print();
    cout << endl;
    obj.InsertInOrder(40);
    obj.Print();
    return 0;
}