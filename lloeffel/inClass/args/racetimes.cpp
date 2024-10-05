/* Took the racetimes.cpp from fileIO notes to add
 * command line args to make the program more flexible
 *
 *
 */
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream> //1
using namespace std;

int main(int argc, char **argv){
	ifstream fin;
	ofstream fout; //2
	string first, last;
	int h, m, s;
	vector <string> lastNames;
	vector <string> firstNames;
	
	if (argc != 3){
		cerr << "usage: ./racetimes inputFileName outputFileName" << endl;
		return 1;
	}


	string filename = argv[1];
	fin.open(filename);
	if (!fin.is_open()) {
		cerr << "input file failed to open" << endl;
		return 1;
	}

	string outputfilename = argv[2];
	fout.open(outputfilename); //3a
	if (!fout.is_open()){ //3b
		cerr << "Could not open output file. Check permissions." << endl;
		return 1;
	}

	while (fin >> first >> last >> h >> m >> s) {
		fout << setfill('0');
		fout << last << ", " << first << " ";
		fout << h << ":" << setw(2) << m << ":" << setw(2) << s << endl;
		//formatTime
		//print out the pace
	}

	fin.close();
	fout.close();
	return 0;
}
