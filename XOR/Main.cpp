#pragma once

#include "Encryptor.h"

using namespace std;

string inputPlaintext();

int main() {
	string plainText;
	Encryptor myMessage;
	char choice;
	
	do {
		cout << "Press 'E' to encrypt then decrypt input text, 'D' to decrypt input text, or 'W' to encrypt text to a file and decrypt it\n";
		cin >> choice;
	
		if (choice == 'E' || choice == 'e') {
			cin.ignore();

			cout << "The encrypted text is: " << myMessage.encryptText(inputPlaintext())<< endl;

			cout << "The decrypted text is: " << myMessage.decryptText(myMessage.getCipherText());

		}
	else if (choice == 'D' || choice == 'd') {
		
			cin.ignore();

			cout << "Please enter the text to be decrypted\n";
			getline(cin, plainText);
			cout << "The decrypted text is: " << myMessage.decryptText(plainText);
	}
	
	
	else if (choice == 'w'|| choice == 'W') {
		cin.ignore();
		fstream myfile("C:\\Users\\dl874\\Documents\\QUB\\QUB C++ Repo\\XOR\\MyFile\\EncryptedMessage.txt", ios::in | ios::out);
		string lineofText;
		string output;
		cout << "Please enter the text to be encrypted:" << endl;

		if (myfile.is_open()) {
			
				getline(cin, lineofText);
				myfile << myMessage.encryptText(lineofText) << endl;
			
			myfile.close();
		}
		else {
			cout << "Unable to open file...";
		}

		myfile.open("C:\\Users\\dl874\\Documents\\QUB\\QUB C++ Repo\\XOR\\MyFile\\EncryptedMessage.txt", ios::in);

		if (myfile.is_open()) {
			cout << "The contents of your file:";
			
				getline(myfile, output);
				cout << output << endl;
				cout << "The decrypted contents of the file: " << myMessage.decryptText(output);
			
			myfile.close();
			
		}
		else {
			cout << "File can't be opened" << endl;
		}
	}
	else {
			cout << "Invalid input...\n";
		}


		} while (myMessage.reset() == true);
	
	return 0;
}

string inputPlaintext() {
	cout << "Please enter the text to be encrypted:\n";
	string plainText;
	getline(cin, plainText);
	return plainText;
}



/*#####################################################################################
	Two suggestions on how to improve the usefulness and usabilty of the application

	1) Save the encrption key: Random secret key generated is saved it will allow the
	encrypted text to be decrytped at a later date, after the program has been exited.
	As the program is currently the secret key is not saved thus, after the program is 
	closed the encrypted text cannot be decryted again. If each randmoly generated key 
	was saved in realtion to the text it encrypted then the overall usability and 
	usefulness of the program will be improved.

	2)Use passwords: If the secret key or encryption key is set to a fixed pin per 
	person then two or more people with the same pin would be able to encrypt and 
	decrypt their text with ease. A three or 4 digit pin is still quite secure, thus
	keeping the encrypted data safe.

######################################################################################*/