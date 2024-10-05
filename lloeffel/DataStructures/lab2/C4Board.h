// Name: Liam Loeffel
// Program: Connect 4 Board Header

#ifndef C4BOARD_H
#define C4BOARD_H

#include <iostream>
#include "C4Col.h"

class C4Board {
	private:
		int num_cols;        // number of columns
		C4Col board[7];      // array of columns
		bool check_winner(); // returns whether the user has won or not
	public:
		C4Board();           // contstructor
		void display();	     // prints the board
		void play();         // starts the player interaction

};

#endif
