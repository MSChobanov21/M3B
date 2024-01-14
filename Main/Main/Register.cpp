#include "Register.h"
#include "Page.h"
#include "Asset.h"
#include "Front-end.h"


string path;

bool userExists(string username)
{
    ifstream file("names.txt");
    string line;
    getline(file, line);
    
        if (line.find(username) != string::npos)
        {
            file.close();
            return true;
        }
    

    file.close();
    return false;
}


void reg()
{
    

    string confirmPass, newPass, newName;
    char numLog;

    cout << endl << "**** Create New Account ****" << endl;

    cout << endl << "Enter new username: ";

    ofstream out("names.txt", std::ios_base::app);
    if (out.is_open())
    {
        string name;
        cin >> name;
        out << name << endl;
        out.close();
        newName = name;
    }
    if (userExists(newName))
    {
        system("cls");
        cout << "Username already exists. Try a different one." << endl;
        reg();
    }
    else
    {
        cout << endl << "Enter new password: ";
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
    }
    
    cin >> numLog;
    if (numLog == '1')
    {
        system("cls");
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
    return false;
}


void login()
{
    string userName, Pass;

    cout << endl << "Enter your username: ";
    cin >> userName;

    cout << endl << "Enter your password: ";
    cin >> Pass;

    if (check(userName, Pass, "names.txt", "passwords.txt")) 
    {
        system("cls");

        path = "../../textFiles/acc.txt";
        displayFunc(path);

        cout << "Hello " << userName << "," << endl << "This is your bank account!" << endl;
        account(userName);
    }
    else 
    {
        cout << endl << "Invalid username or password. Try again!" << endl;
        login();
    }

}


void mainMenu()
{
    string answer;
    string path = "../../textFiles/mainMenu.txt";
    displayFunc(path);
    cout << "If you have an account enter 'login' or if you want to create a new one enter 'create'!" << endl;
    cout << "Enter answer: ";
    cin >> answer;
    if (answer == "create")
    {
        system("cls");
        path = "../../textFiles/register.txt";
        displayFunc(path);
        reg();
    }
    else if (answer == "login")
    {
        system("cls");
        path = "../../textFiles/login.txt";
        displayFunc(path);
        login();
    }
    else if (answer != "create" or answer != "login")
    {
        cout << "Invalid input" << endl;
    }
    
}

