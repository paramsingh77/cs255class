
#include <iostream>
using namespace std;

class Canvas
{
    char **board;
    int dim;
    int last_pos;

public:
    Canvas();
    Canvas(int size);
    void DrawImage() const;
    void DrawBoard() const;
    void Reset();
    int InputPos() const;
    void DrawX(int pos);  // you may choose a toggle over these
    void EraseX(int pos); // two methods
    void Undo();
    Canvas(const Canvas &board);
    Canvas &operator=(const Canvas &right);
    ~Canvas();
};

/*************************************************************************************************
Function/method Name - Canvas
Function/method Description - This Constructor is without parameters and will initialize the board
Return Value - None
Incoming Parameters - None
Outgoing Parameters -None
*************************************************************************************************/

Canvas::Canvas()
{
    Reset();
}

/*************************************************************************************************
Function/method Name - Canvas
Function/method Description - This Constructor is without parameters and will initialize the board
Return Value - None
Incoming Parameters - size of the board 
Outgoing Parameters -None
*************************************************************************************************/
Canvas::Canvas(int size)
{
    dim = size;
    board = new char *[size];

    for (int i = 0; i < dim; i++)
    {
        board[i] = new char[dim];
    }
}

/*************************************************************************************************
Function/method Name - Canvas
Function/method Description - This will test a shallow copy of constructor
Return Value - None
Incoming Parameters - another right object in which value is going to be moved.
Outgoing Parameters -None
*************************************************************************************************/

Canvas::Canvas(const Canvas &right)
{

    dim = right.dim;
    board = new char *[dim];
    for (int i = 0; i < dim; i++)
    {
        board[i] = new char[dim];
    }

    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            board[i][j] = right.board[i][j];
        }
    }
    cout << "Board Copied successfully.." << endl;
}

/*************************************************************************************************
Function/method Name - operator=(assignment operator)
Function/method Description - This will test a deep copy of constructor
Return Value - reutrn a calling object.
Incoming Parameters - another right object in which value is going to be moved.
Outgoing Parameters -None
*************************************************************************************************/
Canvas &Canvas::operator=(const Canvas &right)
{
    if (this != &right)
    {
        if (board != nullptr)
            delete[] board;
        dim = right.dim;
        board = new char *[dim];
        for (int i = 0; i < dim; i++)
        {
            board[i] = new char[dim];
        }
        for (int i = 0; i < dim; i++)
        {
            for (int j = 0; j < dim; j++)
            {
                board[i][j] = right.board[i][j];
            }
        }
    }
    cout << "Assignment operaotor Tested Successsfuly" << endl;
    return *this;
}

/*************************************************************************************************
Function/method Name - Deconstructor
Function/method Description - This will deallocate the memory
Return Value - None
Incoming Parameters - None
Outgoing Parameters -None
*************************************************************************************************/

Canvas::~Canvas()
{
    delete[] board;
    board = nullptr;
    dim = 0;
    cout << "Destructed the Space Successfully " << endl<<endl;
}

/*************************************************************************************************
Function/method Name - Reset
Function/method Description - Reset function will reset the whole board.
Return Value - None
Incoming Parameters - None
Outgoing Parameters -None
*************************************************************************************************/

void Canvas::Reset()
{

    board = new char*[dim];
    for(int i = 0 ; i < dim ; i++)
        board[i] = new char[dim];
    last_pos = 0;
    for (int r = 0; r < dim; r++)
    {
        for (int c = 0; c < dim; c++)
            board[r][c] = ' ';
    }
}

/*************************************************************************************************
Function/method Name - DrawImage
Function/method Description - This function will draw the final image of the board after the users has 
                              tried their methods.
Return Value - None
Incoming Parameters - None
Outgoing Parameters -None
*************************************************************************************************/

void Canvas::DrawImage() const
{
    cout << endl
         << endl;
    cout << "     FINAL IMAGE OF DRAWBAORD" << endl;

    // loop-1
    for (int r = 0; r < dim; r++)
    {
        // loop-2
        for (int c = 0; c < dim; c++)
        {
            if (board[r][c] == 'X')
                cout << "X"
                     << "\t";
            else
                cout << "_"
                     << "\t";
        } // end of loop-2
        cout << endl;
    } // end of loop-1
    cout << endl
         << endl;
        
}

/*************************************************************************************************
Function/method Name - DrawBoard
Function/method Description - This will show the board where the user want to implement operations.
Return Value - None
Incoming Parameters - None
Outgoing Parameters -None
*************************************************************************************************/

