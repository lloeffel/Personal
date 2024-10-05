#include <iostream>
using namespace std;

int main(){
	 char sensor; //values can be "h" for heart rate, "b" for bp, "s" for sc

	 cout << "Enter a sensor to connect: ";
	 cin >> sensor;

	 switch (sensor){
		case 'h':
			cout << "you connected hr" << endl;
			break;
		case 'b':
			cout << "you connected bp" << endl;
			break;
		case 's':
			cout << "you connected sc" << endl;
		default:
			cout << "error" << endl;
	 }
	 return 0;

}
