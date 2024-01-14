#include "Page.h"
#include "Asset.h"
#include "Liability.h"
#include "Register.h"

void exc(int num)
{
    try
    {
        num != 1;
        num != 2;
        num != 3;
        throw num;
    }
    catch (int choose1)
    {
        cout << "Please enter a number between 1,2 and 3.";
    }
}


// Function to add money to the account
void addMoney(double& balance) 
{
    double amount;
    cout << "Enter the amount to add: ";
    cin >> amount;
        
    balance += amount;

    cout << "Money added successfully. New balance: " << balance << endl;
    cout << "Before you make will save your money!" << endl;
}

// Function to save balance to a text file
void saveBalanceToFile(double balance, string user) 
{
    ofstream file(user + ".txt");

    if (file.is_open()) 
    {
        file << balance;
        file.close();
        cout << "Balance saved to file." << endl;
    }
}


void menuBalance(double balance, string userName)
{
    char choice;
    do {
        cout << "1. Add money" << endl;
        cout << "2. Save balance" << endl;
        cout << "3. Make will" << endl;
        cout << "4. Logout" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case '1':
            system("cls");
            addMoney(balance);
            break;
        case '2':
            saveBalanceToFile(balance, userName);
            break;
        case '3':
            menu(balance, userName);
            break;
        case '4':
            system("cls");
            mainMenu();
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != '4');
}

double balanceFunc(string userName)
{
    double balance = 0.0;

    // Load previous balance from file (if available)
    ifstream file(userName + ".txt");
    if (file.is_open()) 
    {
        file >> balance;
        file.close();
        cout << "Previous balance loaded: " << balance << endl;
    }

    menuBalance(balance, userName);

    return balance;

}


void menu(double currentBalance, string user)
{
    char choose;
    do 
    {
        system("cls");
        cout << endl;
        cout << "If you wish to bequeath an asset or liability you can choose from the options bellow." << endl;
        cout << "1. Asset" << endl;
        cout << "2. Liability" << endl;
        cout << "3. Return" << endl;
        cin >> choose;
        switch (choose)
        {
        case '1':
            system("cls");
            asset(currentBalance, user);
            break;
        case '2':
            system("cls");
            liability();
            break;
        case '3':
            system("cls");
            //menuBalance(currentBalance, string userName);
            break;
        default:
            exc(choose);
        }
    } while (choose != '3');

}

void account(string user)
{
    
    double currentBalance = balanceFunc(user);
    menu(currentBalance, user);
}

    