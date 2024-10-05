/* Program Name: Boiling Point Program
 * Student Name: Liam Loeffel
 * Net ID: lloeffel
 * Student ID: 000664706
 * Program Description: This program takes the file the user inputs and prints out all the cities in the first column as a numbered list. Then it prompts the user to enter which city to calculate the boiling temperature for, and then it will output the city indicated and its corresponding boiling point. */

#include <cmath> // new: for pow and log
#include <fstream>
#include <iomanip> //added for setprecision()
#include <iostream>
#include <sstream> // new: for istringstream
#include <string>
#include <vector>

using namespace std;

double elevationToBoilingPoint(const double elevation) {
	double boilingPoint = 0.0;
	// calculating the boiling point
	boilingPoint =(49.161 * log(29.921 * pow(1 -(0.0000068753 * elevation), 5.2559))) + 44.932;
	return boilingPoint;
}

int main(int argc, char **argv) {
	vector <int> elevations; //stores the elevations for each city
	vector <string> cityNames; //stores the names of the cities
	
	//error checking to make sure the user started the program correctly
	if(argc != 2){
		cerr << "usage: ./boiling filename" << endl;
		return 1;
	}
	
	//making an input file stream
	ifstream fin;
	fin.open(argv[1]);

	//error checking if the stream is open
	if (!fin.is_open()){
		cerr << "File failed to open." << endl;
		return 1;
	}

	
	string city;          //temporary value of the city
	string elevation;     //temporary value of the elevation
	string state;         //temporary value of the state
	int listCount = 0;    //used to make the numbered list
	
	//title
	cout << "Boiling Point at Altitude Calculator" << endl;
	
	string line; //temporary value of the line accessed by getline()
	
	//creating the numbered list, and storing the values of elevations and cityNames
	while(getline(fin, line)){
		//skipping the title line of the csv file
		if (listCount != 0){
			istringstream sin(line);
			getline(sin, city, ',');
			cityNames.push_back(city);
			getline(sin, state, ',');
			getline(sin, elevation, ',');
			elevations.push_back(stoi(elevation));
			cout << listCount << ". " << city << endl;
			listCount++;
		}else{
			listCount++;
		}
	}

	int index; //stores the value inputted by the user

	//user input
	cout << "Enter city number: ";
	cin >> index;

	//final output
	cout << "The boiling point at " << cityNames[index - 1] << " is ";
	cout << fixed << setprecision(3) << elevationToBoilingPoint(elevations[index - 1]) << " degrees Fahrenheit." << endl;


	//closing the filestream
	fin.close();
	return 0;
}
