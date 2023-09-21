/*Create a student information system that allows users to enter and display student information.
he program should use a class Student to represent each student, with private member variables name, id, and gpa,
and public member functions setName, setID, setGPA, getName, getID, and getGPA.

The setName, setID, and setGPA functions should take a string, integer, and double argument respectively, and set
the corresponding member variable. The getName, getID, and getGPA functions should return the corresponding member variable.

The program should prompt the user to enter a student's name, ID, and GPA, and then display the information for that student.
The program should also validate the user's input and ensure that the GPA is between 0 and 4.

Example output: ` Welcome to the student information system!

Enter student name: Alex Brenton Enter student ID: 123456 Enter student GPA: 3.5

Student Information: Name: Alex Brenton ID: 123456 GPA: 3.5 ` To complete this assignment,
you'll need to use a class Student to represent each student, and use public member functions to allow users to set and get the
student's name, ID, and GPA.

Here are the steps to complete the assignment:

Declare a class Student with private member variables name, id, and gpa, and public member functions setName, setID, setGPA, getName, getID, and getGPA.
Implement the setName, setID, and setGPA functions to take a string, integer, and double argument respectively, and set the corresponding member variable.
Implement the getName, getID, and getGPA functions to return the corresponding member variable.
In the main function, prompt the user to enter a student's name, ID, and GPA using cin.
Declare a Student object student and use its member functions to set the student's name, ID, and GPA based on the user's input.
Use the get member functions of the Student object to display the student's information to the console.
Validate the user's input and ensure that the GPA is between 0 and 4. If the GPA is invalid, prompt the user to re-enter the GPA until it is valid.
Print a message thanking the user for using the student information system.*/

/*
Modify the Student class to include a private member variable major, and public member functions setMajor
and getMajor to allow the user to set and get the student's major.
challenge 2:
Write a program that reads in a list of student information from the user and stores them in an array of Student objects.
The program should then display the information for each student.
*/
#include <iostream>
#include <string>

using namespace std;

class Student
{
private:
    string name;
    int id;
    double gpa;
    string major;

public:
    void setName(const string &studentName)
    {
        name = studentName;
    }

    void setID(int studentID)
    {
        id = studentID;
    }

    void setGPA(double studentGPA)
    {
        gpa = studentGPA;
    }

    void setMajor(const string &studentMajor)
    {
        major = studentMajor;
    }

    string getName() const
    {
        return name;
    }

    int getID() const
    {
        return id;
    }

    double getGPA() const
    {
        return gpa;
    }

    string getMajor() const
    {
        return major;
    }
};

// Function to swap two Student objects
void swapStudents(Student &a, Student &b)
{
    Student temp = a;
    a = b;
    b = temp;
}

// Function to perform descending GPA sort on an array of Students
void sortStudentsByGPA(Student students[], int numStudents)
{
    for (int i = 0; i < numStudents - 1; ++i)
    {
        for (int j = 0; j < numStudents - i - 1; ++j)
        {
            if (students[j].getGPA() < students[j + 1].getGPA())
            {
                swapStudents(students[j], students[j + 1]);
            }
        }
    }
}

int main()
{
    cout << "Welcome to the student information system!\n";

    int numStudents;
    cout << "Enter the number of students: ";
    cin >> numStudents;
    cin.ignore(); // Consume the newline character

    // Create an array of Student objects
    Student *studentArray = new Student[numStudents];

    // Input student information for each student
    for (int i = 0; i < numStudents; ++i)
    {
        string name;
        int id;
        double gpa;
        string major;

        cout << "\nEnter student " << (i + 1) << " information:\n";

        cout << "Enter student name: ";
        getline(cin, name);
        studentArray[i].setName(name);

        cout << "Enter student ID: ";
        cin >> id;
        studentArray[i].setID(id);

        do
        {
            cout << "Enter student GPA (0-4): ";
            cin >> gpa;
            if (gpa < 0 || gpa > 4)
            {
                cout << "Invalid GPA. Please enter a GPA between 0 and 4.\n";
            }
        } while (gpa < 0 || gpa > 4);
        studentArray[i].setGPA(gpa);

        cin.ignore(); // Consume the newline character

        cout << "Enter student major: ";
        getline(cin, major);
        studentArray[i].setMajor(major);
    }

    // Sort students by GPA in descending order
    sortStudentsByGPA(studentArray, numStudents);

    // Display student information for all students
    cout << "\nStudent Information (sorted by GPA in descending order):\n";
    for (int i = 0; i < numStudents; ++i)
    {
        cout << "\nStudent " << (i + 1) << ":\n";
        cout << "Name: " << studentArray[i].getName() << "\n";
        cout << "ID: " << studentArray[i].getID() << "\n";
        cout << "GPA: " << studentArray[i].getGPA() << "\n";
        cout << "Major: " << studentArray[i].getMajor() << "\n";
    }

    // Clean up: Delete the dynamic array
    delete[] studentArray;

    cout << "\nThank you for using the student information system!\n";

    return 0;
}
