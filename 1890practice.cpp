#include <iostream>
using namespace std;

class Node
{
    int data;
    Node *next;

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
    bool InsertAtEnd(int item);
    bool InsertAtFront(int item);
    bool InsertInOrder(int item);
    bool RemoveLast();
    bool RemoveFirst();
    bool RemoveItem(int item);
    bool FindItem(int item);
    bool FindMiddle();

    void Print() const;
};

Node::Node() : next(nullptr) {}
Node::Node(int d) : data(d), next(nullptr) {}
Node::Node(int d, Node *n) : data(d), next(n) {}

LinkedList::LinkedList() : head(nullptr) { cout<<"List is working"<<endl;}
bool LinkedList::InsertAtFront(int item)
{
    bool success = true;
    head = new Node(item, head);
    return success;
}

bool LinkedList::InsertAtEnd(int item)
{
    bool success = true;
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new Node(item);

    return success;
}

void LinkedList::Print() const
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << "\t";
        temp = temp->next;
    }
    cout << endl;
}
void swap(int *a, int *b);
bool LinkedList::InsertInOrder(int item)
{
    bool success = true;
    Node *prev = head;
    Node *forward = head;
    if (head == NULL || head->data > item)
    {
        head = new Node(item, head);
    }
    else
    {
        while (forward != NULL && forward->data < item)
        {
            prev = forward;
            forward = forward->next;
        }
        Node *newNode = new Node(item);
        newNode->next = prev->next;
        prev->next = newNode;
    }
    return success;
}

bool LinkedList::RemoveFirst()
{
    bool success = true;

    Node *deleteHead = head;
    head = head->next;
    delete deleteHead;

    return success;
}

bool LinkedList::RemoveLast()
{
    bool success = true;
    Node *temp = head;

    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    Node *toBeDeleted = temp->next;
    temp->next = NULL;

    return success;
}

// Method-1 for removing the element
//  bool LinkedList::RemoveItem(int item)
//  {
//      bool success = true;
//      Node *temp = head;
//      while (temp->next != NULL && temp->data != item)
//      {
//          temp = temp->next;
//      }
//      swap(temp->data, temp->next->data);
//      Node *toBeDelete = temp->next;
//      temp->next = temp->next->next;
//      delete toBeDelete;

//     return true;
// }

// Method-2 for removing the item
bool LinkedList::RemoveItem(int item)
{
    bool success = true;
    Node *prev = head;
    Node *forward = head;

    while (forward != NULL && forward->data != item)
    {
        prev = forward;
        forward = forward->next;
    }
    if (forward->next != NULL)
    {
        prev->next = forward->next;
    }
    else
    {
        prev->next = NULL;
    }

    delete forward;

    return true;
}

bool LinkedList::FindItem(int item)
{
    bool success = false;
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == item)
        {
            cout << "Value exists" << endl;
            return true;
        }
        else
        {
            temp = temp->next;
        }
    }

    return success;
}

// bool LinkedList::FindMiddle()
// {
//     bool success = true;
//     Node *fast = head;
//     Node *slow = head;

//     while (fast!= NULL && fast->next!=NULL)
//     {
//         slow = slow->next;
//         fast = fast->next->next;
//     }
//     cout << "Middle Value is "<< slow->data << endl;
//     return success;
// }

bool LinkedList::FindMiddle()
{
    bool success = true;
    Node* temp = head;
    int count  = 0;
    while (temp!=NULL)
    {
       count++;
    }
    temp=head;
    while (count--)
    {
       temp=temp->next;
    }
    cout<<"The middle is: "<<temp->data;

    return success;
}

int main()
{
    LinkedList obj;
    int size;
    cout<<"Enter the size of linked list: ";
    cin>>size;
    int element;
    int item;
    int find1;
    for (int i = 0; i < size; i++)
    {
        cin >> element;
        obj.InsertInOrder(element);
        obj.Print();
        cout << "The middle value is: ";
        obj.FindMiddle();
    }
    cout << "Enter the element you want to remove: ";
    cin >> item;
    obj.RemoveItem(item);
    obj.Print();

    
    cout << "Enter the value you find: ";
    cin >> find1;
    obj.FindItem(find1);

   

    return 0;
}

void swap(int *a, int *b)
{

    int temp = *a;
    *a = *b;
    *b = temp;
}