#pragma once
#include "Query.h"
#include "Header.h"
//string host = "localhost";
//string user = "root";
//string pass = "password";
//string db = "testdb";
#include <sstream>
using namespace std;
void insertEmployee(string content[5],string user, string pass) {
	string hkey,hiv;
	GenerateKey(hkey, hiv);
	
	for (int i = 0; i < 5; i++) {
		if (i != 1) {
			content[i] = AESencrypt(content[i], hkey, hiv);
		}
	}
	MYSQL* conn;
	MYSQL_ROW row;
	MYSQL_RES* res;
	string host = "localhost";
	string db = "employees";
	conn = mysql_init(0);
	conn = mysql_real_connect(conn, host.c_str(),user.c_str(),pass.c_str(),db.c_str(),3306,NULL,0);
	if (conn) {
		std::cout << "Connect successfully\n";
	}
	else {
		std::cout << "Connect fail\n";
	}
	int qstate = 0;
	string lastid;
	string query = "SELECT COUNT(*) FROM employeeinfo";
	qstate = mysql_query(conn, query.c_str());
	res = mysql_store_result(conn);
	while (row = mysql_fetch_row(res)) {
		lastid = (string)row[0]++;
	}
	
	string query1 = "insert into employeeinfo(id, name,sex) values('"+lastid+"', '"+content[0]+"', '"+content[1]+"')";
	string query2 = "UPDATE employeeinfo SET `phone` = '"+content[2]+"', `address` = '"+content[3]+"', `position` = '"+content[4]+"' WHERE `id` = '"+lastid+"';";
	qstate = mysql_query(conn, query1.c_str());
	qstate = mysql_query(conn, query2.c_str());

	signRow(lastid,conn);
	saveKey(lastid, hkey, hiv);
}

//void insertIncome(string content[5], string user, string pass) {
//	MYSQL* conn;
//	MYSQL_ROW row;
//	MYSQL_RES* res;
//	string host = "localhost";
//	string db = "employees";
//	conn = mysql_init(0);
//	conn = mysql_real_connect(conn, host.c_str(), user.c_str(), pass.c_str(), db.c_str(), 3306, NULL, 0);
//	if (!conn) {
//		return;
//	}
//	int qstate = 0;
//	string lastid;
//	string query = "SELECT COUNT(*) FROM income";
//	qstate = mysql_query(conn, query.c_str());
//	res = mysql_store_result(conn);
//	while (row = mysql_fetch_row(res)) {
//		lastid = (string)row[0]++;
//	}
//
//	string query1 = "insert into income(id, staffid, income, bonus) values('"+lastid+"','" + content[0] + "', '" + content[3] + "', '" + content[4] + "')";
//	string query2 = "UPDATE income SET `banknumber` = '" + content[1] + "', `socialnumber` = '" + content[2] + "' WHERE `id` = '" + lastid + "';";
//
//	qstate = mysql_query(conn, query1.c_str());
//	qstate = mysql_query(conn, query2.c_str());
//
//}


void saveKey(string staffid, string hkey, string hiv) {
	string aeskeyfile = "aeskey" + staffid;
	string aesivfile = "aesiv" + staffid;

	SaveHexAES(hkey, hiv, aeskeyfile, aesivfile);
}

void signRow(string staffid, MYSQL* conn) {
	ECDSA<ECP, SHA512>::PrivateKey privateKey;
	ECDSA<ECP, SHA512>::PublicKey publicKey;

	if (!conn) {
		return;
	}
	MYSQL_ROW row;
	MYSQL_RES* res;
	string privfile = "eccprivatekey" + staffid;
	string pubfile = "eccpublickey" + staffid;
	GenKeyECDSA(privfile, pubfile);
	string content;

	int qstate = 0;
	string query = "SELECT * FROM employeeinfo WHERE id='"+staffid+"'";
	qstate = mysql_query(conn, query.c_str());
	res = mysql_store_result(conn);

	while (row = mysql_fetch_row(res)) {
		for (int i = 0; i < 6; i++) {
			content+=(string)row[i];

		}

	}
	string signature=ECDSASign(content, privfile);
	string sigfile = "eccsignature" + staffid;
	SaveSignature(signature, sigfile);
}
bool verifyRow(string staffid, string content) {
	string sigfile = "eccsignature" + staffid;
	string sig = LoadSignature(sigfile);
	string pubfile = "eccpublickey" + staffid;
	return ECDSAVerify(content,sig,pubfile);
}

