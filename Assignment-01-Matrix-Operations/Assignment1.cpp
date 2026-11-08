
#include <iostream>
using namespace std;

const int MAX = 10;

bool validSize(int rows, int cols) 
{
    return rows > 0 && cols > 0 && rows <= MAX && cols <= MAX;
}

void inputMatrix(int mat[MAX][MAX], int rows, int cols) 
{
    cout << "Enter matrix elements row-wise:\n";

    for (int i = 0; i < rows; i++)
	{
        for (int j = 0; j < cols; j++) 
		{
            cin >> mat[i][j];
        }
    }
}

void displayMatrix(int mat[MAX][MAX], int rows, int cols) 
{
    for (int i = 0; i < rows; i++) 
	{
        for (int j = 0; j < cols; j++) 
		{
            cout << mat[i][j] << "\t";
        }
        cout << endl;
    }
}

void addMatrices(int a[MAX][MAX], int b[MAX][MAX], int rows, int cols) 
{
    int result[MAX][MAX];

    for (int i = 0; i < rows; i++)
	{
        for (int j = 0; j < cols; j++)
		{
            result[i][j] = a[i][j] + b[i][j];
        }
    }

    cout << "\nResultant Matrix (A + B):\n";
    displayMatrix(result, rows, cols);
}

void subtractMatrices(int a[MAX][MAX], int b[MAX][MAX], int rows, int cols) 
{
    int result[MAX][MAX];

    for (int i = 0; i < rows; i++) 
	{
        for (int j = 0; j < cols; j++)
		{
            result[i][j] = a[i][j] - b[i][j];
        }
    }

    cout << "\nResultant Matrix (A - B):\n";
    displayMatrix(result, rows, cols);
}

void multiplyMatrices(int a[MAX][MAX], int b[MAX][MAX], int r1, int c1, int c2) 
{
    int result[MAX][MAX] = {};

    for (int i = 0; i < r1; i++) 
	{
        for (int j = 0; j < c2; j++) 
		{
            for (int k = 0; k < c1; k++) 
			{
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    cout << "\nResultant Matrix (A x B):\n";
    displayMatrix(result, r1, c2);
}

void transposeMatrix(int mat[MAX][MAX], int rows, int cols) 
{
    int result[MAX][MAX];

    for (int i = 0; i < rows; i++) 
	{
        for (int j = 0; j < cols; j++) 
		{
            result[j][i] = mat[i][j];
        }
    }

    cout << "\nTranspose Matrix:\n";
    displayMatrix(result, cols, rows);
}

void upperTriangular(int mat[MAX][MAX], int rows, int cols) 
{
    if (rows != cols) 
	{
        cout << "\nError: Matrix must be square.\n";
        return;
    }

    cout << "\nUpper Triangular Matrix:\n";

    for (int i = 0; i < rows; i++) 
	{
        for (int j = 0; j < cols; j++) 
		{
            if (j >= i)
            {
                cout << mat[i][j] << "\t";
        	}
            else
            {
                cout << 0 << "\t";
            }
        }
        cout << endl;
    }
}

int main() 
{
    int a[MAX][MAX], b[MAX][MAX];
    int rowsA, colsA, rowsB, colsB;
    int choice;

    do 
	{
        cout << "\n----- Matrix Operations Menu -----\n";
        cout << "1. Addition\n";
        cout << "2. Subtraction\n";
        cout << "3. Multiplication\n";
        cout << "4. Transpose\n";
        cout << "5. Upper Triangular Matrix\n";
        cout << "6. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
		{

        case 1:
        	
        case 2:
            cout << "Enter rows and columns of Matrix A: ";
            cin >> rowsA >> colsA;

            cout << "Enter rows and columns of Matrix B: ";
            cin >> rowsB >> colsB;

            if (!validSize(rowsA, colsA) || !validSize(rowsB, colsB))
			{
                cout << "Invalid matrix dimensions.\n";
                break;
            }

            if (rowsA != rowsB || colsA != colsB) 
			{
                cout << "Error: Dimensions must match.\n";
                break;
            }

            cout << "Enter Matrix A:\n";
            inputMatrix(a, rowsA, colsA);

            cout << "Enter Matrix B:\n";
            inputMatrix(b, rowsB, colsB);

            if (choice == 1)
            {
                addMatrices(a, b, rowsA, colsA);
            }
            else
            {
                subtractMatrices(a, b, rowsA, colsA);
            }

            break;

        case 3:
            cout << "Enter rows and columns of Matrix A: ";
            cin >> rowsA >> colsA;

            cout << "Enter rows and columns of Matrix B: ";
            cin >> rowsB >> colsB;

            if (!validSize(rowsA, colsA) || !validSize(rowsB, colsB)) 
			{
                cout << "Invalid matrix dimensions.\n";
                break;
            }

            if (colsA != rowsB) 
			{
                cout << "Error: Columns of A must equal rows of B.\n";
                break;
            }

            cout << "Enter Matrix A:\n";
            inputMatrix(a, rowsA, colsA);

            cout << "Enter Matrix B:\n";
            inputMatrix(b, rowsB, colsB);

            multiplyMatrices(a, b, rowsA, colsA, colsB);
            break;

        case 4:
            cout << "Enter rows and columns of Matrix: ";
            cin >> rowsA >> colsA;

            if (!validSize(rowsA, colsA)) 
			{
                cout << "Invalid matrix dimensions.\n";
                break;
            }

            inputMatrix(a, rowsA, colsA);
            transposeMatrix(a, rowsA, colsA);
            break;

        case 5:
            cout << "Enter rows and columns of Matrix: ";
            cin >> rowsA >> colsA;

            if (!validSize(rowsA, colsA)) 
			{
                cout << "Invalid matrix dimensions.\n";
                break;
            }

            if (rowsA != colsA) 
			{
                cout << "Error: Matrix must be square.\n";
                break;
            }

            inputMatrix(a, rowsA, colsA);
            upperTriangular(a, rowsA, colsA);
            break;

        case 6:
            cout << "Exiting program.\n";
            break;

        default:
            cout << "Invalid choice. Try again.\n";
        }

    } 
	
	while (choice != 6);

    return 0;
}

