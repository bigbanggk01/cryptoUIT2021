#pragma once
#include "Header.h"
#include "Query.h"
#include <conio.h>
#include <limits>
#include <ios>
#undef max
string symbol[] = { "[.] ","[+] ", "[-] ", "[!] ", "[?] " };
struct setcolor
{
	int color;
	setcolor(int c) : color(c) {}
	std::ostream& operator()(std::ostream& os)
	{
		HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hcon, color);
		return os;
	}
};
void printASCII(string filename) {
	string line = "";
	ifstream inFile;
	inFile.open(filename);
	if (inFile.is_open()) {
		while (getline(inFile, line)) {
			cout << line << endl;
		}
	}
	inFile.close();
}
void printSymbol(int type) {
	//0 is choosen = [.], 1 is success = [+] , 2 is not success = [-], 3 is warning =[!], 4 is asking of input = [?]
	switch (type)
	{
	case 0:
		cout << symbol[0];
		break;
	case 1:
		cout << symbol[1];
		break;
	case 2:
		cout << symbol[2];
		break;
	case 3:
		cout << symbol[3];
		break;
	case 4:
		cout << symbol[4];
		break;
	default:
		break;
	}

}

int mainFrame(string& user, string& pass) {
	int pointer = 0;
	string Menu[] = { "Login","About","Exit" };

	while (true)
	{
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		printASCII("myfile.txt");
		for (int i = 0; i < 3; i++) {
			if (i == pointer) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
				printSymbol(0);
				cout << ">> " << Menu[i] << " <<";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << endl;
			}
			else {
				printSymbol(0);
				cout << Menu[i] << endl;
			}
		}
		while (true)
		{
			if (GetAsyncKeyState(VK_UP) & 0x8000) {
				pointer -= 1;
				if (pointer == -1) {
					pointer = 2;
				}
				break;

			}
			else if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
				pointer += 1;
				if (pointer == 3) {
					pointer = 0;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
				switch (pointer)
				{
				case 0:
				{
					cin.ignore();
					cout << "Username: ";
					getline(cin, user);
					cout << "Password: ";
					getline(cin, pass);
					eraseLines(1);
					bool check = checkConnect(user, pass);
					if (check == false) {
						return 0;
					}
					else {
						return 2;
					}
				}
				break;
				case 1:
				{
					return 1;
				}
				break;
				case 2:
				{
					return -1;
				}
				default:
					break;
				}
				break;
			}
		}
		Sleep(100);
	}
	return -1;
}
int aboutFrame() {
	int pointer = 0;
	string options[] = { "Back","Exit" };

	while (true)
	{
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		printASCII("myfile.txt");
		for (int i = 0; i < 2; i++) {
			if (i == pointer) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
				printSymbol(0);
				cout << ">> " << options[i] << " <<";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << endl;
			}
			else {
				printSymbol(0);
				cout << options[i];
				cout << endl;
			}
		}
		while (true)
		{
			if (GetAsyncKeyState(VK_UP) & 0x8000) {
				pointer -= 1;
				if (pointer == -1) {
					pointer = 1;
				}
				break;

			}
			else if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
				pointer += 1;
				if (pointer == 2) {
					pointer = 0;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
				switch (pointer)
				{
				case 0:
				{
					cin.ignore();
					return 0;
				}
				break;
				case 1:
				{
					cin.ignore();
					return -1;
				}
				break;
				default:
					break;
				}
				break;
			}
		}
		Sleep(100);
	}
	return -1;
}

int workFrame(string user, string pass) {
	
	int pointer = 0;
	string options[6] = { "Load","Load one","Insert","Delete","Logout","Exit"};
	while (true)
	{
		
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		printASCII("myfile.txt");
		for (int i = 0; i < 6; i++) {
			if (i == pointer) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
				printSymbol(0);
				cout << ">> " << options[i] << " <<";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << endl;
			}
			else {
				printSymbol(0);
				cout << options[i];
				cout << endl;
			}
		}
		while (true)
		{
				
			if (GetAsyncKeyState(VK_UP) & 0x8000) {
				pointer -= 1;
				if (pointer == -1) {
					pointer = 5;
				}
				break;

			}
			else if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
				pointer += 1;
				if (pointer == 6) {
					pointer = 0;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
				switch (pointer)
				{
				case 0:
				{
					cin.clear();
					cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
					return 4;
				}
				break;
				case 1:
				{
					cin.clear();
					cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
					return 5;
				}
				break;
				case 2:
				{
					cin.clear();
					cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
					return 6;
				}
				break;
				case 3:
				{
					cin.clear();
					cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
					return 7;
				}
				break;
				case 4: {
					cin.clear();
					cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
					return 0;
				}
				break;
				case 5: {
					exit(0);
				}
				default:
					break;
				}
				break;
			}
		}
		Sleep(100);
	}
	return -1;
}

