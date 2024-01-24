#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <conio.h>

using namespace std;
//add functions for password
void gateway();
bool userExists(string username);
bool checkPass(string Pass);
void enterPass(string newPass, string confirmPass);
void reg();
bool check(string username, string password, string userFile, string passFile);
void login();
void mainMenu();

