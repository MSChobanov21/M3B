#include "Page.h"

void exc(int num)
{
    try
    {
        num != 1;
        num != 2;
        num != 3;
        throw num;
    }
    catch (int choose1)
    {
        cout << "Please enter a number between 1,2 and 3.";
    }
}


void asset(int balance)
{
    cout << "Who do you want to transfer money to?" << endl;
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
        cout << "What amount of money do you wish to transfer to " << uName << "?" << endl;
        int transferSum;
        cin >> transferSum;
        if (transferSum <= balance)
        {
            cout << "Transfer was successful!" << endl;
            balance -= transferSum;
            cout << "Your updated balance is: " << balance << endl;
        }
        else
        {
            cout << "Transfer cancelled, please try again!" << endl;
        }
    }
    else 
    {
        cout << "Invalid Username";
    }
}


//void Will()
//{
//    if ()
//    {
//        cout << "No wills sent" << endl;
//    }
//    else
//    {
//        cout << "You have a will from:" << 
//    }
//}


void balance()
{
    string num;
    char checkMoney;
    cout << endl << "If you have money in your bank enter 1 to saw it if you want add money enter 2:" << endl;
    cin >> checkMoney;


    if (checkMoney == '2')
    {
        cout << endl << "Enter you money:" << endl;

        ofstream out("money.txt", std::ios_base::app);
        if (out.is_open())
        {
            string money;
            cin >> money;
            out << money << endl;
            out.close();
            cout << "Your balance is:" << money << endl;
            num = money;
        }
    }
    if (checkMoney == '1')
    {

        string money = num;
        ifstream file("money.txt");
        bool found = false;
        string line;
        while (getline(file, line))
        {
            if (line.find(money) != string::npos)
            {
                found = true;

            }
        }
        file.close();

        if (found)
        {
            cout << "Your balance is:" << money << endl;
        }
        else
        {
            cout << "Error";
        }

    }
}


void account()
{
    srand(static_cast<unsigned int>(time(0)));

    /*int balance = rand() % 499000 + 1000;

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
    house9 = "House in Varna, Bulgaria";*/


    cout << "Hello, " << endl << "This is your bank account!" << endl;
    //cout << "This is the value of your assets: " << balance << endl;
    balance();


    cout << "Those are your liabilities: " << endl;


    /*switch (liab)
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
    };*/


    cout << endl;
    cout << "If you wish to bequeath an asset,liability or will, you can choose from the options bellow." << endl;
    cout << "1. Asset" << endl;
    cout << "2. Liability" << endl;
    cout << "3. Will" << endl;


    int choose;
    cin >> choose;
    if (choose == 1)
    {
        //asset();
    }
    else if (choose == 2)
    {

    }
    else if (choose == 3)
    {

    }
    else
    {
        exc(choose);
    }
}

    