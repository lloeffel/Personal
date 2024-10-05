/* DIFFERENT SYNTAX PART 2
 *for a program that works running road races*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Marathon {
	/* attributes are going to be hours and minutes
	 * will have a constructor and a print methond */
	private:
		int hours;
		int minutes;
	public:
		Marathon (int h, int m);
		void printTotalTime();
};

Marathon::Marathon(int h, int m){
	hours = h;
	minutes = m;
}

void Marathon::printTotalTime() {
	cout << hours << ":" << minutes << endl;
}

struct Location { //Carti reference?
	string city;
	string state;
};

int addTwoNums(int a, int b){
	return a+b;
}

int main(){
	Marathon boston(3,30);
	Marathon nyc(4,10);

	nyc.printTotalTime();
	boston.printTotalTime();

	/* struct work goes here */
	Location raceLocation;
	raceLocation.city = "Boston";
	raceLocation.state = "MA";
	cout << "The race loaction is " << raceLocation.city << endl;

	int result = addTwoNums(10,20);
	cout << result << endl;
}
