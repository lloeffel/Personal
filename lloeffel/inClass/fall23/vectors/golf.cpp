#include <iostream>
#include <iomanip>
#include <limits>
#include <vector>

using namespace std;

int main(){
	string player1name;
	int score, strokes, holeNum;
	holeNum = 0;

	vector <int> player1holes;
	const int SHORT_GAME = 2;
	
	cout << "Welcome to Mini Golf Scoring!" << endl;
	cout << "What is your name? ";
	cin >> player1name;
	/*collecting date for each hole */
	for (int i =0; i <SHORT_GAME; i++){
		cout << "What was " << player1name << "'s score for hole ";
		cout << holeNum << "?" << endl;
		cin >> strokes;
		player1holes.push_back(strokes);
		holeNum++;
	}
	
	/* print vector to make sure its saving */
	holeNum = 0;
	for (int i=0; i < player1holes.size(); i++){
		cout << player1name << "'s Game: " << endl;
		cout << " Hole" << holeNum << ": ";
		cout << player1holes[i] << endl; //or player1holes.at(i)
		holeNum++;
	}

}
