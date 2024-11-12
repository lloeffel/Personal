// Name: Liam Loeffel
// Program: Connect 4 Board C++ file

#include <iostream>
#include "C4Board.h"

//constructor
C4Board::C4Board(){
	num_cols = 7;
}

//checks for a winner
bool C4Board::check_winner(){
	bool winState = false; //stores whether the player has won or not
	for (int i = board[0].getMaxDiscs()-1; i >= 0; i--){
		for (int j = 0; j < num_cols; j++){
			if (board[j].getDisc(i) == 'X'){ //is the index an X
				if (winState == true){ //is the game over
					break;
				}
				//check horizontal
				if (j <= 3){ //limits the solver to avoid out of bound errors
					for(int k = j; k < j+4; k++){
						winState = true;
						if (!(board[k].getDisc(i) == 'X')){ //is there a break
							winState = false;
							break;
						}
					}
				}
				if (winState == true){ //is the game over
					break;
				}
				//check vertical
				if (i <= 2){ //limiter to avoid out of bound errors
					for (int k = i; k < i+4; k++){
						winState = true;
						if (!(board[j].getDisc(k) == 'X')){ //is there a break
							winState = false;
							break;
						}
					}
				}
				if (winState == true){ //is the game over
					break;
				}
				//check diagonal1
				if ((j <= 3) && (i <= 2)){ //limiter to avoid out of bound errors
					for (int k = j; k < j+4; k++){
						winState = true;
						if (!(board[k].getDisc(k) == 'X')){ //is there a break
							winState = false;
							break;
						}
					}
				}
				if (winState == true){ //is the game over
					break;
				}
				//check diagonal2
				if ((j > 3) && (!(i > 2))){ //limiter to avoid out of bound errors
					for (int k = 0; k < 4; k++){
						winState = true;
						if (!(board[j-k].getDisc(i+k) == 'X')){ //is there a break
							winState = false;
							break;
						}
					}
				}
				if (winState == true){ //is the game over
					break;
				}
			}else if (board[j].getDisc(i) == 'O'){ //THIS IS THE EXACT SAME CODE AS THE X CHECKER SO ALL COMMENTS ON
							       //THE PREVIOUS ALGORITHM APPLY
				if (winState == true){
					break;
				}
				if (j <= 3){
					for(int k = j; k < j+4; k++){
						winState = true;
						if (!(board[k].getDisc(i) == 'O')){
							winState = false;
							break;
						}
					}
				}
				if (winState == true){
					break;
				}
				//check vertical
				if (i <= 2){
					for (int k = i; k < i+4; k++){
						winState = true;
						if (!(board[j].getDisc(k) == 'O')){
							winState = false;
							break;
						}
					}
				}
				if (winState == true){
					break;
				}
				//check diagonal1
				if ((j <= 3) && (i <= 2)){
					for (int k = j; k < j+4; k++){
						winState = true;
						if (!(board[k].getDisc(k) == 'O')){
							winState = false;
							break;
						}
					}
				}
				if (winState == true){
					break;
				}
				//check diagonal2
				if ((j > 3) && (!(i > 2))){
					for (int k = 0; k < 4; k++){
						winState = true;
						if (!(board[j-k].getDisc(i+k) == 'O')){
							winState = false;
							break;
						}
					}
				}
				if (winState == true){
					break;
				}

			}
			
		}
		if (winState == true){ //is the game over
			break;
		}
	}
	return winState;
}

//prints the board
void C4Board::display(){
	//printing the headers
	int counter = 0; 
	std::cout << "| ";
	for (int i = 0; i < 7; i++){
		counter++;
		std::cout << counter << " | ";
	}
	//printing the array
	std::cout << std::endl;
	for (int i = board[0].getMaxDiscs() - 1; i >= 0; i--){
		std::cout << "| ";
		for (size_t j = 0; j < num_cols; j++){
			std::cout << board[j].getDisc(i) << " | ";
		}
		std::cout << std::endl;
	}
}

//actual play of the game
void C4Board::play() {
	std::cout << "Enter the column number you would like to put the disc into [1-7]:" << std::endl;
	int turnCounter = 1; //stores the count of the turn
	int columnInput = 0; //stores the user input
	int tempVal;         //stores the previous turn number
	while(!check_winner()){
		tempVal = turnCounter; //sets temporary number
		display();
		if(turnCounter%2 == 0){ //is it O's move
			std::cout << "Player O move!" << std::endl;
			while(turnCounter == tempVal){ //has the turn finished?
	  			std::cout << "> ";
				std::cin >> columnInput;
				if (board[columnInput-1].isFull() != 6){ //adds the input unless the column is full
					board[columnInput-1].addDisc('O');
					turnCounter++;
				}else{
					std::cout << "invalid input!" << std::endl;
					std::cin.clear();
					std::cin.ignore(10000, '\n');
				}
			}
			if (check_winner()){
				std::cout << "O Wins!" << std::endl;
				break;
			}
		}else{
			std::cout << "Player X move!" << std::endl;
			while(turnCounter == tempVal){ //has the turn finished?
				std::cout << "> ";
				std::cin >> columnInput;
				if (board[columnInput-1].isFull() != 6){ //adds the input unless the column is full
					board[columnInput-1].addDisc('X');
					turnCounter++;
				}else{
					std::cout << "invalid input!" << std::endl;
					std::cin.clear();
					std::cin.ignore(10000, '\n');
				}
			}
			if (check_winner()){
				std::cout << "X Wins!" << std::endl;
				break;
			}
				
		}
		if (turnCounter == 42){ //is it a tie?
			std::cout << "Tie..." << std::endl;
		}

	}

}
