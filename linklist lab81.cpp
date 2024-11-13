#include <iostream>
#include <string>
using namespace std;

struct Book {
    string title;
    string author;
    float price;
    Book* next;
};

class BookStack {
private:
    Book* top;

public:
    BookStack() : top(NULL) {}

    // Push a book onto the stack
    void push(string title, string author, float price) {
        Book* newBook = new Book;
        newBook->title = title;
        newBook->author = author;
        newBook->price = price;
        newBook->next = top;
        top = newBook;
        cout << "Book \"" << title << "\" added to the stack.\n";
    }

    // Pop a book from the top of the stack
    void pop() {
        if (top == NULL) {
            cout << "Stack is empty. No book to pop.\n";
            return;
        }
        Book* temp = top;
        top = top->next;
        cout << "Popped book: " << temp->title << endl;
        delete temp;
    }

    // Find and display a book by title
    void findBook(string title) {
        Book* current = top;
        bool found = false;
        while (current != NULL) {
            if (current->title == title) {
                cout << "Book Found: \n";
                cout << "Title: " << current->title << "\nAuthor: " << current->author << "\nPrice: $" << current->price << endl;
                found = true;
                break;
            }
            current = current->next;
        }
        if (!found) {
            cout << "Book \"" << title << "\" not found in stack.\n";
        }
    }

    // Delete a book by title
    void deleteBook(string title) {
        if (top == NULL) {
            cout << "Stack is empty. No book to delete.\n";
            return;
        }
        Book* current = top;
        Book* previous = NULL;

        while (current != NULL && current->title != title) {
            previous = current;
            current = current->next;
        }

        if (current == NULL) {
            cout << "Book \"" << title << "\" not found in stack.\n";
            return;
        }

        if (previous == NULL) {
            top = top->next;  // Deleting the top element
        } else {
            previous->next = current->next;
        }

        cout << "Deleted book: " << current->title << endl;
        delete current;
    }

    // Display all books in the stack
    void displayStack() {
        if (top == NULL) {
            cout << "Stack is empty.\n";
            return;
        }
        Book* current = top;
        cout << "Books in Stack (Top to Bottom):\n";
        while (current != NULL) {
            cout << "Title: " << current->title << "\nAuthor: " << current->author << "\nPrice: $" << current->price << endl;
            current = current->next;
        }
    }
};

int main() {
    BookStack stack;
    int choice;
    string title, author;
    float price;

    do {
        cout << "\nChoose an option:\n";
        cout << "1. Push a book onto the stack\n";
        cout << "2. Pop a book from the stack\n";
        cout << "3. Find a book by title\n";
        cout << "4. Delete a book by title\n";
        cout << "5. Display all books in the stack\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();  // To ignore the newline character after choice input

        switch (choice) {
            case 1:
                cout << "Enter title: ";
                getline(cin, title);
                cout << "Enter author: ";
                getline(cin, author);
                cout << "Enter price: ";
                cin >> price;
                stack.push(title, author, price);
                break;

            case 2:
                stack.pop();
                break;

            case 3:
                cout << "Enter title to find: ";
                getline(cin, title);
                stack.findBook(title);
                break;

            case 4:
                cout << "Enter title to delete: ";
                getline(cin, title);
                stack.deleteBook(title);
                break;

            case 5:
                stack.displayStack();
                break;

            case 6:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
                break;
        }
    } while (choice != 6);

    return 0;
}
