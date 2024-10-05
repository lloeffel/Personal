/* Pass by Reference vs Pass by Value
 *
 * defualt in c++ is pass the value 
 */
#include <iostream>
using namespace std;
/* Pass by Value - this takes s "by value" i.e. it makes a copy of s
 *
 */
int myFunction1(string s){	
	s=s + "7";
	cout << "s inside the function 1 = " << s << endl;
	return 7;
}


int myFunction2(string &s){
	s=s + "8";
	cout << "s inside the function 2 = " << s << endl;
	return 8;
}

int main(){
	string nameUT = "Smokey";
	string nameGA = "Uga";
	int result1 = myFunction1(nameUT);
	int result2 = myFunction2(nameGA);

	cout << "my result from funct1 with pass by value: " << result1 << endl;
	cout << " nameUT after the function call: " << nameUT << endl;

	cout << "my result from funct1 with pass by ref: " << result2 << endl;
	cout << " nameGA after the function call: " << nameGA << endl;
	
}
