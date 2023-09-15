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
#include <string.h>
using namespace std;

class student
{
    private:
        string name;
        int id;
        double gpa;
    public:
        void setName(string n)
        {
            name = n;
        }
        void setID(int iD)
        {
            id = iD;
        }
        void setGPA(double grade)
        {
            gpa = grade;
        }
        string getName(string n)
        {
            return n;
        }
        int getId(int iD)
        {
            return iD;
        }
        double getGPA(double grade)
        {
            return grade;
        }
};


int main(){
    student s1, s2;
    cout << "Enter student name: " ;
    string name;
    cin >> name;
    s1.getName(name);
    cout << "Enter student id: " ;
    int id;
    cin >> id;
    s1.getId(id);
    double gpa;
    do
    {
        cout << "Enter student GPA: " ;
        cin >> gpa;
    } while (!(gpa >= 0.0 && gpa <= 4.0));
    s1.getGPA(gpa);
    cout << "Thank you for using student database system" << endl;
    return 0;
}