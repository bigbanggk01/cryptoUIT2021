#include "Header.h"
#include "Query.h"
#include "cryptopp/secblock.h"
using CryptoPP::SecByteBlock;

#include "cryptopp/oids.h"
using CryptoPP::OID;

#include "cryptopp/asn.h"
int main() {
	/*int frame = 0;
	while (true)
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
	

	/*
	AESencrypt(pl, cipher, hkey, hiv);
	string recovered;
	AESdecrypt(cipher, recovered, hkey, hiv);
	cout << recovered;*/
	/*string pl = "hello";
	string hkey;
	string hiv;
	GenerateKey(hkey,hiv);
	string cipher = AESencrypt(pl, hkey, hiv);
	std::cout << "cipher text: ";
	cout<<cipher<<endl;
	string reverse = AESdecrypt(cipher, hkey, hiv);
	cout << "recovered: " << reverse << endl;

	string AES = ECCEncrypt(hiv);
	cout << AES << endl;*/
	//ECCEncrypt("");
	/*AutoSeededRandomPool prng;
	string pri;
	string pub;
	GenECC(pri,pub);
	ECIES<ECP>::Decryptor d1;
	d1.AccessPrivateKey();
	LoadPrivateKey(d1.AccessPrivateKey(),pri);
	d1.GetPrivateKey().ThrowIfInvalid(prng, 3);

	ECIES<ECP>::Encryptor e1;
	LoadPublicKey(e1.AccessPublicKey(),pub);
	e1.GetPublicKey().ThrowIfInvalid(prng, 3);
	string message("tu dep trai 2k");
	string em1,dm1;
	em1= ECCEncrypt(message, e1);;
	cout << em1 << endl;
	cout << ECCDecrypt(em1, d1);*/
	//string a[3] = { "Pham Thach Tu","0966286837","Dong Nai"};
	//insertEmployee(a);

	OID CURVE =ASN1::secp256r1();
	AutoSeededX917RNG<AES> rng;

	ECDH < ECP >::Domain dhA(CURVE), dhB(CURVE);

	// Don't worry about point compression. Its amazing that Certicom got
	// a patent for solving an algebraic equation....
	// dhA.AccessGroupParameters().SetPointCompression(true);
	// dhB.AccessGroupParameters().SetPointCompression(true);

	SecByteBlock privA(dhA.PrivateKeyLength()), pubA(dhA.PublicKeyLength());
	SecByteBlock privB(dhB.PrivateKeyLength()), pubB(dhB.PublicKeyLength());

	dhA.GenerateKeyPair(rng, privA, pubA);
	dhB.GenerateKeyPair(rng, privB, pubB);
	string key;
	HexEncoder hex(new StringSink(key));
	key = "0x";
	hex.Put(privA.BytePtr(), privA.SizeInBytes());
	hex.MessageEnd();
	DL_PrivateKey_EC<ECP> e;
	LoadPrivateKey(e, key);
	

	if (dhA.AgreedValueLength() != dhB.AgreedValueLength())
		throw runtime_error("Shared secret size mismatch");

	SecByteBlock sharedA(dhA.AgreedValueLength()), sharedB(dhB.AgreedValueLength());

	const bool rtn1 = dhA.Agree(sharedA, privA, pubB);
	const bool rtn2 = dhB.Agree(sharedB, privB, pubA);
	if (!rtn1 || !rtn2)
		throw runtime_error("Failed to reach shared secret (A)");

	const bool rtn3 = sharedA.size() == sharedB.size();
	if (!rtn3)
		throw runtime_error("Failed to reach shared secret (B)");

	Integer a, b;

	a.Decode(sharedA.BytePtr(), sharedA.SizeInBytes());
	cout << "(A): " << std::hex << a << endl;

	b.Decode(sharedB.BytePtr(), sharedB.SizeInBytes());
	cout << "(B): " << std::hex << b << endl;

	const bool rtn4 = a == b;
	if (!rtn4)
		throw runtime_error("Failed to reach shared secret (C)");

	cout << "Agreed to shared secret" << endl;

	
	return 0;
}