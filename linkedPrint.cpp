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
    bool RemoveEvenNode();
    bool ReverseArray();
    void PrintList();
};

PrintReverse()
{
    if(head == NULL)
        reutrn nullptr;

    if(head->next == NULL){
        return head;
    }

    Node* newNode = PrintReverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return newNode;
}

// bool LinkedList::InsertList(int item)
// {
//     bool success = true;

//     if (head == NULL || head->data > item)
//         head = new Node(item, head);

//     else
//     {
//         Node *prev = head;
//         Node *forward = head;
//         while (forward != NULL && forward->data < item)
//         {
//             prev = forward;
//             forward = forward->next;
//         }
//         Node *newNode = new Node(item);
//         newNode->next = prev->next;
//         prev->next = newNode;
//     }
//     return success;
// }

LinkedList::LinkedList(const LinkedList& right){
    if(right.head == NULL)
        head = NULL;
    else{
        head = new Node(right.head->data);
        Node *rightCurr = right->next;
        Node *leftCurr = head;
        while (rightCurr!=nullptr)
        {
            leftCurr->next = new Node(right->data);
            rightCurr = rightCurr->next;
            leftCurr=leftCurr->next;
        }
        
    }

    if(head == NULL)
    head = nullptr;
    else{
        head = new Node(right.head->data);
        Node* leftCurr = head;
        Node* rightCurr = rightCurr->next;
        while (rightCurr!=nullptr)
        {
            leftCurr->next = new Node(right->data);
            rightCurr = rightCurr->next;
            leftCurr=leftCurr->next;
        }
        
    }
}
LinkedList::~LinkedList(){
  
  while (head!=nullptr)
  {
    Node*temp = head;
    head = head->next;
    delete temp;
  }
  
    
}
bool LinkedList::InsertList(int item)
{
    bool success = true;
    if (head == NULL || head->data > item)
    {
        head = new Node(item, head);
    }
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

    if (head == NULL)
    {
        delete head;
    }
    else
    {
        if (head != NULL)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
        Node *evenNode = head;
        Node *oddNode = head->next;
        while (evenNode != NULL && oddNode != NULL)
        {
            evenNode->next = oddNode->next;
            delete oddNode;

            evenNode = evenNode->next;

            // if(evenNode!=NULL)
            oddNode = evenNode->next;
        }
    }

    return success;
}

bool LinkedList::RemoveEvenNode()
{
    bool success = true;

    if (head == NULL)
    {
        delete head;
    }
    else
    {
        Node *oddNode = head;
        Node *evenNode = head->next;
        while (oddNode != NULL && evenNode != NULL)
        {
            oddNode->next = evenNode->next;
            delete evenNode;
            oddNode = oddNode->next;
            if (oddNode != NULL)
                evenNode = oddNode->next;
        }
    }

    return success;
}

bool LinkedList::ReverseArray(Node *head)
{
    bool success = true;

    if (head->next == NULL)
        return head;

    Node *newHead = ReverseArray(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
    return success;
}

void LinkedList::PrintList(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    Node *temp = head;
    cout << temp->data;
    PrintList(head->next);
}

void LinkedList::Print(){
    if(head == NULL)
        return;
    Node* temp = head;
    cout<<temp->data;
    PrintList(temp->next);
}

void LinkedList::PrintReverse(){
    if(head == NULL)
        return;
    Node*temp = head;
    PrintReverse(temp->next);
    cout<<temp->data<<endl;
}

if(head->next == NULL)
    return head;

Node* newNode = PrintReverse(head->next);
head->next->next = head;
head->next = NULL;
return newNode;


bool LinkedList::RemoveOddNode(){
    if(head == NULL)
        return nullptr;
    else{
        while(head->data%2 != 0){
            Node*temp = head;
            head = head->next;
            delete temp;
        }
        Node* forward = head->next;
        Node* prev = head;
        while (forward!=NULL && forward->next!=NULL)
        {
            if(forward->data %2!=0){
                Node* temp = forward;
                forward = forward->next;
                delete temp;
            }
            else{
                prev = forward;
                forward = forward->next;
            }
        }
        
    }
}

bool LinkedList::RemoveOddNode()
{
    bool success = true;

    if (head == NULL)
        delete head;

    else
    {
        if(head!=nullptr){
            while (head->data % 2 == 0)
            {
                Node *temp = head;
                head = head->next;
                delete temp;
            }
            Node *forward = head;
            Node *prev = head;
            while (forward != NULL && forward->next != NULL)
            {
                if (forward->data % 2 != 0)
                {
                    Node *temp = forward;
                    forward = forward->next;
                    prev->next = forward;
                    delete temp;
                }
                else{
                    prev = forward;
                    forward = forward->next;
                }
            }
        }
      
    }
    return success;
}

int main()
{
    LinkedList list;
    // Node* head = list;
    list.InsertList(1);
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
    list.RemoveEvenNode();
    list.Print();
    cout << endl;
    return 0;
}