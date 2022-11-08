#include <iostream>
using namespace std;

class Node
{
public:
    int courseNumber;
    string courseName;
    string foodDescription[5];
    string drinkDescription[3];
    string HostName;
    Node *nextCourse;

    Node()
    {
        courseNumber = 0;
        courseName = "No-name";
        HostName = "unknown";
        nextCourse = NULL;
    }

    friend class Course;
};

class Course
{
    int homeVisited;
    int mealEaten;
    Node *courses;

    Node *insertHelper(Node *c)
    {

        Node *temp = courses;
        if (courses == NULL)
        {
            // c->nextCourse = NULL;
            courses = c;
        }
        else
        {
            while (temp->nextCourse != NULL)
            {
                temp = temp->nextCourse;
                cout << "Moved to next course" << endl;
            }
            // c->nextCourse = NULL;
            temp->nextCourse = c;
        }
        cout << "Course-Linked" << endl;
        return temp;
    }

public:
    Course()
    {
        homeVisited = mealEaten = 0;
        courses = NULL;
    }
    void showCourseList()
    {
        Node *temp = courses;
        while (temp != NULL)
        {
            cout << "Course: " << temp->courseName << endl;
            temp = temp->nextCourse;
        }
    }

    void PrintCourseList()
    {
        Node *temp = courses;
        while (temp != NULL)
        {
            cout << "Course Name:" << temp->courseName << endl;
            cout << "Course Number:" << temp->courseNumber << endl;
            cout << "Host Name:" << temp->HostName << endl;
            int i = 0;
            int len = *(&arr + 1) - arr;
            while (temp->drinkDescription[i] != NULL || temp->drinkDescription[i] != 0)
            {
                cout << "Drink Description " << (temp->drinkDescription[i]) << endl;
                i++;
            }

            cout << "Food Description" << temp->foodDescription << endl;

            temp = temp->nextCourse;
        }
    }

    bool insertIntoCourse(int courseNum, string CourseNam, string HostName, string *p, string *n, int size)
    {
        cout << "Array recieved" << endl;
        int temp;
        Node *course = new Node();
        course->courseNumber = courseNum;
        course->courseName = CourseNam;
        course->HostName = HostName;
        // course->nextCourse = nullptr;

        // putting the array content into linked list
        for (int i = 0; i < size; i++)
        {
            course->foodDescription[i] = p[i];
            cout << "foodDescription: " << course->foodDescription[i] << endl;
        }

        cout << endl;
        for (int j = 0; j < size; j++)
        {
            course->drinkDescription[j] = n[j];
            cout << "drinkDescription: " << course->drinkDescription[j] << endl;
        }

        // courses = insertHelper(course);
        // // courses = course;
        insertHelper(course);
        return true;
    }

    bool removeCourse(int num)
    {

        bool success = true;
        Node *prev = courses;
        Node *forward = courses;

        while (forward != NULL && forward->courseNumber != num)
        {
            prev = forward;
            forward = forward->nextCourse;
        }
        if (forward->nextCourse != NULL)
        {
            prev->nextCourse = forward->nextCourse;
        }
        else
        {
            prev->nextCourse = NULL;
        }

        delete forward;

        return success;
    }

    void searchByHost(string name)
    {
        Node *temp = courses;
        while (temp != NULL)
        {
            if (temp->HostName == name)
            {
                cout << "The host" << temp->HostName << " is present in list" << endl;
                return;
            }
            else
            {
                temp = temp->nextCourse;
            }
        }
    }

    void searchByCourseNum(int num)
    {
        Node *temp = courses;
        while (temp != NULL)
        {
            if (temp->courseNumber == num)
            {
                cout << "The course " << temp->courseNumber << " is present in list." << endl;
                return;
            }
            else
            {
                temp = temp->nextCourse;
            }
        }
    }
    void currentCourses()
    {
    }

    string *foodDes(int temp)
    {
        string *foodDescription = new string[temp];
        string element;
        bool proceed = true;
        while (proceed)
        {
            cout << "Enter Food Description in between 1-5: ";
            cin >> temp;
            if (temp < 1 || temp > 5)
            {
                cout << "Error: enter a valid number!";
            }
            else
            {
                proceed = false;
                for (int i = 0; i < temp; i++)
                {
                    cout << "Enter Food Description " << i + 1 << " : ";
                    cin >> element;
                    foodDescription[i] = element;
                }
            }
        }

        return foodDescription;
    }

    string *drinkDes(int temp)
    {
        string *drinkDescription = new string[temp];
        string element;
        bool flag = 1;
        while (flag)
        {
            cout << "Enter Drinks Description in between 1-5: ";
            cin >> temp;
            if (temp < 1 || temp > 5)
            {
                cout << "Error: enter a valid number!";
            }
            else
            {
                flag = 0;
                for (int i = 0; i < temp; i++)
                {
                    cout << "Enter Drinks Description " << i + 1 << " : ";
                    cin >> element;
                    drinkDescription[i] = element;
                }
            }
        }
        cout << "Array passed" << endl;

        return drinkDescription;
    }
};
int main()
{
    Course obj;
    int temp;
    cout << "Enter how many sites visited: ";
    cin >> temp;
    // string foodDescription[size];
    // string drinkDescription[size];

    int courseNum;
    string CourseNam, HostName;

    int courseN;
    string CourseN, HostN;

    for (int i = 0; i < temp; i++)
    {
        cout << "Enter Course Number 1: ";
        cin >> courseNum;

        cout << "Enter the Course Name 1: ";
        cin >> CourseNam;

        cout << "Enter the Host Name 1: ";
        cin >> HostName;

        string *p = obj.foodDes(temp);
        string *n = obj.drinkDes(temp);

        obj.insertIntoCourse(courseNum, CourseNam, HostName, p, n, temp);
        obj.showCourseList();
    }

    obj.PrintCourseList();
    return 0;
}
