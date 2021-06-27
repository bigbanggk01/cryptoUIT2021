#pragma once
#include <stdlib.h>
#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>
#include <limits>
#include <mysql.h>
#include "cryptopp/eccrypto.h"
#include "cryptopp/aes.h"
#include "cryptopp/rijndael.h"
#include "cryptopp/modes.h"
#include "cryptopp/osrng.h"
#include "cryptopp/hex.h"
#include "cryptopp/filters.h"
#include "cryptopp/files.h"
#include "cryptopp/secblock.h"
#include "cryptopp/integer.h"
#include "cryptopp/oids.h"
#include "cryptopp/cryptlib.h"
using namespace std;
using namespace CryptoPP;
//UI header
void printASCII(string filename);
void printSymbol(int type);
int loginFrame();
int aboutFrame();
int workFrame();

//Crypto header
string AESencrypt(string plaintext, string hkey, string hiv);
string AESdecrypt(string hcipher, string hkey, string hiv);
string ByteEncodeToHex(SecByteBlock key);
SecByteBlock HexDecodeToByte(string hinput);
void GenerateKey(string& hkey, string& hiv);
string StringToHex(string input);
string AESencrypt(string plaintext, string hkey, string hiv);
string ECCEncrypt(string plaintext, ECIES<ECP>::Encryptor e);
string ECCDecrypt(string cipher, ECIES<ECP>::Decryptor d);
void GenECC(string& hEpri, string& hEpu);
//void SavePublicKey(const ECIES< CryptoPP::ECP >::PublicKey& key, string& h);
//void SavePrivateKey(const ECIES< CryptoPP::ECP >::PrivateKey& key, string& h);
//void LoadPrivateKey(ECIES< CryptoPP::ECP >::PrivateKey& key, const string& h);
//void LoadPublicKey(ECIES< CryptoPP::ECP >::PublicKey& key, const string& h);
void LoadPublicKey(PublicKey& key, string& file);
void LoadPrivateKey(PrivateKey& key, string& file);
void SavePublicKey(const PublicKey& key, string& file);
void SavePrivateKey(const PrivateKey& key, string& file);



//MySQL
MYSQL Connect();