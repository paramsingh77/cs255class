#include <iostream>
using namespace std;

class Node
{
    int data;
    Node *next;

    Node();
    Node(int d);
    Node(int d, int *n);
    friend class LinkedList;
};

class LinkedList
{
    Node *head;

public:
    LinkedList();
    bool Insert(int item);
    bool removeItem(int item);
    void Print()const;
};

Node::Node():next(nullptr){}
Node::Node(int d):data(d),next(nullptr){}
Node::Node(int d, int* n):data(d),next(n){}

LinkedList::LinkedList():head(nullptr){}
bool LinkedList::Insert(int item){
    bool success = true;
    head = new Node(item,head);

    return success;
}
int main()
{
    return 0;
}