// Name: Liam Loeffel
// Program: Connect 4 Column Header

#ifndef C4COL_H
#define C4COL_H
#include <iostream>

class C4Col {
	private:
		int num_discs;       // number of discs
		int max_discs;       // maximum number of discs
		char disc_array[6];  // stores the values in an array
	public:
		C4Col();             // Constructor 
		int isFull();        // Returns how many discs are in the array
		char getDisc(int);   // Returns the number of the the disc at a particular index
		int getMaxDiscs();   // Returns the value of max_discs
		void addDisc(char);  //	Adds a given disc to the array

};

#endif
