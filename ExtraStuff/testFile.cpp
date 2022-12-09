#include<iostream>
using namespace std;

class Node
{
    int data;
    Node *next;
    Node() : next(NULL) {}
    Node(int d) : data(d), next(NULL) {}
    Node(int d, Node *n) : data(d), next(n) {}
    friend class LinkedList;
};
class LinkedList
{
    Node *head;

public:
    LinkedList() : head(NULL) {}
    void ReviewMethod(int item)
    {
        head = new Node(item, head);
        Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = new Node(item, NULL);
    }
    void Print() const
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "\t";
            temp = temp->next;
        }
    }
};
int main()
{
    LinkedList obj;
    obj.ReviewMethod(60);
    obj.Print();
    cout << endl;
    obj.ReviewMethod(1111);
    obj.Print();
    cout << endl;
    obj.ReviewMethod(30);
    obj.Print();
    cout << endl;
    return 0;
}

