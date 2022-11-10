#include <iostream>
using namespace std;

class BNode
{
    int data;
    BNode *left;
    BNode *right;
    BNode();
    BNode(int d);
    BNode(int d, BNode *l, BNode *r);
    friend class BST;
};

class BST
{
    BNode *root;
    bool InsertHelper(BNode *subroot, int item);
    bool PrintInOrderHelper(BNode *subroot);

public:
    BST();
    bool Insert(int item);
    void PrintInOrder() const;
};

BNode::BNode() : {}
BNode::BNode(int d) {}
BNode::BNode(int d, BNode *l, BNode *r) {}

bool BST::InsertHelper() {}
bool BST::InsertHelper(BNode *subroot, int item) {}
bool BST::PrintInOrderHelper(BNode *subroot) {}

int main()
{
    return 0;
}