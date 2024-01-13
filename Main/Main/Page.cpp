#include "Page.h"
#include "Asset.h"

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
    else 
    {
        cout << "Error: Unable to open file for saving balance." << endl;
    }
}


double balanceFunc(string userName)
{
    double balance = 0.0;
    /*string userName;
    cout << "Enter again you username to check balance:" << endl;
    cin >> userName;*/

    // Load previous balance from file (if available)
    ifstream file(userName + ".txt");
    if (file.is_open()) 
    {
        file >> balance;
        file.close();
        cout << "Previous balance loaded: " << balance << endl;
    }

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
            addMoney(balance);
            break;
        case '2':
            saveBalanceToFile(balance, userName);
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != '2');

    return balance;

}


void menu(double currentBalance)
{
    cout << endl;
    cout << "If you wish to bequeath an asset or liability you can choose from the options bellow." << endl;
    cout << "1. Asset" << endl;
    cout << "2. Liability" << endl;

    int choose;
    cin >> choose;
    if (choose == 1)
    {
        asset(currentBalance);
    }
    else if (choose == 2)
    {

    }
    else
    {
        exc(choose);
    }
}


void account(string user)
{
    srand(static_cast<unsigned int>(time(0)));

    /*int balance = rand() % 499000 + 1000;

    int liab = rand() % 9 + 1;
    string house1, house2, house3, house4, house5, house6, house7, house8, house9;
    house1 = "Apartement in Sofia, Bulgaria";
    house2 = "Apartment is Burgas, Bulgaria";
    house3 = "House in Burgas, Bulgaria";
    house4 = "House in Yambol, Bulgaria";
    house5 = "Apartment in Sydney, Australia";
    house6 = "Apartment in Istanbul, Turkey";
    house7 = "House in Galabovo, Bulgaria";
    house8 = "Apartment in Plovdiv, Bulgaria";
    house9 = "House in Varna, Bulgaria";
    */
    //cout << "This is the value of your assets: " << balance << endl;
    double currentBalance = balanceFunc(user);



    cout << "Those are your liabilities: " << endl;


    /*switch (liab)
    {
    case 1: cout << house1 << endl << house3; break;
    case 2: cout << house5; break;
    case 3: cout << house6; break;
    case 4: cout << house2 << endl << house4; break;
    case 5: cout << house7 << endl << house8; break;
    case 6: cout << house8; break;
    case 7: cout << house2; break;
    case 8: cout << house1 << endl << house8 << endl << house4; break;
    case 9: cout << house9; break;
    };*/
    menu(currentBalance);
}

    