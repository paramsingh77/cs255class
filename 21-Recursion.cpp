LinkedList &LinkedList::operator=(const LinkedList &right) // we have a list to be copied as a parameter.
{
    if (this != &right) // this statement will check if the calling object and object should not be same
    // in other words it will check the address of both the lists that they should not point to the same address
    {
        if (head != nullptr) // it will check that if the calling object is pointing to any memory then it will be deleted for copying the data
        {
            delete head; // delete the memory from heap.
        }

        if (right.head == nullptr) // if passing object's doesn't have any data in the head then it will make the head of calling object as nullptr.
        {
            head = nullptr;
        }
        else
        {
            Node *currRight = right.head;         // here we are making the currRight which will be pointing to the head of passed object.
            Node *currLeft = nullptr;             // currLeft is a node for the calling object pointing to nullptr at inital point.
            head = new Node(currRight->data); // For moving ahead we will make a head node for the calling object list.
            currLeft = head;                      // we assigned head to the first node of calling object's list.
            currRight = currRight->next;          // here we will move right to it's next position.
            while (currRight != nullptr)          // we will initiate a loop which will iterate till the end of object as a parameter list.
            {
                currLeft->next = new Node(currRight->data); // we will make a new node in front of calling object list.
                currRight = currRight->next;                // pointer to the node of passed object will move further by one node.
                currLeft = currLeft->next;                  // pointer to the node of calling object will move further by one node.
            }
        }
    }
    else
    {
        cout << "Objects are same" << endl; // this statement will be printed if the called object and object in the                                                                                    parameter are same.
    }

    cout << "CALLING OBJECT" << endl;
    this->Print(); // this->Print() will print the list of calling object
    cout << "OBJECY PARAMETER " << endl;
    right.Print(); // right.Print() will print the list of object as a paramter
    return *this;  // this will return a list.
}