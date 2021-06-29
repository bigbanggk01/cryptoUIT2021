#include "Header.h"
#include "Query.h"
string user;
string pass;
int main() {
	int frame = 0;
	while (true)
	{
		switch (frame)
		{
		case -1: {
			return 0;
		}break;
		case 0: {
			frame = mainFrame(user,pass);
		}break;
		case 1: {
			frame = aboutFrame();
		}break;
		case 2: {
			frame = workFrame(user, pass);
		}break;
		case 3: {
			frame = loginFrame(user,pass);
		}break;
		case 4: {
			frame = dataFrame(user, pass);
		}break;
		case 5: {
			frame = dataFrame1(user, pass);
		}break;
		case 6: {
			frame = insertFrame(user, pass);
		}break;
		case 7: {
			frame = deleteFrame(user, pass);
		}break;
		default:
			break;
		}
		Sleep(200);
	}
	return 0;
}