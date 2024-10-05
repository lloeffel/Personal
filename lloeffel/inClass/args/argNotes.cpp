/*Command Line Arguments
 * Command Line - the Unix/Linux way of navigating the computer
 *	  we run out c++ executables on the cmd line
 * Arguments - inputs to a function (in this case, it's the main fct)
 *
 * If you want to use Command Line Arguments, then write the main fct () the follwing two ways:
 * int main (int argc, char **argv) {}
 * OR
 * int main (int argc, char *argv[]) {}
 *
 * argc = argument count
 * argv = argument values
 *
 * argv will probably need to be transferred to a c++ string
 * you can use stoi() or stod() to take a c++ string -> int or double
 *
 * Error Checking
 * -----------------
 *	Make usre that argc is correct based on how you wrote the program
 *
 *
 */


#include <iostream>
using namespace std;

int main(int argc, char **argv) {

if(argc != 4){
		cerr << "usage: ./argNotes name favNum computerSize";
		return 1;
	}
	cout << argv[1] << endl;

	cout << "the argument count is " << argc << endl;
	
	string argv3 = argv[3];
	double a = stod(argv3) + 1;

	cout << "a = " << a << endl;
}
