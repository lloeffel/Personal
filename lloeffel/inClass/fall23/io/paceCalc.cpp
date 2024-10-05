/* Marathon Pace Calculator
 * User enters hours and minutes of a goal marathon
 * Program will return a pace
 * 3:30 marathon is an 8:01 min/mile pace -- print (M)M:SS (no deimals with seconds, rounded)
 * Marathon is 26.2 miles.
 * */
#include <iostream>
#include <iomanip>
using namespace std;

int main (){
	int mHr, mMin, pMin, pSec, totalSeconds;
	double marathonDist = 26.2; //miles
	cout << "Enter the marathon time - hours: ";
	cin >> mHr;
	cout << "minutes: ";
	cin >> mMin;

	//algorithm
	totalSeconds = (mHr * 3600) + (mMin * 60);
	double pace = totalSeconds/marathonDist;
	
	//cout << pace << endl; //480.916 for a 3:30 marathon
	
	pMin = (int) (pace / 60); //truncate (drop) the decima
	pSec = ((int) (pace + 0.5)) % 60;

	//cout statement
	cout << "Average Pace - " << pMin << ":" << setfill('0') << setw(2) << pSec << endl;
}
