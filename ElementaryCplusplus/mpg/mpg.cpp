/* Program Name: Miles Per Gallon Calculator
 * Student Name: Liam Loeffel
 * Net ID: lloeffel
 * Student ID: 000664706
 * Program Description: This program gives the user an interface to enter in a car, truck, or to tell the program that they are done. If the user inputs "car" or "truck", they are then prompted to input miles and gallons of the car. Once "done" is inputted, the program outputs the average MPG for cars and trucks if that data exists */

#include <iostream>
#include <limits>
#include <string>

using namespace std;

int main() {
	string carType; //value can be "truck", "car", or "done"
	double miles;
	double gallons; 
	double carMilesSum; //Summation of all cars' miles
	double carGallonsSum; //Summation of all cars' gallons
	double truckMilesSum; // Summation of all trucks' miles
	double truckGallonsSum; //Summation of all trucks' gallons
	carMilesSum = 0;
	carGallonsSum = 0;
	truckMilesSum = 0;
	truckGallonsSum = 0;
	//Loops until the "done" command breaks out the program
	while(true){
		cout << "Enter command: ";
		//checking to make sure the user's input is valid
		if (!(cin >> carType)){
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}else{
			//checking if carType was "car"
			if (carType == "car"){
				//Loops until a valid value for miles is inputted
				while(true){
					cout << "Enter car's miles: ";
					//Checks to see if miles is a valid double
					if (!(cin >> miles)){
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
					}else{
						carMilesSum = carMilesSum + miles; //updating carMilesSum
						//Loops until a valid value for gallons is inputted
						while(true){
							cout << "Enter car's gallons: ";
							//Checks to see if gallons is a valid double
							if (!(cin >> gallons)){
								cin.clear();
								cin.ignore(numeric_limits<streamsize>::max(), '\n');
							}else{
								carGallonsSum = carGallonsSum + gallons; //updating carGallonsSum
								break;
							}
						}
						break;
					}
				}
			//checking if carType was "truck"
			}else if(carType == "truck"){
				//Loops until a valid value for miles is inputted
				while(true){
					cout << "Enter truck's miles: ";
					//Checks if miles is a valid double
					if (!(cin >> miles)){
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
					}else{
						truckMilesSum = truckMilesSum + miles; //updating truckMilesSum
						//Loops until a valid value for gallons is inputted
						while(true){
							cout << "Enter truck's gallons: ";
							//Checks if the gallons is a valid double
							if (!(cin >> gallons)){
								cin.clear();
								cin.ignore(numeric_limits<streamsize>::max(), '\n');
							}else{
								truckGallonsSum = truckGallonsSum + gallons; //updating truckGallonsSum
								break;
							}
						}
						break;
					}
				}
			//checking if carType was "done"
			}else if(carType == "done"){
				//checks to make sure if there are any cars inputted
				if ((carMilesSum / carGallonsSum) > 0){
					cout << "Average car MPG = " << carMilesSum / carGallonsSum << endl;
				}else{
					cout << "Fleet has no cars." << endl;
				}
				//checks to make sure if there are any trucks inputted
				if ((truckMilesSum / truckGallonsSum) > 0){
					cout << "Average truck MPG = " << truckMilesSum / truckGallonsSum << endl;
				}else{
					cout << "Fleet has no trucks." << endl;
				}
				break;
			//runs if the value of carType is not "car", "truck", or "done"
			}else{
				cout << "Unknown command." << endl;
			}
		}
		
	}

	return 0;
}
