#include<iostream>
using namespace std;

int main()
{

    int row = 3;
    int col = 3;
    int arr[row][col];
    // for(int r= 0 ; r<row ;r++){
    //     for(int c = 0 ; c < col;c++){
    //         cout<<"A ";
    //     }
    //     cout<<endl;
    // }

    cout<<endl;
    cout<<endl;
    int i = 0;
    for(int r = 0 ; r < col ; r++){
        for(int c = 0; c< row; c++){
            arr[r][c]=i++;
        }
        cout<<endl;
    }

    for (int c = 0; c < col; c++)
    {
        for (int r = 0; r < row; r++)
        {
            cout<<arr[c][r]<<" ";     //
        }
        cout << endl;
    }

    return 0;
}