// Lab 7:  N-queens using backtracking 
// Name: Liam Loeffel
// Program-Name: Nqueens with constraints!
// Description: This program will find every orientation that a queen from chess can be oriented in so it does not conflict with the
// maximum number of queens on the board. The program will take in a command line argument which specifies the board size for an nxn
// board. This program also implements constraints which makes it so that the code does not have to check a board that we already know
// is invalid.

#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

//keeps a global count of the amount of boards that are considered
int boardCount = 0;

//print function
void print(const vector<int> &board){
  for (size_t i = 0; i < board.size(); i++) {
            cout << board[i];
            if (i != board.size() - 1) {
                cout << ", ";
            }
        }
        cout << endl;
}

//checks conflicts
bool isValid(vector<int> board, int col) {
    for (int i = 0; i < col; i++)
        //checks if there are conflicts horizontally and diagonally in the previous columns
        //The diagonal uses the method described in https://web.eecs.utk.edu/~semrich/cs202-24/labs/7/
        if (board[i] == board[col] || abs(board[i] - board[col]) == abs(i - col)) {return false;}
    return true;
}

void nqueens(vector<int> &board, int col, int size) {
    if (col == size) { //if we are at the end of the board, then print
        print(board);
        return;
    }
    for (int i = 0; i < size; i++) { //goes thru each possible position for i
        board[col] = i;
        if (isValid(board, col)) {  //is it valid?
            boardCount++;
            nqueens(board, col + 1, size);  //if so, then move on
        }
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
    cerr << "Total number of boards checked: " << boardCount << endl;
    return 0;
}
