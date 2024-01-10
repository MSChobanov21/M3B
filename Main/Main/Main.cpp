#include "Header.h"
#include "Page.h"

int main() 
{
    string answer;

    cout << "Do you have an account or want to create a new one?" << endl;
    cin >> answer;
    if (answer == "create")
    {
        reg();
    }
    else if (answer == "login")
    {
        login();
    }
}





