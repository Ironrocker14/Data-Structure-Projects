
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
using namespace std;

int main()
{
    int choice;
    string name, prn, line;
    fstream file;

    do
    {
        cout << "\n--- Student Record Menu ---" << endl;
        cout << "1. Create File" << endl;
        cout << "2. Add Student Record" << endl;
        cout << "3. Display Records" << endl;
        cout << "4. Delete Student Record" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
            case 1:
                file.open("students.txt", ios::out);

                if (file)
                {
                    cout << "Student file created successfully!" << endl;
                    file.close();
                }
                else
                {
                    cout << "Unable to create file!" << endl;
                }

                break;

            case 2:
                file.open("students.txt", ios::app);

                if (file)
                {
                    cout << "Enter student name: ";
                    getline(cin, name);

                    cout << "Enter PRN: ";
                    getline(cin, prn);

                    file << prn << " - " << name << endl;

                    cout << "Student record added!" << endl;
                    file.close();
                }
                else
                {
                    cout << "Create the file first!" << endl;
                }

                break;

            case 3:
                file.open("students.txt", ios::in);

                if (file)
                {
                    cout << "\nStudent Records:" << endl;

                    while (getline(file, line))
                        cout << line << endl;

                    file.close();
                }
                else
                {
                    cout << "File not found!" << endl;
                }

                break;

            case 4:
                cout << "Enter PRN to delete: ";
                getline(cin, prn);

                file.open("students.txt", ios::in);

                if (!file)
                {
                    cout << "File not found!" << endl;
                    break;
                }
				else
                {
                    ofstream temp("temp.txt");
                    bool found = false;

                    while (getline(file, line))
                    {
                        if (line.find(prn + " - ") == 0)
                            found = true;
                        else
                            temp << line << endl;
                    }

                    file.close();
                    temp.close();

                    if (found)
                    {
                        remove("students.txt");
                        rename("temp.txt", "students.txt");
                        cout << "Student record deleted!" << endl;
                    }
                    else
                    {
                        remove("temp.txt");
                        cout << "PRN not found!" << endl;
                    }
                }

                break;

            case 5:
                cout << "Exiting program..." << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
        }

    } 
	
	while (choice != 5);

    return 0;
}

