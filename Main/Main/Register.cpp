#include "Header.h"

void reg()
{
	string newName, newPass, confirmPass;
    int MiniPass;

    cout << endl << "**** Create New Account ****" << endl;

    cout << endl << "Enter New UserName: ";
    cin >> newName;

    cout << endl << "Enter New password: ";
    cin >> newPass; // make it cin * instead of the password

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

