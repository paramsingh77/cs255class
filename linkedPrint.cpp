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
    //~LinkedList();
    void Print() const;
    bool InsertList(int item);
    bool removeItem(int item);
    Node *FindItem(int item);
    // Node*  PrintReverse(Node* );
    int PrintAverage();
    void PrintAddOne();
    bool RemoveOddNode();
};

Node::Node() : next(nullptr) {}
Node::Node(int d) : data(d), next(nullptr) {}
Node::Node(int d, Node *n) : data(d), next(n) {}

LinkedList::LinkedList() : head(nullptr) {}

bool LinkedList::InsertList(int item)
{
    bool success = true;

    if (head == NULL || head->data > item)
        head = new Node(item, head);

    else
    {
        Node *prev = head;
        Node *forward = head;
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

void LinkedList::Print() const
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "\t";
        temp = temp->next;
    }
}

//   Node* LinkedList::PrintReverse(){
//     Node*c = head;
//     Node*p = nullptr;
//     Node*n = head->next;
//     if(head == NULL) return NULL;
//     while (c!=NULL)
//     {
//         c->next = p;
//          p = c;
//          c = n;
//          if (n->next != NULL)
//              n  = n->next;
//     }
//     return p;
// }

int LinkedList::PrintAverage()
{

    if (head->next == NULL)
        return head->data;

    if (head == NULL)
        return 0;

    Node *temp = head;
    int sum = 0;
    int count = 0;

    while (temp != NULL)
    {
        count++;
        sum += temp->data;
        temp = temp->next;
    }

    int avg = sum / count;
    return avg;
}

void LinkedList::PrintAddOne()
{
    Node *temp = head;
    int count = 1;
    while (temp != NULL)
    {
        temp->data = temp->data + 1;
        // or
        // temp->data +=1;
        temp = temp->next;
    }
}
bool LinkedList::RemoveOddNode()
{

    bool success = true;
    cout << "Entered" << endl;
    if (head == NULL)
    {
        delete head;
    }
    else
    {

        Node *prev = head;
        Node *forward = head;
        while (forward != NULL && forward->next != NULL)
        {
            prev = forward;
            forward = forward->next;
            if (forward->data % 2 != 0)
            {
                Node *temp = forward;
                forward = forward->next;
                prev->next = forward;
                delete temp;
            }
            
        }
    }
    return success;
}

int main()
{
    LinkedList list;
    // Node* head = list;
    list.InsertList(2);
    list.Print();
    cout << endl;
    list.InsertList(3);
    list.Print();
    cout << endl;
    list.InsertList(6);
    list.Print();
    cout << endl;
    list.InsertList(4);
    list.Print();
    cout << endl;
    list.InsertList(6);
    list.Print();
    cout << endl;
    list.InsertList(7);
    list.Print();
    cout << endl;
    list.InsertList(8);
    list.Print();
    cout << endl;
    list.InsertList(9);
    list.Print();
    cout << endl;
    cout << endl;
    // list.InsertList(0);
    // list.Print();
    cout << endl;
    // int ans = list.PrintAverage();
    // cout<<"Avg is: "<<ans;cout<<endl;
    // list.PrintAddOne();cout<<endl;
    // list.Print();cout<<endl;
    // cout<<"Removing odd Node is :"<<endl;
    list.RemoveOddNode();
    list.Print();
    cout << endl;
    return 0;
}