
#include <iostream>
using namespace std;

const int MAX = 100;

void copyArray(int source[], int destination[], int n)
{
    for (int i = 0; i < n; i++)
    {
        destination[i] = source[i];
    }
}

void displayArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void bubbleSort(int arr[], int n, int &comparisons, int &swaps)
{
    comparisons = 0;
    swaps = 0;

    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;

        for (int j = 0; j < n - i - 1; j++)
        {
            comparisons++;

            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                swaps++;
                swapped = true;
            }
        }

        if (!swapped)
            break;
    }
}

void selectionSort(int arr[], int n, int &comparisons, int &swaps)
{
    comparisons = 0;
    swaps = 0;

    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < n; j++)
        {
            comparisons++;

            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        if (minIndex != i)
        {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;

            swaps++;
        }
    }
}

void insertionSort(int arr[], int n, int &comparisons, int &swaps)
{
    comparisons = 0;
    swaps = 0;

    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0)
        {
            comparisons++;

            if (arr[j] > key)
            {
                arr[j + 1] = arr[j];
                swaps++;
                j--;
            }
            else
            {
                break;
            }
        }

        arr[j + 1] = key;
    }
}

int partitionArray(int arr[], int low, int high, int &comparisons, int &swaps)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        comparisons++;

        if (arr[j] < pivot)
        {
            i++;

            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;

            swaps++;
        }
    }

    if (i + 1 != high)
    {
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;

        swaps++;
    }

    return i + 1;
}

void quickSort(int arr[], int low, int high,
               int &comparisons, int &swaps)
{
    if (low < high)
    {
        int pivotIndex = partitionArray(
            arr, low, high, comparisons, swaps
        );

        quickSort(arr, low, pivotIndex - 1,
                  comparisons, swaps);

        quickSort(arr, pivotIndex + 1, high,
                  comparisons, swaps);
    }
}

int main()
{
    int original[MAX];
    int arr[MAX];
    int n;
    int choice;

    cout << "==========================================" << endl;
    cout << "           SORTING ALGORITHMS PROGRAM" << endl;
    cout << "==========================================" << endl;

    cout << "Enter number of elements: ";
    cin >> n;

    if (n <= 0 || n > MAX)
    {
        cout << "Invalid number of elements!" << endl;
        return 0;
    }

    cout << "Enter " << n << " elements:" << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> original[i];
    }

    do
    {
        cout << "\n==========================================" << endl;
        cout << "                     MENU" << endl;
        cout << "==========================================" << endl;

        cout << "1. Bubble Sort" << endl;
        cout << "2. Selection Sort" << endl;
        cout << "3. Insertion Sort" << endl;
        cout << "4. Quick Sort" << endl;
        cout << "5. Compare All Sorting Algorithms" << endl;
        cout << "6. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        int comparisons = 0;
        int swaps = 0;

        switch (choice)
        {
            case 1:
                copyArray(original, arr, n);
                bubbleSort(arr, n, comparisons, swaps);

                cout << "\nSorted Array using Bubble Sort: ";
                displayArray(arr, n);

                cout << "Number of Comparisons: " << comparisons << endl;

                cout << "Number of Swaps: " << swaps << endl;
                break;

            case 2:
                copyArray(original, arr, n);
                selectionSort(arr, n, comparisons, swaps);

                cout << "\nSorted Array using Selection Sort: ";
                displayArray(arr, n);

                cout << "Number of Comparisons: " << comparisons << endl;

                cout << "Number of Swaps: " << swaps << endl;
                break;

            case 3:
                copyArray(original, arr, n);
                insertionSort(arr, n, comparisons, swaps);

                cout << "\nSorted Array using Insertion Sort: ";
                displayArray(arr, n);

                cout << "Number of Comparisons: "<< comparisons << endl;

                cout << "Number of Swaps/Shifts: " << swaps << endl;
                break;

            case 4:
                copyArray(original, arr, n);

                comparisons = 0;
                swaps = 0;

                quickSort(arr, 0, n - 1, comparisons, swaps);

                cout << "\nSorted Array using Quick Sort: ";
                displayArray(arr, n);

                cout << "Number of Comparisons: "<< comparisons << endl;

                cout << "Number of Swaps: "<< swaps << endl;
                break;

            case 5:
            {
                int bComp, bSwap;
                int sComp, sSwap;
                int iComp, iSwap;
                int qComp, qSwap;

                int bubble[MAX];
                int selection[MAX];
                int insertion[MAX];
                int quick[MAX];

                copyArray(original, bubble, n);
                copyArray(original, selection, n);
                copyArray(original, insertion, n);
                copyArray(original, quick, n);

                bubbleSort(bubble, n, bComp, bSwap);

                selectionSort(selection, n, sComp, sSwap);

                insertionSort(insertion, n, iComp, iSwap);

                qComp = 0;
                qSwap = 0;

                quickSort(quick, 0, n - 1, qComp, qSwap);

                cout << "\n==========================================" << endl;
                cout << "            COMPARISON OF ALGORITHMS" << endl;
                cout << "==========================================" << endl;

                cout << "\nBubble Sort:" << endl;
                cout << "Sorted Output: ";
                displayArray(bubble, n);
                cout << "Comparisons: " << bComp << endl;
                cout << "Swaps: " << bSwap << endl;

                cout << "\nSelection Sort:" << endl;
                cout << "Sorted Output: ";
                displayArray(selection, n);
                cout << "Comparisons: " << sComp << endl;
                cout << "Swaps: " << sSwap << endl;

                cout << "\nInsertion Sort:" << endl;
                cout << "Sorted Output: ";
                displayArray(insertion, n);
                cout << "Comparisons: " << iComp << endl;
                cout << "Swaps/Shifts: " << iSwap << endl;

                cout << "\nQuick Sort:" << endl;
                cout << "Sorted Output: ";
                displayArray(quick, n);
                cout << "Comparisons: " << qComp << endl;
                cout << "Swaps: " << qSwap << endl;

                cout << "\n==========================================" << endl;
                cout << "All algorithms produce the same sorted output." << endl;
                cout << "The number of comparisons and swaps depends" << endl;
                cout << "on the input data and algorithm used." << endl;
                cout << "==========================================" << endl;

                break;
            }

            case 6:
                cout << "\nProgram terminated successfully." << endl;
                break;

            default:
                cout << "\nInvalid choice! Please try again." << endl;
        }

    } 
	
	while (choice != 6);

    return 0;
}

