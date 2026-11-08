
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string orders[5];
    int rear = 0;
    int choice;
    string pizza;

    do
    {
        cout << "\n--- Pizza Parlour ---" << endl;
        cout << "1. Accept New Order" << endl;
        cout << "2. Deliver Order" << endl;
        cout << "3. Display Waiting Orders" << endl;
        cout << "4. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
            case 1:
                if (rear == 5)
                {
                    cout << "Queue is full!" << endl;
                }
                else
                {
                    cout << "Enter pizza order: ";
                    getline(cin, pizza);

                    orders[rear] = pizza;
                    rear++;

                    cout << "Order added successfully!" << endl;
                }
                break;

            case 2:
                if (rear == 0)
                {
                    cout << "Queue is empty!" << endl;
                }
                else
                {
                    cout << "Delivered order: "
                         << orders[0] << endl;

                    for (int i = 0; i < rear - 1; i++)
                    {
                        orders[i] = orders[i + 1];
                    }

                    rear--;
                }
                break;

            case 3:
                if (rear == 0)
                {
                    cout << "Queue is empty!" << endl;
                }
                else
                {
                    cout << "Waiting orders:" << endl;

                    for (int i = 0; i < rear; i++)
                    {
                        cout << i + 1 << ". "
                             << orders[i] << endl;
                    }
                }
                break;

            case 4:
                cout << "Exiting program..." << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
        }

    }
	 while (choice != 4);

    return 0;
}

