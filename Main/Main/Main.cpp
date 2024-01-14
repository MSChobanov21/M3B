#include "Register.h"

int main() 
{
    string answer;

    cout << "If you have an account enter 'login' or if you want to create a new one enter 'create'!" << endl;
    cin >> answer;
    if (answer == "create")
    {
        system("cls");
        reg();
    }
    else if (answer == "login")
    {
        system("cls");
        login();
    }
    else if (answer != "create" or answer != "login")
    {
        cout << "Invalid input";
    }
}





