#include "Page.h"
#include "Asset.h"
#include "Register.h"


void exc(int num)
{
    try
    {
        num != 1;
        num != 2;
        throw num;
    }
    catch (int choose1)
    {
        cout << "Please enter a number between 1 and 2.";
    }
}


// Function to add money to the account
void addMoney(double& balance) 
{
    gateway();

    double amount;
    cout << "Enter the amount to add: ";

    

    while(!(cin >> amount))
    {
        cout << "Please enter number!" << endl;
        cin.clear();
        cin.ignore(100, '\n');
    }
    balance += amount;
    cout << "Money added successfully. New balance: " << balance << endl;
    cout << "Before you make will save your money!" << endl;
    
    
}

// Function to save balance to a file
void saveBalanceToFile(double balance, string user) 
{
    ofstream file(user + ".txt");

    if (file.is_open()) 
    {

        file << balance;
        file.close();

        gateway();

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
            system("cls");
            saveBalanceToFile(balance, userName);
            break;
        case '3':
            system("cls");
            asset(balance, userName);
            break;
        case '4':
            system("cls");
            mainMenu();
            break;
        default:
            system("cls");
            cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != '4');
}

double balanceFunc(string userName)
{
    double balance = 0.0;

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



    