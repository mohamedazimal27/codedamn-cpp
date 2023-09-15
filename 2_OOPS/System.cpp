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

#include <iostream>
#include <string>

using namespace std;

class Student
{
private:
    string name;
    int id;
    double gpa;

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
};

int main()
{
    cout << "Welcome to the student information system!\n";

    Student student;

    string name;
    int id;
    double gpa;

    // Input student information
    cout << "Enter student name: ";
    getline(cin, name);
    student.setName(name);

    cout << "Enter student ID: ";
    cin >> id;
    student.setID(id);

    // Validate GPA input
    do
    {
        cout << "Enter student GPA (0-4): ";
        cin >> gpa;
        if (gpa < 0 || gpa > 4)
        {
            cout << "Invalid GPA. Please enter a GPA between 0 and 4.\n";
        }
        else
        {
            student.setGPA(gpa);
        }
    } while (gpa < 0 || gpa > 4);

    // Display student information
    cout << "\nStudent Information:\n";
    cout << "Name: " << student.getName() << "\n";
    cout << "ID: " << student.getID() << "\n";
    cout << "GPA: " << student.getGPA() << "\n";

    cout << "Thank you for using the student information system!\n";

    return 0;
}
