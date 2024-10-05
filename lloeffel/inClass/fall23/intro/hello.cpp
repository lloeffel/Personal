/* Simple Hello World Program
 * 8/29/23 */

#include <iostream>
using namespace std;

int main(){
	int x = 5;
	int y;
	cout << "Hello World!" << endl;
	cout << "My integer is " << x << endl;
	cout << "What is your favorite number? " << endl;
	cin >> y;
	cout << "You typed " << y << endl;
	string name, stName;
	int stNumber;
	cout << "Enter your first name followed by your street number and street name: ";
	cin >> name >> stNumber >> stName;
	cout << "Name = " << name << endl;
	cout << "Address = " << stNumber << " " << stName << endl;

}

