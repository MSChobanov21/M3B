#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <sstream>
using namespace std;

void account();
void exc(int num);
void asset(int balance);
//void Will();
void balance();
void saveBalanceToFile(double balance, string user);
void addMoney(double& balance);