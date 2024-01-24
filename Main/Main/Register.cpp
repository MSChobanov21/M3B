#include "Register.h"
#include "Page.h"
#include "Asset.h"
#include "Front-end.h"


string path;
void gateway()
{
    displayFunc("../../textFiles/balance.txt");
}

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

bool checkPass(string Pass) //pasword requierments
{
    if (Pass.length() < 8) 
    {
        cout << "Password should be at least 8 characters long." << endl;
        return false;
    }

    bool Upper = false;
    for (char ch : Pass) 
    {
        if (isupper(ch)) 
        {
            Upper = true;
        }
    }
    if (!Upper) 
    {
        cout << "Password should contain at least one uppercase letter." << endl;
        return false;
    }

    bool Lower = false;
    for (char ch : Pass) 
    {
        if (islower(ch)) 
        {
            Lower = true;
        }
    }
    if (!Lower) 
    {
        cout << "Password should contain at least one lowercase letter." << endl;
        return false;
    }

    bool Digit = false;
    for (char ch : Pass) 
    {
        if (isdigit(ch)) 
        {
            Digit = true;
        }
    }
    if (!Digit) 
    {
        cout << "Password should contain at least one digit." << endl;
        return false;
    }

    bool specialChar = false;
    for (char ch : Pass) 
    {
        if (!isalnum(ch)) 
        {
            specialChar = true;
        }
    }
    if (!specialChar) 
    {
        cout << "Password should contain at least one special character." << endl;
        return false;
    }

    return true;
}

//enter your password
void enterPass(string newPass, string confirmPass)
{
    string Pass;
    cout << endl << "Enter new password: ";
    cin >> Pass;
    if (checkPass(Pass))
    {
        ofstream out1("passwords.txt", std::ios_base::app);
        if (out1.is_open())
        {
            out1 << Pass << endl;
            out1.close();
            newPass = Pass;

        }
        cout << endl << "Confirm the password: ";
        cin >> confirmPass;

        if (confirmPass == newPass)
        {
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
    else
    {
        enterPass(newPass, confirmPass);
    }
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

        cout << endl << "Password requirements:" << endl;
        cout << "The password should be at least 8 characters long," << endl;
        cout << "The password should contain at least one uppercase letter," << endl;
        cout << "The password should contain at least one lowercase letter," << endl;
        cout << "The password should contain at least one digit," << endl;
        cout << "The password should contain at least one special character!" << endl;
        enterPass(newPass, confirmPass);

    }
    
    
    do
    {
        cin >> numLog;
        switch (numLog)
        {
        case '1':
            system("cls");
            path = "../../textFiles/login.txt";
            displayFunc(path);
            login();
            break;
        default:
            cout << "Wrong input. Try again:";
        }
    } while (numLog != '1');
}
//check if the username and password exist
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
    char ch;

    cout << endl << "Enter your username: ";
    cin >> userName;

    cout << endl << "Enter your password: ";
    while ((ch = _getch()) != '\r')
    {
        cout << '*';
        Pass += ch;
    }

    if (check(userName, Pass, "names.txt", "passwords.txt")) 
    {
        system("cls");

        path = "../../textFiles/acc.txt";
        displayFunc(path);
        path = "../../textFiles/styling.txt";
        displayFunc(path);

        cout << "Hello " << userName << "," << endl << "This is your bank account!" << endl;
        
        balanceFunc(userName);
    }
    else 
    {
        cout << endl << "Invalid username or password. Try again!" << endl;
        login();
    }

}

//choose from 2 options
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
        system("cls");
        cout << "Invalid input" << endl;
        mainMenu();
        
    }
    
}

