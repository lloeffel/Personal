//Name: Liam Loeffel
//Description: This code implements the card game blackjack. It is only single player and the user can only either Hit or Stand.


#include "CardDeck.h"   // class definition for CardDeck used below
#include <iostream>
#include <string>
#include <vector>

using namespace std;


//helper function to get the card type or face
int getCardIndex(int n){
  int index = n%13;
  return index;
}

//helper function to print the score
void printScore(int p, int d){
  cout << "Game count: Dealer - " << d << ", Player - " << p << endl;
}

//checks if either the player or the dealer bust
bool bustStatus(int playerScore, int dealerScore, int &playerWins, int &dealerWins){
  if(playerScore > 21){
    dealerWins++;
    cout << "Player Bust! You Lost :(" << endl;
    return true;
  }else if(dealerScore > 21){
    playerWins++;
    cout << "Dealer Bust! You Won :)" << endl;
    return true;
  }
  return false;
}


int main() {
  //new deck
  CardDeck * test;
  test = new CardDeck;

  //Testing the shuffle code
  srand(0);
  cout << "Testing shuffle..." << endl;
  test->print();
  test->shuffle();
  test->print();
  test->~CardDeck();

  CardDeck * deck;
  deck = new CardDeck(52);

  //value access arrays
  const int cardVals[] = {2,3,4,5,6,7,8,9,10,11,10,10,10};
  const string faceVals[] = {"2","3","4","5","6","7","8","9","10","Ace","Jack","Queen","King"};

  //game vars
  int dealerScore, playerScore, tempDealerCard, tempPlayerCard;
  int playerWins = 0;
  int dealerWins = 0;
  char input; //stores the cin input
  vector<string> dealerHand; //stores the dealer's hand
  vector<string> playerHand; //stores the player's hand
  while(1){ //main game loop
    deck->shuffle(); //initial shuffle
    //reset used vars
    dealerScore = 0;
    playerScore = 0;
    dealerHand.clear();
    playerHand.clear();
    cout << endl;
    cout << "--BlackJack--" << endl << endl;
    //first round of dealing
    tempDealerCard = getCardIndex(deck->deal());
    tempPlayerCard = getCardIndex(deck->deal());
    dealerHand.push_back(faceVals[tempDealerCard]);
    playerHand.push_back(faceVals[tempPlayerCard]);
    dealerScore = cardVals[tempDealerCard];
    playerScore = cardVals[tempPlayerCard];
    //second round of dealing
    tempDealerCard = getCardIndex(deck->deal());
    tempPlayerCard = getCardIndex(deck->deal());
    dealerHand.push_back(faceVals[tempDealerCard]);
    playerHand.push_back(faceVals[tempPlayerCard]);
    dealerScore += cardVals[tempDealerCard];
    playerScore += cardVals[tempPlayerCard];
    cout << "Dealer's hand: ? (face down), " << dealerHand[1] << " (face up)" << endl;
    cout << "Your hand: " << playerHand[0] << " (face down), " << playerHand[1] << " (face up)"<< endl << endl;
    //bust check
    if(bustStatus(playerScore,dealerScore,playerWins,dealerWins)){
      printScore(playerWins,dealerWins);
      cout << "Play Again? (Y/N)" << endl;
      while(1){ //looping for valid inputs
        cout << "> ";
        cin >> input;
        if (input == 'Y' || input == 'N'){break;}
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "invalid input: try inputting Y or N" << endl;
      }
      if(input == 'N'){return 0;}
      break;
    }
    //checking for blackjack
    if(playerScore == 21){
      playerWins++;
      cout << "Player Wins! BlackJack!" << endl;
      printScore(playerWins,dealerWins);
      cout << "Play Again? (Y/N)" << endl;
      while(1){ //looping for valid inputs
        cout << "> ";
        cin >> input;
        if (input == 'Y' || input == 'N'){break;}
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "invalid input: try inputting Y or N" << endl;
      }
      if(input == 'N'){return 0;}
      continue;
    }
    //Player Hit/Stand loop
    while(1){
      cout << "Hit or Stand? (H/S)" << endl;
      while(1){ //looping for valid inputs
        cout << "> ";
        cin >> input;
        if (input == 'H' || input == 'S'){break;}
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "invalid input: try inputting H or S" << endl;
      }
      if (input == 'H'){ //if user Hits
        tempPlayerCard = getCardIndex(deck->deal());
        playerHand.push_back(faceVals[tempPlayerCard]);
        playerScore += cardVals[tempPlayerCard];
      }else{ //if user stands
        break;
      }
      //print out the hand after every hit
      cout << endl <<"Your hand is: " << playerHand[0] << " (face down), ";
      for(size_t i = 1; i < playerHand.size()-1; i++){
        cout << playerHand[i] << " (face up), ";
      }
      cout << playerHand[playerHand.size()-1] << " (face up)" << endl;
      cout << endl;
      //check for bust
      if(bustStatus(playerScore,dealerScore,playerWins,dealerWins)){
        printScore(playerWins,dealerWins);
        cout << "Play Again? (Y/N)" << endl;
        while(1){ //looping for valid inputs
          cout << "> ";
          cin >> input;
          if (input == 'Y' || input == 'N'){break;}
          cin.clear();
          cin.ignore(10000, '\n');
          cout << "invalid input: try inputting Y or N" << endl;
        }
        if(input == 'N'){return 0;}
        break;

      }
      //checking for blackjack
      if(playerScore == 21){
        playerWins++;
        cout << "Player Wins! BlackJack!" << endl;
        printScore(playerWins,dealerWins);
        cout << "Play Again? (Y/N)" << endl;
        while(1){ //looping for valid inputs
          cout << "> ";
          cin >> input;
          if (input == 'Y' || input == 'N'){break;}
          cin.clear();
          cin.ignore(10000, '\n');
          cout << "invalid input: try inputting Y or N" << endl;
        }
        if(input == 'N'){return 0;}
        break;
      }
    }
    //skip dealer deals if player bust
    if(input == 'Y'){continue;}

    //Dealer Hit/Stand loop
    while(dealerScore < 17){
      //draw card
      tempDealerCard = getCardIndex(deck->deal());
      dealerHand.push_back(faceVals[tempDealerCard]);
      dealerScore += cardVals[tempDealerCard];
      //check for bust
      if(bustStatus(playerScore,dealerScore,playerWins,dealerWins)){
        printScore(playerWins,dealerWins);
        cout << endl << "Play Again? (Y/N)" << endl;
        while(1){ //looping for valid inputs
          cout << "> ";
          cin >> input;
          if (input == 'Y' || input == 'N'){break;}
          cin.clear();
          cin.ignore(10000, '\n');
          cout << "invalid input: try inputting Y or N" << endl;
        }
        if(input == 'N'){return 0;}
        break;
      }
    }
    //skip score comparison if the dealer already bust
    if(input == 'Y'){continue;}

    //compare only if the player and dealer didnt bust
    if(playerScore>=dealerScore){ //if the player won
      cout << "Player won by score" << endl;
      playerWins++;
      printScore(playerWins,dealerWins);
      cout << "Play Again? (Y/N)" << endl;
      while(1){ //looping for valid inputs
        cout << "> ";
        cin >> input;
        if (input == 'Y' || input == 'N'){break;}
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "invalid input: try inputting Y or N" << endl;
      }
      if(input == 'N'){return 0;}
      break;
    }else{
      cout << "Dealer won by score" << endl;
      cout << endl <<"Dealer's hand is: " << dealerHand[0] << " (face down), ";
      //shows the dealer's hand
      for(size_t i = 1; i < dealerHand.size()-1; i++){
        cout << dealerHand[i] << " (face up), ";
      }
      cout << dealerHand[dealerHand.size()-1] << " (face up)" << endl;
      cout << endl;
      printScore(playerWins,dealerWins);
      cout << "Play Again? (Y/N)" << endl;
      while(1){ //looping for valid inputs
        cout << "> ";
        cin >> input;
        if (input == 'Y' || input == 'N'){break;}
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "invalid input: try inputting Y or N" << endl;
      }
      if(input == 'N'){return 0;}
      break;
      dealerWins++;
    }
  }
  return 0;
}
