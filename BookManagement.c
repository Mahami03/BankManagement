#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

struct Book {
  char title[100];
  char author[100];
  int year;
  int available;
};

struct Library {
  struct Book books[MAX_BOOKS];
  int numBooks;
};

void addBook(struct Library *library, struct Book book) {
  if (library->numBooks < MAX_BOOKS) {
    library->books[library->numBooks] = book;
    library->numBooks++;
    printf("Book added successfully!\n");
  } else {
    printf("Library is full. Cannot add more books.\n");
  }
}

void updateBook(struct Library *library, char *title) {
  int i;
  for (i = 0; i < library->numBooks; i++) {
    if (strcmp(library->books[i].title, title) == 0) {
      printf("Enter new author: ");
      scanf("%s", library->books[i].author);
      printf("Enter new year: ");
      scanf("%d", &library->books[i].year);
      printf("Book updated successfully!\n");
      return;
    }
  }
  printf("Book not found.\n");
}

void searchBook(struct Library *library, char *title) {
  int i;
  for (i = 0; i < library->numBooks; i++) {
    if (strcmp(library->books[i].title, title) == 0) {
      printf("Title: %s\n", library->books[i].title);
      printf("Author: %s\n", library->books[i].author);
      printf("Year: %d\n", library->books[i].year);
      printf("Availability: %s\n", library->books[i].available ? "Yes" : "No");
      return;
    }
  }
  printf("Book not found.\n");
}

void returnBook(struct Library *library, char *title) {
  int i;
  for (i = 0; i < library->numBooks; i++) {
    if (strcmp(library->books[i].title, title) == 0) {
      if (library->books[i].available) {
        printf("Book is already returned.\n");
      } else {
        library->books[i].available = 1;
        printf("Book returned successfully!\n");
      }
      return;
    }
  }
  printf("Book not found.\n");
}

int main() {
  struct Library library;
  library.numBooks = 0;

  int choice;
  char title[100];

  do {
    printf("\nLibrary Management System\n");
    printf("1. Add Book\n");
    printf("2. Update Book\n");
    printf("3. Search Book\n");
    printf("4. Return Book\n");
    printf("5. Display All Books\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter book title: ");
        scanf("%s", library.books[library.numBooks].title);
        printf("Enter book author: ");
        scanf("%s", library.books[library.numBooks].author);
        printf("Enter book year: ");
        scanf("%d", &library.books[library.numBooks].year);
        library.books[library.numBooks].available = 1;
        addBook(&library, library.books[library.numBooks]);
        break;
      case 2:
        printf("Enter book title: ");
        scanf("%s", title);
        updateBook(&library, title);
        break;
      case 3:
        printf("Enter book title: ");
        scanf("%s", title);
        searchBook(&library, title);
        break;
      case 4:
        printf("Enter book title: ");
        scanf("%s", title);
        returnBook(&library, title);
        break;
      case 5:
        for (int i = 0; i < library.numBooks; i++) {
          printf("Book %d:\n", i + 1);
          printf("Title: %s\n", library.books[i].title);
          printf("Author: %s\n", library.books[i].author);
          printf("Year: %d\n", library.books[i].year);
          printf("Availability: %s\n\n", library.books[i].available ? "Yes" : "No");
        }
        break;
      case 6:
        printf("Exiting...\n");
        break;
      default:
        printf("Invalid choice. Please try again.\n");
    }
  } while (choice != 6);

  return 0;
}
