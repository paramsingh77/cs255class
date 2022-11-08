/*********************************************************************************************************
Name - Parminder Singh
Project Number - 2
File Name : Canvas.cpp
Project Description - Canvas.h file have all the function and class definitions. In this all the methods will be implemented as per the game requirements.
Course - CS-255
Instructor - Dr. Jenkins
*********************************************************************************************************/

#include "Canvas.h"

//***************************************************************
// class definition/ implementation
//***************************************************************

//***************************************************************
// Constructor
//***************************************************************
Canvas ::Canvas()

{

    cout << endl
         << endl;
    cout << "************ SAMPLE BOARD ************" << endl
         << endl;
    int i = 0;
    for (int r = 0; r < DIM; r++)
    {
        for (int c = 0; c < DIM; c++)
        {
            board[r][c] = (++i);
            cout << board[r][c] << "\t";
        }
        cout << endl;
    }
    cout << "**************************************" << endl
         << endl;
    cout << endl
         << endl
         << endl;
}

//***************************************************************
// Other Methods
//***************************************************************

/***************************************************************************************
Function/method Name - DrawBoard
Function/method Description - This function will print the board with the numbers
                              and 'X' according to function with it will be implemented.
Return Value - None
Incoming Parameters - None
Outgoing Parameters - None
***************************************************************************************/

void Canvas::DrawBoard() const
{
    // loop-1
    for (int r = 0; r < DIM; r++)
    {
        // loop-2
        for (int c = 0; c < DIM; c++)
        {
            if (board[r][c] == 99)
                cout << "X"
                     << "\t";
            else
                cout << board[r][c] << "\t";
        } // end of loop-2
        cout << endl;
    } // end of loop-1
    cout << endl
         << endl;
}

/***************************************************************************************
Function/method Name - DrawImage
Function/method Description - This function will print the board with the final image of
                              board after the user has implemented all operations with "_"
                              and "X".
Return Value - None
Incoming Parameters - None
Outgoing Parameters - None
***************************************************************************************/

void Canvas::DrawImage() const
{
    cout << endl
         << endl;
    cout << "     FINAL IMAGE OF DRAWBAORD" << endl;

    // loop-1
    for (int r = 0; r < DIM; r++)
    {
        // loop-2
        for (int c = 0; c < DIM; c++)
        {
            if (board[r][c] == 99)
                cout << "X"
                     << "\t";
            else
                cout << "_"
                     << "\t";
        } // end of loop-2
        cout << endl;
    } // end of loop-1
    cout << endl
         << endl
         << endl
         << endl;
}

/***************************************************************************************
Function/method Name - Reset
Function/method Description - This function will Reset the board to the initil values with
                              from starting.
Return Value - None
Incoming Parameters - None
Outgoing Parameters - None
***************************************************************************************/

void Canvas::Reset()
{
    int i = 0;
    for (int r = 0; r < DIM; r++)
    {
        for (int c = 0; c < DIM; c++)
        {
            board[r][c] = i++;
        } // end of loop
        cout << endl;
    }
}

/***************************************************************************************
Function/method Name - DrawX
Function/method Description - This Function will take the position as a parameter and will
                              print "X" at that position.
Return Value - None
Incoming Parameters - position
Outgoing Parameters - None
***************************************************************************************/

void Canvas::DrawX(int pos)
{
    // loop-1
    for (int r = 0; r < DIM; r++)
    {
        // loop-2
        for (int c = 0; c < DIM; c++)
        {
            if (board[r][c] == pos)
            {
                board[r][c] = 99;
                last_pos = pos;
            }
        } // end of loop-1
    }     // end of loop-2
}

/***************************************************************************************
Function/method Name - removeValue
Function/method Description - This Function will take the position as a parameter and will
                              remove the element from that position by putting last position
                              back to the position in board.
Return Value - None
Incoming Parameters - position
Outgoing Parameters - None
***************************************************************************************/

void Canvas::removeValue(int pos)
{
    cout << "\nPressed Undo: \n";
    int i = 0;

    // loop-1
    for (int r = 0; r <= DIM; r++)
    {
        // loop-2
        for (int c = 0; c < DIM; c++)
        {
            i++;
            if (i == pos)
            {
                board[r][c] = last_pos;
            }
        } // end of loop-2
    }     // end of loop-1
    DrawBoard();
}

/***************************************************************************************
Function/method Name - Undo
Function/method Description - This function will call the removeValue function in it and
                              it will take last position as a paramter. This function will
                              print back the board with last move.
Return Value - None
Incoming Parameters - position
Outgoing Parameters - None
***************************************************************************************/

void Canvas::Undo()
{
    removeValue(last_pos);
}

/***************************************************************************************
Function/method Name - eraseX
Function/method Description - This  function will erase the value from the baord as the
                              user wants. In this iterator will go to the same position
                              as a paramter and will put back position to that place.
Return Value - None
Incoming Parameters - position
Outgoing Parameters - None
***************************************************************************************/

void Canvas::eraseX(int pos)
{
    int i = 0;

    // loop-1
    for (int r = 0; r <= DIM; r++)
    {
        // loop-2
        for (int c = 0; c < DIM; c++)
        {
            ++i;
            if (i == pos)
            {
                board[r][c] = pos;
            }
        } // end of loop-2
    }     // end of loop-1
}
