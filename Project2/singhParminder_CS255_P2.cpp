/************************************************************************************************************************************
Name - Parminder Singh
Project Number - 2
File Name : main.cpp
Project Description - In this project user can draw a picture on the board. User has many abilities in application. Using the if else     statement we can draw a X on board , erase X ,Undo the last move and displaying the final picture user made. This is a driver file in which all the functions will be used. In this user will be given option what operation they want to perform.

Course - CS-255
Instructor - Dr. Jenkins
*************************************************************************************************************************************/

#include "Canvas.h"

//***************************************************************
// Method declaration
//***************************************************************
void getMenu();
int getOperation();
int InputPos();

//***************************************************************
// Driver Function
//***************************************************************

int main()
{
    Canvas c1;
    int getValueForOperation = getOperation();

    // while loop-1
    while (getValueForOperation < 6)
    {
        if (getValueForOperation < 6)
        {

            if (getValueForOperation == 1)
            {
                int toPrintX = InputPos();

                // while loop-2
                while (toPrintX != 0)
                {
                    if (toPrintX <= DIM * DIM)
                    {
                        c1.DrawX(toPrintX);
                        c1.DrawBoard();
                        cout << "Enter the position you want to enter x or 0 to exit: ";
                        cin >> toPrintX;
                    }
                    else
                    {
                        cout << "Invalid operation....sorry" << endl;
                        cout << "Enter the value again: ";
                        cin >> toPrintX;
                    }
                } // end of while loop-2
            }
            else if (getValueForOperation == 2)
            {
                int toDelete;
                cout << "Enter the position where you want to delete or 0 to exit: ";
                cin >> toDelete;
                c1.eraseX(toDelete);
                c1.DrawBoard();
            }
            else if (getValueForOperation == 3)
                c1.Undo();

            else if (getValueForOperation == 4)
            {
                c1.Reset();
                c1.DrawBoard();
            }
            else if (getValueForOperation == 5)
                c1.DrawImage();
        }

        getMenu();

        cout << "Enter the Number of next operation: ";
        cin >> getValueForOperation;

        if (getValueForOperation == 0)
        {
            cout << endl
                 << endl;
            cout << "Thank you for playing GAME" << endl;
            break;
        }
    } // end of while loop-1
    return 0;
}
//***************************************************************
// Method definition
//***************************************************************

/***************************************************************************************
Function/method Name - getOperation
Function/method Description - This function will get the operation number from user and
                              return it.
Return Value - int
Incoming Parameters - None
Outgoing Parameters - None
***************************************************************************************/

int getOperation()
{
    getMenu();
    int getOpr;
    cout << "Enter the operation you want to operate: ";
    cin >> getOpr;
    return getOpr;
}

/***************************************************************************************
Function/method Name - getMenu
Function/method Description - This function will print the operations available.
Return Value - int
Incoming Parameters - None
Outgoing Parameters - None
***************************************************************************************/

void getMenu()
{
    cout << "******* OPERATIONS FOR THE GAME *******" << endl
         << endl;
    cout << "Enter 1 for Drawing X on board " << endl;
    cout << "Enter 2 for Erase X from board " << endl;
    cout << "Enter 3 for Undoing last board " << endl;
    cout << "Enter 4 for Reset the board " << endl;
    cout << "Enter 5 for Displaying Final Image " << endl;
    cout << "Enter 0 for Exiting the Game " << endl
         << endl;
    cout << "***************************************" << endl
         << endl
         << endl;
}

/***************************************************************************************
Function/method Name - InputPos
Function/method Description - This function will take the input from user where they want
                              to print the 'X'.
Return Value - int
Incoming Parameters - None
Outgoing Parameters - None
***************************************************************************************/

int InputPos()
{
    cout << endl
         << endl;
    int pos;
    cout << "Enter the position you want to enter x: ";
    cin >> pos;
    return pos;
}
