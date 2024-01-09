#include "Header.h"

void reg()
{
    string newPass, confirmPass;
    int MiniPass;

    cout << endl << "**** Create New Account ****" << endl;

    cout << endl << "Enter New UserName: ";

    ofstream out("names.txt", std::ios_base::app);
    if (out.is_open())
    {
        string name;
        cin >> name;
        out << name << endl;
        out.close();
    }


    cout << endl << "Enter New password: ";
    // make it cin * instead of the password
    ofstream out("passwords.txt", std::ios_base::app);
    if (out.is_open())
    {
        string name;
        cin >> name;
        out << name << endl;
        out.close();
    }

    cout << endl << "Confirm the password: ";
    cin >> confirmPass;

    MiniPass = newPass.length();

    if (MiniPass < 8) {
        cout << endl << "Your password is weak at least 8 letters!" << endl;
    }
    else if (confirmPass == newPass) 
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

}

