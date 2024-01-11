#include "Header.h"
#include "Page.h"

void reg()
{
    string confirmPass, newPass;
    int numLog;

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
    ofstream out1("passwords.txt", std::ios_base::app);
    if (out1.is_open())
    {
        string Pass;
        cin >> Pass;
        out1 << Pass << endl;
        out1.close();
        newPass = Pass;
    }

    cout << endl << "Confirm the password: ";
    cin >> confirmPass;

    if (confirmPass == newPass) 
    {
        //Add smth like a check mark
        cout << "\n===================================\n";
        cout << "\nSuccessfully new account created! \n \n";
        cout << "===================================\n";
        cout << endl;
        cout << "If you want to login in your account enter '1':" << endl;
    }
    else 
    {
        cout << endl << "Password confirmation not correct!" << endl;

    }

    // Add system("cls")
    cin >> numLog;
    if (numLog == 1)
    {
        login();
    }
}

bool check(string username, string password, string userFile, string passFile)
{
    ifstream file(userFile);
    ifstream file1(passFile);

    string storedUsername;
    string storedPassword;

    while (file >> storedUsername && file1 >> storedPassword)
    {
        if (storedUsername == username)
        {
            file.close();
            file1.close();
            return storedPassword == password;
        }
    }

    file.close();
    file1.close();
}


void login()
{
    string userName, Pass;

    cout << endl << "Enter Your UserName: ";
    cin >> userName;

    cout << endl << "Enter Your password: ";
    cin >> Pass;

    if (check(userName, Pass, "names.txt", "passwords.txt")) 
    {
        cout << "Hello " << userName << "," << endl << "This is your bank account!" << endl;
        account();
    }
    else 
    {
        cout << endl << "Invalid username or password." << endl;
    }

}

