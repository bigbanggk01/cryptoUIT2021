#include <iostream>
#include <istream>
#include <string>
#include <sstream>
#include "include/cryptopp/des.h"
#include "include/cryptopp/osrng.h"
#include "include/cryptopp/hex.h"
#include "include/cryptopp/modes.h"
#include "include/cryptopp/files.h"
#include "include/cryptopp/aes.h"
#include "include/cryptopp/gcm.h"
#include "include/cryptopp/ccm.h"
#include "include/cryptopp/xts.h"
#include "assert.h"
#include <ctime>
using namespace CryptoPP;
using CryptoPP::StringSink;
using CryptoPP::StringSource;
using CryptoPP::AuthenticatedEncryptionFilter;
using CryptoPP::AuthenticatedDecryptionFilter;
using CryptoPP::GCM;
using CryptoPP::GCM_TablesOption;
using CryptoPP::StringSink;
using CryptoPP::StringSource;
using CryptoPP::AuthenticatedEncryptionFilter;
using CryptoPP::AuthenticatedDecryptionFilter;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::cerr;
void DES_2(){
    AutoSeededRandomPool rng;
    HexEncoder encoder(new FileSink(std::cout));
    DES_EDE2_Encryption encrypt;
    

    SecByteBlock key(DES::DEFAULT_KEYLENGTH);
    SecByteBlock iv(DES::BLOCKSIZE);
    std::cout<<"Type message....";
    std::string plain;
    std::cin>> plain;
    std::string cipher,recovered;
    int sttime = clock();
    double etime;
    rng.GenerateBlock(key, key.size());
    rng.GenerateBlock(iv, iv.size());

    CBC_Mode<DES>::Encryption e;
    e.SetKeyWithIV(key,key.size(),iv);
    StringSource s(plain, true, 
        new StreamTransformationFilter(e,
            new StringSink(cipher)
        )
    ); 
    int stime = clock();
    etime=(stime-sttime)/double(CLOCKS_PER_SEC)*1000;
    std::cout << "Execution time: " << etime << " ms"  << std::endl ;

    std::cout << "key: ";
    encoder.Put(key, key.size());
    encoder.MessageEnd();
    std::cout << std::endl;

    std::cout << "iv: ";
    encoder.Put(iv, iv.size());
    encoder.MessageEnd();
    std::cout << std::endl;

    std::cout << "cipher text: ";
    encoder.Put((const byte*)&cipher[0], cipher.size());
    encoder.MessageEnd();
    std::cout << std::endl<< std::endl;
}

void DES_3(){
    AutoSeededRandomPool rng;
    HexEncoder encoder(new FileSink(std::cout));
    DES_EDE3_Encryption encrypt;
    

    SecByteBlock key(DES::DEFAULT_KEYLENGTH);
    SecByteBlock iv(DES::BLOCKSIZE);
    std::cout<<"Type message....";
    std::string plain;
    std::cin>>plain;
    
    std::string cipher,recovered;

    int sttime = clock();
    double etime;

    rng.GenerateBlock(key, key.size());
    rng.GenerateBlock(iv, iv.size());

    CBC_Mode<DES>::Encryption e;
    e.SetKeyWithIV(key,key.size(),iv);
    StringSource s(plain, true, 
        new StreamTransformationFilter(e,
            new StringSink(cipher)
        )
    );
    int stime = clock();
    etime = (stime-sttime)/double(CLOCKS_PER_SEC)*1000;
    std::cout << "Execution time: " << etime << " ms"  << std::endl;

    std::cout << "key: ";
    encoder.Put(key, key.size());
    encoder.MessageEnd();
    std::cout << std::endl;

    std::cout << "iv: ";
    encoder.Put(iv, iv.size());
    encoder.MessageEnd();
    std::cout << std::endl;

    std::cout << "cipher text: ";
    encoder.Put((const byte*)&cipher[0], cipher.size());
    encoder.MessageEnd();
    std::cout << std::endl<< std::endl;
    
}

SecByteBlock setupKeyAES(){
    AutoSeededRandomPool prng;
    SecByteBlock tmp(AES::DEFAULT_KEYLENGTH);
    int useRandKey;
    cout<<"Use randomkey? Yes=1/ No=0"<<endl;
    cin >>useRandKey;
    switch (useRandKey)
    {
    case 0:
        cout<<"type key: ";
        cin>>tmp;
        break;
    
    case 1:
        prng.GenerateBlock( tmp, tmp.size() );
        break;
    default:
        prng.GenerateBlock( tmp, tmp.size() );
        break;
    }
    return tmp;
}

