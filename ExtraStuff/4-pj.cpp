#include <iostream>
using namespace std;
const int DIM = 5;
class Canvas
{
    int board[DIM][DIM];
    int dim;
    int last_pos;

public:
    Canvas();
    void DrawImage() const;
    void DrawBoard() const;
    void Reset();
    int InputPos() const;
    void DrawX(int &pos);       // you may choose a toggle over these
    void removeValue(int &pos); // two methods
    void Undo();
    void print();
    void earseX(int);
    void getMenu() const;
    int getOperation();
    void setOperation();
};

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

void Canvas::DrawBoard() const
{
    for (int r = 0; r < DIM; r++)
    {
        for (int c = 0; c < DIM; c++)
        {
            if (board[r][c] == 99)
                cout << "X"
                     << "\t";
            else
                cout << board[r][c] << "\t";
        }
        cout << endl;
    }
    cout << endl
         << endl;
}

void Canvas::DrawImage() const
{
    cout << endl
         << endl;
    cout << "     FINAL IMAGE OF DRAWBAORD" << endl;
    for (int r = 0; r < DIM; r++)
    {
        for (int c = 0; c < DIM; c++)
        {
            if (board[r][c] == 99)
                cout << "X"
                     << "\t";
            else
                cout << "_"
                     << "\t";
        }
        cout << endl;
    }
    cout << endl
         << endl
         << endl
         << endl;
}

void Canvas::Reset()
{
    // this.Canvas();
    // make our own code.
    int i = 0;
    for (int r = 0; r < DIM; r++)
    {
        for (int c = 0; c < DIM; c++)
        {
            board[r][c] = i++;
        }
        cout << endl;
    }
}

int Canvas::InputPos() const
{
    cout << endl
         << endl;
    int pos;
    cout << "Enter the position you want to enter x: ";
    cin >> pos;
    return pos;
}

void Canvas::DrawX(int &pos)
{

    for (int r = 0; r < DIM; r++)
    {
        for (int c = 0; c < DIM; c++)
        {
            if (board[r][c] == pos)
            {
                board[r][c] = 99;
                last_pos = pos;
            }
        }
    }
}

void Canvas::removeValue(int &pos)
{
    cout << "\nPressed Undo: \n";
    int i = 0;
    for (int r = 0; r <= DIM; r++)
    {
        for (int c = 0; c < DIM; c++)
        {
            i++;
            if (i == pos)
            {
                board[r][c] = last_pos;
            }
        }
    }
    DrawBoard();
}

void Canvas::Undo()
{
    removeValue(last_pos);
}

void Canvas::earseX(int pos)
{
    int i = 0;
    for (int r = 0; r <= DIM; r++)
    {
        for (int c = 0; c < DIM; c++)
        {
            ++i;
            if (i == pos)
            {
                board[r][c] = pos;
            }
        }
    }
}

void Canvas::getMenu() const
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

int Canvas::getOperation()
{
    getMenu();
    int getOpr;
    cout << "Enter the operation you want to operate: ";
    cin >> getOpr;
    return getOpr;
}

void Canvas::setOperation()
{
    int getValueForOperation = getOperation();
    while (getValueForOperation < 6)
    {
        if (getValueForOperation < 6)
        {

            if (getValueForOperation == 1)
            {
                // draw x
                int toPrintX = InputPos();
                while (toPrintX <= DIM * DIM && toPrintX != 0)
                {
                    DrawX(toPrintX);
                    DrawBoard();
                    cout << "Enter the position you want to enter x or 0 to exit: ";
                    cin >> toPrintX;
                }
            }
            else if (getValueForOperation == 2)
            {
                int toDelete;
                cout << "Enter the position where you want to delete or 0 to exit: ";
                cin >> toDelete;
                earseX(toDelete);
                DrawBoard();
            }
            else if (getValueForOperation == 3)
            {
                Undo();
            }
            else if (getValueForOperation == 4)
            {
                Reset();
                DrawBoard();
            }
            else if (getValueForOperation == 5)
            {
                DrawImage();
            }
        }
        getMenu();
        cout << "Enter the Number of next operation: ";
        cin >> getValueForOperation;
        if (getValueForOperation == 0)
            break;
    }
}

int main()
{
    Canvas c1;
    c1.setOperation();
    return 0;
}
