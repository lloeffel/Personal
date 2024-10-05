#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <string>
using namespace std;

class Player {
	public:
	    Player(string);
        int getLives();     //retuns the lives left that the player has
        vector<string> getLore();      //returns all the lore the player has collected
        string getName();
        void addLore(string);
        void takeDamage();
	private:
		int lives;
        string name;        //name of the player
        vector<string> lore;//lore the player has collected
};
#endif
