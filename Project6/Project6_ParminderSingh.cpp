/********************************************************************************
/Name : Parminder Singh
Project Number : 6
File Name : Project6_ParminderSingh.cpp
Project Description : This project focuses on the different operations which can
be perform on binary search tree. In this project we will have class of BST which
will have all the headers.
Course : CS255-01
Instructor:Janet T. Jenkins
*********************************************************************************/

/********************************************************************************/
/*************************CLASS DECLARATION**************************************/
/********************************************************************************/

#include <iostream>
using namespace std;

/***Class BNode***/
class BNode
{
    // data members
    int data;
    BNode *left;
    BNode *right;

    // helper methods
    BNode();
    BNode(int);
    BNode(int, BNode *, BNode *);
    friend class BST;
};

/***Class BST***/
class BST
{
    // data member
    BNode *root;

    // helper methods
    bool InsertHelp(int e, BNode *&b);
    void PrintInOrderHelp(BNode *b) const;
    int CountHelper(BNode *b) const;
    int CountHeightHelper(BNode *b) const;
    void PrintInPreOrderHelp(BNode *b) const;
    void PrintInPostOrderHelp(BNode *b) const;
    bool SearchInTreeHelp(BNode *b, int item) const;
    int GetAvgHelp(BNode *b);
    int FindMinHelper(BNode *b);
    int FindMaxHelper(BNode *);
    //void PrintLevelOrderHelp(BNode*root , int level);

public:
    BST();
    bool Insert(int e);
    void PrintInOrder() const;
    void PrintInPostOrder();
    int Count() const;
    int CountHeight() const;
    void PrintPreOrder() const;
    bool SearchInTree(int item) const;
    int GetAvergae();
    int FindMin();
    int FindMax();
    // void PrintInLevelOrder()const;
};
void menu();

/********************************************************************************/
/**************************MAIN FUNCTION******************************************/
/********************************************************************************/

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
            tree.PrintPreOrder();
        else if (choice == 'o')
            tree.PrintInPostOrder();
        else if (choice == '?')
        {
            int input;
            cin >> input;
            if (tree.SearchInTree(input))
            {
                cout << input << " exists in the tree" << endl;
            }
            else
            {
                cout << input << " dosen't exist in the tree " << endl;
            }
        }
        else if (choice == 'c')
            cout << "There are " << tree.Count() << " items in the tree" << endl;
        else if (choice == 'h')
            cout << "The height of this tree is " << tree.CountHeight() << "."
                 << endl;
        else if (choice == 'a')
        {
            int avg = tree.GetAvergae();
            cout << "Average of tree is: " << avg << endl;
        }
        else if (choice == '<')
        {
            int ans = tree.FindMin();
            cout << "The Minimum value in tree is: " << ans << endl;
        }
        else if (choice == '>')
        {
            int ans = tree.FindMax();
            cout << "The Maximum Value in tree is: " << ans << endl;
        }
        // else if (choice == '5')
        // {
        //    tree.PrintInLevelOrder();
        // }
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

/***********************************************************/
/*******************FUNCTION DEFINITION*******************/
/***********************************************************/

/***************************************************************************************************
Function/method Name - BNode()
Function/method Description - It is a defualt constructor which will put the left and node value to zero.
Return Value - NA
Incoming Parameters - NA
Outgoing Parameters - NA
***************************************************************************************************/

BNode::BNode() { left = right = nullptr; }

/***************************************************************************************
Function/method Name - BNode()
Function/method Description - It is a parametrized constructor which will take the data
and put the right and left to nullptr.
Return Value - NA
Incoming Parameters - integer data
Outgoing Parameters - NA
****************************************************************************************/
BNode::BNode(int d)
{
    data = d;
    left = right = nullptr;
}

/***************************************************************************************
Function/method Name - BNode()
Function/method Description - It is a defualt constructor which will take the parameter data and left and right paramter put the left and node value to zero.
Return Value - NA
Incoming Parameters - integer data, left node and right node
Outgoing Parameters - N/A
****************************************************************************************/
BNode::BNode(int d, BNode *l, BNode *r)
{
    data = d;
    left = l;
    right = r;
}

/***************************************************************************************
Function/method Name - BST
Function/method Description - It is a defualt constructor which will put the left and node value to zero.
Return Value - NA
Incoming Parameters - NA
Outgoing Parameters - NA
****************************************************************************************/
BST::BST()
{
    root = nullptr;
}

/***************************************************************************************
Function/method Name - Insert
Function/method Description - This function call the InsertHelp and put the data value into
the function.
Return Value - InsertHelp function.
Incoming Parameters - integer data.
Outgoing Parameters - NA
****************************************************************************************/
bool BST::Insert(int e) { return InsertHelp(e, root); }

/// HELPER FUNCTION DEFINITION

