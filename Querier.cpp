#include "Query.h"
string host = "localhost";
string user = "root";
string pass = "password";
string db = "testdb";

void insertEmployee(string content[3]) {
	MYSQL* conn;
	MYSQL_ROW row;
	MYSQL_RES* res;
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
	string query = "SELECT COUNT(*) FROM employees";
	qstate = mysql_query(conn, query.c_str());
	res = mysql_store_result(conn);
	while (row = mysql_fetch_row(res)) {
		lastid = (string)row[0]++;
	}
	
	string query1 = "insert into employees(id, name, phone, address) values('10000000', '"+content[0]+"', '"+content[1]+"', '" + content[2]+"')";
	qstate = mysql_query(conn, query1.c_str());
}

void insertFinance(string content[3]) {
	MYSQL* conn;
	MYSQL_ROW row;
	MYSQL_RES* res;
	conn = mysql_init(0);
	conn = mysql_real_connect(conn, host.c_str(), user.c_str(), pass.c_str(), db.c_str(), 3306, NULL, 0);
	if (conn) {
		cout << "Connect successfully\n";
	}
	else {
		cout << "Connect fail\n";
	}
	int qstate = 0;
	string lastid;
	string query = "SELECT COUNT(*) FROM employees";
	qstate = mysql_query(conn, query.c_str());
	res = mysql_store_result(conn);
	while (row = mysql_fetch_row(res)) {
		lastid = (string)row[0]++;
	}

	string query1 = "insert into finance(bank, income) values('" + content[0] + "', '" + content[1] +"')";
	qstate = mysql_query(conn, query1.c_str());
}

void insertKey(string key, string tablename) {

}