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
    double amount;
    cout << "Enter the amount to add: ";
    cin >> amount;

    // Update balance
    balance += amount;

    cout << "Money added successfully. New balance: " << balance << endl;
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
    // Menu for adding money
    char choice;
    do {
        cout << "1. Add money" << endl;
        cout << "2. Save balance" << endl;
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
        default:
            cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != '2');
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


void menu(double currentBalance)
{
    system("cls");
    cout << endl;
    cout << "If you wish to bequeath an asset or liability you can choose from the options bellow." << endl;
    cout << "1. Asset" << endl;
    cout << "2. Liability" << endl;

    int choose;
    cin >> choose;
    if (choose == 1)
    {
        system("cls");
        asset(currentBalance);
    }
    else if (choose == 2)
    {
        srand(static_cast<unsigned int>(time(0)));
        int liab = rand() % 9 + 1;
        string house1, house2, house3, house4, house5, house6, house7, house8, house9;
        properties(house1, house2, house3, house4, house5, house6, house7, house8, house9);
        cout << "Those are your liabilities: " << endl;
        yourProperties(liab, house1, house2, house3, house4, house5, house6, house7, house8, house9);
        
            cout << "Who do you want to bequeath a property to?" << endl;
            cout << "Enter username: ";
            string uName;
            cin >> uName;

            ifstream file("names.txt");
            bool found = false;
            string line;
            while (getline(file, line))
            {
                if (line.find(uName) != string::npos)
                {
                    found = true;
                }
            }
            file.close();

            if (found)
            {
                cout << "Which property do you want to bequeath to " << uName << "?" << endl;
                cout << "Enter Apartment or House: " << endl;
                string house, city;
                cin >> house;
                cout << "Enter city, country";
                getline(cin, city);
                cout << "Bequeath was successful!" << endl;
                system("cls");
                mainMenu();

            }
            else
            {
                cout << "Bequeath cancelled, please try again!" << endl;

            }
        }
    }




void account(string user)
{
    
    double currentBalance = balanceFunc(user);
    menu(currentBalance);
}

    