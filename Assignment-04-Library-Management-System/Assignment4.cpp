
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const int MAX = 50;

class Book
{
private:
    string isbn;
    string bookName;
    string authorName;
    string publisherName;
    double price;

public:
    void inputBook()
    {
        cin.ignore();

        cout << "Enter ISBN: ";
        getline(cin, isbn);

        cout << "Enter Book Name: ";
        getline(cin, bookName);

        cout << "Enter Author Name: ";
        getline(cin, authorName);

        cout << "Enter Publisher Name: ";
        getline(cin, publisherName);

        cout << "Enter Price: ";
        cin >> price;
    }

    void displayBook() const
    {
        cout << left;

        cout << setw(15) << isbn
             << setw(25) << bookName
             << setw(20) << authorName
             << setw(20) << publisherName
             << setw(10) << price
             << endl;
    }

    string getISBN() const
    {
        return isbn;
    }

    string getBookName() const
    {
        return bookName;
    }

    string getAuthorName() const
    {
        return authorName;
    }

    string getPublisherName() const
    {
        return publisherName;
    }

    double getPrice() const
    {
        return price;
    }
};

void displayHeader()
{
    cout << left;

    cout << setw(15) << "ISBN"
         << setw(25) << "Book Name"
         << setw(20) << "Author"
         << setw(20) << "Publisher"
         << setw(10) << "Price"
         << endl;

    cout << string(90, '-') << endl;
}

void sortByISBN(Book books[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (books[j].getISBN() > books[j + 1].getISBN())
            {
                Book temp = books[j];
                books[j] = books[j + 1];
                books[j + 1] = temp;
            }
        }
    }
}

void binarySearchISBN(Book books[], int n, const string &key)
{
    int low = 0;
    int high = n - 1;

    bool found = false;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (books[mid].getISBN() == key)
        {
            cout << "\nBook Found using Binary Search:\n";

            displayHeader();

            books[mid].displayBook();

            found = true;
            break;
        }
        else if (books[mid].getISBN() < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    if (!found)
    {
        cout << "No book found with ISBN: " << key << endl;
    }
}

void linearSearch(Book books[], int n, int fieldChoice, const string &key)
{
    bool found = false;

    cout << "\nSearch Results:\n";

    displayHeader();

    for (int i = 0; i < n; i++)
    {
        bool match = false;

        switch (fieldChoice)
        {
            case 2:
                match = (books[i].getBookName() == key);
                break;

            case 3:
                match = (books[i].getAuthorName() == key);
                break;

            case 4:
                match = (books[i].getPublisherName() == key);
                break;
        }

        if (match)
        {
            books[i].displayBook();
            found = true;
        }
    }

    if (!found)
    {
        cout << "No matching record found for the given search value.\n";
    }
}

void highestAndLowestPriced(Book books[], int n)
{
    if (n == 0)
        return;

    int maxIndex = 0;
    int minIndex = 0;

    for (int i = 1; i < n; i++)
    {
        if (books[i].getPrice() > books[maxIndex].getPrice())
        {
            maxIndex = i;
        }

        if (books[i].getPrice() < books[minIndex].getPrice())
        {
            minIndex = i;
        }
    }

    cout << "\nBook with Highest Price:\n";

    displayHeader();

    books[maxIndex].displayBook();

    cout << "\nBook with Lowest Price:\n";

    displayHeader();

    books[minIndex].displayBook();
}

void countByAuthor(Book books[], int n, const string &authorName)
{
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (books[i].getAuthorName() == authorName)
        {
            count++;
        }
    }

    cout << "\nNumber of books available by \"" << authorName << "\": " << count << endl;
}

int main()
{
    Book books[MAX];

    int n;
    int choice;

    cout << "Enter number of books: ";
    cin >> n;

    if (n <= 0 || n > MAX)
    {
        cout << "Invalid number of books." << endl;
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        cout << "\n--- Enter details for Book "<< i + 1<< " ---\n";

        books[i].inputBook();
    }

    do
    {
        cout << "\n===== Library Management System =====\n";

        cout << "1. Search a book\n";
        cout << "2. Display book with highest and lowest price\n";
        cout << "3. Count books by a given author\n";
        cout << "4. Display all books\n";
        cout << "5. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
            {
                int fieldChoice;
                string key;

                cout << "\nSearch by:\n";

                cout << "1. ISBN (Binary Search)\n";
                cout << "2. Book Name (Linear Search)\n";
                cout << "3. Author Name (Linear Search)\n";
                cout << "4. Publisher Name (Linear Search)\n";

                cout << "Enter choice: ";
                cin >> fieldChoice;

                cin.ignore();

                cout << "Enter search value: ";
                getline(cin, key);

                if (fieldChoice == 1)
                {
                    sortByISBN(books, n);
                    binarySearchISBN(books, n, key);
                }
                else if (fieldChoice >= 2 && fieldChoice <= 4)
                {
                    linearSearch(books, n, fieldChoice, key);
                }
                else
                {
                    cout << "Invalid search choice.\n";
                }

                break;
            }

            case 2:
            {
                highestAndLowestPriced(books, n);
                break;
            }

            case 3:
            {
                string authorName;

                cin.ignore();

                cout << "Enter author name: ";
                getline(cin, authorName);

                countByAuthor(books, n, authorName);

                break;
            }

            case 4:
            {
                cout << "\nAll Books in Library:\n";

                displayHeader();

                for (int i = 0; i < n; i++)
                {
                    books[i].displayBook();
                }

                break;
            }

            case 5:
            {
                cout << "Exiting...\n";
                break;
            }

            default:
            {
                cout << "Invalid choice. Try again.\n";
            }
        }

    } while (choice != 5);

    return 0;
}

