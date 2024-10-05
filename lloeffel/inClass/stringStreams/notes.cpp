/* String streams notes
 *
 * The string stream class is used for insertion and
 * extraction of data to/from strings. It acts as
 * a stream for the string object.
 *
 * Similar to cin/cout, fin/fout, the stream is just a different source
 *
 * source cin/cout -> console
 * source fin/fout -> file
 * source sin/sout -> string
 *
 */


#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <sstream>

using namespace std;

int main() {
	
	string date = "03 27"; //want mon is an int  and day as an int
	string date2 = "05 23";
	int mon, day;
	//string ssNum = "123-45-6789";
	
	//string time = "13:01:03";
	
	/* Steps for using a string as an input stream
	 * 1. Declare an istringstream
	 * 2. "Connect" the istringstream to a string (your input string)
	 * 3. Extract data
	 * 4. (Optional) Reuse istringstream -> need to use .clear() then
	 *	  a new string inside .str()
	 *
	 */

	//can use string as input
	istringstream sin;
	sin.str(date);
	sin >> mon >> day;
	cout << "Mon is " << mon << " and day is " << day << endl;
	
	sin.clear();
	sin.str(date2);
	sin >> mon >> day;
	cout << "Mon is " << mon << " and day is " << day << endl;
	/* sout 
	 * 1. Construct an  ostringstream (sout) object
	 * 2. Write using sout
	 * 3. Return the string
	 * 4. Reuse
	 *
	 */
	ostringstream sout;
	sout << mon << "-" << day << "-" << "2099";
	string finalWord = sout.str();
	cout << finalWord << endl;


	
}