SecByteBlock setupIVAES(){
    AutoSeededRandomPool prng;
    SecByteBlock iv(AES::BLOCKSIZE);
    int useRandKey;
    cout<<"Use random IV? Yes=1/ No=0"<<endl;
    cin >>useRandKey;
    switch (useRandKey)
    {
    case 0:
        cout<<"type IV: ";
        cin>>iv;
        break;
    case 1:
        prng.GenerateBlock( iv, iv.size() );
        break;
    default:
        prng.GenerateBlock( iv, iv.size() );
        break;
    }
    return iv;
}

string getPlaint(){
    string input;
    cout<<"type message: "<<endl;
    cin.ignore();
    std::getline(cin,input);
    
    return input;
}

void display(SecByteBlock key, SecByteBlock iv, string cipher){
    HexEncoder encoder(new FileSink(std::cout));
    std::cout << "key: ";
    encoder.Put(key, key.size());
    encoder.MessageEnd();
    std::cout << std::endl;

    std::cout << "iv: ";
    encoder.Put(iv, iv.size());
    encoder.MessageEnd();
    std::cout << std::endl;

    std::cout << "cipher text: ";
    encoder.Put((const byte*)&cipher[0], cipher.size());
    encoder.MessageEnd();
    std::cout << std::endl;
}

void AESEncrypt_CBC(){
    SecByteBlock key(AES::DEFAULT_KEYLENGTH);
    SecByteBlock iv(AES::BLOCKSIZE);
    key=setupKeyAES();
    iv=setupIVAES();
    
    std::string plain = getPlaint();
    std::string cipher, recovered;
    std::cout << "plain text: " << plain << std::endl;
    try
    {
        int sttime = clock();
        double etime;
        CBC_Mode< AES >::Encryption e;
        e.SetKeyWithIV(key, key.size(), iv);

        StringSource s(plain, true, 
            new StreamTransformationFilter(e,
                new StringSink(cipher)
            ) 
        );
        int stime = clock();
        etime = (stime-sttime)/double(CLOCKS_PER_SEC)*1000;
        std::cout << "Encryption time: " << etime << " ms"  << std::endl;
    }
    catch(const Exception& e)
    {
        std::cerr << e.what() << std::endl;
        exit(1);
    }
    display(key,iv,cipher);
    try
    {   
        CBC_Mode< AES >::Decryption d;
        d.SetKeyWithIV(key, key.size(), iv);
        int sttime = clock();
        double etime;
        StringSource s(cipher, true, 
            new StreamTransformationFilter(d,
                new StringSink(recovered)
            ) // StreamTransformationFilter
        ); // StringSource
        
        int stime = clock();
        etime = (stime-sttime)/double(CLOCKS_PER_SEC)*1000;
        std::cout << "Decryption time: " << etime << " ms"  << std::endl;
        

        std::cout << "recovered text: " << recovered << std::endl<<endl;
    }
    catch(const Exception& e)
    {
        std::cerr << e.what() << std::endl;
        exit(1);
    }

}

