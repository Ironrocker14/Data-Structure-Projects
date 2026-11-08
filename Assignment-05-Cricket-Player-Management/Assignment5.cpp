
#include <iostream>
#include <string>
#include <limits>
#include <cctype>
using namespace std;

struct Player
{
    int id;
    string name;
    string mobile;
    int age;
    Player* next;
};

class PlayerList
{
    Player* head;

    string toLower(string s)
    {
        for (size_t i = 0; i < s.length(); i++)
            s[i] = static_cast<char>(
                tolower(static_cast<unsigned char>(s[i]))
            );
        return s;
    }

    bool isValidMobile(const string& m)
    {
        if (m.length() != 10)
            return false;

        for (size_t i = 0; i < m.length(); i++)
        {
            if (!isdigit(static_cast<unsigned char>(m[i])))
                return false;
        }

        return true;
    }

    Player* findById(int id)
    {
        Player* temp = head;

        while (temp != NULL)
        {
            if (temp->id == id)
                return temp;

            temp = temp->next;
        }

        return NULL;
    }

public:

    PlayerList()
    {
        head = NULL;
    }

    ~PlayerList()
    {
        while (head != NULL)
        {
            Player* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void addPlayer()
    {
        int id, age;
        string name, mobile;

        cout << "Enter Player ID: ";
        cin >> id;

        if (findById(id) != NULL)
        {
            cout << "Error: A player with ID " << id << " already exists!\n";
            return;
        }

        cout << "Enter Player Name: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, name);

        cout << "Enter Mobile Number (10 digits): ";
        cin >> mobile;

        if (!isValidMobile(mobile))
        {
            cout << "Error: Invalid mobile number! Player not added.\n";
            return;
        }

        cout << "Enter Age: ";
        cin >> age;

        if (age <= 0)
        {
            cout << "Error: Invalid age! Player not added.\n";
            return;
        }

        Player* newNode = new Player;

        newNode->id = id;
        newNode->name = name;
        newNode->mobile = mobile;
        newNode->age = age;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            Player* temp = head;

            while (temp->next != NULL)
                temp = temp->next;

            temp->next = newNode;
        }

        cout << "Player added successfully!\n";
    }

    void deletePlayer()
    {
        if (head == NULL)
        {
            cout << "List is empty. Nothing to delete.\n";
            return;
        }

        int id;

        cout << "Enter Player ID to delete: ";
        cin >> id;

        Player* temp = head;
        Player* prev = NULL;

        while (temp != NULL && temp->id != id)
        {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL)
        {
            cout << "Player with ID " << id << " not found. Deletion unsuccessful.\n";
            return;
        }

        if (prev == NULL)
        {
            head = temp->next;
        }
        else
        {
            prev->next = temp->next;
        }

        delete temp;

        cout << "Player with ID " << id << " deleted successfully!\n";
    }

    void displayPlayers()
    {
        if (head == NULL)
        {
            cout << "No player records to display.\n";
            return;
        }

        cout << "\n--------------------------------------------------------\n";
        cout << "ID\tName\t\t\tMobile\t\tAge\n";
        cout << "--------------------------------------------------------\n";

        Player* temp = head;

        while (temp != NULL)
        {
            cout << temp->id << "\t" << temp->name;

            if
			{
			  (temp->name.length() < 8)
                cout << "\t\t\t";
            }
            else if
			{
			  (temp->name.length() < 16)
                cout << "\t\t";
            }
            else
			{
                cout << "\t";
            }

            cout << temp->mobile << "\t" << temp->age << "\n";

            temp = temp->next;
        }

        cout << "--------------------------------------------------------\n";
    }

    void searchByName()
    {
        if (head == NULL)
        {
            cout << "List is empty. Nothing to search.\n";
            return;
        }

        string name;

        cout << "Enter Player Name to search: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, name);

        Player* temp = head;
        bool found = false;

        while (temp != NULL)
        {
            if (toLower(temp->name) == toLower(name))
            {
                if (!found)
                    cout << "Player found!\n";

                cout << "ID: " << temp->id << ", Name: " << temp->name << ", Mobile: " << temp->mobile << ", Age: " << temp->age << "\n";

                found = true;
            }

            temp = temp->next;
        }

        if (!found)
        {
            cout << "Player \"" << name << "\" not found.\n";
        }
    }

    void updateMobile()
    {
        if (head == NULL)
        {
            cout << "List is empty. Nothing to update.\n";
            return;
        }

        int id;
        string mobile;

        cout << "Enter Player ID to update mobile number: ";
        cin >> id;

        Player* p = findById(id);

        if (p == NULL)
        {
            cout << "Player with ID " << id << " not found. Update unsuccessful.\n";
            return;
        }

        cout << "Enter new Mobile Number (10 digits): ";
        cin >> mobile;

        if (!isValidMobile(mobile))
        {
            cout << "Error: Invalid mobile number! Update unsuccessful.\n";
            return;
        }

        p->mobile = mobile;

        cout << "Mobile number updated successfully!\n";
    }
};

int main()
{
    PlayerList list;
    int choice;

    do
    {
        cout << "\n===== CRICKET PLAYER MANAGEMENT =====\n";
        cout << "1. Add a new player\n";
        cout << "2. Delete a player (by ID)\n";
        cout << "3. Display all players\n";
        cout << "4. Search a player by name\n";
        cout << "5. Update mobile number\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";

        cin >> choice;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            choice = 0;
        }

        switch (choice)
        {
            case 1:
                list.addPlayer();
                break;

            case 2:
                list.deletePlayer();
                break;

            case 3:
                list.displayPlayers();
                break;

            case 4:
                list.searchByName();
                break;

            case 5:
                list.updateMobile();
                break;

            case 6:
                cout << "Exiting program. Goodbye!\n";
                break;

            default:
                cout << "Invalid choice! Please enter 1-6.\n";
        }

    }
	
	 while (choice != 6);

    return 0;
}

