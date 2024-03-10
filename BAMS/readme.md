# Bank Account Management System

This is a simple C program that simulates a bank account management system. The program allows users to create, deposit, withdraw, check balance, and calculate interest for savings and checking accounts.

## Features

- **Login/Logout**: Users can log in and log out of their accounts using their account number and password.
- **Create Account**: Users can create new savings or checking accounts with an initial balance.
- **Deposit**: Logged-in users can deposit money into their accounts.
- **Withdraw**: Logged-in users can withdraw money from their accounts (if they have sufficient balance).
- **Check Balance**: Logged-in users can check their current account balance.
- **Calculate Interest**: Logged-in users can calculate the interest earned on their accounts based on the account type (savings or checking) and the respective interest rates.

## Limitations

- The program can handle a maximum of 100 accounts.
- Account names and passwords have length limitations (50 and 20 characters, respectively).
- Interest rates are hard-coded (3% for savings accounts and 1% for checking accounts).

## Usage

1. Compile the C source code.
2. Run the compiled program.
3. Follow the on-screen instructions to interact with the bank account management system.

## Code Structure

The program consists of the following main components:

- `Account` struct: Represents an individual account with fields for account number, name, password, account type, and balance.
- Global variables: Arrays to store accounts and track logged-in account, as well as constants for maximum accounts, name/password lengths, and interest rates.
- Function prototypes: Declarations for all the functions used in the program.
- `main()` function: The entry point of the program, which displays the main menu and handles user choices.
- Helper functions: Functions to perform various operations like login, logout, account creation, deposit, withdrawal, balance check, and interest calculation.

## Note

This program is for educational purposes only and should not be used in a production environment. It lacks proper input validation, security measures, and error handling mechanisms.