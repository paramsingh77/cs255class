#include "iostream"
using namespaces std;

void Go(int* &ptr)
{
    int temp = 5;
    cout << temp << endl;
    int *ptr  = nullptr;
    ptr = new int[3];
}

int main()
{
    int temp =10;
    cout<<temp<<endl;
    int *array = nullptr;
    Go(array);
    delete[]array;
    return 0;
}