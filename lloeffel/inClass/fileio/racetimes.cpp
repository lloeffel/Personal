/* READING FROM A FILE - input.txt is our file to read from
 * 1.  Include <fstream> header
 * 2.  Declare a file variable (ifstream for reading, stands for input file stream)
 *	   and name it
 * 3a. Open the file by connecting the variable (fin) to the actual filename
 * 3b. Check for failure to open
 * 4. Do the work on the intended file (read from the file)
 * 5. Close the file
 */
/* WRITING TO A FILE - results.txt is our file to write to
 * 1.  Include <fstream> header
 * 2.  Declare a file variable (ofstream for writing, stands for output file stream)
 *	   and name it
 * 3a. Open the file by connecting the variable (fout) to the actual filename
 * 3b. Check for failure to open
 * 4. Do the work on the intended file (read from the file)
 * 5. Close the file
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream> //1
using namespace std;

int main(){
	ifstream fin;
	ofstream fout; //2
	string first, last;
	int h, m, s;
	vector <string> lastNames;
	vector <string> firstNames;

	string filename = "racetimesHMS.txt";
	fin.open(filename);
	if (!fin.is_open()) {
		cerr << "racetimesHMS.txt failed to open" << endl;
		return 1;
	}

	string outputfilename = "results.txt";
	fout.open(outputfilename); //3a
	if (!fout.is_open()){ //3b
		cerr << "Could not open file. Check permissions." << endl;
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
