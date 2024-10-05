#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>

using namespace std;


int main (){
	ifstream fin("dues.csv");
	if(!fin.is_open()){
		cerr << "File failed to open - check permissions" << endl;
		return 1;
	}

	string firstName, email, jan, feb, mar, apr, may;
	int age;
	bool j, f, m;
	string line;

	while (getline(fin, line)){
		istringstream sin(line);
		getline(sin, firstName, ',');
		getline(sin, ageStr, ',');
		age = stoi(ageStr);
		getline(sin, email, ',');
		getline(sin, jan, ',');
		j = ("paid" == jan) ? true : false;
		getline(sin, feb, ',');
		f = ("paid" == feb) ? true : false;
		getline(sin, mar, ',');
		m = ("paid" == mar) ? true : false;

		getline(sin, apr, ',');
		getline(sin, may, ',');
		//store data in vectors BEFORE we get to the next line
		
		//cout << firstName << " " << email << endl;
	}
}
