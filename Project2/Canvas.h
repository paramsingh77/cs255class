/*********************************************************************************************************
Name - Parminder Singh
Project Number - 2
File Name : Canvas.h
Project Description - In this Canvas.h file have all the function and class delcarations with the global declarations.
Course - CS-255
Instructor - Dr. Jenkins
*********************************************************************************************************/

#ifndef _CANVAS_H
#define _CANVAS_H

#include <iostream>
using namespace std;

//****GLOBAL VARIABLE*******
const int DIM = 5;
//**************************

//********CLASS CANVAS***********//
class Canvas
{
    // Data Members
    int board[DIM][DIM];
    int dim;
    int last_pos;

public:
    // Constructor
    Canvas();

    // Methods
    void DrawImage() const;
    void DrawBoard() const;
    void Reset();
    void DrawX(int pos);       // you may choose a toggle over these
    void removeValue(int pos); // two methods
    void Undo();
    void print();
    void eraseX(int);
};

#endif