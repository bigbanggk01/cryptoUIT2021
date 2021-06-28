#pragma once
#include "Query.h"
#include "Header.h"
//string host = "localhost";
//string user = "root";
//string pass = "password";
//string db = "testdb";
#include <sstream>
void insertEmployee(string content[5],string user, string pass) {
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
	/*unsigned long inlastid;
	stringstream(lastid) >> inlastid;
	inlastid++;
	stringstream ss;
	ss << inlastid;
	string insertid = ss.str();*/
	string query1 = "insert into employeeinfo(id, name,sex) values('"+lastid+"', '"+content[0]+"', '"+content[1]+"')";
	string query2 = "UPDATE employeeinfo SET `phone` = '"+content[2]+"', `address` = '"+content[3]+"', `position` = '"+content[4]+"' WHERE `id` = '"+lastid+"';";
	qstate = mysql_query(conn, query1.c_str());
	qstate = mysql_query(conn, query2.c_str());
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

void insertKey(string staffid, string user, string pass) {
	MYSQL* conn;
	MYSQL_ROW row;
	MYSQL_RES* res;
	string host = "localhost";
	string db = "employees";
	conn = mysql_init(0);
	conn = mysql_real_connect(conn, host.c_str(), user.c_str(), pass.c_str(), db.c_str(), 3306, NULL, 0);
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
	string aeskeyfile = "aeskey" + lastid;
	string aesivfile = "aesiv" + lastid;
	string eccpriv = "eccpriv" + lastid;
	string eccpub = "eccpub" + lastid;

	GenerateKey(aeskeyfile,aesivfile);
	GenKeyECDSA(eccpriv, eccpub);
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
	string lastid;
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
