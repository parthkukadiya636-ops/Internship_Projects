#include <iostream>
#include <vector>
using namespace std;

class Book
{
public:
    int id;
    string title;
    string author;
    bool issued;

    Book(int i, string t, string a)
    {
        id = i;
        title = t;
        author = a;
        issued = false;
    }
};

vector<Book> library;

// Add Book
void addBook()
{
    int id;
    string title, author;

    cout << "Enter Book ID: ";
    cin >> id;
    cin.ignore();

    cout << "Enter Book Title: ";
    getline(cin, title);

    cout << "Enter Author Name: ";
    getline(cin, author);

    library.push_back(Book(id, title, author));

    cout << "Book Added Successfully!\n";
}

// Display Books
void displayBooks()
{
    if (library.empty())
    {
        cout << "No books available.\n";
        return;
    }

    cout << "\n--- Book List ---\n";

    for (int i = 0; i < library.size(); i++)
    {
        cout << "ID: " << library[i].id << endl;
        cout << "Title: " << library[i].title << endl;
        cout << "Author: " << library[i].author << endl;

        if (library[i].issued)
            cout << "Status: Issued\n";
        else
            cout << "Status: Available\n";

        cout << "-------------------\n";
    }
}

// Search Book
void searchBook()
{
    int id;
    cout << "Enter Book ID to search: ";
    cin >> id;

    for (int i = 0; i < library.size(); i++)
    {
        if (library[i].id == id)
        {
            cout << "\nBook Found!\n";
            cout << "Title: " << library[i].title << endl;
            cout << "Author: " << library[i].author << endl;

            if (library[i].issued)
                cout << "Status: Issued\n";
            else
                cout << "Status: Available\n";

            return;
        }
    }

    cout << "Book not found.\n";
}

// Issue Book
void issueBook()
{
    int id;
    cout << "Enter Book ID to issue: ";
    cin >> id;

    for (int i = 0; i < library.size(); i++)
    {
        if (library[i].id == id)
        {
            if (library[i].issued)
            {
                cout << "Book already issued.\n";
            }
            else
            {
                library[i].issued = true;
                cout << "Book Issued Successfully!\n";
            }
            return;
        }
    }

    cout << "Book not found.\n";
}

int main()
{
    int choice;

    do
    {
        cout << "\n===== Library Management System =====\n";
        cout << "1. Add Book\n";
        cout << "2. Display Books\n";
        cout << "3. Search Book\n";
        cout << "4. Issue Book\n";
        cout << "5. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addBook();
            break;

        case 2:
            displayBooks();
            break;

        case 3:
            searchBook();
            break;

        case 4:
            issueBook();
            break;

        case 5:
            cout << "Exiting Program...\n";
            break;

        default:
            cout << "Invalid Choice.\n";
        }

    } while (choice != 5);

    return 0;
}