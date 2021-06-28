#pragma once
#include <iostream>
#include <mysql.h>
#include <stdlib.h>
using namespace std;

void insertIncome(string content[5], string user, string pass);
void insertEmployee(string content[5], string user, string pass);
void insertKey(string staffid, string user, string pass);
void LoadData(string user, string pass);
