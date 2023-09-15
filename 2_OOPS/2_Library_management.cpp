/*Create a library management system that allows users to add, remove, and search for books in the library.
The program should use a class Book to represent each book, with private member variables title, author, isbn,
and available, and public member functions setTitle, setAuthor, setISBN, setAvailable, getTitle, getAuthor, getISBN, getAvailable, borrowBook, and returnBook.

The setTitle, setAuthor, and setISBN functions should take a string argument and set the corresponding member variable.
The setAvailable function should take a boolean argument and set the available member variable to true if the book is available
or false if it is checked out. The getTitle, getAuthor, and getISBN functions should return the corresponding member variable.
The getAvailable function should return a string indicating whether the book is available or checked out.
The borrowBook function should set the available member variable to false if the book is available or print an error message if the book is checked out.
The returnBook function should set the available member variable to true if the book is checked out or print an error message if the book is available.

The program should use a dynamic array of Book objects to represent the library, with a maximum capacity of 100 books.
The program should prompt the user to add, remove, or search for books, and then perform the corresponding operation.
The program should also validate the user's input and ensure that the library does not exceed its maximum capacity.

Example output:

Welcome to the library management system!

Menu:
1. Add book
2. Remove book
3. Search for book
4. Exit

Enter your choice: 1
Enter book title: The Hitchhiker's Guide to the Galaxy
Enter book author: Douglas Adams
Enter book ISBN: 9780345391803
Book added to library.

Menu:
1. Add book
2. Remove book
3. Search for book
4. Exit

Enter your choice: 2
Enter book ISBN: 9780345391803
Book removed from library.

Menu:
1. Add book
2. Remove book
3. Search for book
4. Exit

Enter your choice: 3
Enter book ISBN: 9780345391803

Book Information:
Title: The Hitchhiker's Guide to the Galaxy
Author: Douglas Adams
ISBN: 9780345391803
Availability: Checked out

Menu:
1. Add book
2. Remove book
3. Search for book
4. Exit

Enter your choice: 4
Thank you for using the library management system!
To complete this assignment, you'll need to use a class Book to represent each book, and use public member functions to allow users to set and get the book's title, author, ISBN, and availability, and borrow and return the book. You'll also need to use a dynamic array of Book objects to represent the library, and use if-else statements or a switch statement to perform the corresponding operation based on the user's choice.

Here are the steps to complete the assignment:

Declare a class Book with private member variables title, author, isbn, and available, and public member functions setTitle, setAuthor, setISBN, setAvailable, getTitle, getAuthor, getISBN, getAvailable, borrowBook, and returnBook.
Implement the setTitle, setAuthor, and setISBN functions to take a string argument and set the corresponding member variable.
Implement the setAvailable function to take a boolean argument and set the available member variable to true if the book is available or false if it is checked out.
Implement the getTitle, getAuthor, and getISBN functions to return the corresponding member variable.
Implement the getAvailable function to return a string indicating whether the book is available or checked out.
Implement the borrowBook function to set the available member variable to false if the book is available or print an error message if the book is checked out.
Implement the returnBook function to set the available member variable to true if the book is checked out or print an error message if the book is available.
In the main function, declare a dynamic array of Book objects with a maximum capacity of 100 books.
Use if-else statements or a switch statement to prompt the user to add, remove, or search.
*/

#include <iostream>
using namespace std;

class library
{
private:
    string title, author, isbn;
    bool available;

public:
    void setTitle(string bookTitle)
    {
        title = bookTitle;
    }
    void setAuthor(string bookAuthor)
    {
        author = bookAuthor;
    }
    void setISBN(string bookISBN)
    {
        isbn = bookISBN;
    }
    void setAvailable(bool bookAvailability)
    {
        available = bookAvailability;
    }
    string getTitle() const
    {
        return title;
    }
    string getAuthor() const
    {
        return author;
    }
    string getISBN() const
    {
        return isbn;
    }
    string getAvailable() const
    {
        if (available == 0)
            return "true";
        else
            return "false";
    }
    void borrowBook()
    {
        if (available == true)
            available = false;
        else
            cout << "Book is unavailable";
    }
    void returnBook()
    {
        if (available == false)
            available = true;
        else
            cout << "Book is unavailable";
    }
};

int main()
{
    // Get number of books need to be stored in library
    cout << "Number of books to be stored in Library Management System(1-100): ";
    int numBooks;
    do
    {
        cin >> numBooks;
        if (numBooks <= 0 || numBooks > 100)
            cout << "Invalid choice selected" << endl;
    } while (numBooks <= 0 || numBooks > 100);
    // Create book object
    library *books = new library[numBooks];
    for (int i = 0; i < numBooks; i++)
    {
        cout << "******************************************" << endl;
        cout << "Welcome to the library management system!" << endl;
        cout << "******************************************" << endl;
        cout << endl;
        cout << "\tMenu:" << endl;
        cout << "\t1. Add book" << endl;
        cout << "\t2. Remove book" << endl;
        cout << "\t3. Search for book" << endl;
        cout << "\t4. Exit" << endl;
        cout << endl;
        string title, author, isbn;

        uint choice;
        do
        {
            cout << "Enter your choice(1-4) : ";
            cin >> choice;
            if (choice <= 0 || choice > 4)
                cout << "Invalid choice selected" << endl;
        } while (choice <= 0 || choice > 4);
        cout << "end";
        switch (choice)
        {
        case 1:
            cout << "Enter book title: ";
            cin >> title;
            books[i].setTitle(title);
            cout << "Enter book author: ";
            cin >> author;
            books[i].setAuthor(author);
            cout << "Enter book ISBN: ";
            cin >> isbn;
            books[i].setISBN(isbn);
            cout << "Book added to library.break" << endl;
            books[i].setAvailable(1);
            break;

        case 2:
            cout << "Enter book ISBN: ";
            cin >> isbn;
            books[i].setISBN(isbn);
        default:
            break;
        }
    }

    return 0;
}