#pragma once
#include <iostream>
#include <mysql.h>
#include <stdlib.h>
#include "cryptopp/eccrypto.h"
#include "cryptopp/cryptlib.h"
using namespace std;

void insertIncome(string content[5], string user, string pass);
void insertEmployee(string content[5], string user, string pass);
void saveKey(string staffid, string hkey, string hiv);
void insertSignature(string staffid, string hprivateKey, string hpublicKey, MYSQL* conn);
void LoadOne(string staffid, string user, string pass);
void LoadData(string user, string pass);
void signRow(string staffid, MYSQL* conn);
bool verifyRow(string staffid, string content);
