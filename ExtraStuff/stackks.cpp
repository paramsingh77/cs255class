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
    LinkedList(const LinkedList &right);
    ~LinkedList();
    bool InsertAtEnd(int item);
    bool InsertAtFront(int item);
    bool InsertInOrder(int item);
    bool RemoveLast();
    bool RemoveFirst();
    bool RemoveItem(int item);
    bool FindItem(int item);
    bool FindMiddle();
    bool ReverseLinkedList();
    LinkedList &operator=(const LinkedList &right);
    void Print() const;
};

Node::Node() : next(nullptr) {}
Node::Node(int d) : data(d), next(nullptr) {}
Node::Node(int d, Node *n) : data(d), next(n) {}

LinkedList::LinkedList() : head(nullptr) { cout << "List is working" << endl; }
LinkedList::~LinkedList()
{
    cout << "DESTRUCTING" << endl;
    while (head != nullptr)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    cout << "End of Deconstructor" << endl;
}

LinkedList::LinkedList(const LinkedList &right)
{
    if (right.head == nullptr)
        head = nullptr;
    else
    {
        Node *currRight = right.head;
        Node *currLeft = nullptr; // curleft points to node we just created
        this->head = new Node(currRight->data);
        currLeft = head;
        currRight = currRight->next;
        while (currRight != nullptr)
        {
            currLeft->next = new Node(currRight->data);
            currRight = currRight->next;
            currLeft = currLeft->next; // curleft points to node we just created
        }
    }
    cout << "PRINTING PARAMETER " << endl;
    right.Print();
    cout << endl;
    cout << "PRINTING CALLING OBJECT" << endl;
    this->Print();
    cout << endl;
}

// LinkedList &LinkedList::operator=(const LinkedList &right)
// {
//     cout << "Assignment operator" << endl;
//     if (this != &right)
//     {
//         if (head != nullptr)
//             delete head;

//         if (right.head == nullptr)
//             head = nullptr;
//         else
//         {
//             Node *currRight = right.head;
//             Node *currLeft = nullptr; // curleft points to node we just created
//             this->head = new Node(currRight->data);
//             currLeft = head;
//             currRight = currRight->next;
//             while (currRight != nullptr)
//             {
//                 currLeft->next = new Node(currRight->data);
//                 currRight = currRight->next;
//                 currLeft = currLeft->next; // curleft points to node we just created
//             }
//         }
//         cout << "PRINTING PARAMETER " << endl;
//         right.Print();
//         cout << endl;
//         cout << "PRINTING CALLING OBJECT" << endl;
//         this->Print();
//         cout << endl;
//     }
//     else
//     {
//         cout << endl;
//         cout << "Calling and passing object is same" << endl;
//     }
//     return *this;
// }

LinkedList &LinkedList::operator=(const LinkedList &right)  // we have a list to be copied as a parameter.
{
    if (this != &right) // this statement will check if the calling object and object should not be same
                        // in other words it will check the address of both the lists that they should not point to the same address
    {
        if (head != nullptr)  // it will check that if the calling object is pointing to any memory then it will be deleted for copying the data
        {
            delete head;       //delete the memory from heap.
        }

        if (right.head == nullptr)   //if passing object's doesn't have any data in the head then it will make the head of calling object as nullptr.
        {
            head = nullptr;
        }
        else
        {
            Node *currRight = right.head;   // here we are making the currRight which will be pointing to the head of passed object.
            Node *currLeft = nullptr;       //currLeft is a node for the calling object pointing to nullptr at inital point.
            currLeft = new Node(currRight->data); //For moving ahead we will make a head node for the calling object list.
            currLeft = head;    //we assigned head to the first node of calling object's list.
            currRight = currRight->next;  // here we will move right to it's next position.
            while (currRight != nullptr)      // we will initiate a loop which will iterate till the end of object as a parameter list.
            {
                currLeft->next = new Node(currRight->data); // we will make a new node in front of calling object list.
                currRight = currRight->next; //pointer to the node of passed object will move further by one node.
                currLeft = currLeft->next;   // pointer to the node of calling object will move further by one node.
            }
        }
    }
    else
    {
        cout << "Objects are same" << endl; // this statement will be printed if the called object and object in paratmer are same.
    }

    cout << "CALLING OBJECT" << endl; 
    this->Print();    //this->Print() will print the list of calling object
    cout << "OBJECY PARAMETER " << endl;
    right.Print();   //right.Print() will print the list of object as a paramter
    return *this; //this will return a list.
}

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
    cout << "Insert In Order " << endl;
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
    int count = 0;
    while (temp != NULL)
    {
        count++;
        if (temp->data == item)
        {
            cout << "Value exists at index :" << count << endl;
            return true;
        }
        else
        {
            temp = temp->next;
        }
    }

    return success;
}

bool LinkedList::FindMiddle()
{
    bool success = true;
    Node *fast = head;
    Node *slow = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    cout << "Middle Value is " << slow->data << endl;
    return success;
}

// bool LinkedList::FindMiddle()
// {
//     bool success = true;
//     Node* temp = head;
//     int count  = 0;
//     while (temp!=NULL)
//     {
//       count++;
//     }
//     temp=head;
//     int half = count/2;
//     while (half--)
//     {
//       temp=temp->next;
//     }
//     cout<<"The middle is: "<<temp->data;

//     return success;
// }

bool LinkedList::ReverseLinkedList()
{
    bool success = true;
    Node *prev = NULL, *curr = head, *n = head->next;

    while (curr != NULL)
    {
        curr->next = prev;
        prev = curr;
        curr = n;
        if (n != NULL)
            n = n->next;
    }

    while (prev != NULL)
    {
        cout << prev->data << "\t";
        prev = prev->next;
    }

    return success;
}

// bool LinkedList::ReverseLinkedList()
// {
//     bool success = true;
//     Node *prev = NULL, *curr = head, *forward = head->next;
//     while (curr != NULL)
//     {
//         curr->next = prev;
//         prev  = curr;
//         curr = forward;
//         if (forward != NULL)
//             forward = forward->next;
//     }

//     while (prev != NULL)
//     {
//         cout << prev->data << "\t";
//         prev = prev->next;
//     }

//     return true;
// }

LinkedList::LinkedList(const LinkedList& right){
    if(right.head == NULL)
        head == NULL;
    else{
        Node*rightCurr = right.head->data;
        Node*leftCurr =  new Node(rightCurr->data);
        
    }
}

int main()
{
    LinkedList obj;
    int size;
    cout << "Enter the size of linked list: ";
    cin >> size;
    int element;
    int item;
    int find1;
    for (int i = 0; i < size; i++)
    {
        cin >> element;
        obj.InsertInOrder(element);
        obj.Print();
    }
    //     cout << "The middle value is: ";
    //     obj.FindMiddle();
    // }
    // cout << "Enter the element you want to remove: ";
    // cin >> item;
    // obj.RemoveItem(item);
    // obj.Print();

    // find1 = 1;
    // while (find1 != 0)
    // {
    //     cout << "Enter the value you find: ";
    //     cin >> find1;
    //     obj.FindItem(find1);
    // }
    // cout << "Reverse Linked List is: " << endl;
    // obj.ReverseLinkedList();

    LinkedList obj2(obj);
    obj2 = obj;

    return 0;
}

void swap(int *a, int *b)
{

    int temp = *a;
    *a = *b;
    *b = temp;
}