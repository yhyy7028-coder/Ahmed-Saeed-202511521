// Name   : Ahmed Yahia Fadl Saeed
// Roll   : 202511521

#include <iostream>
#include <string>
using namespace std;

const int DEFAULT_PIN = 12345;
const int MAX_ATTEMPTS = 3;
const int MAX_TRANSACTIONS = 100;

int balance = 0;
string transactionHistory[MAX_TRANSACTIONS];
int transCount = 0;

void displayHeader() {
    cout << "\033[36m";
    cout << "\t\t==========================================" << endl;
    cout << "\t\t         BK ATM SYSTEM                   " << endl;
    cout << "\t\t==========================================" << endl;
    cout << "\033[0m" << endl;
}

void displayMenu() {
    cout << "\n\033[34m=========== MAIN MENU ===========\033[0m" << endl;
    cout << "  [1] Check Balance" << endl;
    cout << "  [2] Deposit Money" << endl;
    cout << "  [3] Withdraw Money" << endl;
    cout << "  [4] Transaction History" << endl;
    cout << "  [5] Exit" << endl;
    cout << "\033[34m=================================\033[0m" << endl;
}

void checkBalance() {
    cout << "\033[32m";
    cout << "\nCurrent Balance : " << balance << " FRW" << endl;
    cout << "\033[0m";
}

void depositMoney() {
    int amount;
    cout << "\nEnter amount to deposit : ";
    cin >> amount;

    if (amount <= 0) {
        cout << "\033[31mInvalid amount.\033[0m" << endl;
        return;
    }

    balance += amount;
    transactionHistory[transCount++] = "Deposited : " + to_string(amount) + " FRW";

    cout << "\033[32m";
    cout << "\nDeposit Successful" << endl;
    cout << "New Balance : " << balance << " FRW" << endl;
    cout << "\033[0m";
}

void withdrawMoney() {
    int amount;
    cout << "\nEnter amount to withdraw : ";
    cin >> amount;

    if (amount <= 0) {
        cout << "\033[31mInvalid amount.\033[0m" << endl;
        return;
    }

    if (amount > balance) {
        cout << "\033[31m\nInsufficient Funds\033[0m" << endl;
    } else {
        balance -= amount;
        transactionHistory[transCount++] = "Withdrawn : " + to_string(amount) + " FRW";

        cout << "\033[32m";
        cout << "\nWithdrawal Successful" << endl;
        cout << "Withdrawn Amount  : " << amount << " FRW" << endl;
        cout << "Remaining Balance : " << balance << " FRW" << endl;
        cout << "\033[0m";
    }
}

void viewTransactions() {
    cout << "\n\033[36m====== TRANSACTION HISTORY ======\033[0m" << endl;

    if (transCount == 0) {
        cout << "\033[31mNo Transactions Found\033[0m" << endl;
    } else {
        for (int i = 0; i < transCount; i++) {
            cout << i + 1 << ". " << transactionHistory[i] << endl;
        }
    }
}

bool login() {
    int pin;
    int attemptsLeft = MAX_ATTEMPTS;

    do {
        cout << "\tEnter your PIN : ";
        cin >> pin;
        attemptsLeft--;

        if (pin == DEFAULT_PIN) {
            cout << "\033[32m\n\tLogin Successful\033[0m" << endl;
            cout << "\033[35m\tWelcome to BK ATM\033[0m" << endl;
            return true;
        } else {
            cout << "\033[31m\nWrong PIN\033[0m" << endl;
            if (attemptsLeft > 0) {
                cout << "\033[33mRemaining Attempts : " << attemptsLeft << "\033[0m" << endl;
            }
        }

    } while (attemptsLeft > 0);

    cout << "\033[31m\nATM BLOCKED\033[0m" << endl;
    return false;
}

int main() {
    displayHeader();

    if (!login()) return 0;

    int choice;
    do {
        displayMenu();
        cout << "\nEnter your choice : ";
        cin >> choice;

        switch (choice) {
            case 1: checkBalance();     break;
            case 2: depositMoney();     break;
            case 3: withdrawMoney();    break;
            case 4: viewTransactions(); break;
            case 5:
                cout << "\033[33m\nThank You For Using BK ATM\033[0m" << endl;
                break;
            default:
                cout << "\033[31m\nInvalid Choice\033[0m" << endl;
        }

    } while (choice != 5);

    return 0;
}