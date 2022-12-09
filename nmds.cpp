/************************************************************/
// P6: Binary Search Tree Fun
// Author: Janet T. Jenkins
// Use this file as a starting file for Project 6
// You will need to add the appropriate functionality
// to the BST class in order to complete this work.
/************************************************************/

/*
    ***********************************************************
 Name: Ramneek Singh Matharu
 Course: CS-255
 Project 6: Binary Search Tree Fun
 About Project : For this project, you will use the file I provide you as a starter for a Binary Search Tree exercise. I am going to allow you
                to keep the BST header, definition, and the drivers in the same file for this project.
 Date: 11/30/2022
***********************************************************
*/
#include <iostream>
using namespace std;
class BNode
{
    int data;
    BNode *left;
    BNode *right;
    BNode();
    BNode(int);
    BNode(int, BNode *, BNode *);
    friend class BST;
};
BNode::BNode() { left = right = nullptr; }
BNode::BNode(int d)
{
    data = d;
    left = right = nullptr;
}
BNode::BNode(int d, BNode *l, BNode *r)
{
    data = d;
    left = l;
    right = r;
}
class BST
{
    // data member
    BNode *root;

    // helper methods
    bool InsertHelp(int e, BNode *&b);
    void PrintInOrderHelp(BNode *b) const;
    int CountHelper(BNode *b) const;
    int CountHeightHelper(BNode *b) const;
    void PrintInPostHelp(BNode *root) const;
    void PrintInPrerHelp(BNode *root) const;
    bool SearchInTreeHelp(int key, BNode *root);
    int GetSumHelp(BNode *root);
    int GetMinHelp(BNode *root);
    int GetMaxHelp(BNode *root);

public:
    BST();
    bool Insert(int e);
    void PrintInOrder() const;
    int Count() const;
    int CountHeight() const;
    void PrintInPost() const;
    void PrintInPre() const;
    bool SearchInTree(int);
    int GetAverage();
    int GetMin();
    int GetMax();
};
BST::BST() { root = nullptr; }
bool BST::InsertHelp(int e, BNode *&b)
{
    bool success = false;
    if (b == nullptr)
    {
        b = new BNode(e);
        success = true;
    }
    else
    {
        if (e < b->data)
            success = InsertHelp(e, b->left);
        else if (e > b->data)
            success = InsertHelp(e, b->right);
        else
        {
            cout << "NO DUPs" << endl;
            success = false;
        }
    }
    return success;
}
bool BST::Insert(int e) { return InsertHelp(e, root); }
void BST::PrintInOrderHelp(BNode *b) const
{
    if (b != nullptr)
    {
        PrintInOrderHelp(b->left);
        cout << b->data << "\t";
        PrintInOrderHelp(b->right);
    }
}
void BST::PrintInOrder() const
{
    cout << "<\t";
    PrintInOrderHelp(root);
    cout << ">" << endl;
}
int BST::CountHelper(BNode *b) const
{
    if (b != nullptr)
        return 1 + CountHelper(b->left) + CountHelper(b->right);
    else
        return 0;
}
int BST::Count() const { return CountHelper(root); }
int BST::CountHeightHelper(BNode *b) const
{
    if (b != nullptr)
    {
        return 1 + max(CountHeightHelper(b->left), CountHeightHelper(b->right));
    }
    else
        return 0;
}
int BST::CountHeight() const { return CountHeightHelper(root); }

//************************************************
// Function/method Name -  PrintInPostHelp
// Function/method Description - PrintPostHelpis taking the root node as a parameter
// and printing a tree in left right root manner.
// Return Value - no rturn values due to void
// Incoming Parameters - BNode root
//************************************************

void BST::PrintInPostHelp(BNode *root) const
{
    if (root == NULL)
        return;

    PrintInPostHelp(root->left);
    PrintInPostHelp(root->right);
    cout << root->data << "\t";
}

//************************************************
// Function/method Name -  PrintInPrerHelp
// Function/method Description - PrintInPrerHelp taking the root node as a parameter
// and printing a tree in root left right manner.
// Return Value - no rturn values due to void
// Incoming Parameters - BNode root
//************************************************

void BST::PrintInPrerHelp(BNode *root) const
{

    if (root == NULL)
        return;

    cout << root->data << "\t";
    PrintInPrerHelp(root->left);
    PrintInPrerHelp(root->right);
}

//************************************************
// Function/method Name -  SearchInTreeHelp
// Function/method Description - SearchInTreeHelp it will find the value that the user is looking for
// Return Value - it will return success true/false
// Incoming Parameters - int key,BNode root
//************************************************

bool BST::SearchInTreeHelp(int key, BNode *root)
{

    if (root == NULL)
    {
        return false;
    }
    bool success = false;
    while (root != NULL)
    {

        if (key < root->data)
        {
            root = root->left;
        }
        else if (key > root->data)
        {
            root = root->right;
        }
        else
        {
            success = true;
            break;
        }
    }

    return success;
}

//************************************************
// Function/method Name -  GetSumHelp
// Function/method Description - GetSumHelp it will calculate the values by adding them
// Return Value - it will return AverageOfNodes
// Incoming Parameters - BNode root
//************************************************

