#include "Liability.h"
#include "Register.h"



void yourProperties(int liab, string house1, string house2, string house3, string house4, string house5,
    string house6, string house7, string house8, string house9)
{
    house1 = "Apartement in Sofia, Bulgaria";
    house2 = "Apartment is Burgas, Bulgaria";
    house3 = "House in Burgas, Bulgaria";
    house4 = "House in Yambol, Bulgaria";
    house5 = "Apartment in Sydney, Australia";
    house6 = "Apartment in Istanbul, Turkey";
    house7 = "House in Galabovo, Bulgaria";
    house8 = "Apartment in Plovdiv, Bulgaria";
    house9 = "House in Varna, Bulgaria";

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

void liability()
{
    srand(static_cast<unsigned int>(time(0)));
    int liab = rand() % 9 + 1;
    string house1, house2, house3, house4, house5, house6, house7, house8, house9;
    cout << "Those are your liabilities: " << endl;
    yourProperties(liab, house1, house2, house3, house4, house5, house6, house7, house8, house9);

    cout << endl << "Who do you want to bequeath a property to?" << endl;
    cout << "Enter username: ";
    string uName;
    cin >> uName;

    ifstream file("names.txt");
    bool found = false;
    string line;
    while (getline(file, line))
    {
        if (line.find(uName) != string::npos)
        {
            found = true;
        }
    }
    file.close();

    if (found)
    {
        cout << "Which property do you want to bequeath to " << uName << "?" << endl;
        cout << "Enter Apartment or House: " << endl;
        string house, city;
        cin >> house;
        cout << "Enter city, country";
        getline(cin, city);
        cout << "Bequeath was successful!" << endl;
        system("cls");
        mainMenu();

    }
    else
    {
        cout << "Bequeath cancelled, please try again!" << endl;

    }
}