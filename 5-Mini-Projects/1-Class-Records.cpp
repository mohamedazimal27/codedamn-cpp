/*
Class Records
Objective
Write a program to implement the records of your class. The attributes of a record are as follows.

(a) Roll No (Primary Key)
(b) Name
(c) Father's Name
(d) Date of birth
(e) Branch
(f) Year of admission
(g) Tentative year of passing
(h) State
(i) PIN
(j) Country

The program must comprise of the following methods.

(a) Input/Add to the list
(b) Update a record
(c) Delete record
(d) Generate a report based on the following input parameters.

(i) persons (students) with common name.

(ii) persons (students) with common state.

(iii) persons (students) with common district.

You are required to use 1-D struct array
*/

#include <iostream>
#include <string>
using namespace std;

struct StudentRecord
{
    int rollNo;
    string name;
    string fatherName;
    string dob;
    string branch;
    int yearOfAdmission;
    int tentativeYearOfPassing;
    string state;
    string pin;
    string country;
};

const int MAX_RECORDS = 100; // Maximum number of records

// Global array to store student records
StudentRecord records[MAX_RECORDS];

// Function to add a new record
void addRecord(int &count)
{
    if (count < MAX_RECORDS)
    {
        cout << "Enter Student Details:" << endl;
        cout << "Roll No: ";
        cin >> records[count].rollNo;
        cout << "Name: ";
        cin.ignore();
        getline(cin, records[count].name);
        cout << "Father's Name: ";
        getline(cin, records[count].fatherName);
        cout << "Date of Birth: ";
        getline(cin, records[count].dob);
        cout << "Branch: ";
        getline(cin, records[count].branch);
        cout << "Year of Admission: ";
        cin >> records[count].yearOfAdmission;
        cout << "Tentative Year of Passing: ";
        cin >> records[count].tentativeYearOfPassing;
        cout << "State: ";
        cin.ignore();
        getline(cin, records[count].state);
        cout << "PIN: ";
        getline(cin, records[count].pin);
        cout << "Country: ";
        getline(cin, records[count].country);
        count++;
        cout << "Record added successfully!" << endl;
    }
    else
    {
        cout << "Maximum records reached. Cannot add more." << endl;
    }
}

// Function to update a record by roll number
void updateRecord(int count, int rollNo)
{
    for (int i = 0; i < count; i++)
    {
        if (records[i].rollNo == rollNo)
        {
            cout << "Enter updated information for Roll No " << rollNo << ":" << endl;
            cout << "Name: ";
            cin.ignore();
            getline(cin, records[i].name);
            cout << "Father's Name: ";
            getline(cin, records[i].fatherName);
            cout << "Date of Birth: ";
            getline(cin, records[i].dob);
            cout << "Branch: ";
            getline(cin, records[i].branch);
            cout << "Year of Admission: ";
            cin >> records[i].yearOfAdmission;
            cout << "Tentative Year of Passing: ";
            cin >> records[i].tentativeYearOfPassing;
            cout << "State: ";
            cin.ignore();
            getline(cin, records[i].state);
            cout << "PIN: ";
            getline(cin, records[i].pin);
            cout << "Country: ";
            getline(cin, records[i].country);
            cout << "Record updated successfully!" << endl;
            return;
        }
    }
    cout << "Record with Roll No " << rollNo << " not found." << endl;
}

// Function to delete a record by roll number
void deleteRecord(int &count, int rollNo)
{
    for (int i = 0; i < count; i++)
    {
        if (records[i].rollNo == rollNo)
        {
            for (int j = i; j < count - 1; j++)
            {
                records[j] = records[j + 1];
            }
            count--;
            cout << "Record with Roll No " << rollNo << " deleted successfully!" << endl;
            return;
        }
    }
    cout << "Record with Roll No " << rollNo << " not found." << endl;
}

// Function to generate a report of students with a common attribute
void generateReport(int count, const string &attribute, const string &value)
{
    bool found = false;
    cout << "Students with " << attribute << " '" << value << "':" << endl;
    for (int i = 0; i < count; i++)
    {
        if (attribute == "Name" && records[i].name == value)
        {
            cout << "Roll No: " << records[i].rollNo << ", Name: " << records[i].name << endl;
            found = true;
        }
        else if (attribute == "State" && records[i].state == value)
        {
            cout << "Roll No: " << records[i].rollNo << ", State: " << records[i].state << endl;
            found = true;
        }
        else if (attribute == "District" && records[i].pin == value)
        {
            cout << "Roll No: " << records[i].rollNo << ", PIN: " << records[i].pin << endl;
            found = true;
        }
    }
    if (!found)
    {
        cout << "No records found with " << attribute << " '" << value << "'" << endl;
    }
}

int main()
{
    int count = 0;

    while (true)
    {
        cout << "\nMenu:" << endl;
        cout << "1. Add a record" << endl;
        cout << "2. Update a record" << endl;
        cout << "3. Delete a record" << endl;
        cout << "4. Generate report by Name" << endl;
        cout << "5. Generate report by State" << endl;
        cout << "6. Generate report by District (PIN)" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;
        int rollNo;
        string name;
        string state;
        string district;

        switch (choice)
        {
        case 1:
            addRecord(count);
            break;
        case 2:

            cout << "Enter Roll No of the record to update: ";
            cin >> rollNo;
            updateRecord(count, rollNo);
            break;
        case 3:
            cout << "Enter Roll No of the record to delete: ";
            cin >> rollNo;
            deleteRecord(count, rollNo);
            break;
        case 4:
            cout << "Enter Name to generate report: ";

            cin.ignore();
            getline(cin, name);
            generateReport(count, "Name", name);
            break;
        case 5:
            cout << "Enter State to generate report: ";

            cin.ignore();
            getline(cin, state);
            generateReport(count, "State", state);
            break;
        case 6:
            cout << "Enter District (PIN) to generate report: ";

            cin.ignore();
            getline(cin, district);
            generateReport(count, "District", district);
            break;
        case 7:
            cout << "Exiting program. Thank you!" << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}