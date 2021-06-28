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
	/*string employee[3] = {"Do Truong An","1587469422","SAI GON"};
	string haes;
	string hiv;
	GenerateKey(haes, hiv);
	string buff = AESencrypt(employee[1], haes, hiv);
	employee[1] = buff;
	insertEmployee(employee);
	insertKey(haes, hiv);*/
	//string staff[5] = { "Do Truong An", "1", "123456789", "SAI GON", "Admin" };
	//insertEmployee(staff,"root", "password");
	//string income[5] = { "0","123123","123123","110000","12321323" };
	//insertIncome(income,"root", "password");


	/*string hpriv;
	string hpub;
	GenKeyECDSA(hpriv,hpub);

	ECDSA<ECP, SHA512>::PrivateKey privateKey;
	ECDSA<ECP, SHA512>::PublicKey publicKey;

	LoadPrivateKey(privateKey, hpriv);
	LoadPublicKey(publicKey, hpub);

	string mess = "abbbbbbbbbbcccccccddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd";
	string signal = ECDSASign(mess, privateKey);
	string fmess = "abbbbbbbbbbcccccccdddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddde";

	bool result = ECDSAVerify(mess, signal, publicKey);
	cout << result;
	cout << endl << StringToHex(signal);
	cout << endl << StringToHex(hpriv);*/

	//LoadData("root", "password");
	//insertKey("0","root", "password");

	//string staff[5] = { "Do Truong An", "1", "123456789", "SAI GON", "Admin" };
	//insertEmployee(staff, "root", "password");
	LoadOne("1", "root", "password");
	return 0;
}