// Name: Liam Loeffel (utk id: lloeffel)
// Lab 1:  Tic-tac-toe solver
// Description: This is a program for the express purpose of the TAs or GTAs to have an easier time grading the toe.cpp program. The toe.cpp program describes the program's purpose in further detail.
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int diagonalWinCheck(vector<vector<char>> array){
	const int size = array.size();	     // stores the size of the given vector
	int whoWon = 0;                  // this value will either be 0, 1, or 2 by the end (0 = no diagonal win) (1 = X diagonal win) (2 = O diagonal win)

	//"backslash win" check "\"	
	if (array[0][0] == 'X'){         // is the top left corner an X?
		for (size_t i = 1; i < size; i++){
			whoWon = 1;
			if (!(array[i][i] == 'X')){ // is the value in the diagonal not an X?
				whoWon = 0;
				break;
			}
		}
	}else if(array[0][0] == 'O'){      // is the top left corner an O?
		for (size_t i = 1; i < size; i++){
			whoWon = 2;
			if (!(array[i][i] == 'O')){ // is the value in the diagonal not an O?
				whoWon = 0;
				break;
			}
		}

	}

	//checks to see if someone won
	if (whoWon != 0) return whoWon;

	//"forwardslash win" check "/"
	if (array[0][size - 1] == 'X'){         // is the top right corner an X?
		for (size_t i = 1; i < size; i++){
			whoWon = 1;
			if (!(array[i][size-1-i] == 'X')){ //is the value in the diagonal not an X?
				whoWon = 0;
				break;
			}
		}
	}else if(array[0][size - 1] == 'O'){      // is the top right corner an O?
		for (size_t i = 1; i < size; i++){
			whoWon = 2;
			if (!(array[i][size-1-i] == 'O')){  // is the value in the diagonal not an O?
				whoWon = 0;
				break;
			}
		}

	}
	return whoWon;
}


int verticalWinCheck(vector<vector<char>> a){
	const int size = a.size(); //stores the size of the given vector
	int whoWon = 0;          //this value will either be 0, 1, or 2 (0 = no vertical win) (1 = X vertical win) (2 = X vetical win)
	//loops thru each column
	for (size_t i = 0; i < size; i++){
		if (a[0][i] == 'X'){                              //is the first value in the column X?
			for (size_t j = 1; j < size; j++){            // does the whole column match?
				whoWon = 1;
				if (a[j][i] != 'X'){                      // does it not match?
					whoWon = 0;
					break;
				}
			}
		}else if(a[0][i] == 'O'){                         //is the first value in the column O?
			for (size_t j = 1; j < size; j++){            //does the whole column match?
				whoWon = 2;
				if (a[j][i] != 'O'){                      //does it not match?
					whoWon = 0;
					break;
				}
			}
		}
		if (whoWon != 0){                                 //has someone won yet?
			return whoWon;
		}
	}
	return whoWon;
}

int horizontalWinCheck(vector<vector<char>> a){
	const int size = a.size(); //stores the size of the given vector
	int whoWon = 0;              //this value will either be 0, 1, or 2 (0 = no horizontal win) (1 = X horizontal win) (2 = O horizontal win)
	//loops thru each column
	for (size_t i = 0; i < size; i++){
		if (a[i][0] == 'X'){                              //is the first value in the row X?
			for (size_t j = 1; j < size; j++){            //does the whole row match?
				whoWon = 1;
				if (a[i][j] != 'X'){                      //does it not match?
					whoWon = 0;
					break;
				}
			}
		}else if(a[i][0] == 'O'){                         //is the first value in the row O?
			for (size_t j = 1; j < size; j++){            //does the whole row match?
				whoWon = 2;
				if (a[i][j] != 'O'){                      //does it not match?
					whoWon = 0;
					break;
				}
			}
		}
		if (whoWon != 0){                                 //has someone won yet?
			return whoWon;
		}
	}
	return whoWon;
}
int main(int argc, char *argv[]){
	int N; //board size
	cin >> N;
	vector<vector<char>> board(N,vector<char>(N)); //vector with the board
	char boardInput; //input variable for cin

	//puts the file input into the vector
	for (size_t i = 0; i < board.size(); i++){
		for (size_t j = 0; j < board[i].size(); j++){
			cin >> boardInput;
			if (boardInput == 'X' || boardInput == 'O'){
				board[i][j] = boardInput;
			}
		}
	}
	
	//Checks for a win and exits main when there is one:
	//Since there can be multiple wins on the board my algorithm messes up 
	//so I came up with this mess to deal with it without having to change my algorithm.
	if (horizontalWinCheck(board) != 0){
		if (horizontalWinCheck(board) == 1){
			cout << "X wins" << endl;
			return 0;
		}else {
			cout << "O wins" << endl;
			return 0;
		}
	}
	if (verticalWinCheck(board) != 0){
		if (verticalWinCheck(board) == 1){
			cout << "X wins" << endl;
			return 0;
		}else {
			cout << "O wins" << endl;
			return 0;
		}
	}
	if (diagonalWinCheck(board) != 0){
		if (diagonalWinCheck(board) == 1){
			cout << "X wins" << endl;
			return 0;
		}else {
			cout << "O wins" << endl;
			return 0;
		}
	}
	if ((diagonalWinCheck(board) + horizontalWinCheck(board) + verticalWinCheck(board)) == 0){
		cout << "Tie" << endl;
	}
	
	return 0;
}
