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


/*void balance()
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
}*/


int changeBalance(int data, int newD)
{
    // Step 1: Open the file for reading and writing
    ifstream inFile("balance.txt");

    // Step 2: Read the content of the file
    string content;
    string line;
    while (getline(inFile, line)) 
    {
        content += line + '\n';
    }

    // Step 3: Modify the specific information
    // For example, let's say you want to replace "old_data" with "new_data"
    string oldData = to_string(data);
    string newData = to_string(newD);
    size_t pos = content.find(oldData);
    if (pos != string::npos) 
    {
        content.replace(pos, oldData.length(), newData);
    }
    else 
    {
        cerr << "Data not found in the file." << endl;
        inFile.close();
        return 1;
    }

    // Step 4: Write the modified content back to the file
    ofstream outFile("balance.txt");

    outFile << content;

    // Close the files
    inFile.close();
    outFile.close();

    cout << "File updated successfully." << endl;

    return 0;
}
/*
// Function to add money to the account
void addMoney(double& balance) 
{
    double amount;
    cout << "Enter the amount to add: ";
    cin >> amount;

    // Update balance
    balance += amount;

    cout << "Money added successfully. New balance: " << balance << endl;
}

// Function to save balance to a text file
void saveBalanceToFile(double balance) {
    ofstream file("balance.txt");

    if (file.is_open()) {
        file << balance;
        file.close();
        cout << "Balance saved to file." << endl;
    }
    else {
        cout << "Error: Unable to open file for saving balance." << endl;
    }
}*/


void balance()
{
    double balance = 0.0;

    // Load previous balance from file (if available)
    ifstream file("balance.txt");
    if (file.is_open()) {
        file >> balance;
        file.close();
        cout << "Previous balance loaded: " << balance << endl;
    }
    else {
        cout << "No previous balance found. Starting with a balance of 0." << endl;
    }

    double newBalance = balance;

    // Menu for adding money
    char choice;
    do {
        cout << "1. Add money\n";
        cout << "2. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case '1':
            //addMoney(balance);

            double amount;
            cout << "Enter the amount to add: ";
            cin >> amount;

            // Update balance
            
            newBalance += amount;

            cout << "Money added successfully. New balance: " << newBalance << endl;

            break;
        case '2':
            cout << changeBalance(balance, newBalance);
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != '2');
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
    house9 = "House in Varna, Bulgaria";
    */
    
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
        //asset(); - trqbva balans
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

    