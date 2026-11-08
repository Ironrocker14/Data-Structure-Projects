# Infix to Postfix Expression Conversion using Stack

**Data Structures – Assignment 6**  
Deccan Education Society, Pune University

## Project Overview

A C++ program that converts an infix expression into a postfix expression using the Stack data structure.

The program processes operands directly and temporarily stores operators in a stack according to their precedence and associativity.

## Concepts Used

- Stack Data Structure
- Infix and Postfix Expressions
- Operator Precedence
- Operator Associativity
- Parentheses Handling
- Expression Validation

## Operators Supported

| Operator | Precedence |
|---|---|
| `^` | Highest |
| `*`, `/` | Medium |
| `+`, `-` | Lowest |

## Example

**Input:**
```text
A+B*C
```

**Output:**
```text
ABC*+
```

## Features

- Converts infix expressions into postfix expressions.
- Handles operator precedence and associativity.
- Supports parentheses.
- Detects invalid expressions and characters.
- Uses a stack to manage operators.

## Technologies Used

- Language: C++
- IDE: Dev-C++ / Eclipse CDT / any C++ IDE
- Header Files: iostream, stack, string, cctype

## Conclusion

Successfully implemented infix-to-postfix expression conversion using the Stack data structure in C++.
