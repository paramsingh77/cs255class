#include <iostream>
using namespace std;
#include "Canvas.h"
int main()
{
    Canvas c1;
    c1.DrawBoard();
    cout << endl;
    int pos = c1.InputPos();
    while (pos > 0)
    {
        c1.DrawX(pos);
        c1.DrawImage();
        pos = c1.InputPos();
    }
    c1.Undo();
    c1.DrawImage();
    return 0;
}