void AESEncrypt_GCM(){
    AutoSeededRandomPool prng;
    SecByteBlock key( AES::DEFAULT_KEYLENGTH );

    key=setupKeyAES();

    byte iv[AES::BLOCKSIZE];
    int useRandKey;
    cout<<"Use random IV? Yes=1/ No=0"<<endl;
    cin >>useRandKey;
    switch (useRandKey)
    {
    case 0:
        cout<<"type IV: ";
        cin>>iv;
        break;
    case 1:
        prng.GenerateBlock( iv, sizeof(iv));
        break;
    default:
        prng.GenerateBlock( iv, sizeof(iv) );    
        break;
    }

    const int TAG_SIZE = 12;
    string pdata;
    pdata = getPlaint();

    string cipher, encoded;

    string rpdata;

    try
    {
        GCM< AES >::Encryption e;
        e.SetKeyWithIV( key, key.size(), iv, sizeof(iv) );
        int sttime = clock();
        double etime;
        StringSource ss1( pdata, true,
            new AuthenticatedEncryptionFilter( e,
                new StringSink( cipher ), false, TAG_SIZE
            ) // AuthenticatedEncryptionFilter
        ); // StringSource
        int stime = clock();
        etime = (stime-sttime)/double(CLOCKS_PER_SEC)*1000;
        std::cout << "Encryption time: " << etime << " ms"  << std::endl;
        
    }
    catch( CryptoPP::Exception& e )
    {
        cerr << e.what() << endl;
        exit(1);
    }
    HexEncoder encoder(new FileSink(std::cout));
    std::cout << "key: ";
    encoder.Put(key, key.size());
    encoder.MessageEnd();
    cout<<endl;
    cout<<"iv: "<<iv<<endl;
    std::cout << "cipher text: ";
    encoder.Put((const byte*)&cipher[0], cipher.size());
    encoder.MessageEnd();
    std::cout << std::endl;
    

    try
    {
        GCM< AES >::Decryption d;
        d.SetKeyWithIV( key, key.size(), iv, sizeof(iv) );
        int sttime = clock();
        double etime;
        AuthenticatedDecryptionFilter df( d,
            new StringSink( rpdata ),
            AuthenticatedDecryptionFilter::DEFAULT_FLAGS, TAG_SIZE
        );

        StringSource ss2( cipher, true,
            new Redirector(df)
       
        ); 
         int stime = clock();
        etime = (stime-sttime)/double(CLOCKS_PER_SEC)*1000;
        std::cout << "Decryption time: " << etime << " ms"  << std::endl;
        if( true == df.GetLastResult() ) {
            cout << "recovered text: " << rpdata << endl;
        }
        
    }
    catch( CryptoPP::Exception& e )
    {
        cerr << e.what() << endl;
        exit(1);
    }
}

void AESEncrypt_CCM(){
   
    SecByteBlock key( AES::DEFAULT_KEYLENGTH );
    key=setupKeyAES();

    byte iv[ 12 ];
    AutoSeededRandomPool prng;
    int useRandKey;
    cout<<"Use random IV? Yes=1/ No=0"<<endl;
    cin >>useRandKey;
    switch (useRandKey)
    {
    case 0:
        cout<<"type 12 bytes iv: ";
        cin>>iv;
        break;
    case 1:
        prng.GenerateBlock( iv, sizeof(iv) );
        break;
    default:
        prng.GenerateBlock( iv, sizeof(iv) );
        break;
    }

    const int TAG_SIZE = 8;

    string pdata;
    pdata = getPlaint();
    string cipher;
    string rpdata;
    try
    {
        CCM< AES, TAG_SIZE >::Encryption e;
        e.SetKeyWithIV( key, key.size(), iv, sizeof(iv) );
        e.SpecifyDataLengths( 0, pdata.size(), 0 );
        int sttime = clock();
        double etime;
        StringSource ss1( pdata, true,
            new AuthenticatedEncryptionFilter( e,
                new StringSink( cipher )
            ) // AuthenticatedEncryptionFilter
        ); // StringSource
        int stime = clock();
        etime = (stime-sttime)/double(CLOCKS_PER_SEC)*1000;
        std::cout << "Encryption time: " << etime << " ms"  << std::endl;
         // StringSource
    }
    catch( CryptoPP::Exception& e )
    {
        cerr << "Caught Exception..." << endl;
        cerr << e.what() << endl;
        cerr << endl;
    }
    HexEncoder encoder(new FileSink(std::cout));
    cout << "key: ";
    encoder.Put(key, key.size());
    encoder.MessageEnd();
    cout << endl;
    cout<<"iv: "<<iv<<endl;
    std::cout << "cipher text: ";
    encoder.Put((const byte*)&cipher[0], cipher.size());
    encoder.MessageEnd();
    std::cout << std::endl<< std::endl;

    try
    {
        CCM< AES, TAG_SIZE >::Decryption d;
        d.SetKeyWithIV( key, key.size(), iv, sizeof(iv) );
        d.SpecifyDataLengths( 0, cipher.size()-TAG_SIZE, 0 );
        int sttime = clock();
        double etime;
        AuthenticatedDecryptionFilter df( d,
            new StringSink( rpdata )
        ); // AuthenticatedDecryptionFilter
        StringSource ss2( cipher, true,
            new Redirector( df )
        );  // StringSource
        int stime = clock();
        etime = (stime-sttime)/double(CLOCKS_PER_SEC)*1000;
        std::cout << "Decryption time: " << etime << " ms"  << std::endl;

        if( true == df.GetLastResult() ) {
            cout << "recovered text: " << rpdata << endl;
        }
    }
    catch( CryptoPP::Exception& e )
    {
        cerr << "Caught Exception..." << endl;
        cerr << e.what() << endl;
        cerr << endl;
    }

}

