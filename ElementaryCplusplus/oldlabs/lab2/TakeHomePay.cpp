/* Program Name: TakeHomePay.cpp
 * Student Name: Liam Loeffel
 * Net ID: lloeffel
 * Student ID: 000664706
 * Program Description: This program takes in the user's salary, and outputs the Yearly Salary, Social Security Tax, Medicare Tax, Income Tax, Yearly Take Home Pay, and Monthly Take Home Pay. */
#include <iostream>
#include <iomanip>
#include <limits>
#include <vector>
const double MINIMUM_WAGE = 15080;

using namespace std;

int main (){
	double salary; //stores the user salary
	vector <double> taxRanges = {0,10275,41775,89075,170050,215950,539900}; //Stores the tax ranges for each bracket
	vector <double> taxRates = {.1,.12,.22,.24,.32,.35,.37}; //Stores the values of the tax Rates for each bracket
	int taxIndex; //Used to store the value of the user's tax index

	//Gathering the data on the user's salary
	cout << "Enter a salary: $";
	cin >> salary;
	
	//Eliminating values below minimum wage
	if (salary <= MINIMUM_WAGE) {
		 cerr << "This is less than minimum wage for a yearly salary." << endl;
		 return 1; //returns an error
	}

	//finding the tax bracket the user is in
	for (int i = taxRanges.size() - 1; i >= 0; i--){
		//finds the largest tax bracket that the salary qualifies for
		if (salary > taxRanges[i]){
			taxIndex = i;
			break; 
		}
	}

	//Calculating Income Tax:
	double incomeTax;
	for (int i = 0; i <= taxIndex; i++){
		//Since the first bracket is subtracted from the salary, there is a different calculation
		//for the first interation than the rest.
		if (i == 0){ 
			incomeTax = ((salary-taxRanges[taxIndex]) * taxRates[taxIndex]); // (SALARY - Tax Bracket) * Tax Bracket Ratio
			continue;
		}
		incomeTax = incomeTax + ((taxRanges[taxIndex-i+1]-taxRanges[taxIndex-i]) * taxRates[taxIndex-i]); // ADDS ((Previous Tax Bracket - Current Tax Bracket) * Tax Bracket Ratio) to the incomeTax calculated so far
	}

	//Adding aesthetic to the super fancy table:
	cout << "-----------------------------------" << endl;

	//Printing the Yearly Salary in the Table
	cout << left << setw(25) << "Yearly Salary:" << right << "$";
	cout << right << setw(9) << setprecision(2) << fixed << salary << endl;
	//Printing the Social Security Tax in the Table
	cout << left << setw(25) << "Social Security Tax:" << right << "$";
	cout << right << setw(9) << setprecision(2) << fixed << salary * 0.062 << endl;
	//Printing the Medicare Tax in the Table
	cout << left << setw(25) << "Medicare Tax:" << right << "$";
	cout << right << setw(9) << setprecision(2) << fixed << salary * 0.0145 << endl;
	//Printing the Income Tax in the Table
	cout << left << setw(25) << "Income Tax:" << right << "$";
	cout << right << setw(9) << setprecision(2) << fixed << incomeTax << endl;
	
	//More aesthetic to the fancy table
	cout << "-----------------------------------" << endl;
	
	//Printing the Take Home Salary to the table:
	cout << left << setw(25) << "Take Home Salary:" << right << "$";
	cout << right << setw(9) << setprecision(2) << fixed << salary - (salary * 0.062) - (salary * 0.0145) - incomeTax << endl;
	//Printing the Monthly Take Home Pay to the table:
	cout << left << setw(25) << "Monthly Take Home Pay:" << right << "$";
	cout << right << setw(9) << setprecision(2) << fixed << (salary - (salary * 0.062) - (salary * 0.0145) - incomeTax) / 12.0 << endl;
	return 0;

}
