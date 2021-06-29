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
int mainFrame(string& user, string& pass);
int loginFrame(string& user, string& pass);
int aboutFrame();
int workFrame(string user,string pass);
bool checkConnect(string user, string pass);
int dataFrame(string user, string pass);
int dataFrame1(string user, string pass);
int insertFrame(string user, string password);
void eraseLines(int count);
//Crypto header
string AESencrypt(string plaintext, string hkey, string hiv);
string AESdecrypt(string hcipher, string hkey, string hiv);
string ByteEncodeToHex(SecByteBlock key);
SecByteBlock HexDecodeToByte(string hinput);
//void GenerateKey(string& hkey, string& hiv, string& keyfile, string& ivfile);
void GenerateKey(string& hkey, string& hiv);
void SaveHexAES(string hexkey, string hexiv, string& keyfile, string& ivfile);
void LoadHexAES(string& hkey, string& hiv, string keyfile, string ivfile);
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

void GenKeyECDSA(string& hprivateKey, string& hpublicKey);
string ECDSASign(string mess, string hprivateKey);
bool ECDSAVerify(string mess, string signature, string hpublicKey);
void SaveSignature(string signature, string file);
void SaveEDCSA(string hprivate, string hpublic, string privfile, string pubfile);
void LoadEDCSA(string& hprivate, string& hpublic, string privfile, string pubfile);
string LoadSignature(string file);
//MySQL
MYSQL Connect();