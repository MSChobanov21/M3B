#include "Page.h"

void account()
{
    char checkMoney;
    cout << endl << "If you have money in your Will enter 1 to saw it if you want add you balance enter 2:" << endl;
    cin >> checkMoney;

    if (checkMoney == '1')
    {
        double money;
        ifstream file("money.txt");
        file >> money;
        cout << money;
    }
    else if (checkMoney == '2')
    {
	    cout << endl << "Enter you money:" << endl;
	
        ofstream out("money.txt", std::ios_base::app);
        if (out.is_open())
        {
            double money;
            cin >> money;
            out << money << endl;
            out.close();
        }
    }




}