/***************************************************************************************
Function/method Name - PrintInPreOrderHelp
Function/method Description - This function will take the root node as a parameter and
will traverse the tree in PreOrder manner i.e is root left right.
Return Value - NA
Incoming Parameters - NA
Outgoing Parameters - NA
****************************************************************************************/
void BST::PrintInPreOrderHelp(BNode *b) const
{
    if (b == nullptr)
        return;

    // PrintInPreOrderHelp(b->data);
    cout << b->data << "\t";
    PrintInPreOrderHelp(b->left);
    PrintInPreOrderHelp(b->right);
}

/***************************************************************************************
Function/method Name - PrintInPostOrderHelp
Function/method Description - This function will take the root node as a parameter and
will traverse the tree in PostOrder manner i.e is left right root.
Return Value - NA
Incoming Parameters - root node.
Outgoing Parameters - NA
****************************************************************************************/

void BST::PrintInPostOrderHelp(BNode *b) const
{
    if (b != nullptr)
    {
        PrintInPostOrderHelp(b->left);
        PrintInPostOrderHelp(b->right);
        cout << b->data << "\t";
    }
}

/***************************************************************************************
Function/method Name - SearchInTreeHelp
Function/method Description - This function will take the root node and value to be searched
as a parameter and it will traverse whole tree if the value will be present then it will return
true or false.
will traverse the tree and find out the
Return Value - boolean value success.
Incoming Parameters - root node and integer item
Outgoing Parameters - NA
****************************************************************************************/

bool BST::SearchInTreeHelp(BNode *b, int item) const
{
    if (b == NULL)
        return false;

    bool success = false;
    while (b != NULL)
    {
        if (item < b->data)
            b = b->left;

        else if (item > b->data)
            b = b->right;
        else
        {
            success = true;
            break;
        }
    }
    return success;
}
/*********************************************************************************
Function/method Name - counterHelper.
Function/method Description - This function will take the root as a parameter and will make
the recursive call to both the left and right childern of root and will return the count of
nodes.

Return Value - NA
Incoming Parameters - root node
Outgoing Parameters - NA
****************************************************************************************/
int BST::CountHelper(BNode *b) const
{
    if (b != nullptr)
        return 1 + CountHelper(b->left) + CountHelper(b->right);
    else
        return 0;
}

/***************************************************************************************
Function/method Name - PrintInOrderHelp()
Function/method Description - This function is a helper function which takes the root as
paramter and print the tree in InOrder type.
Return Value - NA
Incoming Parameters - root.
Outgoing Parameters - NA
****************************************************************************************/
void BST::PrintInOrderHelp(BNode *b) const
{
    if (b != nullptr)
    {
        PrintInOrderHelp(b->left);
        cout << b->data << "\t";
        PrintInOrderHelp(b->right);
    }
}

/***********************************************************************************************
Function/method Name - InsertHelp
Function/method Description - This function will take the parameter as root and item which is to
be inserted.
Return Value - N/A
Incoming Parameters - integer item and root
Outgoing Parameters - NA
************************************************************************************************/

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

/*****************************************************************************************************
Function/method Name - FindMinHelper
Function/method Description - This function will take the go to the extreme right of tree. As it is a binary search tree so the biggest value will be at extreme right of tree. So it will return that value.
Return Value - return day
Incoming Parameters - NA
Outgoing Parameters - NA
******************************************************************************************************/

int BST::FindMinHelper(BNode *b)
{

    if (b == nullptr)
        return INT16_MAX;
    while (b->left != NULL)
        b = b->left;

    return (b->data);
}

/****************************************************************************************************
Function/method Name - FindMaxHelper
Function/method Description - This function will take the root node as a parameter will traverse whole tree. It will make a max variable first then it will compare the values of nodes. If value is
equal then it will return the value.
Return Value - NA
Incoming Parameters - NA
Outgoing Parameters - NA
****************************************************************************************************/

int BST::FindMaxHelper(BNode *b)
{
    if (b == nullptr)
        return INT16_MIN;
    while (b->right != NULL)
        b = b->right;

    return (b->data);
}

/****************************************************************************************************
Function/method Name - CountHeightHelper
Function/method Description - This function will be act as a helper to the the countHeight function.It will recursively call the left and right heights of the tree and will return the heights.
Return Value - NA
Incoming Parameters - NA
Outgoing Parameters - NA
****************************************************************************************************/

int BST::CountHeightHelper(BNode *b) const
{
    if (b != nullptr)
    {
        return 1 + max(CountHeightHelper(b->left), CountHeightHelper(b->right));
    }
    else
        return 0;
}

/****************************************************************************************************
Function/method Name - GetAvgHelp
Function/method Description - This function will calculate the sum of all the nodes by recursive calls
to both the left and right project.
Return Value - return the sum of all the nodes by recurive calls.
Incoming Parameters - NA
Outgoing Parameters - NA
****************************************************************************************************/
int BST::GetAvgHelp(BNode *b)
{
    int sum = 0;
    if (b == nullptr)
        return 0;
    return (b->data + GetAvgHelp(b->left) + GetAvgHelp(b->right));
}

