#pragma once
#include "Header.h"

string username;
string password;
string symbol[] = { "[.] ","[+] ", "[-] ", "[!] ", "[?] " };


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

int loginFrame() {
	int pointer = 0;
	string Menu[] = { "Login","About","Exit" };

	while (true)
	{
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		printASCII("myfile.txt");
		for (int i = 0; i < 3; i++) {
			if (i == pointer) {
				printSymbol(0);
				cout << ">> " << Menu[i] << " <<";
				cout << endl;
			}
			else {
				printSymbol(0);
				cout << Menu[i] << endl;
			}
		}
		while (true)
		{
			if (GetAsyncKeyState(VK_UP) != 0) {
				pointer -= 1;
				if (pointer == -1) {
					pointer = 2;
				}
				break;

			}
			else if (GetAsyncKeyState(VK_DOWN) != 0) {
				pointer += 1;
				if (pointer == 3) {
					pointer = 0;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_RETURN) != 0) {
				switch (pointer)
				{
				case 0:
				{
					cin.ignore(256, '\n');
					/*cout << "username: "; cin >> username;
					cout << "password:"; cin >> password;*/
					return 2;
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
				printSymbol(0);
				cout << ">> " << options[i] << " <<";
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
			if (GetAsyncKeyState(VK_UP) != 0) {
				pointer -= 1;
				if (pointer == -1) {
					pointer = 1;
				}
				break;

			}
			else if (GetAsyncKeyState(VK_DOWN) != 0) {
				pointer += 1;
				if (pointer == 2) {
					pointer = 0;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_RETURN) != 0) {
				switch (pointer)
				{
				case 0:
				{
					cin.ignore(256, '\n');
					return 0;
				}
				break;
				case 1:
				{
					cin.ignore(256, '\n');
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

int workFrame() {
	int pointer = 0;
	string options[] = { "Load","Insert","Update","Delete","Exit" };

	while (true)
	{
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		printASCII("myfile.txt");
		for (int i = 0; i < 6; i++) {
			if (i == pointer) {
				printSymbol(0);
				cout << ">> " << options[i] << " <<";
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
			if (GetAsyncKeyState(VK_UP) != 0) {
				pointer -= 1;
				if (pointer == -1) {
					pointer = 5;
				}
				break;

			}
			else if (GetAsyncKeyState(VK_DOWN) != 0) {
				pointer += 1;
				if (pointer == 6) {
					pointer = 0;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_RETURN) != 0) {
				switch (pointer)
				{
				case 0:
				{
					cin.ignore(256, '\n');
					return 0;
				}
				break;
				case 1:
				{
					cin.ignore(256, '\n');
				}
				break;
				case 2:
				{
					cin.ignore(256, '\n');
				}
				break;
				case 3:
				{
					cin.ignore(256, '\n');
				}
				break;
				case 4:
				{
					cin.ignore(256, '\n');
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
