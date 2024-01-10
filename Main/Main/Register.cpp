#include "Header.h"

struct Account
{
    string newPass;
    string newName;
};

void reg()
{
    string confirmPass;
    int MiniPass;
    Account acc;

    cout << endl << "**** Create New Account ****" << endl;

    cout << endl << "Enter New UserName: ";

    ofstream out("names.txt", std::ios_base::app);
    if (out.is_open())
    {
        string name;
        cin >> name;
        out << name << endl;
        out.close();
        acc.newName = name;
    }

    cout << endl << "Enter New password: ";
    // make it cin * instead of the password
    ofstream out1("passwords.txt", std::ios_base::app);
    if (out1.is_open())
    {
        string Pass;
        cin >> Pass;
        out1 << Pass << endl;
        out1.close();
        acc.newPass = Pass;
    }

    cout << endl << "Confirm the password: ";
    cin >> confirmPass;

    /*MiniPass = acc.newPass.length();

    if (MiniPass < 8) 
    {
        cout << endl << "Your password is weak at least 8 letters!" << endl;
    }*/
    if (confirmPass == acc.newPass) 
    {
        //Add smth like a check mark
        cout << "\n===================================\n";
        cout << "\nSuccessfully new account created! \n \n";
        cout << "===================================\n";
    }
    else 
    {
        cout << endl << "Password confirmation not correct!" << endl;

    }
}

void login()
{
    string userName, Pass;
    int MiniPass;
    Account acc;

    cout << endl << "Enter Your UserName: ";
    cin >> userName;

    cout << endl << "Enter Your password: ";
    cin >> Pass;

    /*MiniPass = Pass.length();

    if (MiniPass < 8)
    {
        cout << endl << "Your password is weak at least 8 letters!" << endl;
    }*/
    while (Pass == acc.newPass)
    {
        cout << endl << "Successfully login!" << endl;
    }

    while (userName == acc.newName)
    {
        cout << endl << "Successfully login!" << endl;
    }


    if (Pass != acc.newPass && userName != acc.newName)
    {
        cout << endl << "Your username is wrong!" << endl;
        cout << endl << "Your password is wrong!" << endl;
    }
}

