#pragma once
#include "Query.h"
#include "Header.h"
//string host = "localhost";
//string user = "root";
//string pass = "password";
//string db = "testdb";
#include <sstream>
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
		cout << "Connect successfully\n";
	}
	else {
		cout << "Connect fail\n";
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
	insertKey(lastid,hkey,hiv, conn);
}

void insertIncome(string content[5], string user, string pass) {
	MYSQL* conn;
	MYSQL_ROW row;
	MYSQL_RES* res;
	string host = "localhost";
	string db = "employees";
	conn = mysql_init(0);
	conn = mysql_real_connect(conn, host.c_str(), user.c_str(), pass.c_str(), db.c_str(), 3306, NULL, 0);
	if (!conn) {
		return;
	}
	int qstate = 0;
	string lastid;
	string query = "SELECT COUNT(*) FROM income";
	qstate = mysql_query(conn, query.c_str());
	res = mysql_store_result(conn);
	while (row = mysql_fetch_row(res)) {
		lastid = (string)row[0]++;
	}

	string query1 = "insert into income(id, staffid, income, bonus) values('"+lastid+"','" + content[0] + "', '" + content[3] + "', '" + content[4] + "')";
	string query2 = "UPDATE income SET `banknumber` = '" + content[1] + "', `socialnumber` = '" + content[2] + "' WHERE `id` = '" + lastid + "';";

	qstate = mysql_query(conn, query1.c_str());
	qstate = mysql_query(conn, query2.c_str());

}

void insertKey(string staffid, string hkey, string hiv, MYSQL *conn) {
	MYSQL_ROW row;
	MYSQL_RES* res;
	if (!conn) {
		exit;
	}
	int qstate = 0;
	string lastid;
	string query = "SELECT COUNT(*) FROM keycode";
	qstate = mysql_query(conn, query.c_str());
	res = mysql_store_result(conn);
	while (row = mysql_fetch_row(res)) {
		lastid = (string)row[0]++;
	}
	/*string aeskeyfile = "aeskey" + lastid;
	string aesivfile = "aesiv" + lastid;
	string eccpriv = "eccpriv" + lastid;
	string eccpub = "eccpub" + lastid;

	GenerateKey(aeskeyfile,aesivfile);
	GenKeyECDSA(eccpriv, eccpub);*/
	string aeskeyfile = "aeskey" + lastid;
	string aesivfile = "aesiv" + lastid;
	SaveHexAES(hkey, hiv, aeskeyfile, aesivfile);
	string query1 = "insert into keycode(id, staffid) values('" + lastid + "', '" + staffid + "')";
	qstate = mysql_query(conn, query1.c_str());

}
void LoadData(string user, string pass) {
	MYSQL* conn;
	MYSQL_ROW row;
	MYSQL_RES* res;
	string host = "localhost";
	string db = "employees";
	conn = mysql_init(0);
	conn = mysql_real_connect(conn, host.c_str(), user.c_str(), pass.c_str(), db.c_str(), 3306, NULL, 0);
	if (!conn) {
		return;
	}
	int qstate = 0;
	string query = "SELECT * FROM employeeinfo";
	qstate = mysql_query(conn, query.c_str());
	res = mysql_store_result(conn);
	system("cls");
	//cout << "id\t" << "name\t\t" << "sex\t" << "phone\t\t" << "address\t\t" << "position\n";
	printf("+%5s+%20s+%5s+%10s+%10s+%10s+", "-----", "--------------------", "-----", "----------", "----------", "----------");
	cout << "\n";
	printf("|%-5s|%-20s|%-5s|%-10s|%-10s|%-10s|", "id", "name", "sex", "phone", "address", "position");
	cout << "\n";
	printf("+%5s+%20s+%5s+%10s+%10s+%10s+", "-----", "--------------------", "-----", "----------", "----------", "----------");
	cout << "\n";
	while (row = mysql_fetch_row(res)) {
		//cout << row[0]<<"\t" << row[1]<< "\t"<< row[2] << "\t"<< row[3] << "\t"<< row[4] << "\t\t"<< row[5] << "\n";
		printf("|%-5s|%-20s|%-5s|%-10s|%-10s|%-10s|", row[0], row[1], row[2], row[3],row[4], row[5]);
		cout << "\n";
		printf("+%5s+%20s+%5s+%10s+%10s+%10s+", "-----", "--------------------", "-----", "----------", "----------", "----------");
		cout << "\n";

	}
	
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
	string querykey = "SELECT id FROM keycode WHERE staffid ='"+staffid+"'";
	qstate = mysql_query(conn, querykey.c_str());
	reskey = mysql_store_result(conn);
	string hkey, hiv;
	while (rowkey = mysql_fetch_row(reskey))
	{
		string keyfile = "aeskey" + (string)rowkey[0];
		string ivfile = "aesiv" + (string)rowkey[0];
		LoadHexAES(hkey, hiv, keyfile, ivfile);
	}

	qstate = mysql_query(conn, query.c_str());


	res = mysql_store_result(conn);
	system("cls");
	printf("+%5s+%20s+%5s+%12s+%20s+%20s+", "-----", "--------------------", "-----", "------------", "--------------------", "--------------------");
	cout << "\n";
	printf("|%-5s|%-20s|%-5s|%-12s|%-20s|%-20s|", "id", "name", "sex", "phone", "address", "position");
	cout << "\n";
	printf("+%5s+%20s+%5s+%12s+%20s+%20s+", "-----", "--------------------", "-----", "------------", "--------------------", "--------------------");
	cout << "\n";
	while (row = mysql_fetch_row(res)) {
		string decrypted[6];
		for (int i = 0; i < 6; i++) {
			if (i != 0&& i!=2) {
				decrypted[i] = AESdecrypt((string)row[i],hkey,hiv);
			}
			else {
				decrypted[i] = (string)row[i];
			}
		}
		
		printf("|%-5s|%-20s|%-5s|%-12s|%-20s|%-20s|", decrypted[0].c_str(), decrypted[1].c_str(), decrypted[2].c_str(), decrypted[3].c_str(), decrypted[4].c_str(), decrypted[5].c_str());
		cout << "\n";
		printf("+%5s+%20s+%5s+%12s+%20s+%20s+", "-----", "--------------------", "-----", "------------", "--------------------", "--------------------");
		cout << "\n";
	}
}