#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <sstream>
using namespace std;


void exc(int num);
void addMoney(double& balance);
void saveBalanceToFile(double balance, string user);
double balanceFunc(string userName);
void menu(double currentBalance);
void account(string user);