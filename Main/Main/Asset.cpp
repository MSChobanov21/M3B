#include "Asset.h"
#include "Page.h"


void asset(double balance)
{
    cout << "Who do you want to transfer money to?" << endl;
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
        cout << "What amount of money do you wish to transfer to " << uName << "?" << endl;
        double transferSum;
        cin >> transferSum;
        if (transferSum <= balance)
        {
            cout << "Transfer was successful!" << endl;
            balance -= transferSum;
            cout << "Your updated balance is: " << balance << endl;
        }
        else
        {
            cout << "Transfer cancelled, please try again!" << endl;
        }
    }
    else
    {
        cout << "Invalid Username";
    }
}