void AESEncrypt_CFB(){
    AutoSeededRandomPool prng;

    SecByteBlock key(AES::DEFAULT_KEYLENGTH);
    key=setupKeyAES();
    SecByteBlock iv( AES::BLOCKSIZE );
    iv = setupIVAES();
    string plain= getPlaint();
    string cipher, encoded, recovered;
    try
    {
        cout << "plain text: " << plain << endl;

        CFB_Mode< AES >::Encryption enc;
        enc.SetKeyWithIV( key, key.size(), iv );
        int sttime = clock();
        double etime;
        StringSource ss1( plain, true, 
            new StreamTransformationFilter( enc,
                new StringSink( cipher )
            ) // StreamTransformationFilter      
        ); // StringSource
        int stime = clock();
        etime = (stime-sttime)/double(CLOCKS_PER_SEC)*1000;
        std::cout << "Encryption time: " << etime << " ms"  << std::endl;
        
    }
    catch( CryptoPP::Exception& e )
    {
        cerr << e.what() << endl;
        exit(1);
    }

    StringSource ss2( cipher, true,
        new HexEncoder(
            new StringSink( encoded )
        ) // HexEncoder
    ); // StringSource
    display(key,iv, cipher);


    try
    {
        CFB_Mode< AES >::Decryption dec;
        dec.SetKeyWithIV( key, key.size(), iv );
        int sttime = clock();
        double etime;
        StringSource ss3( cipher, true, 
            new StreamTransformationFilter( dec,
                new StringSink( recovered )
            ) // StreamTransformationFilter
        ); // StringSource
        int stime = clock();
        etime = (stime-sttime)/double(CLOCKS_PER_SEC)*1000;
        std::cout << "Decryption time: " << etime << " ms"  << std::endl;
        

        cout << "recovered text: " << recovered << endl;
    }
    catch( CryptoPP::Exception& e )
    {
        cerr << e.what() << endl;
        exit(1);
    }
}
void AESEncrypt_XTS(){
    AutoSeededRandomPool prng;

    SecByteBlock key(32), iv(16);
    int useRandKey;
    cout<<"Use random key + IV? Yes=1/ No=0"<<endl;
    cin>>useRandKey;
    switch (useRandKey)
    {
    case 0:
        cout<<"key: ";
        cin>>key;
        cout<<"iv: ";
        cin>>iv;
        break;
    
    case 1:
        prng.GenerateBlock( key, key.size());
        prng.GenerateBlock( iv, iv.size());
        break;
    default:
        prng.GenerateBlock( key, key.size());
        prng.GenerateBlock( iv, iv.size());
        break;
    }
    std::string plain;
    cout<<"type long message: ";
    cin.ignore();
    getline(cin,plain);
    std::string cipher, encoded, recovered;

    try
    {
        std::cout << "plain text: " << plain << std::endl;

        XTS_Mode< AES >::Encryption enc;
        enc.SetKeyWithIV( key, key.size(), iv );
        int sttime = clock();
        double etime;
        StringSource ss( plain, true, 
            new StreamTransformationFilter( enc,
                new StringSink( cipher ),
                StreamTransformationFilter::NO_PADDING
            ) // StreamTransformationFilter      
        ); // StringSource
        int stime = clock();
        etime = (stime-sttime)/double(CLOCKS_PER_SEC)*1000;
        std::cout << "Encryption time: " << etime << " ms"  << std::endl;
        
    }
    catch( const CryptoPP::Exception& ex )
    {
        std::cerr << ex.what() << std::endl;
        exit(1);
    }

    StringSource ss( cipher, true,
        new HexEncoder(
            new StringSink( encoded )
        ) // HexEncoder
    ); // StringSource
    std::cout << "cipher text: " << encoded << std::endl;

    try
    {
        XTS_Mode< AES >::Decryption dec;
        dec.SetKeyWithIV( key, key.size(), iv );
        int sttime = clock();
        double etime;
        StringSource ss( cipher, true, 
            new StreamTransformationFilter( dec,
                new StringSink( recovered ),
                StreamTransformationFilter::NO_PADDING
            ) // StreamTransformationFilter
        ); // StringSource
        int stime = clock();
        etime = (stime-sttime)/double(CLOCKS_PER_SEC)*1000;
        std::cout << "Decryption time: " << etime << " ms"  << std::endl;
        std::cout << "recovered text: " << recovered << std::endl;
    }
    catch( const CryptoPP::Exception& ex )
    {
        std::cerr << ex.what() << std::endl;
        exit(1);
    }
}
void AESEncrypt_ECB(){
    AutoSeededRandomPool prng;

	SecByteBlock key(AES::DEFAULT_KEYLENGTH);
	key=setupKeyAES();
    
	string plain;
    cout<<"Type message: ";
    cin.ignore();
    getline(cin,plain);
	string cipher, encoded, recovered;

	// Pretty print key
	encoded.clear();
	StringSource(key, sizeof(key), true,
		new HexEncoder(
			new StringSink(encoded)
		) // HexEncoder
	); // StringSource
	cout << "key: " << encoded << endl;

	try
	{
		cout << "plain text: " << plain << endl;

		ECB_Mode< AES >::Encryption e;
		e.SetKey(key, sizeof(key));
        int sttime = clock();
        double etime;
        StringSource(plain, true, 
			new StreamTransformationFilter(e,
				new StringSink(cipher)
			) // StreamTransformationFilter      
		); // StringSource
        int stime = clock();
        etime = (stime-sttime)/double(CLOCKS_PER_SEC)*1000;
        std::cout << "Encryption time: " << etime << " ms"  << std::endl;
		
	}
	catch(const CryptoPP::Exception& e)
	{
		cerr << e.what() << endl;
		exit(1);
	}


	// Pretty print
	encoded.clear();
	StringSource(cipher, true,
		new HexEncoder(
			new StringSink(encoded)
		) // HexEncoder
	); // StringSource
	cout << "cipher text: " << encoded << endl;


	try
	{
		ECB_Mode< AES >::Decryption d;
		d.SetKey(key, sizeof(key));
        int sttime = clock();
        double etime;
        StringSource s(cipher, true, 
			new StreamTransformationFilter(d,
				new StringSink(recovered)
			) // StreamTransformationFilter
		); // StringSource
        int stime = clock();
        etime = (stime-sttime)/double(CLOCKS_PER_SEC)*1000;
        std::cout << "Decryption time: " << etime << " ms"  << std::endl;
		

		cout << "recovered text: " << recovered << endl;
	}
	catch(const CryptoPP::Exception& e)
	{
		cerr << e.what() << endl;
		exit(1);
	}
}
void AESEncrypt_OFB(){
    AutoSeededRandomPool prng;
    SecByteBlock key(AES::DEFAULT_KEYLENGTH);
    key=setupKeyAES();
    byte iv[ AES::BLOCKSIZE ];
    prng.GenerateBlock( iv, sizeof(iv) );

    string plain;
    cout<<"type message: ";
    cin.ignore();
    std::getline(cin,plain);

    string cipher, encoded, recovered;

    try
    {
        cout << "plain text: " << plain << endl;
        OFB_Mode< AES >::Encryption e;

        e.SetKeyWithIV( key, sizeof(key), iv );

        int sttime = clock();
        double etime;
        StringSource ss1( plain, true, 
            new StreamTransformationFilter( e,
                new StringSink( cipher )
            ) // StreamTransformationFilter      
        ); // StringSource
        int stime = clock();
        etime = (stime-sttime)/double(CLOCKS_PER_SEC)*1000;
        std::cout << "Encryption time: " << etime << " ms"  << std::endl;
        
    }
    catch( CryptoPP::Exception& e )
    {
        cerr << e.what() << endl;
        exit(1);
    }
    StringSource ss2( cipher, true,
        new HexEncoder(
            new StringSink( encoded )
        ) // HexEncoder
    ); // StringSource
    cout << "cipher text: " << encoded << endl;
    try
    {
        OFB_Mode< AES >::Decryption d;
        d.SetKeyWithIV( key, sizeof(key), iv );

        int sttime = clock();
        double etime;
        StringSource ss3( cipher, true, 
            new StreamTransformationFilter( d,
                new StringSink( recovered )
            ) // StreamTransformationFilter
        ); // StringSource
        int stime = clock();
        etime = (stime-sttime)/double(CLOCKS_PER_SEC)*1000;
        std::cout << "Decryption time: " << etime << " ms"  << std::endl;
        

        cout << "recovered text: " << recovered << endl;
    }
    catch( CryptoPP::Exception& e )
    {
        cerr << e.what() << endl;
        exit(1);
    }
}
void AESEncrypt_CTR(){
    AutoSeededRandomPool prng;

    SecByteBlock key(AES::DEFAULT_KEYLENGTH);
    key = setupKeyAES();

    byte ctr[ AES::BLOCKSIZE ];
    prng.GenerateBlock( ctr, sizeof(ctr) );

    std::string plain;
    cout<<"type message: ";
    cin.ignore();
    getline(cin,plain);
    string cipher, encoded, recovered;

    try
    {
        cout << "plain text: " << plain << endl;

        CTR_Mode< AES >::Encryption e;
        e.SetKeyWithIV( key, key.size(), ctr );

        int sttime = clock();
        double etime;
        StringSource ss1( plain, true, 
            new StreamTransformationFilter( e,
                new StringSink( cipher )
            ) // StreamTransformationFilter      
        ); // StringSource
        int stime = clock();
        etime = (stime-sttime)/double(CLOCKS_PER_SEC)*1000;
        std::cout << "Encryption time: " << etime << " ms"  << std::endl;
        
    }
    catch( CryptoPP::Exception& e )
    {
        cerr << e.what() << endl;
        exit(1);
    }

    StringSource ss2( cipher, true,
        new HexEncoder(
            new StringSink( encoded )
        ) // HexEncoder
    ); // StringSource
    cout << "cipher text: " << encoded << endl;


    try
    {
        CTR_Mode< AES >::Decryption d;
        d.SetKeyWithIV( key, key.size(), ctr );
        
        int sttime = clock();
        double etime;
        StringSource ss3( cipher, true, 
            new StreamTransformationFilter( d,
                new StringSink( recovered )
            ) // StreamTransformationFilter
        ); // StringSource
        int stime = clock();
        etime = (stime-sttime)/double(CLOCKS_PER_SEC)*1000;
        std::cout << "Decryption time: " << etime << " ms"  << std::endl;
        

        cout << "recovered text: " << recovered << endl;
    }
    catch( CryptoPP::Exception& e )
    {
        cerr << e.what() << endl;
        exit(1);
    }
}



