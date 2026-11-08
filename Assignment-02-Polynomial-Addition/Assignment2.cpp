
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

#define MAX 100

void readPolynomial(int poly[], int size) 
{
    int terms, coeff, expo;

    cout << "Enter number of terms: ";
    cin >> terms;

    for (int i = 0; i < terms; i++) 
	{
        cout << "Enter coefficient and exponent for term "
             << (i + 1) << ": ";
        cin >> coeff >> expo;

        if (expo >= 0 && expo < size) 
		{
            poly[expo] += coeff;
        } 
		else
		{
            cout << "Exponent out of allowed range, term ignored.\n";
        }
    }
}


void addPolynomials(int poly1[], int poly2[], int result[], int size) 
{
    for (int i = 0; i < size; i++) 
	{
        result[i] = poly1[i] + poly2[i];
    }
}

void displayPolynomial(int poly[], int size) 
{
    bool firstTerm = true;

    for (int i = size - 1; i >= 0; i--) 
	{
        if (poly[i] != 0) 
		{

            if (!firstTerm) 
			{
                cout << (poly[i] > 0 ? " + " : " - ");
            } 
			else if (poly[i] < 0) 
			{
                cout << "-";
            }

            int absCoeff = abs(poly[i]);

            if (i == 0) 
			{
                cout << absCoeff;
            }
            else if (i == 1) 
			{
                cout << (absCoeff == 1 ? "x" : to_string(absCoeff) + "x");
            }
            else 
			{
                cout << (absCoeff == 1 ?"x^" + to_string(i) : to_string(absCoeff) + "x^" + to_string(i));
            }

            firstTerm = false;
        }
    }

    if (firstTerm) 
	{
        cout << "0";
    }

    cout << endl;
}

int main() 
{
    int poly1[MAX] = {0};
    int poly2[MAX] = {0};
    int result[MAX] = {0};

    cout << "----- Polynomial 1 -----\n";
    readPolynomial(poly1, MAX);

    cout << "\n----- Polynomial 2 -----\n";
    readPolynomial(poly2, MAX);

    addPolynomials(poly1, poly2, result, MAX);

    cout << "\nPolynomial 1: ";
    displayPolynomial(poly1, MAX);

    cout << "Polynomial 2: ";
    displayPolynomial(poly2, MAX);

    cout << "Sum          : ";
    displayPolynomial(result, MAX);

    return 0;
}

