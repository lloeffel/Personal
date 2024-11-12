/* Program Name: bowling score calculator
 * Student Name: Liam Loeffel
 * Net ID: lloeffel
 * Student ID: 000-664-706
 * Program Description: The user inputs a player name and number of pins knocked down with each roll, then they are prompted to wither say done or input another player's information. When the user is done, the players and their final scores are outputted, and the winner and last place players are decided. */

// NOTE:
// `size_t` is an unsigned integer type that is guaranteed to be large
// and is used for representing sizes and indexes
//
// vector `.size()` returns a `size_t` integer value
// compiler warnings happen if you try to compare integer types that do not
// match e.g. `int` and `size_t`

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//! Remember: non-const globals are a penalty
//    "non-const globals" aka variables defined outside of a function e.g. main
//    without the const keyword are a penalty on your grade
const int NUMBER_OF_FRAMES = 10;
const int ROLLS_PER_FRAME = 2;
const int TOTAL_ROLLS = NUMBER_OF_FRAMES * 2 + 1; // 21
const int NUMBER_OF_PINS = 10;

void printGameSummary(const vector<string> &playerNames, const vector<int> &playerScores) {

	// This line prevents the program from seg faulting if no players were entered
	if (playerNames.size() == 0) {
		cout << "No players were entered." << endl;
		return;
	}
	cout << endl;
	string worstPlayerName = playerNames[0];
	int worstPlayerScore = playerScores[0];

	string bestPlayerName = playerNames[0];
	int bestPlayerScore = playerScores[0];

	//outputting the first player and score
	cout << playerNames[0] << " scored " << playerScores[0] << "." << endl;
	//finding the winner and the last place players and printing all players and scores
	for (size_t i = 1; i < playerNames.size(); ++i) {
		//finding best score and player
		if (playerScores[i] > bestPlayerScore){
			bestPlayerScore = playerScores[i];
			bestPlayerName = playerNames[i];
		}
		//finding best score and player
		if (playerScores[i] < worstPlayerScore){
			worstPlayerScore = playerScores[i];
			worstPlayerName = playerNames[i];
		}
		cout << playerNames[i] << " scored " << playerScores[i] << "." << endl;
	}

	//printing best and worst scores with their players
	cout << worstPlayerName << " did the worst by scoring " << worstPlayerScore << "." << endl;
	cout << bestPlayerName << " won the game by scoring " << bestPlayerScore << "." << endl;
}

int main() {
	vector<string> playerNames;
	vector<int> playerScores;
	vector<int> roundStates; //stores the state of a round (0 = normal, 1 = spare, 2 = strike)
	vector<int> roundScores; //stores the score added by each round

	//filling the roundStates and roundScores arrays with values to be changed later
	for(int i = 0; i <10; i++){
		roundStates.push_back(0);
		roundScores.push_back(0);
	}
	int input1; //stores the value of the pins knocked down in roll 1
	int input2; //stores the value of the pins knocked down in roll 2
	int input3; //stores the value of the pins knocked down in roll 3
	while (true) {
		string inputString;
		//collecting info on the player name
		cout << "Enter player's name (done for no more players): ";
		cin >> inputString;

		//if the user is done inputting players
		if(inputString == "done"){
			break;
		}
		//add player to the player vector
		playerNames.push_back(inputString);
		//Asks the user to input the score of each roll, and calculates the scores of each frame/round
		for (int i = 0; i < NUMBER_OF_FRAMES; i++){
			//resetting the input variables as a redundancy
			input1 = 0;
			input2 = 0;
			input3 = 0;
			//collecting info on the first roll
			cout << "Enter score for frame " << i+1 << ", roll 1: ";
			cin >> input1;
			//for frames 2-9
			if ((i != 0) && (i != 9)){
				if(roundStates[i-1] == 1){//if the previous frame was a spare
					roundScores[i-1] = input1 + 10;
				}else if(roundStates[i-1] == 2){//if the previous frame was a strike
					if (i > 1){//making sure there have been more than 2 frames played
						if (roundStates[i-2] == 2){//if the frame two rounds ago was a strike
							roundScores[i-2] = 20 + input1;
						}
					}
				}
				if(input1 == 10){//if the frame is a strike
					roundStates[i] = 2;
				}else{//if the frame is not a strike
					//collecting info on the second roll
					cout << "Enter score for frame " << i+1 << ", roll 2: ";
					cin >> input2;
					//if the round before was a strike
					if(roundStates[i-1] == 2){
						roundScores[i-1] = 10 + input1 + input2;
					}
					if((input2 + input1) == 10){//if the round was a spare
						roundStates[i] = 1;
					}else{//if the round was neither a spare or strike
						roundStates[i] = 0;
						roundScores[i] = input1 + input2;
					}
				}
			}else if(i == 0){//runs only on the first frame
				//if the frame is a strike
				if(input1 == 10){
					roundStates[i] = 2;
				}else{//if the frame is not a strike
					//Collecting the info on roll 2
					cout << "Enter score for frame " << i+1 << ", roll 2: ";
					cin >> input2;
					//if the frame is a spare
					if((input2 + input1) == 10){
						roundStates[i] = 1;
					}else{//if the frame is neither a strike or spare
						roundStates[i] = 0;
						roundScores[i] = input1 + input2;
					}
				}
			}else{//runs only in the last frame
				//if the last two rounds are strikes
				if((roundStates[i-2] == 2) && (roundStates[i-1] == 2)){
					roundScores[i-2] = input1 + 20;
				}else if(roundStates[i-1] == 1){ //if the last round was a spare
					roundScores[i-1] = input1 + 10;
				}
				//Collecting the value of the second roll
				cout << "Enter score for frame " << i+1 << ", roll 2: ";
				cin >> input2;

				//if the last round was a strike
				if(roundStates[i-1] == 2){
					roundScores[i-1] = 10 + input1 + input2;
				}
				//Evaluating if the third roll should be played
				if ((input1 + input2) >= 10){
					cout << "Enter score for frame " << i+1 << ", roll 3: ";
					cin >> input3;
				}
				//final Calculation
				roundScores[i] = input1 + input2 + input3;
			}
		}

		//value will be used to sum the roundScores
		int finalScore = roundScores[0];

		//summing all the roundScores
		for(size_t i = 1; i < roundScores.size(); i++){
			finalScore = finalScore + roundScores[i];
		}

		//adding the summation to the playerScores vector
		playerScores.push_back(finalScore);

		// Prevents infinite loop if cin is in a bad state
		if (!cin) {
			throw runtime_error("Invalid input");
		}
	}

	//printing the final results
	printGameSummary(playerNames, playerScores);

	return 0;
}
