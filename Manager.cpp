#include "Header.h"
string ByteEncodeToHex(SecByteBlock key) {
    std::string str(reinterpret_cast<const char*>(&key[0]), key.size());
    string hstr;
    StringSource s(str, true,new HexEncoder( new StringSink(hstr)));
    return hstr;
}

SecByteBlock HexDecodeToByte(string hinput) {
    string str;
    StringSource s(hinput, true, new HexDecoder(new StringSink(str)));
    SecByteBlock key(reinterpret_cast<const byte*>(&str[0]), str.size());
    return key;
}

void GenerateKey(string& hkey, string& hiv) {
    AutoSeededRandomPool prng;
    SecByteBlock key(AES::MAX_KEYLENGTH);
    SecByteBlock iv(AES::BLOCKSIZE);

    prng.GenerateBlock(key, key.size());
    prng.GenerateBlock(iv, iv.size());

    hkey = ByteEncodeToHex(key);
    hiv = ByteEncodeToHex(iv);
}
string StringToHex(string input) {
    string output;
    StringSource s(input, true, new HexEncoder(new StringSink(output)));
    return output;
}
string HexToString(string input) {
    string output;
    StringSource s(input, true, new HexDecoder(new StringSink(output)));
    return output;
}
string AESencrypt(string plaintext, string hkey, string hiv) {
    string cipher;
    SecByteBlock key = HexDecodeToByte(hkey);
    SecByteBlock iv = HexDecodeToByte(hiv);

    try
    {
        CBC_Mode< AES >::Encryption e;
        e.SetKeyWithIV(key, key.size() , iv);

        StringSource s(plaintext, true,
            new StreamTransformationFilter(e,
                new StringSink(cipher)
            ) // StreamTransformationFilter
        ); // StringSource
    }
    catch (const Exception& e)
    {
        std::cerr << e.what() << std::endl;
        exit(1);
    }
    return StringToHex(cipher);
}
string AESdecrypt(string hcipher, string hkey, string hiv) {
    string cipher = HexToString(hcipher);
    SecByteBlock key = HexDecodeToByte(hkey);
    SecByteBlock iv = HexDecodeToByte(hiv);
    string recovered;
    try
    {
        CBC_Mode< AES >::Decryption d;
        d.SetKeyWithIV(key, key.size(), iv);

        StringSource s(cipher, true,
            new StreamTransformationFilter(d,
                new StringSink(recovered)
            ) // StreamTransformationFilter
        ); // StringSource

    }
    catch (const Exception& e)
    {
        cerr << e.what() << endl;
        exit(1);
    }
    return recovered;
}

void SavePrivateKey(const PrivateKey& key, string& str)
{
    StringSink sink(str);
    key.Save(sink);
    string buffer;
    StringSource s(str, true, new HexEncoder(new StringSink(buffer)));
    str = buffer;
}


void SavePublicKey(const PublicKey& key,  string& str)
{
    StringSink sink(str);
    key.Save(sink);
    string buffer;
    StringSource s(str, true, new HexEncoder(new StringSink(buffer)));
    str = buffer;
}

void LoadPublicKey(PublicKey& key, string& str)
{
    string buffer;
    StringSource s(str, true, new HexDecoder(new StringSink(buffer)));
    StringSource source(buffer, true);
    key.Load(source);
}

void LoadPrivateKey(PrivateKey& key, string& str)
{
    string buffer;
    StringSource s(str, true, new HexDecoder(new StringSink(buffer)));
    StringSource source(buffer, true);
    key.Load(source);
}

void GenECC(string &hEpri, string &hEpu) {
    AutoSeededRandomPool prng;

    ECIES<ECP>::Decryptor d0(prng, ASN1::secp256r1());
    ECIES<ECP>::Encryptor e0(d0);
    
    SavePrivateKey(d0.GetPrivateKey(), hEpri);
    SavePublicKey(e0.GetPublicKey(), hEpu);
}

string ECCEncrypt(string plaintext, ECIES<ECP>::Encryptor e) {
    AutoSeededRandomPool prng;
    string cipher;
    StringSource s(plaintext, true, new PK_EncryptorFilter(prng, e, new StringSink(cipher)));

    return cipher;
}

string ECCDecrypt(string cipher, ECIES<ECP>::Decryptor d) {
    AutoSeededRandomPool prng;
    string recovered;
    StringSource s(cipher, true, new PK_DecryptorFilter(prng, d, new StringSink(recovered)));

    return recovered;
}

