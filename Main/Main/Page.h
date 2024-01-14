#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;


void exc(int num);
void addMoney(double& balance);
void saveBalanceToFile(double balance, string user);
void menuBalance(double balance, string userName);
double balanceFunc(string userName);
void menu(double currentBalance);
void account(string user);