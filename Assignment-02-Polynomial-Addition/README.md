# Polynomial Addition Using Arrays

**Data Structures I – Assignment 2**  
**B.Tech Computer Science Engineering**  
**Deccan Education Society, Pune University**

## Project Overview

A C++ program that performs the addition of two polynomials using arrays.

The program accepts coefficients and exponents from the user, combines terms having the same exponent, and displays the resulting polynomial in standard mathematical notation.

## Features

- Accepts two polynomials from the user.
- Stores polynomial coefficients using arrays.
- Combines like terms automatically.
- Adds polynomial coefficients element by element.
- Displays polynomials in descending order of exponents.
- Handles positive, negative and zero coefficients.
- Uses separate functions for reading, addition and displaying polynomials.

## Technologies Used

- **Language:** C++
- **IDE:** Dev-C++
- **Concepts:** Arrays, Functions, Loops and Polynomial Representation.

## Program Structure

| File | Description |
|---|---|
| `main.cpp` | Main program containing polynomial input, addition and display functions. |

## How It Works

1. Accepts the number of terms in the first polynomial.
2. Reads the coefficient and exponent of each term.
3. Stores coefficients at array indices corresponding to their exponents.
4. Repeats the process for the second polynomial.
5. Adds both polynomial arrays element by element.
6. Displays the two original polynomials and their sum.

## Example

**Input Polynomials:**

- Polynomial 1: 2x² + 3x + 5
- Polynomial 2: 4x² + 1

**Result:**

6x² + 3x + 6

## Time and Space Complexity

- **Time Complexity:** O(MAX) for the fixed-size coefficient arrays used in this implementation.
- **Space Complexity:** O(MAX) for the polynomial and result arrays.

## Learning Outcomes

- Understanding polynomial representation using arrays.
- Implementing array-based mathematical operations.
- Combining like terms using array indexing.
- Using functions to organize C++ programs.
- Understanding time and space complexity.

---

**Author:** Mirza Yaser Ali  
**GitHub:** [Ironrocker14](https://github.com/Ironrocker14)
