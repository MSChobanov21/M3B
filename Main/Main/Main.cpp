#include <iostream>
#include <string>

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


int main() {
    infoBank you;
    string answer;
    cout << "Enter you first name: ";
    cin >> you.firstName;
    cout << endl << "Enter you last name: ";
    cin >> you.lastName;
    
    cout << endl << "Enter you balance: ";
    cin >> you.balance;

    if (sizeof(you.balance) == 1)
        cout << "Your balance is wrong"; // need to be fixed

}