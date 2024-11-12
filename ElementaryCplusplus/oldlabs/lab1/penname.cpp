/* Program Name: penname
 * Student Name: Liam Loeffel
 * NetID: lloeffel
 * Student ID: 000-664-706
 * Program Description:
 *		This Program asks the user to enter their first name, middle name, age, street number, street name, street type, and city of birth.
 *		Then the Program takes those inputs and outputs an alias for a writer's penname, address, and age
 * */
#include <iostream>
#include <iomanip>
using namespace std;

int main (){
	//variables
	string fName, mName, city, stName, stType; //fName: First Name; mName: Middle Name; city: City of Birth; stName: Street Name; stType: Street Type
	int age, stNum; //age: Age; stNum: Street Number

	//Gathering Data on the User
	//	name
	cout << "Enter your first and middle names: ";
	cin >> fName >> mName;
	//	age
	cout << "Enter your age: ";
	cin >> age;
	//	street
	cout << "Enter your street number, name, and type: ";
	cin >> stNum >> stName >> stType;
	//	city
	cout << "Enter your city of birth: ";
	cin >> city;

	//Output
	cout << endl << "Your penname name is " << city << " " << stName << ".";
	cout << endl << "You will write as a " << (stNum % age) * 3 << " year old" << ".";
	cout << endl << "Your address is " << (age * 425) / stNum << " " << mName << " " << stType << "." << endl;
}
