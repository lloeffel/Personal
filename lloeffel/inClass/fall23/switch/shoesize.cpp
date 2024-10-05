#include <iostream>
using namespace std;

int main(){
	int shoesize;
	cout << "What is your shoe size? ";
	cin >> shoesize;
	
	if (4 == shoesize || 5 == shoesize){
	 cout << "you need a kids size shoe" << endl;
	}
	else if (6 == shoesize || 7 == shoesize || 8 == shoesize){
		cout << "you need a small size shoe" << endl;
	}
	
	else if (9 == shoesize || 10 == shoesize || 11 == shoesize){
		cout << "you need a medium size shoe" << endl;
	}
	//converting to a switch statement:
	switch (shoesize){
		case 4:
		case 5:
			cout << " in switch - you need a kids size shoe" << endl;
			break;
		case 6:
		case 7:
		case 8:
			cout << " in switch - you need a small size shoe" << endl;
			break;
		case 9:
		case 10:
		case 11:
			cout << " in switch - you need a medium size shoe" << endl;
			break;
		case 12:
		case 13:
		case 14:
		case 15:
			cout << " in switch - you need a large size shoe" << endl;
			break;
		default:
			cout << " you got big feet (show em off)" << endl;
	}
	return 0;
}
