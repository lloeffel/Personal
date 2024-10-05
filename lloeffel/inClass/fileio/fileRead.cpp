/* READING FROM A FILE - input1.txt is our file to read from
 * 1.  Include <fstream> header
 * 2.  Declare a file variable (ifstream for reading, stands for input file stream)
 *	   and name it
 * 3a. Open the file by connecting the variable (fin) to the actual filename
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
	ifstream fin; //2
	int a, b, c;
	vector <int> data;
	
	fin.open("input1.txt"); //3a

	if (!fin.is_open()){ //3b
		cerr << "Could not open input1.txt" << endl;
		return 1;
	}

	while (fin >> a >> b >> c){ //4
		cout << "You read " << a << b << c << endl;
		data.push_back(a);
		data.push_back(b);
		data.push_back(c);
	}

	fin.close;

	

}
