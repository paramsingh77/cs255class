#include "1-LL.h"
#include "2-stuff.h"
#include "4-Things.h"
#include <iostream>
using namespace std;

int main()
{
    string arr[] = {"1", "2", "f", "gh"};
    double arr2[] = {3, 5, 79};
    Stuff s("Singh", "sgofni", "St.", "dfs", "dfs", "SDf", arr);
    LL<Stuff> l;
    l.Insert(s);

    Stuff s2("Singh", "jdcxnfk", "St.", "dfs", "dfs", "SDf", arr);
    l.Insert(s2);

    Stuff s3;
    s3 = s2;
    cout << endl;
    l.Insert(s3);
    cout << endl;
    Stuff s4(s3);

    l.Insert(s4);
    // l.Print();

    //   LL<Things> l2;
    //   Things t1(1, 3, arr2);
    //   l2.Insert(t1);
    //   //l2.Print();

    //   // Things t12(3, 3, arr2);
    //   // l2.Insert(t12);
    //   //2.Print();

    //   // cout<<"THid is"<<endl;
    //   Things t3(t1);
    //   l2.Insert(t3);
    //   l2.Print();
    // // cout<<"end"<<endl;
    // cout<<"Hss"<<endl;
    //  Things t13(4, 3, arr2);
    // l2.Insert(t13);
    // l2.Print();
    cout << "Assignment copy" << endl;
    Stuff t10;
    t10 = t10;
    l.Insert(t10);
    l.Print();

    return 0;
}

// #include <fstream>
// #include <iostream>
// #include <string>
// using namespace std;

int main()
{

    LL<Stuff> stuffList;

    ifstream istuffFile("stuff.txt");
    string last, first, str, cityadd, state, zip, mess[3];

    getline(istuffFile, last);
    while (!istuffFile.eof())
    {

        getline(istuffFile, first);
        getline(istuffFile, str);
        getline(istuffFile, cityadd);
        getline(istuffFile, state);
        getline(istuffFile, zip);
        for (int i = 0; i < 3; i++)
            getline(istuffFile, mess[i]);
        cout << last << endl;
        cout << first << endl;
        cout << str << endl;
        cout << cityadd << endl;
        cout << state << endl;
        cout << zip << endl;
        for (int i = 0; i < 3; i++)
            cout << mess[i] << endl;

        Stuff temp(last, first, str, cityadd, state, zip, mess);
        stuffList.Insert(temp);

        getline(istuffFile, last);
        cout << endl;
        cout << "Printing starts: " << endl;
        stuffList.Print();
        // stuffList.Tinker();
        cout << "Printing starts Reverse: " << endl;

        stuffList.Print();
    }
    istuffFile.close();

    LL<ThingsList> ThingsList;

    ifstream istuffFile("ThingsList.txt");
    int courseNumber, noOfItems;
    int size = 2;
    double *arr = new double[size];
    int count = 0;
    while (!istuffFile.eof())
    {

        istuffFile >> courseNumber;
        istuffFile >> noOfItems;
        for (int i = 0; i < size; i++)
            istuffFile >> arr[i];

        Things temp(courseNumber, noOfItems, arr);
        cout << "Iterator: " << count++ << endl;
        ThingsList.Insert(temp);
        ThingsList.Print();
        cout << "*************************" << endl;
        //  Things t4(temp);
        //  ThingsList.Print();

        // LL<Things> tqmp3(temp);
        ThingsList t4;
        t4 = temp;
        cout << "Copied" << endl;
        ThingsList.Insert(t4);
        cout << "Inserted again" << endl;
        ThingsList.Print();
    }
    istuffFile.close();
    delete[] arr;
    return 0;
}

// LL<Stuff> stuffList;

// ifstream istuffFile("stuff.txt");
// string last,first, str, cityadd, state, zip, mess[4];

// getline(istuffFile, last);
// while (!istuffFile.eof()){

// 	getline(istuffFile, first);
// 	getline(istuffFile, str);
// 	getline(istuffFile, cityadd);
// 	getline(istuffFile, state);
// 	getline(istuffFile, zip);
// 	for (int i = 0; i < 4; i++)
// 		getline(istuffFile, mess[i]);
// 	cout << last << endl;
// 	cout << first<< endl;
// 	cout << str << endl;
// 	cout << cityadd<< endl;
// 	cout << state << endl;
// 	cout << zip << endl;
// 	for (int i = 0; i < 4; i++)
// 		cout << mess[i] << endl;

//         Stuff temp(last, first, str, cityadd, state, zip, mess);
//         stuffList.Insert(temp);

// 	getline(istuffFile, last);
// 	cout<<endl;
// 	cout<<"Printing starts: "<<endl;
// 	stuffList.Print();
// 	cout<<"Printing starts Reverse: "<<endl;

//        stuffList.Print();
// }
// istuffFile.close();

#include "1-LL.h"
#include "2-stuff.h"

#include <iostream>
using namespace std;

Stuff::Stuff()
{
    LastName = "Uknwon";
    FirstName = "Not Available";
    StreetAddress = "Uknown-street";
    city = "uknown";
    ST = "Alabama";
    zip = "35632;";
}

Stuff::Stuff(string LastN, string firstN, string street, string cT, string state,
             string zipCode, string thanksArray[])
{
    LastName = LastN;
    FirstName = firstN;
    StreetAddress = street;
    city = cT;
    ST = state;
    zip = zipCode;
    for (int i = 0; i < ThanksSize; i++)
    {
        thanks[i] = thanksArray[i];
    }
}
/****************************************/
// help by Dr. Jenkins
bool operator<(const Stuff &left, const Stuff &right)
{
    return (left.LastName == right.LastName);
}
bool operator>(const Stuff &left, const Stuff &right)
{
    return (left.LastName != right.LastName);
}
/*********************************************/
ostream &operator<<(ostream &as, const Stuff &right)
{
    as << right.LastName << endl;
    as << right.FirstName << endl;
    as << right.city << endl;
    as << right.zip << endl;
    as << right.ST << endl;
    as << right.StreetAddress << endl;
    for (int i = 0; i < ThanksSize; i++)
    {
        cout << right.thanks[i] << endl;
    }
    return as;
}
