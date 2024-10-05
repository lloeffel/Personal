/* Time Zone Conversion Calculator 
 * Convert from Pacific to Eastern */


#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	// 3 hour time difference
	// Print out the time as HH:MM
	
	int min, pHr, eHr;

	cout << "Enter the Pacific time - Hours: ";
	cin >> pHr;
	cout << "Minutes: ";
	cin >> min;
	eHr = (pHr +3) % 12;
	if (eHr == 0){
		eHr = 12;
	}

	cout << "The time converted to Eastern time is ";
	cout << setfill('0') << setw(2) << eHr << ":" << setw(2) << min << endl;
}
