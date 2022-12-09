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

    // HELPER FUNCITON DECLARATION
    bool InsertIntoBSTHelp(BNode *&root, int item);
    void PrintLevelOrderHelp(BNode *root, int level);
    int HeightOfTreeHelp(BNode *root);

public:
    bool InsertIntoBST(int item);
    void PrintInLevelOrder();
    int HeightOfTree();
};

BNode::BNode()
{
    left = right = nullptr;
}

BNode::BNode(int d)
{
    data = d;
    left = nullptr;
    right = nullptr;
}
BNode::BNode(int d, BNode *l, BNode *r)
{
    data = d;
    left = l;
    right = r;
}

bool BST::InsertIntoBSTHelp(BNode *&root, int item)
{
    bool success = false;
    if (root == NULL)
    {
        root = new BNode(item);
        success = true;
    }
    else
    {
        if (item < root->data)
        {
            success = InsertIntoBSTHelp(root->left, item);
        }
        else if (item > root->data)
        {
            success = InsertIntoBSTHelp(root->right, item);
        }
        else
        {
            cout << "DUPLICATED" << endl;
            success = false;
        }
    }

    return success;
}

bool BST::InsertIntoBST(int item)
{
    return InsertIntoBSTHelp(root, item);
}

void BST::PrintLevelOrderHelp(BNode *root, int level)
{

    if (root == NULL)
        return;

    if (level == 1)
        cout << root->data << "\t" << endl;

    PrintLevelOrderHelp(root->left, level - 1);
    PrintLevelOrderHelp(root->right, level - 1);
}

int BST::HeightOfTreeHelp(BNode *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int lh = HeightOfTreeHelp(root->left);
    int rh = HeightOfTreeHelp(root->right);

    return (1 + max(lh, rh));
}

int BST::HeightOfTree()
{
    return HeightOfTreeHelp(root);
}

void BST::PrintInLevelOrder()
{

    int heightOfTree = HeightOfTree();
    for (int i = 0; i < heightOfTree; i++)
    {
        PrintLevelOrderHelp(root, i + 1);
        cout << endl;
    }
}

Node *deleteFromBST(BNode *root,int item)
{
    if (root == null)
        return nullptr;

    if (root->data == item)
    {
        // 0
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return nullptr;
        }
        if (root->left != NULL && root->right == NULL)
        {
            BNode *temp = root->left;
            delete root;
            return temp;
        }
        if(root->left==NULL && root->right!=NULL){
            BNode* temp = root->right;
            delete root;
            return temp;
        }
        if(root->left!=NULL && root->right!=NULL){
            int mini = Getmin(root->right)->data;
            root->data = mini;
            root->right = deleteFromBST(root->right,mini);
        }
    }
    else if(root->data > item){
        root->left = deleteFromBST(root->left, item);
        return root;
    }
    else (root->data < item){
        root->right = deleteFromBST(root->right,item);
        return root;
    }
}

BNode *deleteFromBST(root, val)
{
    if (root == NULL)
        return root;

    if (root->data == val)
    {
        // 0 child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        // 1child
        if (root->left != NULL && root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        if (root->left == NULL && root->right != NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        // 2 child
        if (root->left != NULL && root->right != NULL)
        {
            int mini = miniValue(root->left)->data;
            root->val = mini;
            root->right = deleteFromBST(root->right, mini);
        }
    }
    else if (root->data > val)
    {
        root->left = deleteFromBST(root->left, val);
        return root;
    }
    else
    {
        root->right = deleteFromBST(root->right, val)
    }
}

int main()
{
    BST tree;
    cout << "'e";
    tree.InsertIntoBST(10);

    tree.InsertIntoBST(20);
    tree.InsertIntoBST(30);
    tree.InsertIntoBST(40);
    tree.PrintInLevelOrder();

    return 0;
}