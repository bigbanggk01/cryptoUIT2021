#include "Header.h"
#include "Query.h"

int main() {
	int frame = 0;
	/*while (true)
	{
		switch (frame)
		{
		case -1: {
			return 0;
		}break;
		case 0: {
			frame = loginFrame();
		}break;
		case 1: {
			frame = aboutFrame();
		}break;
		case 2: {
			frame = workFrame();
		}break;
		default:
			break;
		}
		Sleep(200);
	}*/
	
	/*string staff1[5] = { "Tham Thach Tu","1","213456","Dong Nai","director" };
	insertEmployee(staff1, "root", "password");
	string staff2[5] = { "Do Truong An","1","2132132131","Sai GON","admin" };
	insertEmployee(staff2, "root", "password");
	string staff3[5] = { "To Thi My Au","0","0113188348","Da Nang","director" };
	insertEmployee(staff3, "root", "password");*/
	//LoadData("root", "password");
	//LoadOne("6","root","password");
	/*MYSQL* conn;
	MYSQL_ROW row;
	MYSQL_RES* res;
	string host = "localhost";
	string db = "employees";
	string pass = "password";
	string user = "root";
	conn = mysql_init(0);
	conn = mysql_real_connect(conn, host.c_str(), user.c_str(), pass.c_str(), db.c_str(), 3306, NULL, 0);*/
	//signRow("6",conn);
	/*string h = "123", h1 = "456";
	GenKeyECDSA(h, h1);
	string mess = "asssssasdassaas";
	string sig = ECDSASign(mess, "123");
	cout<<ECDSAVerify(mess, sig, h1);*/
	LoadData("root", "password");
	return 0;
}