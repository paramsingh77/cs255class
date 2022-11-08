#include <iostream>
using namespace std;

int main()
{
    // char pointer
    char ch = 'A';
    char *ptrToChr = &ch;                         // in this ptrTochr will store address of ch
    cout << "print address " << ptrToChr << endl; // ptrTOchr will print the adress of ch
    cout << "print to ptr" << *ptrToChr << endl;  //*ptrTochr will print out the value bcz it will act as derefrencing pointer
    cout << ch << endl;

    // integer pointer
    int integ = 8;
    int *ptrToInt = &integ;                       // in this ptrTochr will store address of ch
    cout << "print address " << ptrToInt << endl; // ptrTOchr will print the adress of ch
    cout << "print to ptr" << *ptrToInt << endl;  //*ptrTochr will print out the value bcz it will act as derefrencing pointer
    cout << integ << endl;

    // double integer pointer
    int **doublePointer = &ptrToInt;
    // in this ptrTochr will store address of ch
    cout << "print address  to double pointer " << doublePointer << endl; // ptrTOchr will print the adress of ch
    cout << "print to ptr " << **doublePointer << endl;                   //*ptrTochr will print out the value bcz it will act as derefrencing pointer
    cout << *ptrToInt << endl;

    // tirple pointer

    int ***triplePtr = &doublePointer;
    cout << "Print address f triple pointer " << triplePtr << endl;
    cout << "Print the value at triple pointer " << ***triplePtr << endl;
    cout << *doublePointer << endl;

    // quad pointer
    int ****quadptr = &triplePtr;
    cout << "Address of quad ptr " << quadptr << endl;
    cout << "Value at quad ptr  " << ****quadptr << endl;
    cout << ***triplePtr << endl;

    return 0;
}