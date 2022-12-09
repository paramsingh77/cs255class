#include<iostream>
using namespace std; 

int ExamFun(int N)
{
    cout << N << "_";
    if (N > 0)
    {
        ExamFun(N - 1);
    }
    cout << N << "_";
}
int main()
{
    cout << "****" << endl;
    ExamFun(5);
    cout << endl;
    cout << "****" << endl;
    ExamFun(3);
    cout << endl;
    cout << "****" << endl;
    return 0;
}