//**Static memory is chugging a lang and it's compile time**/
//***Dynamic memoery is run-time**9///

int main(){
    int size = 0;

    cout<<"Enter the size of list"<<endl;
    cin>>size;

    int arr[size];

    //this is run time becasue compiler first compile then runs it.

    int *array = nullptr;  //because array is a poiner to first element;
    //so we can dynamically alot the size;
    array = new int[size];  //dynamic array;


    delete[]array; //deallocates memoery that address points to.
    //after deleting nullify it.
    array = nullptr;
}