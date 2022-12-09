#include<fstream>
#include<iostream>
using namespace std;

int main(){
    
    ofstream obj;
    obj.open("fileHandling.txt");
    obj<<"hello";

    ifstream fin;
    fin.open("fileHandling.txt");
    char ch;
    fin>>ch; 
    
    fin.close();
    return 0;
}