int loginFrame(string &user, string& pass) {
	cout << "Username: "; 
	getline(cin, user);
	
	cout << "Password: ";
	getline(cin, pass);

	bool check = checkConnect(user, pass);
	if (check == false) {
		return 0;
	}
	else {
		return 2;
	}
}
void eraseLines(int count) {
	if (count > 0) {
		std::cout << "\x1b[2K"; // Delete current line
		// i=1 because we included the first line
		for (int i = 1; i < count; i++) {
			std::cout
				<< "\x1b[1A" // Move cursor up one
				<< "\x1b[2K"; // Delete the entire line
		}
		std::cout << "\r"; // Resume the cursor at beginning of line
	}
}

int dataFrame(string user, string pass) {
	LoadData(user, pass);
	int pointer = 0;
	string options[2] = { "Back","Exit"};
	while (true)
	{
		

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		for (int i = 0; i < 2; i++) {
			if (i == pointer) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
				printSymbol(0);
				cout << ">> " << options[i] << " <<";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << endl;
			}
			else {
				printSymbol(0);
				cout << options[i];
				cout << endl;
			}
		}
		while (true)
		{

			if (GetAsyncKeyState(VK_UP) & 0x8000) {

				pointer -= 1;
				if (pointer == -1) {
					pointer = 1;
				}

				break;

			}
			else if (GetAsyncKeyState(VK_DOWN) & 0x8000) {

				pointer += 1;
				if (pointer == 2) {
					pointer = 1;
				}

				break;
			}
			else if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
				switch (pointer)
				{
				case 0:
				{
					cin.clear();
					cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
					return 2;
				}
				break;
				case 1:
				{
					exit(0);
				}
				break;
				default:
					break;
				}
				break;
			}
		}
		Sleep(100);
		eraseLines(3);
	}

}
int dataFrame1(string user, string pass) {
	system("cls");
	string staffid;
	cout << "[?] Staff id = ";
	getline(cin, staffid);
	LoadOne(staffid, user, pass);
	int pointer = 0;
	string options[2] = { "Back","Exit" };
	while (true)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		for (int i = 0; i < 2; i++) {
			if (i == pointer) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
				printSymbol(0);
				cout << ">> " << options[i] << " <<";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << endl;
			}
			else {
				printSymbol(0);
				cout << options[i];
				cout << endl;
			}
		}
		while (true)
		{

			if (GetAsyncKeyState(VK_UP) & 0x8000) {

				pointer -= 1;
				if (pointer == -1) {
					pointer = 1;
				}

				break;

			}
			else if (GetAsyncKeyState(VK_DOWN) & 0x8000) {

				pointer += 1;
				if (pointer == 2) {
					pointer = 1;
				}

				break;
			}
			else if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
				switch (pointer)
				{
				case 0:
				{
					cin.clear();
					cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
					return 2;
				}
				break;
				case 1:
				{
					exit(0);
				}
				break;
				default:
					break;
				}
				break;
			}
		}
		Sleep(100);
		eraseLines(3);
	}
}

int insertFrame(string user, string password) {
	system("cls");
	printSymbol(1);
	cout << "Enter to start.";
	cin.clear();
	cin.ignore(std::numeric_limits < std:: streamsize > :: max(), '\n');
	string newstaff[5];
	printSymbol(4);
	cout << "Name: ";
	getline(cin, newstaff[0]);
	
	printSymbol(4);
	cout << "Sex (male=1, female=0): ";
	getline(cin, newstaff[1]);
	
	printSymbol(4);
	cout << "Phone: ";
	getline(cin, newstaff[2]);

	printSymbol(4);
	cout << "Address: ";
	getline(cin, newstaff[3]);

	printSymbol(4);
	cout << "Position: ";
	getline(cin, newstaff[4]);

	insertEmployee(newstaff, user, password);
	
	return 2;
}

int deleteFrame(string user, string pass) {
	system("cls");
	printSymbol(1);
	cout << "Enter to start.";
	cin.clear();
	cin.ignore(std::numeric_limits < std::streamsize > ::max(), '\n');
	printSymbol(4);
	
	cout << "Delete: ";
	string staffid;
	getline(cin, staffid);
	bool result = deleteEmployee(staffid, user, pass);

	if (result == true) {
		printSymbol(1);
		cout << "Delete successfully.\n";
		printSymbol(0);
		cout << "Enter to back";
		cin.ignore();
	}
	else {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		printSymbol(3);
		cout << "Staff does not exsist.\n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		printSymbol(0);
		cout << "Enter to back";
		cin.ignore();
	}
	return 2;
}