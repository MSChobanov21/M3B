#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;
//functions for assets
double sum(string userName);
void send(string user, double balance, double transferSum);
void asset(double balance, string user);
void seeYourBalance(double balance, string user, string uName, double transferSum);