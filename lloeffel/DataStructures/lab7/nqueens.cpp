// Lab 7:  N-queens using backtracking 
// Name: Liam Loeffel
// Program-Name: Nqueens problem
// Description: This program will find every orientation that a queen from chess can be oriented in so it does not conflict with the
// maximum number of queens on the board. The program will take in a command line argument which specifies the board size for an nxn
// board.

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

//this checks if the whole board is valid
bool isValid(vector<int> &board) {
    int size = board.size();
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (board[i] == board[j] || abs(board[i] - board[j]) == abs(i - j)) {
                return false;
            }
        }
    }
    return true;
}

//print function
void printVals(const vector<int> &board){
  for (size_t i = 0; i < board.size(); i++) {
            cout << board[i];
            if (i != board.size() - 1) {
                cout << ", ";
            }
        }
        cout << endl;
}

//
void nqueens(vector<int> &board, int col, int size) {
    if (col == size) { //if we are at the end of the board, then print
        if(isValid(board)){
          printVals(board);
        }
        return;
    }
    for (int i = 0; i < size; i++) { //goes thru each possible position for i
        board[col] = i;
        nqueens(board, col + 1, size);
    }
}



int main(int argc, char *argv[]) {
    //error checking
    
    if (argc != 2){ //usage check
      cerr << "Error: usage" << endl;
      return 1;
    }
    if (stoi(argv[1]) < 4){ //input number range
      cerr << "Error: input a number greater than 3" << endl;
      return 1;
    }
    int boardSize = stoi(argv[1]);
    vector<int> board(boardSize);
    nqueens(board, 0, boardSize);
    return 0;
}