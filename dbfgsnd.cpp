#include<iostream>
using namespace std;

int sum(int n){
    if(n > 0)
        return sum(n-1)+n;
    else{
        return 0;
    }
}

int main(){
    cout<<sum(5);
    return 0;
}

Node* recursion(Node* head){
    if(head==null)
        return null;
    if(head->next == NULL)
        return head;
    Node* newHead = recursion(head->next);
    head->next->next = head;
    head->next= nullptr;
    return newHead;
}