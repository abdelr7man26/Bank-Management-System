# 🏦 Bank Management System

A Bank Management System that simulates basic banking operations such as account management, authentication, and financial transactions.
The system follows a Client–Server architecture where a graphical client application communicates with a server responsible for processing requests and managing stored data.

This project demonstrates practical concepts in:

⚫ Client–Server system design

⚫ Object-Oriented Programming (OOP)

⚫ Data persistence using TXT


---

## 📌 Table of Contents

⚫ Project Overview

⚫ System Architecture

⚫ Features

⚫ Technologies Used

⚫ Project Structure

⚫ Installation

⚫ Running the Project

⚫ How the System Works

⚫ Future Improvements

⚫ Author


---

### 📖 Project Overview

The Bank Management System is designed to simulate how basic banking services operate in a distributed environment.

Users interact with the system through the console , while the server handles business logic and data processing. The system allows users to authenticate, view account information, and perform financial operations such as deposits and withdrawals.

Data is stored in TXT files, which act as a lightweight database for account and login information.



---

### 🏗 System Architecture

The system is divided into Three main components:

1. UI 

The UI provides the User interface that users interact with.

Responsibilities:

⚫ User login

⚫ Displaying account information

⚫ Performing banking operations through the interface

2. Core 

The Core contains the main and the global classes. 

Responsibilities:

⚫ Handling UI connections
  
⚫ Authenticating users

⚫ Processing transactions

⚫ Reading and updating stored data

3. Utilities 

The Utilites contain a helpfull classes that i have build to help in managing the operations. 

Responsibilities:

⚫ Show the Date
  
⚫ Deal with Strings 

⚫ Validate inputs

⚫ encrybt passwords


---

## ✨ Features
### Authentication System

⚫ User login with credentials

⚫ Server-side validation

### Account Management

⚫ View account details

⚫ Check current balance

### Banking Transactions

Users can perform basic banking operations such as:

⚫ Deposit money

⚫ Withdraw money

⚫ Transfer money

⚫ Balance inquiry

### Data Storage

The system uses TXT files to store:

⚫ User account information

⚫ Clients account information

⚫ currancies information

⚫ Login /transfare history

### security
the system concidered the security of data by :

⚫ password hashing and encrypting 

⚫ Users Permissions 

---

## 🛠 Technologies Used

| Technology   | Purpose                        |
| ------------ | ------------------------------ |
| C++          | Core system development        |
| TXT          | Data storage                   |

---

## 📂 Project Structure

Bank-Management-System
│
├── Banking_System_Client
│   ├── GUI source files
│   ├── Client application logic
│   └── Network request handling
│
├── Banking_System_Server
│   ├── Server implementation
│   ├── Authentication logic
│   ├── Transaction processing
│   └── Data handling
│
├── Database
│   ├── DataBase.json
│   └── Login.json
│
├── send_email1.py
│
└── README.md


---
## ⚙️ Installation
### Prerequisites

Before running the project, install the following:

C++ Compiler (MinGW / GCC)

### 🚀 Running the Project

1.  **Clone the Repository:**
    ```bash
    git clone [https://github.com/abdelr7man26/Bank-Management-System.git](https://github.com/abdelr7man26/Bank-Management-System.git)
    ```
2.  **Navigate to the Directory:**
    ```bash
    cd Bank-Management-System
    ```
3.  **Compile the Code:**
    ```bash
    g++ main.cpp -o BankSystem
    ```
4.  **Execute the Program:**
    ```bash
    ./BankSystem
    ```

---

## 🔄 How the System Works

1.The server application starts and waits for client connections.

2.The client application connects to the server.

3.The user enters login credentials.

4.The server validates the credentials using stored data.

5.After successful authentication, the user can perform banking operations.

6.The server processes the request and updates the stored data if necessary.



---

## 🚧 Future Improvements

Possible improvements for future development:

⚫ Use a real database (MySQL / PostgreSQL)

⚫ Support multiple concurrent users

⚫ Improve UI/UX design Using .Net


---
## 👨‍💻 Author

### Abdelrhman Mohamed

#### GitHub
#### https://github.com/abdelr7man26


---
*Developed as part of a technical portfolio to demonstrate proficiency in C++ and systems design.*