int BST::GetSumHelp(BNode *root)
{

    if (root == NULL)
    {
        return 0;
    }

    int sumOfNodes = (root->data + GetSumHelp(root->left) + GetSumHelp(root->right));
    return sumOfNodes;
}

//************************************************
// Function/method Name -  GetMinHelp
// Function/method Description - GetMinHelp it will find the minimum value in the tree
// Return Value - it will return root->data
// Incoming Parameters - BNode root
//************************************************

int BST::GetMinHelp(BNode *root)
{
    if(root == nullptr)
        return INT16_MAX;

    while (root->left != NULL)
    {
        root = root->left;
    }
    return (root->data);
}

//************************************************
// Function/method Name -  GetMaxHelp
// Function/method Description - GetMaxHelp it will find the maximum value in the tree
// Return Value - it will return root->data
// Incoming Parameters - BNode root
//************************************************

int BST::GetMaxHelp(BNode *root)
{   
    if(root == nullptr)
        return INT16_MIN;

    while (root->right != NULL)
    {
        root = root->right;
    }
    return (root->data);
}

//************************************************
// Function/method Name -  PrintInPost
// Function/method Description - PrintInPost it will postfix the values
// Return Value - it will return PrintInPostHelp
// Incoming Parameters - NA
//************************************************
void BST::PrintInPost() const
{
    PrintInPostHelp(root);
}

//************************************************
// Function/method Name -  PrintInPre
// Function/method Description - PrintInPre it will prefix the values
// Return Value - it will return PrintInPrerHelp
// Incoming Parameters - NA
//************************************************

void BST::PrintInPre() const
{
    PrintInPrerHelp(root);
}

//************************************************
// Function/method Name -  SearchInTree
// Function/method Description - SearchInTree it will find the value in the tree
// Return Value - it will return SearchInTreeHelp
// Incoming Parameters - int data
//************************************************

bool BST::SearchInTree(int data)
{
    return SearchInTreeHelp(data, root);
}

//************************************************
// Function/method Name -  GetAverage
// Function/method Description - GetAverage it will calculat the average
// Return Value - it will return GetSumHelp
// Incoming Parameters - NA
//************************************************

int BST::GetAverage()
{
    int sumOfNodes = GetSumHelp(root);
    int CountOfNodes = Count();

    int AverageOfNodes = sumOfNodes / CountOfNodes;
    return AverageOfNodes;
}

//************************************************
// Function/method Name -  GetMin
// Function/method Description - GetMin it will find the minimum value in the tree
// Return Value - it will return GetMinHelp
// Incoming Parameters - NA
//************************************************

int BST::GetMin()
{
    return GetMinHelp(root);
}

//************************************************
// Function/method Name -  GetMax
// Function/method Description - GetMax it will find the minimum value in the tree
// Return Value - it will return GetMaxHelp
// Incoming Parameters - NA
//************************************************

int BST::GetMax()
{
    return GetMaxHelp(root);
}

void menu()
{
    cout << "+ x - Insert x into the BST" << endl;
    cout << "i - Print the BST inorder" << endl;
    cout << "r - Print the BST preorder" << endl;
    cout << "o - Print the BST postorder" << endl;
    cout << "? x - Search for x in the BST" << endl;
    cout << "c - Print the item count in the BST" << endl;
    cout << "h - Print the height of the BST" << endl;
    cout << " a - Print the average of the values in the BST" << endl;
    cout << "< - Print the minimum value in the BST" << endl;
    cout << "> - Print the maximum value in the BST" << endl;
    cout << "m - Print menu" << endl;
    cout << "q - Quit" << endl;
}

int main()
{
    BST tree;
    char choice = 'q';

    menu();
    cin >> choice;

    while (choice != 'q')
    {
        if (choice == '+')
        {
            int input;
            cin >> input;
            tree.Insert(input);
        }
        else if (choice == 'i')
            tree.PrintInOrder();

        else if (choice == 'r')
            tree.PrintInPre();

        else if (choice == 'o')
            tree.PrintInPost();

        else if (choice == '?')
        {
            int input;
            cin >> input;
            if (tree.SearchInTree(input))
            {
                cout << "Item is present" << endl;
            }
            else
            {
                cout << "Not present" << endl;
            }
        }
        else if (choice == 'c')
            cout << "There are " << tree.Count() << " items in the tree" << endl;

        else if (choice == 'h')
            cout << "The height of this tree is " << tree.CountHeight() << "." << endl;

        else if (choice == 'a')
            cout << tree.GetAverage() << endl;

        else if (choice == '<')
            cout << tree.GetMin() << endl;

        else if (choice == '>')
            cout << tree.GetMax() << endl;

        else if (choice == 'm')
            menu();

        else
        {
            cout << "Invalid instruction" << endl;
            menu();
        }

        cout << "-------------------------------------------------" << endl;
        tree.PrintInOrder();
        cout << "-------------------------------------------------" << endl;
        cin >> choice;
    }
    return 0;
}
