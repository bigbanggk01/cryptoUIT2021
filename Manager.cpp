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

void GenerateKey(string &hkey, string &hiv) {
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
        /*cerr << e.what() << endl;
        exit(1);*/
        return "";

    }
    return recovered;
}

void SaveHexAES(string hexkey, string hexiv, string &keyfile, string& ivfile) {
    StringSource s(hexkey, true, new FileSink(keyfile.c_str()));
    StringSource s1(hexiv, true, new FileSink(ivfile.c_str()));
}

void LoadHexAES(string &hkey, string &hiv, string keyfile, string ivfile) {
    FileSource s(keyfile.c_str(), true, new StringSink(hkey));
    FileSource s1(ivfile.c_str(), true, new StringSink(hiv));
}

void SavePrivateKey(const PrivateKey& key, string& file)
{
    string str;
    StringSink sink(str);
    key.Save(sink);
    StringSource s(str, true, new HexEncoder(new FileSink(file.c_str())));

    //string buffer;
    //StringSource s(str, true, new HexEncoder(new StringSink(buffer)));
    //str = buffer;
    //StringSource s1(str, true, new FileSink(str));
}


void SavePublicKey(const PublicKey& key, string& file)
{
    string str;
    StringSink sink(str);
    key.Save(sink);
    StringSource s(str, true, new HexEncoder(new FileSink(file.c_str())));
    /*StringSink sink(str);
    key.Save(sink);
    string buffer;
    StringSource s(str, true, new HexEncoder(new StringSink(buffer)));
    str = buffer;*/
}

void LoadPublicKey(PublicKey& key, string& file)
{
    string buffer;
    FileSource s(file.c_str(), true, new HexDecoder(new StringSink(buffer)));
    StringSource source(buffer, true);
    key.Load(source);
}

void LoadPrivateKey(PrivateKey& key, string& file)
{
    string buffer;
    FileSource s(file.c_str(), true, new HexDecoder(new StringSink(buffer)));
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
    try {
        StringSource s(cipher, true, new PK_DecryptorFilter(prng, d, new StringSink(recovered)));
    }
    catch (...) {
        return "Data can't be decrypt.";
    }
    
    return recovered;
}

void GenKeyECDSA(string& privfile, string& pubfile) {
    AutoSeededRandomPool prng;
    ECDSA<ECP, SHA512>::PrivateKey privateKey;
    ECDSA<ECP, SHA512>::PublicKey publicKey;
    privateKey.Initialize(prng, ASN1::secp256k1());
    privateKey.MakePublicKey(publicKey);
    
    FileSink fs(privfile.c_str());
    privateKey.Save(fs);

    FileSink fs2(pubfile.c_str());
    publicKey.Save(fs2);
}

void SaveSignature(string signature, string file) {
    StringSource s(signature, true, new FileSink(file.c_str()));
}

string ECDSASign(string mess,string file) {
    ECDSA<ECP, SHA512>::PrivateKey privateKey;
    FileSource fs(file.c_str(), true);
    privateKey.Load(fs);

    string signature;
    signature.erase();
    AutoSeededRandomPool prng;
    StringSource s(mess, true,
        new SignerFilter(prng,
            ECDSA<ECP, SHA512>::Signer(privateKey),
            new StringSink(signature)
        )
    );
    return signature;
}

bool ECDSAVerify(string mess, string signature, string fpublicKey) {
    ECDSA<ECP, SHA512>::PublicKey publicKey;
    FileSource fs(fpublicKey.c_str(), true);
    publicKey.Load(fs);
    bool result = false;
    try{
        StringSource s(signature + mess, true,
            new SignatureVerificationFilter(
                ECDSA<ECP, SHA512>::Verifier(publicKey),
                new ArraySink((CryptoPP::byte*)&result, sizeof(result))
            )
        );
    }
    catch (...) {
        return false;
    };
    
    return result;
}

void SaveEDCSA(string hprivate, string hpublic , string privfile, string pubfile) {
    StringSource s(hprivate, true, new FileSink(privfile.c_str()));
    StringSource s1(hpublic, true, new FileSink(pubfile.c_str()));
}

void LoadEDCSA(string& hprivate, string& hpublic, string privfile, string pubfile) {
    FileSource s(privfile.c_str(), true, new StringSink(hprivate));
    FileSource s1(pubfile.c_str(), true, new StringSink(hpublic));
}

string LoadSignature(string file) {
    string sig;
    FileSource f(file.c_str(), true, new StringSink(sig));
    return sig;
}