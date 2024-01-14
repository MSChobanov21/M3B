#include <iostream>
#include <fstream>
#include <string>


void displayFunc(string path)
{
    fstream newfile;

    newfile.open(path, ios::in); //open a file to perform read operation using file object
    if (newfile.is_open()) { //checking whether the file is open
        string tp;
        while (getline(newfile, tp)) { //read data from file object and put it into string.
            cout << tp << endl; //print the data of the string
        }
        newfile.close(); //close the file object.
    }
}

