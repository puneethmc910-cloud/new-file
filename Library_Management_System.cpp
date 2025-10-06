#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Book {
protected:
    string title;
    string author;
    int id;
public:
    void setBook(int i, string t, string a) {
        id = i;
        title = t;
        author = a;
    }

    void displayBook() const {
        cout << "ID: " << id << ", Title: " << title << ", Author: " << author << endl;
    }

    int getID() const {
        return id;
    }
};

class Library {
private:
    vector<Book> books;
public:
    void addBook(const Book& b) {
        books.push_back(b);
        cout << "Book added successfully!\n";
    }

    void showAllBooks() const {
        if(books.empty()) {
            cout << "No books in library.\n";
            return;
        }
        cout << "Books in Library:\n";
        for(const auto &b : books) {
            b.displayBook();
        }
    }

    void searchByID(int searchID) const {
        bool found = false;
        for(const auto &b : books) {
            if(b.getID() == searchID) {
                cout << "Book found:\n";
                b.displayBook();
                found = true;
                break;
            }
        }
        if(!found) cout << "Book with ID " << searchID << " not found.\n";
    }
};

int main() {
    Library lib;
    int choice;

    do {
        cout << "\n===== Library Menu =====\n";
        cout << "1. Add Book\n2. Show All Books\n3. Search Book by ID\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if(choice == 1) {
            int id;
            string title, author;
            cout << "Enter Book ID: "; cin >> id;
            cin.ignore();
            cout << "Enter Book Title: "; getline(cin, title);
            cout << "Enter Author Name: "; getline(cin, author);

            Book b;
            b.setBook(id, title, author);
            lib.addBook(b);
        }
        else if(choice == 2) {
            lib.showAllBooks();
        }
        else if(choice == 3) {
            int searchID;
            cout << "Enter Book ID to search: "; cin >> searchID;
            lib.searchByID(searchID);
        }
        else if(choice == 4) {
            cout << "Exiting...\n";
        }
        else {
            cout << "Invalid choice! Try again.\n";
        }

    } while(choice != 4);

    return 0;
}
