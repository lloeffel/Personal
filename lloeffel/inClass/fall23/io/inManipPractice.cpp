#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	/* FIRST WAY TO PRINT WITH FORMATTING - SIMILAR TO JAVA */
	//code goes here
	//lets say we want to print
	//"my favorite number is (pi rounded to 2 decimal places)"
	double pi = 3.1415;
	double x = 5.156289;
	//System.out.format("My favorite number is %.2f and %.2f, pi, x);
	printf("My favorite number is %.2f and %.2f\n", pi, x);
	/*THE OTHER WAY TO FORMAT - must #include */
	int i = 10;
	double d = 120.2145;
	double d2 = 330.123456;
	cout << i << " " << d << endl;
	cout << fixed << setprecision(2);
	cout << d << endl;
	cout << d2 << endl;
	cout << setw(10) << d << endl;
	cout << setfill('-') << setw(10) << d2 << endl;
	
}
