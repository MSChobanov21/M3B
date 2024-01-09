#include <iostream>
#include <string>
#include "Header.h"

using namespace std;

struct houseInfo {
    string address;
    float price;
    string owner;
};

struct infoBank {
    string firstName;
    string lastName;
    float balance;
    houseInfo house;
    int cars;
};

struct person{
    string firstName;
    string lastName;
    float balance;
    int house;
    int cars;
};


int main() 
{
    infoBank you;
    string answer;

    cout << "Do you have an account or want to create a new one?" << endl;
    cin >> answer;
    if (answer == "create")
    {
        reg();
    }
    else if (answer == "login")
    {
        
    }
}




/*


        cout << "Enter you first name: ";
        cin >> you.firstName;
        cout << endl << "Enter you last name: ";
        cin >> you.lastName;
    
        cout << endl << "Enter you balance: ";
        cin >> you.balance;

        if (sizeof(you.balance) == 1)
            cout << "Your balance is wrong"; // need to be fixed

        cout << endl << "Hi " << you.firstName << " " << you.lastName << "," << endl << "Do you want to inherit a property" << endl;
        cin >> answer;
        if (answer == "Yes")
        {
            cout << "Please enter the address of the property: ";
            cin >> you.house.address;
        }
        else
        {
            cout << "Okay.";
        }


*/


