#include "Header.h"

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

void login()
{
    string userName, Pass;

    cout << endl << "Enter Your UserName: ";
    cin >> userName;

    cout << endl << "Enter Your password: ";
    cin >> Pass;

    ifstream file("names.txt");
    bool found = false;
    string line;
    while (getline(file, line)) 
    {
        if (line.find(userName) != string::npos) 
        {
            found = true;
            break;
        }
    }
    file.close();

    ifstream file1("passwords.txt");
    bool found1 = false;
    string line1;
    while (getline(file1, line1))
    {
        if (line1.find(Pass) != string::npos)
        {
            found1 = true;
            break;
        }
    }
    file1.close();

    if (found == true && found1 == true) 
    {
        cout << endl << "Successfully login!" << endl;
    }
    else if(found == false)
    {
        cout << endl << "Wrong username!" << endl;
    }
    else if (found1 == false)
    {
        cout << endl << "Wrong password!" << endl;
    }

}

