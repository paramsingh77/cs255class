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
    bool InsertHelper(BNode *&subroot, int item);
    void PrintInOrderHelper(BNode *subroot) const;

public:
    BST();
    bool Insert(int item);
    void PrintInOrder() const;
};

BNode::BNode() : left(nullptr), right(nullptr) {}
BNode::BNode(int d) : data(d), left(nullptr), right(nullptr) {}
BNode::BNode(int d, BNode *l, BNode *r) : data(d), left(nullptr), right(nullptr) {}

BST::BST() : root(nullptr) {}

bool BST:: InsertHelper(BNode *&subroot, int item)
{
    // insert at root
    if (subroot == nullptr)
    {
        subroot = new BNode(item, nullptr, nullptr);
        return true;
    }
    else if (item == subroot->data)
    { // don't insert if duplicate
        cout << "NO DUPLICATES" << endl;
        return false;
    }
    else if (item < subroot->data) // insert to the left of node
    {
        InsertHelper( subroot->left, item);
    }
    else
    { // insert to the right of node
        InsertHelper(item, subroot->right, item);
    }
}

bool BST::Insert(int item)
{
    return InsertHelper(root,item);
}

bool BST::PrintInOrderHelper(BNode *&subroot) const
{

    if (subroot != nullptr)
    {
        // recurse the left subtree
        PrintInOrderHelper(subroot->left);
        // print the root
        cout << subroot->data << "\t";
        // recurse the right subtree
        PrintInOrder(subroot->right);
    }
    // print the root
    // recurse the right subtree
}
void BST::PrintInOrder() const
{
    cout << "<\t ";
    PrintInOrderHelper(root);
    cout << " >";
}

int main()
{
    BST b;
    b.Insert(50);
    b.PrintInOrder();cout<<endl;
    b.Insert(25);
    b.PrintInOrder();
    cout << endl;
    b.Insert(75);
    b.PrintInOrder();
    cout << endl;
    return 0;
}