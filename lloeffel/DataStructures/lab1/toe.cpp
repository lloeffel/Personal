// Name: Liam Loeffel (utk id: lloeffel)
// Lab 1:  Tic-tac-toe solver
// Description: The Game is Tic-Tac-Toe. The user is prompted to input a board size, and then the user is prompted to input a number corressponding with the cell in the board. The program will end when either the board is full, or either X or O wins.
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void updateBoardDisplay(vector<vector<char>> a){
	for (size_t i = 0; i < a.size(); i++){
		for (size_t j = 0; j < a[i].size(); j++){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}


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


int main(int argc, char *argv[]) {
	
	int N;                                             // board size
	cout << "input a board size greater than 2: " << endl << "> ";
	cin >> N;

	vector<vector<char>> board(N,vector<char>(N,'-')); // board variable
	
	updateBoardDisplay(board);

	int winState = 0;
	int turnNumber = 0;
	int userInput = 0;
	char playerSign = 'X';
	cout << "input the number that corresponds to the cell the player desires to put an 'X' or 'O': " << endl << "> ";
	while (winState == 0){
		//exit case
		if (winState > 0) break;

		//updates the turns so the computer knows whose turn it is
		turnNumber++;
		if (turnNumber%2 == 1){
			playerSign = 'X';
		}else{
			playerSign = 'O';
		}
		//is the board full?
		if (turnNumber > (N*N)){
			break;
		}


		//takes in a number 1 to N^2 to find what space to put the respective 'X' or 'O' in
		while(cin >> userInput){
			if (userInput > (N*N) || userInput < 1){                    // is the userInput in the scope of the board?
				cout << "invalid input" << endl;
				cin.clear();
				cin.ignore(10000, '\n');
			}

			if (userInput%N == 0){                                      // is the userInput is at the end of a row?
				if(board[(userInput/N)-1][N-1] == '-'){                 // is the cell empty?   						
					board[(userInput/N)-1][N-1] = playerSign;
					break;
				}else{
					cout << "invalid input"  << endl;
					cin.clear();
					cin.ignore(10000, '\n');
				}
			}else{
				if(board[userInput/N][(userInput%N)-1] == '-'){          // is the cell empty?
					board[userInput/N][(userInput%N)-1] = playerSign;
					break;
				}else{
					cout << "invalid input" << endl;
					cin.clear();
					cin.ignore(10000, '\n');
				}
			}
		}
		updateBoardDisplay(board);
		cout << "> ";
		//updates the winState
		winState = diagonalWinCheck(board) + horizontalWinCheck(board) + verticalWinCheck(board);
	}
	if (winState == 0){
		cout << "tie" << endl;
	}else if (winState == 1){
		cout << "X wins" << endl;
	}else {
		cout << "O wins" << endl;
	}
	return 0;
		
}

