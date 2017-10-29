#include <iostream>
#include <stdlib.h>    
#include <time.h>       
#include <string>
#include <fstream>

using namespace std;

class Encryptor{
private:
	unsigned char privateKey;
	
	string  cipherText;
	string decryptedText;
	
public:
	Encryptor();
	string encryptText(string plainText);
	string decryptText(string output);
	bool Encryptor::reset();
	unsigned char generaterRandomValue();
	string getCipherText();
	
};