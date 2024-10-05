#include "Player.h"
#include <vector>

using namespace std;
//Player constructor taking in a string
Player::Player(string s) {
    lives = 3;
    string name = s; // set the name to the string passed
    vector<string> lore;
}

void Player::takeDamage(){
    lives--;
}

void Player::addLore(string s){
    lore.push_back(s);
}

//Lives accessor
int Player::getLives(){
    return lives;
}

//Lore accessor
vector<string> Player::getLore(){
    return lore;
}

//Name accessor
string Player::getName(){
    return name;
}