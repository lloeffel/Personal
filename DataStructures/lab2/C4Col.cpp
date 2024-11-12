// Name: Liam Loeffel
// Program: Connect 4 Column C++ file

#include "C4Col.h"

//constructor
C4Col::C4Col(){
	num_discs = 0;
	max_discs = 6;
	//fill the array with 0s
	for (size_t i = 0; i < sizeof(disc_array) / sizeof(char); i++){
		disc_array[i] = ' ';
	}
}

//returns fullness of the array
int C4Col::isFull(){
	int fullness = 0; //Number showing how full the array is
	//Increases the fullness value until there is a '0' detected
	for (size_t i = 0; i < sizeof(disc_array) / sizeof(char); i++){
		if (disc_array[i] != ' '){
			fullness++;
		}else{
			break;
		}
	}
	return fullness;
}

//gets the disc in an index
char C4Col::getDisc(int a){
	return disc_array[a];
}

//gets the array size
int C4Col::getMaxDiscs(){
	return max_discs;
}

//adds a disc to the array
void C4Col::addDisc(char a){
	disc_array[num_discs] = a;
	num_discs++;
}
