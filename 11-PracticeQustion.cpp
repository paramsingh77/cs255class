#include <iostream>
using namespace std;

class Money
{
    int dollars;
    int cents;
    Void MakeValid();

public:
    Money();
    int GetCents() const;
    Money operator+(const Money &m) const;
    friend bool operator==(const Money &m1, const Money &m2);
    friend bool operator<<(ostream &os, const Money &m);

    void MakeSet()
    {
        MakeValid();
    }
};

void MakeSet(){
    
}

int main()
{
    
    return 0;
}