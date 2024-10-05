#include <iostream>
using namespace std;

int main(){
	int i, j;
	/*	If i is not an integer typed in the terminal,
	 *	neither i nor j will get saved. cin goes into a
	 *	FAIL state
	 *	to get cin OUT of the fail state, we use
	 *	cin.clear()
	 * */	
	cin >> i;
	cin.clear();
	cout << "I is " << i << endl;
	cin >> j;
	cin.clear();
	cout << "J is " << j << endl;
}
