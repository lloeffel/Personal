// Name: Liam Loeffel
// Program: Card Deck Header File
// Description: this is the header file for the card deck class 

#ifndef CARDDECK_H
#define CARDDECK_H

#include <iostream>


//CITATION: Using the notes posted on canvas:
class CardDeck {

	public:
		CardDeck( int = 10 ); // default constructor  
		CardDeck( const CardDeck & ); // copy constructor
		~CardDeck(); // destructor                    
		int getSize() const; // return size
		const CardDeck &operator=( const CardDeck & ); // assignment operator
		bool operator==( const CardDeck & ) const; // equality operator   
		void shuffle(); //shuffles the cards in the deck
		int deal(); //increments the top variable and returns the card that was previously on top  
		void print();
		int getTop();

	private:
		int size; // pointer-based array size
		int *ptr; // pointer to first element of pointer-based array
		int top; //stores the index of the card on top of the deck
};

#endif

