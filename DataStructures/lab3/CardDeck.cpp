//Name: Liam Loeffel
//Description: This is the code for implementing the functions in the header file.

#include "CardDeck.h"

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;



//CITATION: Made using the notes on https://web.eecs.utk.edu/~semrich/cs202-24/notes/5/array.cpp
//default constructor
CardDeck::CardDeck( int arraySize )  {
	top = 0;
	size = ( arraySize > 0 ? arraySize : 10 ); // validate arraySize

	ptr = new int[ size ]; // create space for pointer-based array

	for ( int i = 0; i < size; i++ )
	ptr[ i ] = i; // set pointer-based array element to zero

} // end Array default constructor

//CITATION: Made using the notes on https://web.eecs.utk.edu/~semrich/cs202-24/notes/5/array.cpp
//copy constructor
CardDeck::CardDeck( const CardDeck &arrayToCopy )  : size( arrayToCopy.size )  {

	ptr = new int[ size ]; // create space for pointer-based array

	for ( int i = 0; i < size; i++ )
		ptr[ i ] = arrayToCopy.ptr[ i ]; // copy into object

}  // end of copy constructor

//CITATION: Made using the notes on https://web.eecs.utk.edu/~semrich/cs202-24/notes/5/array.cpp
//destructor
CardDeck::~CardDeck() {

	delete [] ptr; // release pointer-based array space

} // end destructor

//CITATION: Made using the notes on https://web.eecs.utk.edu/~semrich/cs202-24/notes/5/array.cpp
//get size
int CardDeck::getSize() const  {

	return (size); // number of elements in Array

} // end function getSize

//CITATION: Made using the notes on https://web.eecs.utk.edu/~semrich/cs202-24/notes/5/array.cpp
//assignment operator
const CardDeck &CardDeck::operator=( const CardDeck &right ) {

	if ( &right != this ) { // avoid self-assignment

		if ( size != right.size ) {

			delete [] ptr; // release space
			size = right.size; // resize this object
			ptr = new int[ size ]; // create space for array copy

		} // end inner if

		for ( int i = 0; i < size; i++ )	
		ptr[ i ] = right.ptr[ i ]; // copy array into object

	} 

	return (*this); // enables x = y = z, for example

} // end function operator=

//shuffles the deck
void CardDeck::shuffle(){
	top = 0; //reset top card
	vector <int> deck(ptr,ptr+size); //make a copy vector
	random_shuffle(deck.begin(),deck.end()); //shuffle
	for(int i = 0; i < size; i++){ //copy the vector into the dynamically stored array
		ptr[i] = deck[i];
	}
	return;
}

//deals a card from the top
int CardDeck::deal(){
	int card = ptr[top]; //stores the card on the top
	top++; //increments the top val
	return card; //returns the stored card val
}

//prints the card deck for debugging
void CardDeck::print(){
	for(int i = 0; i < size; i++){
		cout << ptr[i] << ", ";
	}
	cout << endl;
	return;
}

//returns the top var
int CardDeck::getTop(){
	return top;
}
