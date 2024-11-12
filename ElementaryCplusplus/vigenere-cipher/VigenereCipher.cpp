/* Program Name: Vigenere Cipher
 * Student Name: Liam Loeffel
 * Net ID: lloeffel
 * Student ID: 000-664-706
 * Program Description: This program will take a message, and output that message encrypted into an output file using the given key. This program will also take an encrypted message and the given key, and output the intended message into an output file. */

#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string> //added to manipulate strings
#include <cstring> // added to compare strings
using namespace std;

class VigenereCipher {
	private:
		string key;
		char vTable[26][26];
		string fileToString(string fileName);
		void stringToFile(string s, string outputFileName);
		string makeKeystream(string msg);

	public:
		VigenereCipher(string k);
		void encrypt(string inputFile, string outputFile);
		void decrypt(string inputFilename, string outputFilename);
		void printVTable();

};

string VigenereCipher::fileToString(string fileName) {
	ifstream fin(fileName);
	string message;
	char character;

	if (!fin.is_open()) {
		cerr << "file " << fileName << " unable to open." << endl;
		exit(1);
	}
	while (fin.get(character)) {
		message.push_back(character);
	}
	fin.close();
	return message;
}

void VigenereCipher::stringToFile(string s, string outputFileName) {
	ofstream fout(outputFileName);
	if (!fout.is_open()) {
		cerr << "output file " << outputFileName << " unable to open." << endl;
		exit(1);
	}
	fout << s;
	fout.close();
}

string VigenereCipher::makeKeystream(string msg) { 
	int j = 0; // keeps index of the key as it skips special characters and spaces
	for(int i = 0; i < msg.size(); i++){
		if (msg[i] <= 'z' && msg[i] >= 'a'){ //checks if the character is in the lowercase alphabet
			msg[i] = key[j%key.size()]; //converts message into the keyStream
			j++;
		}
	}
	return msg;
}

VigenereCipher::VigenereCipher(string k) {
	key = k;

	//fills vTable with letters for the cipher
	char letter = 'a';
	for(int i = 0; i < 26; i++){
		for(int j = 0; j < 26; j++){
			vTable[i][j] = letter;
			if (letter == 'z'){
				letter = 'a';
			}else{
				letter++;
			}
		}
		letter++;
	}	
}

void VigenereCipher::encrypt(string inputFile, string outputFile) {
	string keyStream = makeKeystream(fileToString(inputFile)); //creating the keystream
	string message = fileToString(inputFile);	//creating the message
	for(int i = 0; i < keyStream.size(); i++){
		for(int j = 0; j < 26; j++){
			if(keyStream[i] == vTable[j][0]){//finds the column value for the cipher letter
				for(int k = 0; k < 26; k++){
					if(message[i] == vTable[0][k]){ //finds the row value for the cipher letter
						keyStream[i] = vTable[j][k];
						break;
					}
				}
				break;
			}
		}
	}
	stringToFile(keyStream, outputFile); //puts the final product into an output file
}

void VigenereCipher::decrypt(string inputFile, string outputFile) {
	string keyStream = makeKeystream(fileToString(inputFile)); //creating the keystream
	string message = fileToString(inputFile); //creating the message
	for(int i = 0; i < keyStream.size(); i++){
		for(int j = 0; j < 26; j++){
			if(keyStream[i] == vTable[j][0]){ //finds the column value of the cipher letter
				for(int k = 0; k < 26; k++){
					if(vTable[j][k] == message[i]){ // finds the row value matching the cipher letter and message
						keyStream[i] = vTable[0][k];
						break;
					}
					
				}
				break;
			}
		}
	}
	
	stringToFile(keyStream, outputFile); //puts the final product into an output file
}

void VigenereCipher::printVTable() {
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < 26; j++) {
			cout << " " << vTable[i][j] << " ";
		}
		cout << endl;
	}
}

int main(int argc, char **argv) {

	//checks to make sure the usage is correct
	if (argc != 5){
		cerr << "usage: ./vigenereCipher inputFilename outputFilename key [e/d]" << endl;
		return 1;
	}

	//creates the object
	VigenereCipher caesarCipher(argv[3]);
	
	//sees if the code is meant to decrypt or encrypt
	if(strcmp(argv[4],"e") == 0){
		caesarCipher.encrypt(argv[1], argv[2]);
	}else{	
		caesarCipher.decrypt(argv[1], argv[2]);
	}
	return 0;
}
