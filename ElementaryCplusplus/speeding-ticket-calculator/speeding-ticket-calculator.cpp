/* Program Name: Speeding Ticket Calculator
 * Student Name: Liam Loeffel
 * Net ID: lloeffel
 * Student ID: 000664706
 * Program Description: This program uses a given file with the speeding ticket info, and outputs formatted date, citation, and fine. It will only calculate it for the range of dates the user gives.
 * */

//! Remember: your comments
//! Remember: your formatting
//  auto-format in vim: gg=G in normal mode, in vscode: alt+shift+f

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

//! Remember: non-const globals are a penalty
//    "non-const globals" aka variables defined outside of a function e.g. main
//    without the const keyword are a penalty on your grade

const string THREE_LETTER_MONTHS[] = {
	"Jan", "Feb", "Mar", "Apr", "May", "Jun",
	"Jul", "Aug", "Sep", "Oct", "Nov", "Dec",
};

const double INTERSTATE_MULTIPLIER = 5.2243 /* TODO */;
const double HIGHWAY_MULTIPLIER = 9.4312 /* TODO */;
const double RESIDENTIAL_MULTIPLIER = 17.2537/* TODO */;
const double DEFAULT_MULTIPLIER = 12.916 /* TODO */;

int serializeDate(const int year, const int month, const int day) {
	// TODO: combine the month, day, and year into a single integer
	// TODO: in the form YYYYMMDD to easily compare dates
	// Example usage:
	//   int serialStartDate = serializeDate(startYear, startMonth, startDay);
	int serialDate;
	int tempYear;
	tempYear = 2000;

	//Dealing with cases where the year in the data table is only two digits
	//and adding the year to the serialDate variable
	if ((year % 1000) == year){
		tempYear = tempYear + year;
		serialDate = tempYear * 10000;
	}else {
		serialDate = year * 10000;
	}
	//adding the month and day to the serialDate
	serialDate = serialDate + (month * 100) + day;
	return serialDate;
}

int main() {
	// - HINT: You do not need vectors for this lab, you can write each line of
	//   output directly to the output file
	// - HINT: You do not need `getline` or `stringstreams`
	//   you can use the format while(fin >> citationNumber >> month >> ...)
	//   to read out the fields of data from each line
	// - HINT: remember to check if your file opened,
	//   and close it once finished

	// TODO
	string inputFileName; //stores the input file name
	string outputFileName; //stores the output file name
	int m, d, y, speed, speedLimit; //m = month, d = day, y = year, speed = the speed clocked by the cop, speedLimit = speedLimit that the driver surpassed
	char multiplierType; // stores the road type for the speeding violation
	string monthText; // stores the month's three letter text
	string caseID; // stores the citation ID
	double fine; // stores the calculated value of the fine
	double fineMultiplier; //stores the correct value for the fine multiplier
	int startDate; // stores the starting date of the range
	int endDate; // stores the ending date of the range
	//prompts the user to enter the path to the ticket file
	cout << "Enter a ticket file: "; 
	cin >> inputFileName;
	ifstream fin;
	fin.open(inputFileName);
	//checking to make sure the file is openable
	if (!fin.is_open()){
		cerr << "Unable to open " << inputFileName << "." << endl;
		return 1;
	}
	//prompts the user to enter the path to the output file
	cout << "Enter a report file: ";
	cin >> outputFileName;
	ofstream fout;
	fout.open(outputFileName);
	//checking to make sure the file is openable
	if (!fout.is_open()){
		cerr << "Unable to open " << outputFileName << "." << endl;
		return 1;
	}
	//prompts the user to input the starting date for the range
	cout << "Enter report start date (mm dd yyyy): ";
	cin >> m >> d >> y;
	//storing the starting value of the range
	startDate = serializeDate(y,m,d);
	//prompts the user to input the ending date for the range
	cout << "Enter report end date   (mm dd yyyy): ";
	cin >> m >> d >> y;
	//storing the ending value of the range
	endDate = serializeDate(y,m,d);
	//going thru the fin file
	while (fin >> caseID >> m >> d >> y >> speed >> speedLimit >> multiplierType){
		//checking if the date is in the valid range
		if ((serializeDate(y,m,d) >= startDate) && (serializeDate(y,m,d) <= endDate)){
			//finding the correct multiplier for the value
			switch (multiplierType){
				case 'i':
					fineMultiplier = INTERSTATE_MULTIPLIER;
					break;
				case 'h':
					fineMultiplier = HIGHWAY_MULTIPLIER;
					break;
				case 'r':
					fineMultiplier = RESIDENTIAL_MULTIPLIER;
					break;
				case 'I':
					fineMultiplier = INTERSTATE_MULTIPLIER;
					break;
				case 'H':
					fineMultiplier = HIGHWAY_MULTIPLIER;
					break;
				case 'R':
					fineMultiplier = RESIDENTIAL_MULTIPLIER;
					break;

				default:
					fineMultiplier = DEFAULT_MULTIPLIER;
			}
			//Calculating fine
			fine = (speed - speedLimit) * fineMultiplier;
			//checking to make sure the fine is not negative
			if (fine <= 0){
				fine = 0.00;
			}
			//Formatting for the output file
			fout << setfill('0');
			fout << setw(2) << d << "-" << setw(2) << THREE_LETTER_MONTHS[m-1] << "-" << serializeDate(y,m,d)/10000 << " " << caseID;
			fout << "    $" << setfill(' ') << right << setprecision(2) << fixed << setw(9) << fine << endl;
		}
	}
	fin.close();
	fout.close();
	return 0;
}