void LoadData(string user, string pass) {
	MYSQL* conn;
	MYSQL_ROW row;
	MYSQL_ROW checkrow;
	MYSQL_ROW rowkey;
	MYSQL_RES* res;
	MYSQL_RES* reskey;

	string host = "localhost";
	string db = "employees";
	conn = mysql_init(0);
	conn = mysql_real_connect(conn, host.c_str(), user.c_str(), pass.c_str(), db.c_str(), 3306, NULL, 0);
	if (!conn) {
		return;
	}

	if (!conn) {
		exit;
	}
	int qstate0 = 0;
	string lastid;
	string query = "SELECT COUNT(*) FROM employeeinfo";
	qstate0 = mysql_query(conn, query.c_str());
	res = mysql_store_result(conn);
	while (row = mysql_fetch_row(res)) {
		lastid = (string)row[0];
	}
	
	stringstream convert(lastid);
	int index = 0;
	convert >> index;

	system("cls");
	std::printf("+%5s+%20s+%5s+%12s+%20s+%20s+", "-----", "--------------------", "-----", "------------", "--------------------", "--------------------");
	std::cout << "\n";
	std::printf("|%-5s|%-20s|%-5s|%-12s|%-20s|%-20s|", "id", "name", "sex", "phone", "address", "position");
	std::cout << "\n";
	std::printf("+%5s+%20s+%5s+%12s+%20s+%20s+", "-----", "--------------------", "-----", "------------", "--------------------", "--------------------");
	std::cout << "\n";
	for (int i = 0; i < index; i++) {
		string staffid = std::to_string(i);
		int qstate = 0;
		string queryemployee = "SELECT * FROM employeeinfo WHERE id ='" +staffid+"'";
		string querykey = "SELECT id FROM keycode WHERE staffid ='" + staffid+"'";
		qstate = mysql_query(conn, querykey.c_str());
		reskey = mysql_store_result(conn);
		string hkey, hiv;
		while (rowkey = mysql_fetch_row(reskey))
		{
			string keyfile = "aeskey" + (string)rowkey[0];
			string ivfile = "aesiv" + (string)rowkey[0];
			LoadHexAES(hkey, hiv, keyfile, ivfile);
		}

		qstate = mysql_query(conn, queryemployee.c_str());


		res = mysql_store_result(conn);
		while (row = mysql_fetch_row(res)) {
			string decrypted[6];
			for (int i = 0; i < 6; i++) {
				if (i != 0 && i != 2) {
					decrypted[i] = AESdecrypt((string)row[i], hkey, hiv);
				}
				else {
					decrypted[i] = (string)row[i];
				}
			}
			std::printf("|%-5s|%-20s|%-5s|%-12s|%-20s|%-20s|", decrypted[0].c_str(), decrypted[1].c_str(), decrypted[2].c_str(), decrypted[3].c_str(), decrypted[4].c_str(), decrypted[5].c_str());
			std::cout << "\n";
		}
		int notOK;
		while (checkrow = mysql_fetch_row(res)) {
			string content;
			for (int i = 0; i < 6; i++) {
				content += (string)checkrow[i];
			}
			if (!verifyRow(staffid, content)) {
				std::cout << "Verify: NO OK AT " + (string)checkrow[0] + "\n";
				notOK = 1;
			}
		}
	}
	std::printf("+%5s+%20s+%5s+%12s+%20s+%20s+", "-----", "--------------------", "-----", "------------", "--------------------", "--------------------");
	std::cout << "\n";
}

void LoadOne(string staffid,string user, string pass){
	MYSQL* conn;
	MYSQL_ROW row;
	MYSQL_ROW rowkey;
	MYSQL_RES* res;
	MYSQL_RES* reskey;

	string host = "localhost";
	string db = "employees";
	conn = mysql_init(0);
	conn = mysql_real_connect(conn, host.c_str(), user.c_str(), pass.c_str(), db.c_str(), 3306, NULL, 0);
	if (!conn) {
		return;
	}
	int qstate = 0;
	string query = "SELECT * FROM employeeinfo WHERE id ='" + staffid + "'";
	reskey = mysql_store_result(conn);
	string hkey, hiv;
	string keyfile = "aeskey" + staffid;
	string ivfile = "aesiv" + staffid;
	LoadHexAES(hkey, hiv, keyfile, ivfile);

	qstate = mysql_query(conn, query.c_str());


	res = mysql_store_result(conn);
	system("cls");
	std::printf("+%5s+%20s+%5s+%12s+%20s+%20s+", "-----", "--------------------", "-----", "------------", "--------------------", "--------------------");
	std::cout << "\n";
	std::printf("|%-5s|%-20s|%-5s|%-12s|%-20s|%-20s|", "id", "name", "sex", "phone", "address", "position");
	std::cout << "\n";
	std::printf("+%5s+%20s+%5s+%12s+%20s+%20s+", "-----", "--------------------", "-----", "------------", "--------------------", "--------------------");
	std::cout << "\n";
	string content;

	while (row = mysql_fetch_row(res)) {
		string decrypted[6];

		for (int i = 0; i < 6; i++) {
			content += (string)row[i];
			if (i != 0&& i!=2) {
				decrypted[i] = AESdecrypt((string)row[i],hkey,hiv);
			}
			else {
				decrypted[i] = (string)row[i];
			}
			
		}
		if (!verifyRow(staffid, content)) {
			std::cout << "Verify: NO OK";
			return;
		}
		std::printf("|%-5s|%-20s|%-5s|%-12s|%-20s|%-20s|", decrypted[0].c_str(), decrypted[1].c_str(), decrypted[2].c_str(), decrypted[3].c_str(), decrypted[4].c_str(), decrypted[5].c_str());
		std::cout << "\n";
		
	}
	std::printf("+%5s+%20s+%5s+%12s+%20s+%20s+", "-----", "--------------------", "-----", "------------", "--------------------", "--------------------");
	std::cout << "\n";
	
}