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
/*challengs

Modify the Book class to include a private member variable description, and public member functions setDescription
    and getDescription to allow the user to set and get a description of the book.
Implement a search function that allows the user to search for books by title or author.
Add a destructor to the Book class that prints a message indicating that the book object has been destroyed.*/
#include <iostream>
#include <string>

class Book
{
private:
    std::string title;
    std::string author;
    std::string isbn;
    bool available;
    std ::string description;

public:
    // Constructors
    Book() : title(""), author(""), isbn(""), available(true), description("") {}

    // Member functions to set book details
    void setTitle(const std::string &newTitle)
    {
        title = newTitle;
    }

    void setAuthor(const std::string &newAuthor)
    {
        author = newAuthor;
    }

    void setISBN(const std::string &newISBN)
    {
        isbn = newISBN;
    }

    void setAvailable(bool isAvailable)
    {
        available = isAvailable;
    }

    // Member functions to get book details
    std::string getTitle() const
    {
        return title;
    }

    std::string getAuthor() const
    {
        return author;
    }

    std::string getISBN() const
    {
        return isbn;
    }

    std::string getAvailable() const
    {
        return available ? "Available" : "Checked out";
    }

    // Borrow a book
    void borrowBook()
    {
        if (available)
        {
            available = false;
        }
        else
        {
            std::cout << "Error: Book is already checked out." << std::endl;
        }
    }

    // Return a book
    void returnBook()
    {
        if (!available)
        {
            available = true;
        }
        else
        {
            std::cout << "Error: Book is already available." << std::endl;
        }
    }
    void set_description(const std::string &newDescription)
    {
        description = newDescription;
    }
    std::string getDescription() const
    {
        return description;
    }
};

// Function to search for books by title or author
void searchBooks(const Book library[], int numBooks)
{
    std::cout << "\nSearch Book by:" << std::endl;
    std::cout << "1. ISBN" << std::endl;
    std::cout << "2. Author" << std::endl;
    std::cout << "3. Title" << std::endl;
    int searchChoice;
    std::cin >> searchChoice;
    bool found = false;
    std::string searchQuery;

    switch (searchChoice)
    {
    case 1:
        std::cout << "Enter book ISBN: ";
        std::cin >> searchQuery;

        for (int i = 0; i < numBooks; i++)
        {
            if (library[i].getISBN() == searchQuery)
            {
                found = true;
                std::cout << "\nBook is Available" << std::endl;
                std::cout << "Book Information:" << std::endl;
                std::cout << "Title: " << library[i].getTitle() << std::endl;
                std::cout << "Author: " << library[i].getAuthor() << std::endl;
                std::cout << "ISBN: " << library[i].getISBN() << std::endl;
                std::cout << "Description: " << library[i].getDescription() << std::endl;
                std::cout << "Availability: " << library[i].getAvailable() << std::endl;
                break;
            }
        }
        if (!found)
        {
            std::cout << "Error: Book not found in library." << std::endl;
        }
        break;

    case 2:
        std::cout << "Enter book Author: ";
        std::cin >> searchQuery;

        for (int i = 0; i < numBooks; i++)
        {
            if (library[i].getAuthor() == searchQuery)
            {
                found = true;
                std::cout << "\nBook is Available" << std::endl;
                std::cout << "Book Information:" << std::endl;
                std::cout << "Title: " << library[i].getTitle() << std::endl;
                std::cout << "Author: " << library[i].getAuthor() << std::endl;
                std::cout << "ISBN: " << library[i].getISBN() << std::endl;
                std::cout << "Description: " << library[i].getDescription() << std::endl;
                std::cout << "Availability: " << library[i].getAvailable() << std::endl;
                break;
            }
        }
        if (!found)
        {
            std::cout << "Error: Book not found in library." << std::endl;
        }
        break;

    case 3:
        std::cout << "Enter book Title: ";
        std::cin >> searchQuery;

        for (int i = 0; i < numBooks; i++)
        {
            if (library[i].getTitle() == searchQuery)
            {
                found = true;
                std::cout << "\nBook is Available" << std::endl;
                std::cout << "Book Information:" << std::endl;
                std::cout << "Title: " << library[i].getTitle() << std::endl;
                std::cout << "Author: " << library[i].getAuthor() << std::endl;
                std::cout << "ISBN: " << library[i].getISBN() << std::endl;
                std::cout << "Description: " << library[i].getDescription() << std::endl;
                std::cout << "Availability: " << library[i].getAvailable() << std::endl;
                break;
            }
        }
        if (!found)
        {
            std::cout << "Error: Book not found in library." << std::endl;
        }
        break;

    default:
        std::cout << "Invalid choice. Please enter a valid option." << std::endl;
        break;
    }
}

int main()
{
    const int maxBooks = 100;
    Book library[maxBooks];
    int numBooks = 0;
    Book newBook; // Declare newBook outside the switch block

    std::cout << "Welcome to the library management system!" << std::endl;

    while (true)
    {
        std::cout << "\nMenu:" << std::endl;
        std::cout << "1. Add book" << std::endl;
        std::cout << "2. Remove book" << std::endl;
        std::cout << "3. Search for book" << std::endl;
        std::cout << "4. Exit" << std::endl;

        int choice;
        do
        {
            std::cout << "Enter your choice: ";
            std::cin >> choice;
            if (choice < 0 || choice > 4)
                std::cout << "Invalid choice selected" << std::endl;
        } while (choice < 0 || choice > 4);

        switch (choice)
        {
        case 1:
        {
            if (numBooks < maxBooks)
            {
                std::string title, author, isbn, description;
                std::cout << "Enter book title: ";
                std::cin.ignore();
                std::getline(std::cin, title);
                std::cout << "Enter book author: ";
                std::getline(std::cin, author);
                std::cout << "Enter book description: ";
                std::getline(std::cin, description);
                std::cout << "Enter book ISBN: ";
                std::cin >> isbn;

                newBook.setTitle(title);
                newBook.setAuthor(author);
                newBook.setISBN(isbn);
                newBook.set_description(description);

                library[numBooks] = newBook;
                numBooks++;

                std::cout << "Book added to library." << std::endl;
            }
            else
            {
                std::cout << "Error: Library is at maximum capacity." << std::endl;
            }
            break;
        }
        case 2:
        {
            std::string isbn;
            std::cout << "Enter book ISBN: ";
            std::cin >> isbn;
            bool found = false;
            for (int i = 0; i < numBooks; i++)
            {
                if (library[i].getISBN() == isbn)
                {
                    found = true;
                    library[i].returnBook();
                    std::cout << "Book removed from library." << std::endl;
                    break;
                }
            }

            if (!found)
            {
                std::cout << "Error: Book not found in library." << std::endl;
            }
            break;
        }
        case 3:
        {
            searchBooks(library, numBooks);
            break;
        }
        case 4:
        {
            std::cout << "Thank you for using the library management system!" << std::endl;
            return 0;
        }
        default:
            std::cout << "Invalid choice. Please enter a valid option." << std::endl;
            break;
        }
    }
    return 0;
}
