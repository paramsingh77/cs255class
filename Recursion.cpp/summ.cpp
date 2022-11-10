#include "Course.h"

int main()
{
    Course c1;
    int courseNum;
    string CourseNam, HostName;
    int courseNumber;

    cout << "Enter the number of courses: ";
    cin >> courseNumber;

    int getValueForOperation = getOperation();

    // while loop-1
    while (getValueForOperation < 7)
    {
        if (getValueForOperation < 7)
        {
            if (getValueForOperation == 1)
                c1.PrintCourseList();

            else if (getValueForOperation == 2)
            {
                for (int i = 0; i < temp; i++)
                {
                    cout << "Enter Course Number 1: ";
                    cin >> courseNum;

                    cout << "Enter the Course Name 1: ";
                    cin >> CourseNam;

                    cout << "Enter the Host Name 1: ";
                    cin >> HostName;

                    string *p = c1.foodDes(temp);
                    string *n = c1.drinkDes(temp);

                    c1.insertIntoCourse(courseNum, CourseNam, HostName, p, n, temp);
                }
            }
            else if (getValueForOperation == 3)
                c1.Undo();

            else if (getValueForOperation == 4)
            {
                c1.Reset();
                c1.DrawBoard();
            }
            else if (getValueForOperation == 5)
                c1.DrawImage();
        }

        getMenu();

        cout << "Enter the Number of next operation: ";
        cin >> getValueForOperation;

        if (getValueForOperation == 0)
        {
            cout << endl
                 << endl;
            cout << "Thank you for playing GAME" << endl;
            break;
        }
    } // end of while loop-1
    return 0;
}

obj.PrintCourseList();
return 0;
}

int getOperation()
{
    getMenu();
    int getOpr;
    cout << "Enter the operation you want to operate: ";
    cin >> getOpr;
    return getOpr;
}

void getMenu()
{
    cout << "******* OPERATIONS ON COURSE LIST *******" << endl
         << endl;
    cout << "Enter 1 for printing the course list " << endl;
    cout << "Enter 2 for insert a course into linked list " << endl;
    cout << "Enter 3 for removing a course from list " << endl;
    cout << "Enter 4 for searching the course list by host name " << endl;
    cout << "Enter 5 for searching the course list by course number " << endl;
    cout << "Enter 6 for printing current number of courses in the course list " << endl
         << endl;
    cout << "Enter 0 for exit " << endl;
    cout << "***************************************" << endl
         << endl
         << endl;
}
