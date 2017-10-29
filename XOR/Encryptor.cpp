#include "Encryptor.h"
using namespace std;

string Encryptor::getCipherText() { return cipherText; }

Encryptor::Encryptor(void) {
	privateKey = generaterRandomValue();
}

unsigned char Encryptor::generaterRandomValue() {
	static bool firstTime = false;

	if (firstTime == false) {
		srand((unsigned)time(0));
		firstTime = true;

		unsigned char secretKey = rand() % 255 + 1;
		return(secretKey);
	}
}

string Encryptor::encryptText(string plainText){
	for (string::iterator iter = plainText.begin(); iter < plainText.end(); iter++) {
		cipherText.push_back(*iter ^privateKey);  
	}

	return cipherText;
}

string Encryptor::decryptText(string cipherText){
	for (string::iterator iter = cipherText.begin(); iter < cipherText.end(); iter++) {
		decryptedText.push_back(*iter ^privateKey);  
	}

	return decryptedText;
}

bool Encryptor::reset() {
	cout << "\nDo you wish to encrypt / decrypt a new message? (y/n)\n";
	char restart;
	cin >> restart;
	if (restart == 'y' || restart == 'Y') {
		cin.ignore();
		cipherText.clear();
		decryptedText.clear();
		return true;
	}
	else if (restart == 'n' || restart == 'N') {
		cout << "Terminating the program...\n";
		return false;
	}
	else {
		cout << "Invalid input...\nTerminating the program...\n";
		return false;
	}
}