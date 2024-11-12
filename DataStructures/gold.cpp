// Name: Liam Loeffel (UTK id: lloeffel)
// Lab 0:  finding gold!!
// Date: 1/25/2024
// Description: This program takes a .txt file and reads it finding "gold" and counts how much it weighs based on the numerical value of the character.

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
	
	char mapInput; //stores the map
	int goldWeight = 0; //stores the weight of the gold
	
	while (cin >> mapInput){

		//Looking for Gold
		if (mapInput != '.' && mapInput != '-'){

			//Adds to the goldweight based on the char's numerical value
			goldWeight = goldWeight + mapInput - 64;	

		}

	}

	//final output
	cout << goldWeight << endl;

	return 0;
}

