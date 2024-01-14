#include "Asset.h"
#include "Page.h"
#include "Register.h"

double sum(string userName)
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


void asset(double balance)
{
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
        cin >> transferSum;
        if (transferSum <= balance)
        {
            cout << "Bequeath was successful!" << endl;
            balance -= transferSum;
            cout << "If you want to see your balance after bequeath enter your username:" << endl;
            string yourUsername;
            cin >> yourUsername;
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
            cout << "Bequeath cancelled, please try again!" << endl;
        }
    }
    else
    {
        cout << "Invalid Username";
    }

}

