/*******************************
 * Name - Parminder Singh
 * Professor - Dr. Janet Truitt Jenkins
 *********************************/

#include<cstring> //its a c++ version of #include<string.h> (char stars)
#include<iostream>
using namespace std;


int main(){
    char word[4]="LEO";
    char newC[5] = "ROAR";


    //copy 
    strcpy(word,newC);
    cout<<word<<endl;

    //2 is a limiit of elements to be copied in left parameter
    strncpy(newC,word,2);//copied ch into c1
    //
    cout<<newC<<endl;


    //concatination
    strcat(newC,word);
    cout<<newC<<endl;

    //strlen
    cout<<"LEenght of string word is: "<<strlen(word)<<endl;

    //char array will be stored with a string assuming the null charaher at end;
    char ch[5] = "GOLD";
    cout<<ch<<endl;


    //compare
    cout << strcmp(newC, word) << endl;


    return 0;
}
