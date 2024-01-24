#include "Asset.h"
#include "Page.h"
#include "Register.h"

double sum(string userName) //enter balance
{
    double balance = 0.0;
    ifstream file(userName + ".txt");
    if (file.is_open())
    {
        file >> balance;
        file.close();
        return balance;
    }
}

void send(string user, double balance, double transferSum) 
{
    ofstream file(user + ".txt");

    if (file.is_open())
    {
        balance = balance + transferSum;
        file << balance;
        file.close();
        cout << "Balance saved to file." << endl;
    }
}


void seeYourBalance(double balance, string user, string uName, double transferSum) // go back to menu
{
    cout << "To see your balance after bequeath enter your username:" << endl;
    cout << "Enter you username:";
    string yourUsername;
    cin >> yourUsername;
    if (user == yourUsername)
    {
        saveBalanceToFile(balance, yourUsername);
        system("cls");
        cout << "Your updated balance is: " << balance << endl;
        double balanceSum = sum(uName);
        send(uName, balanceSum, transferSum);
        menuBalance(balanceSum, yourUsername);
        system("cls");
        mainMenu();
    }
    else
    {
        //check for username
        cout << "Invalid Username" << endl;
        seeYourBalance(balance, user, uName, transferSum);
    }
}


void asset(double balance, string user)
{
    //send an amount of money
    cout << "Who do you want to bequeath money to?" << endl;
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
        cout << "What amount of money do you want to bequeath to " << uName << "?" << endl;
        cout << "Enter amount: ";
        double transferSum;
        
        while (!(cin >> transferSum))
        {
            cout << "Please enter number!" << endl;
            cin.clear();
            cin.ignore(100, '\n');
        }
        if (transferSum <= balance)
        {
            cout << "Bequeath was successful!" << endl;
            balance -= transferSum;
            seeYourBalance(balance, user, uName, transferSum);
                

        }
        else
        {
            system("cls");
            cout << "Bequeath cancelled, please try again!" << endl;
            asset(balance, user);
        }
    }
    else
    {
        cout << "Invalid Username. Try again!" << endl;
        asset(balance, user);
    }

}