/****************************************************************************************************
Function/method Name - GetAverage
Function/method Description - This function will call the average function which will return the sum of all the nodes. And count function will return the total number of nodes. Then it will divide both sum and count and will return average.
Return Value - NA
Incoming Parameters - return average
Outgoing Parameters - NA
****************************************************************************************************/

int BST::GetAvergae()
{
    int sum = GetAvgHelp(root);
    int count = Count();
    int avg = sum / count;
    return avg;
}

/****************************************************************************************************
Function/method Name - PrintInPreOrder
Function/method Description - This function will be call the PrintPreOrderHelp function will and print the pre order traversal of tree.
Return Value - NA
Incoming Parameters - NA
Outgoing Parameters - NA
****************************************************************************************************/

void BST::PrintPreOrder() const
{
    cout << "<\t";
    PrintInPreOrderHelp(root);
    cout << ">" << endl;
}

/****************************************************************************************************
Function/method Name - PrintInPostOrder
Function/method Description - this will function will call the PrintInPostOrderHelp function and will
call the root and traverse it.
Return Value - NA
Incoming Parameters - NA
Outgoing Parameters - NA
****************************************************************************************************/

void BST::PrintInPostOrder()
{
    cout << "<\t";
    PrintInPostOrderHelp(root);
    cout << ">" << endl;
}

/***************************************************************************************
Function/method Name - PrintInOrder
Function/method Description - This functions call the PrintInOrderHelp and print out the
traversal in print order.
Return Value - NA
Incoming Parameters - NA
Outgoing Parameters - NA
****************************************************************************************/
void BST::PrintInOrder() const
{
    cout << "<\t";
    PrintInOrderHelp(root);
    cout << ">" << endl;
}

/****************************************************************************************************
Function/method Name - SearchInTree
Function/method Description - this will function will call the PrintInPostOrderHelp function and will
pass the value to be searched and if it is present then it will return true else false.
Return Value - NA
Incoming Parameters - NA
Outgoing Parameters - NA
****************************************************************************************************/
bool BST::SearchInTree(int item) const
{
    return SearchInTreeHelp(root, item);
}

/****************************************************************************************************
Function/method Name - FindMin
Function/method Description - this function will call tehe FindMinHelper function and will return the
value.
Return Value - return the value from the FindMinHelper function.
Incoming Parameters - NA
Outgoing Parameters - NA
****************************************************************************************************/
int BST::FindMin()
{
    return FindMinHelper(root);
}

/****************************************************************************************************
Function/method Name - FindMax
Function/method Description - this function will call tehe FindMaxHelper function and will return the
value from the FindMaxHelper function.
Return Value - return the value from the FindMinHelper function.
Incoming Parameters - NA
Outgoing Parameters - NA
****************************************************************************************************/

int BST::FindMax()
{
    return FindMaxHelper(root);
}

/****************************************************************************************************
Function/method Name - Count
Function/method Description - This function will call the CountHelper the function. This function will return the CountHelper function which will return the count of nodes.
Return Value - return the value from the CountHelper function.
Incoming Parameters - NA
Outgoing Parameters - NA
****************************************************************************************************/

int BST::Count() const
{
    return CountHelper(root);
}

/****************************************************************************************************
Function/method Name - CountHeight
Function/method Description - CountHeight function will call the CountHeightHelper function. and it will return the count the height of tree.
Return Value - return the height of binary search tree.
Incoming Parameters - NA
Outgoing Parameters - NA
****************************************************************************************************/

int BST::CountHeight() const { return CountHeightHelper(root); }

/****************************************************************************************************
Function/method Name - menu
Function/method Description - This function will print the menu of the  tree.
Return Value - NA
Incoming Parameters - NA
Outgoing Parameters - NA
****************************************************************************************************/

// void BST::PrintLevelOrderHelp(BNode* root ,int level){

//         if(root == NULL)
//             return;
        
//         if(level == 1){
//             cout<<root->data<<"\t";
//         }

//         PrintLevelOrderHelp(root->left,level-1);
//         PrintLevelOrderHelp(root->right,level-1);

// }

// void BST::PrintInLevelOrder(){

//     int heightOfTree = CountHelper(root);
//     for(int i = 0 ; i <= heightOfTree ; i++){
//         PrintLevelOrderHelp(root,i+1);
//     }

// }
void  menu()
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


// bool BST::Insert(BNode* root,int data){
//     bool success = false;
//     if(root == NULL){
//         root = new BNode(data);
//         success  = true;
//     }

//     if(data <= root->data){
//         success = Insert(root->left);
//     }
//     else if(data > root->data){
//         success = Insert(root->right);
//     }
//     else{
//         cout<<"NO-DUPS"<<endl;
//         success  = false;
//     }

//     return success;
// }