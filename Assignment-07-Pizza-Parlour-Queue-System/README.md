# Pizza Parlour Take-away System using Queue

**Data Structures I – Assignment 7**  
**Deccan Education Society, Pune University**  
**B.Tech Computer Science and Engineering – Second Year, Term III**

## Project Overview

A menu-driven Pizza Parlour Take-away System developed using C++. The application uses an array-based Queue data structure to manage customer pizza orders.

The system follows the **First-In-First-Out (FIFO)** principle, ensuring that the first order received is the first order delivered.

## Features

- Accept new pizza orders.
- Deliver the first pending order.
- Display all waiting orders.
- Check whether the queue is full or empty.
- Menu-driven interface.
- Exit the application.

## Technologies Used

- **Programming Language:** C++
- **IDE:** Dev-C++ / Visual Studio
- **Data Structure:** Queue
- **Concept:** First-In-First-Out (FIFO)

## Queue Operations

| Operation | Description |
|---|---|
| Enqueue | Add a new pizza order |
| Dequeue | Deliver the first pizza order |
| Display | Show all waiting orders |
| Overflow | Display message when queue is full |
| Underflow | Display message when queue is empty |

## Queue Implementation

The program uses an array of size 5 to store pizza orders.

When an order is delivered, the remaining orders are shifted forward to maintain FIFO order.

## Sample Output

```text
--- Pizza Parlour ---
1. Accept New Order
2. Deliver Order
3. Display Waiting Orders
4. Exit

Enter your choice: 1
Enter pizza order: Paneer
Order added successfully!

Enter your choice: 1
Enter pizza order: Chicken
Order added successfully!

Enter your choice: 3
Waiting orders:
1. Paneer
2. Chicken

Enter your choice: 2
Delivered order: Paneer
```

## Concepts Learned

- Queue data structure
- FIFO principle
- Array implementation of Queue
- Enqueue and Dequeue operations
- Front and Rear concepts
- Queue overflow and underflow
- Array element shifting
- Menu-driven programming

## Conclusion

Successfully implemented a Pizza Parlour Take-away System using the Queue data structure in C++. The project demonstrates the FIFO principle through pizza order management and provides practical understanding of queue operations.
