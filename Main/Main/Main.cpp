#include <iostream>
#include <string>
#include "Header.h"
#include <cstdlib>
#include <ctime>

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
        login();
    }


        srand(static_cast<unsigned int>(time(0)));
        int balance = rand() % 499000 + 1000;
        int liab = rand() % 9 + 1;
        string house1, house2, house3, house4, house5, house6, house7, house8, house9;
        house1 = "Apartement in Sofia, Bulgaria";
        house2 = "Apartment is Burgas, Bulgaria";
        house3 = "House in Burgas, Bulgaria";
        house4 = "House in Yambol, Bulgaria";
        house5 = "Apartment in Sydney, Australia";
        house6 = "Apartment in Istanbul, Turkey";
        house7 = "House in Galabovo, Bulgaria";
        house8 = "Apartment in Plovdiv, Bulgaria";
        house9 = "House in Varna, Bulgaria";
        cout << "Hello, " << endl << "This is your bank account!";
        cout << "This is the value of your assets: " << balance << endl;
        cout << "Those are your liabilities: " << endl;
        switch (liab)
        {
        case 1: cout << house1 << endl << house3; break;
        case 2: cout << house5; break;
        case 3: cout << house6; break;
        case 4: cout << house2 << endl << house4; break;
        case 5: cout << house7 << endl << house8; break;
        case 6: cout << house8; break;
        case 7: cout << house2; break;
        case 8: cout << house1 << endl << house8 << endl << house4; break;
        case 9: cout << house9; break;
        };

}





