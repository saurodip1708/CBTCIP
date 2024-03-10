#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max_acc 100
#define max_name_len 50
#define max_pass_len 20
#define SAVINGS 1
#define CURRENT 2
#define SAVINGS_INTEREST_RATE 0.03
#define CURRENT_INTEREST_RATE 0.01

typedef struct {
 int accountNumber;
char name[max_name_len];
char password[max_pass_len];
int accountType;
 double balance;
} Account;

Account accounts[max_acc];
int numAccounts = 0;
int loggedInAccount = -1;

// Function prototypes
void login();
void logout();
void createAccount();
void deposit(int accountNumber);
void withdraw(int accountNumber);
void checkBalance(int accountNumber);
void calculateInterest(int accountNumber);
int findAccount(int accountNumber);

int main() {
    int choice;

    while (1) {
        if (loggedInAccount == -1) {
printf("\nBank Account Management System\n");
 printf("1. Login\n");
            printf("2. Create Account\n");
          printf("3. Exit\n");
                    printf("Enter your choice: ");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    login();
                    break;
                    case 2: createAccount();
             break;
                case 3:
                    return 0;
                default:
                    printf("Invalid choice. Try again.\n");
            }
        } else {
            printf("\nBank Account Management System\n");
            printf("1. Deposit\n");
            printf("2. Withdraw\n");
            printf("3. Check Balance\n");
            printf("4. Calculate Interest\n");
            printf("5. Logout\n");
            printf("6. Exit\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    deposit(accounts[loggedInAccount].accountNumber);
                    break;
                case 2:
                    withdraw(accounts[loggedInAccount].accountNumber);
                    break;
                case 3:
                    checkBalance(accounts[loggedInAccount].accountNumber);
                    break;
                case 4:
                    calculateInterest(accounts[loggedInAccount].accountNumber);
                    break;
                case 5:
                    logout();
                    break;
                case 6:
                    return 0;
                default:
                    printf("Invalid choice. Try again.\n");
            }
        }
    }

    return 0;
}

void login() {
    int accountNumber;
    char password[max_pass_len];

    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    int index = findAccount(accountNumber);

    if (index == -1) {
        printf("Account not found.\n");
        return;
    }

    printf("Enter password: ");
    scanf("%s", password);

    if (strcmp(accounts[index].password, password) != 0) {
        printf("Incorrect password.\n");
        return;
    }

    loggedInAccount = index;
    printf("Login successful.\n");
}

void logout() {
    if (loggedInAccount == -1) {
        printf("You are not logged in.\n");
        return;
    }

    loggedInAccount = -1;
    printf("Logout successful.\n");
}

void createAccount() {
    if (numAccounts >= max_acc) {
        printf("Maximum number of accounts reached.\n");
        return;
    }

    Account newAccount;
    printf("Enter name: ");
    scanf("%s", newAccount.name);

    printf("Enter password: ");
    scanf("%s", newAccount.password);

    printf("Enter account type (1 for Savings, 2 for Cureent Account): ");
    scanf("%d", &newAccount.accountType);

    printf("Enter Opening balance: ");
    scanf("%lf", &newAccount.balance);

    newAccount.accountNumber = numAccounts + 1;
    accounts[numAccounts++] = newAccount;
    printf("Account created successfully. Account number: %d\n", newAccount.accountNumber);
}

void deposit(int accountNumber) {
    int index = findAccount(accountNumber);

    if (index == -1) {
        printf("Account not found.\n");
        return;
    }

    double amount;
    printf("Enter amount to deposit: ");
    scanf("%lf", &amount);

    accounts[index].balance += amount;
    printf("Deposit successful. New balance: %.2f\n", accounts[index].balance);
}

void withdraw(int accountNumber) {
int index = findAccount(accountNumber);

if (index == -1) {
    printf("Account not found.\n");
        return;
 }

    double amount;
 printf("Enter amount to withdraw: ");
    scanf("%lf", &amount);

    if (amount > accounts[index].balance) {
     printf("Insufficient balance.\n");
        return;
    }

accounts[index].balance -= amount;
printf("Withdrawal successful. New balance: %.2f\n", accounts[index].balance);
}

void checkBalance(int accountNumber) {
int index = findAccount(accountNumber);

 if (index == -1) {
 printf("Account not found.\n");
return;
}

printf("Account Balance: %.2f\n", accounts[index].balance);
}

void calculateInterest(int accountNumber) {
int index = findAccount(accountNumber);

if (index == -1) {
printf("Account not found.\n");
return;
    }

 double interestRate;
if (accounts[index].accountType == SAVINGS) {
interestRate = SAVINGS_INTEREST_RATE;
} else if (accounts[index].accountType == CURRENT) {
      interestRate = CURRENT_INTEREST_RATE;
} else {
printf("Invalid account type.\n");
return;
}

    double interest = accounts[index].balance * interestRate;
    printf("Interest earned: %.2f\n", interest);
}

int findAccount(int accountNumber) {
    for (int i = 0; i < numAccounts; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            return i;
        }
    }

    return -1;
}