void my_AES(){
    

    std::cout<<"\nChoose a mode by type a number below:";
    std::cout<<"\n1. CBC";
    std::cout<<"\n2. GCM";
    std::cout<<"\n3. CCM";
    std::cout<<"\n4. CFB";
    std::cout<<"\n5. XTS";
    std::cout<<"\n6. ECB";
    std::cout<<"\n7. OFB";
    std::cout<<"\n8. CTR\n";

    int choose = 1;
    std::cin>>choose;
    switch (choose)
    {
    case 1:
        AESEncrypt_CBC();
        break;
    case 2:
        AESEncrypt_GCM();
        break;
    case 3:
        AESEncrypt_CCM();
        break;
    case 4:
        AESEncrypt_CFB();
        break;
    case 5:
        AESEncrypt_XTS();
        break;
    case 6:
        AESEncrypt_ECB();
        break;
    case 7:
        AESEncrypt_OFB();
        break;
    case 8:
        AESEncrypt_CTR();
        break;
    default:
        break;
    }
    
    
}


int main(){ 
    std::cout<<"+-------------------------------------------------+"<<std::endl;
    std::cout<<"|                   A_CRYPTO_APP                  |"<<std::endl;
    std::cout<<"+-------------------------------------------------+"<<std::endl;
    std::cout<<"Enter to start."<<std::endl;
    
    for(;;){
        int tmpAl;
        std::cout<<"Type number to choose...... "<<std::endl;
            std::cout<<"1> 2DES"<<std::endl;
            std::cout<<"2> 3DES"<<std::endl;
            std::cout<<"3> AES"<<std::endl;
            std::cout<<"4> Exit app"<<std::endl;
        while (true)
        {
            std::string tmp;
            getline(std::cin,tmp);
            std::stringstream convertor(tmp);
            convertor>>tmpAl;
            if(tmpAl>0&& tmpAl<5){
                break;
            }
        }
        
        int algo=tmpAl;
        tmpAl =-1;
        switch (algo)
        {
        case 1:
            DES_2();
            break;
        case 2:
            DES_3();

            break;
        case 3:
            my_AES();
            break;
        case 4:
            return 0;
            break;
        }
    }
    
    return 0;
}