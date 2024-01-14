#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool userExists(string username);
void reg();
bool check(string username, string password, string userFile, string passFile);
void login();
void mainMenu();