void Canvas::DrawBoard() const
{

    int count = 1;
    for (int r = 0; r < dim; r++)
    {
        for (int c = 0; c < dim; c++)
        {
            cout << count++ << '\t';
        }
        cout << endl
             << endl;
    }
}

/***************************************************************************************************
Function/method Name - InputPos
Function/method Description - Input pos will ask the user where they want to draw X.
Return Value - None
Incoming Parameters - None
Outgoing Parameters -None
****************************************************************************************************/

int Canvas::InputPos() const
{
    cout << endl;
    DrawBoard();
    cout << endl;
    cout << "Enter the number where you want to draw an X: " ;
    int temp;
    cin >> temp;
    return temp;
}

/******************************************************************************************************
Function/method Name - DrawX
Function/method Description - This method will print the X at the given position.
Return Value - None
Incoming Parameters - None
Outgoing Parameters -None
******************************************************************************************************/

void Canvas::DrawX(int pos)
{
    int r = (pos - 1) / dim;
    int c = (pos - 1) % dim;
    board[r][c] = 'X';
    last_pos = pos;
}

/******************************************************************************************************
Function/method Name - Undo
Function/method Description - This function will keep the track of the last position and undo the move.
Return Value - None
Incoming Parameters - None
Outgoing Parameters -None
*******************************************************************************************************/

void Canvas::Undo()
{
    if (last_pos > 0)
    {
        int r = (last_pos - 1) / dim;
        int c = (last_pos - 1) % dim;
        board[r][c] = ' ';
    }
}

/******************************************************************************************************
Function/method Name - EraseX
Function/method Description - This function will remove the X from the position where user wants to.
Return Value - None
Incoming Parameters - None
Outgoing Parameters -None
*******************************************************************************************************/

void Canvas::EraseX(int pos)
{
    int i = 0;

    // loop-1
    for (int r = 0; r <= dim; r++)
    {
        // loop-2
        for (int c = 0; c < dim; c++)
        {
            ++i;
            if (i == pos)
            {
                board[r][c] = pos;
            }
        } // end of loop-2
    }     // end of loop-1
}

/************************************************************************************************************************************
Name - Parminder Singh
Project Number - 2
File Name : main.cpp
Project Description - In this project user can draw a picture on the board. User has many abilities in application. Using the if else     statement we can draw a X on board , erase X ,Undo the last move and displaying the final picture user made. This is a driver file in which all the functions will be used. In this user will be given option what operation they want to perform.

Course - CS-255
Instructor - Dr. Jenkins
*************************************************************************************************************************************/

//***************************************************************
// Method declaration
//***************************************************************
void getMenu();
int getOperation();

//***************************************************************
// Driver Function
//***************************************************************

int main()
{
    int sizeOfBoard;
    cout << "Enter the size of board: ";
    cin >> sizeOfBoard;
    Canvas c1(sizeOfBoard);
    int newSize = sizeOfBoard * sizeOfBoard;
    int getValueForOperation = getOperation();
    
    // while loop-1
    while (getValueForOperation < 8)
    {
        if (getValueForOperation < 8)
        {

            if (getValueForOperation == 1)
            {
                int toPrintX = c1.InputPos();

                // while loop-2
                while (toPrintX != 0)
                {
                    if (toPrintX <= newSize)
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
                c1.EraseX(toDelete);
                c1.DrawBoard();
            }
            else if (getValueForOperation == 3)
                c1.Undo();

            else if (getValueForOperation == 4)
            {
                c1.Reset();
                c1.DrawBoard();
            }
            else if (getValueForOperation == 5){
            
             Canvas c2(c1);
             c1.DrawImage(); 
             c2.DrawImage();   
            }

            else if (getValueForOperation == 6){
            Canvas c3;
            c3 = c1;
            c1.DrawImage();
            c3.DrawImage();
            }
                
            else if(getValueForOperation == 7)
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
    cout << "Enter 5 for Testing the COPY Constructor(Shallow Copy) " << endl;
    cout << "Enter 6 for testing assingment operator or (Deep copy)" << endl;
    cout << "Enter 5 for Displaying Final Image " << endl;
    cout << "Enter 0 to Exit the Game " << endl
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

// int InputPos()
// {
//     cout << endl
//          << endl;
//     int pos;
//     cout << "Enter the position you want to enter x: ";
//     cin >> pos;
//     return pos;
// }
