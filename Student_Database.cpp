#include<iostream>
using namespace std;

struct Student
{
    int rollNo;
    char name[50];
    char program[50];
    char course[50];
    int total;
};

int main()
{
    Student s[10], temp;
    int n, choice, roll;
    int found = 0;

    // Add Student Records
    cout << "Enter Number of Students: ";
    cin >> n;

    if(n < 1 || n > 10)
    {
        cout << "Invalid Number of Students";
        return 0;
    }

    for(int i=0; i<n; i++)
    {
        cout << "\nEnter Details of Student " << i+1 << endl;

        cout << "Roll Number: ";
        cin >> s[i].rollNo;

        cin.ignore(1000, '\n');

        cout << "Name: ";
        cin.getline(s[i].name, 50);

        cout << "Program: ";
        cin.getline(s[i].program, 50);

        cout << "Course: ";
        cin.getline(s[i].course, 50);

        cout << "Total Marks: ";
        cin >> s[i].total;
    }

    do
    {
        cout << "\n===== STUDENT DATABASE =====";
        cout << "\n1. Display";
        cout << "\n2. Search";
        cout << "\n3. Sort";
        cout << "\n4. Modify";
        cout << "\n5. Append";
        cout << "\n6. Exit";

        cout << "\nEnter Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:  // Display

                cout << "\nStudent Records:\n";

                for(int i=0; i<n; i++)
                {
                    cout << "\nRoll No: " << s[i].rollNo;
                    cout << "\nName: " << s[i].name;
                    cout << "\nProgram: " << s[i].program;
                    cout << "\nCourse: " << s[i].course;
                    cout << "\nTotal: " << s[i].total << endl;
                }
                break;

            case 2:  // Search

                found = 0;

                cout << "\nEnter Roll Number: ";
                cin >> roll;

                for(int i=0; i<n; i++)
                {
                    if(s[i].rollNo == roll)
                    {
                        found = 1;

                        cout << "\nStudent Found";
                        cout << "\nRoll No: " << s[i].rollNo;
                        cout << "\nName: " << s[i].name;
                        cout << "\nProgram: " << s[i].program;
                        cout << "\nCourse: " << s[i].course;
                        cout << "\nTotal: " << s[i].total << endl;
                    }
                }

                if(found == 0)
                    cout << "Student Not Found";

                break;

            case 3:  // Sort

                for(int i=0; i<n-1; i++)
                {
                    for(int j=0; j<n-i-1; j++)
                    {
                        if(s[j].total < s[j+1].total)
                        {
                            temp = s[j];
                            s[j] = s[j+1];
                            s[j+1] = temp;
                        }
                    }
                }

                cout << "\nRecords Sorted Successfully";
                break;

            case 4:  // Modify

                found = 0;

                cout << "\nEnter Roll Number to Modify: ";
                cin >> roll;

                for(int i=0; i<n; i++)
                {
                    if(s[i].rollNo == roll)
                    {
                        found = 1 ;

                        cin.ignore(1000, '\n');

                        cout << "Enter New Name: ";
                        cin.getline(s[i].name, 50);

                        cout << "Enter New Program: ";
                        cin.getline(s[i].program, 50);

                        cout << "Enter New Course: ";
                        cin.getline(s[i].course, 50);

                        cout << "Enter New Total: ";
                        cin >> s[i].total;

                        cout << "Record Updated";
                    }
                }

                if(found == 0)
                    cout << "Student Not Found";

                break;

            case 5:  // Append

                if(n < 10)
                {
                    cout << "\nEnter New Student Details\n";

                    cout << "Roll Number: ";
                    cin >> s[n].rollNo;

                    cin.ignore(1000, '\n');

                    cout << "Name: ";
                    cin.getline(s[n].name, 50);

                    cout << "Program: ";
                    cin.getline(s[n].program, 50);

                    cout << "Course: ";
                    cin.getline(s[n].course, 50);

                    cout << "Total Marks: ";
                    cin >> s[n].total;

                    n++;

                    cout << "Student Added Successfully";
                }
                else
                    cout << "Database Full";

                break;

            case 6:

                cout << "\nProgram Ended";
                break;

            default:

                cout << "\nInvalid Choice";
        }

    } while(choice != 6);

    return 0;
}
