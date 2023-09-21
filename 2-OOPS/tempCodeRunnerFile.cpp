if (numBooks < 100) {
    books[numBooks] = newbook;
    numBooks++;
    cout << "Book added to library." << endl;
} else {
    cout << "Library is full. Cannot add more books." << endl;
}