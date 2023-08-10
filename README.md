# BankManagement
This code is a basic implementation of a Library Management System in the C programming language. It allows users to perform various actions related to managing a library, such as adding books, updating book information, searching for books, returning books, and displaying all books in the library. Let's break down the code step by step:

Struct Definitions:

struct Book: Represents a book with attributes such as title, author, year, and available.
struct Library: Represents a library, which contains an array of Book structures and keeps track of the number of books.
Function Definitions:

void addBook(struct Library *library, struct Book book): Adds a new book to the library. It checks if there is space in the library and then adds the book to the array of books.
void updateBook(struct Library *library, char *title): Updates the information of a book (author and year) by searching for the book title in the library.
void searchBook(struct Library *library, char *title): Searches for a book by title in the library and displays its information.
void returnBook(struct Library *library, char *title): Marks a book as returned (sets its availability to 1) by searching for the book title in the library.
Main Function (main):

Initializes a struct Library called library and sets the number of books in the library to 0.
Enters a loop that displays a menu of options to the user and waits for their choice.
The user can choose from the following options:
Add Book: Prompts the user to enter information about a new book (title, author, and year) and then adds it to the library.
Update Book: Prompts the user to enter a book title and then updates the author and year of the book if found in the library.
Search Book: Prompts the user to enter a book title and then searches for and displays information about the book if found.
Return Book: Prompts the user to enter a book title and marks the book as returned if it is in the library.
Display All Books: Displays information about all the books in the library.
Exit: Exits the program.
The loop continues until the user chooses to exit (option 6).
