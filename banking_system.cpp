#include <iostream>
#include <vector>
#include <string>
using namespace std;

class BankAccount {
private:
    string accountNumber;
    string accountHolder;
    double balance;

public:
    BankAccount(string accNum, string accHolder, double initialBalance) {
        accountNumber = accNum;
        accountHolder = accHolder;
        balance = initialBalance;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: $" << amount << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: $" << amount << endl;
        } else {
            cout << "Insufficient funds" << endl;
        }
    }

    void displayBalance() {
        cout << "Account Balance: $" << balance << endl;
    }

    string getAccountNumber() {
        return accountNumber;
    }
};

class BankingSystem {
private:
    vector<BankAccount> accounts;

public:
    void createAccount() {
        string accNum, accHolder;
        double initialBalance;
        
        cout << "Enter account number: ";
        cin >> accNum;
        cout << "Enter account holder name: ";
        cin.ignore();
        getline(cin, accHolder);
        cout << "Enter initial balance: ";
        cin >> initialBalance;

        accounts.push_back(BankAccount(accNum, accHolder, initialBalance));
        cout << "Account created successfully!" << endl;
    }

    BankAccount* findAccount(string accNum) {
        for (auto &account : accounts) {
            if (account.getAccountNumber() == accNum) {
                return &account;
            }
        }
        return nullptr;
    }

    void performTransaction() {
        string accNum;
        int choice;
        double amount;

        cout << "Enter account number: ";
        cin >> accNum;

        BankAccount* account = findAccount(accNum);
        if (account == nullptr) {
            cout << "Account not found!" << endl;
            return;
        }

        cout << "1. Deposit\n2. Withdraw\n3. Check Balance\nChoice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter amount to deposit: ";
                cin >> amount;
                account->deposit(amount);
                break;
            case 2:
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                account->withdraw(amount);
                break;
            case 3:
                account->displayBalance();
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    }
};

int main() {
    BankingSystem bank;
    int choice;

    while (true) {
        cout << "\n1. Create Account\n2. Perform Transaction\n3. Exit\nChoice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                bank.createAccount();
                break;
            case 2:
                bank.performTransaction();
                break;
            case 3:
                return 0;
            default:
                cout << "Invalid choice!" << endl;
        }
    }
}