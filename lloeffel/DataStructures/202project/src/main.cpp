#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include "../include/Player.h"
#include "../include/Level.h"

//used ChatGPT on the lore to get some more verbose text


using namespace std;

const int numRooms = 7;
const vector<string> desc = {"the first","To the north, the forest gradually yields to a soft, inviting glow. Light filters through the dense canopy, casting a gentle radiance upon the path ahead. The air carries whispers of peace and tranquility, promising a serene respite amidst nature's embrace. A hidden oasis beckons, its allure tempting you with the possibility of solace and reflection.","Glancing towards the north, the forest seems to close in, its shadows deepening and branches intertwining with an air of mystery. Amidst the gloom, an ancient structure emerges, its silhouette shrouded in intrigue. Vines snake their way around weathered stone, hinting at secrets waiting to be unveiled. Yet, an adventurous spirit stirs within, drawn by the promise of discovery and the potential for untold treasures hidden within its walls.","To the left, the forest seems to burst with vibrant colors and harmonious melodies, inviting you to journey further into its depths. Sunlight dances through the trees, casting a warm glow upon the path, while friendly forest creatures offer guidance along the way. The air is filled with promise, hinting at the wonders awaiting discovery amidst the verdant expanse.","To the right, the allure of the clearing fades into a foreboding silence, a stark contrast to the serenity of the pond. Shadows lurk among the trees, and a chill runs down your spine as you venture deeper into the gloom. Thorny underbrush and tangled roots obstruct the path, a daunting obstacle in your way. Despite the warning signs, a sense of curiosity compels you forward, drawn by the enigmatic allure of the unknown.", "As you stand before the ancient structure, two paths beckon, each cloaked in mystery and possibility. Through the left door, darkness envelopes a narrow hallway, the air thick with dust and echoes of whispers. The path ahead is shrouded in uncertainty, yet a flicker of curiosity ignites within, driving you deeper into the unknown depths of the structure's secrets.", "To the right, a sense of trepidation lingers as you peer into the darkness beyond the second door. Shadows dance amidst crumbling stone, hinting at the secrets veiled within the labyrinthine corridors. Though uncertainty looms, an adventurous spirit stirs within, urging you to venture forth into the depths of the structure, where untold mysteries await discovery."};

//prints rooms for debug
void printDebug(Level *level) {
    cout << "... printing level information ..." << endl;

    cout << "Overview: \n" << level->getOverview() << endl;

    vector<Room> temp = level->getRooms();

    cout << "\nRoom Desciptions: " << endl;
    for(size_t i = 0; i < temp.size(); i++) {
        cout << "Room " << i+1 << ": \n";
        cout << temp[i].getDescription() << endl << endl;
    }
}

//was going to be used to print rooms, this would be useful if we chose to expand the program
void print(Room room){
    cout << "Description: " << room.getDescription() << endl;
    cout << "Lore: " << room.getLore() << endl;
    int t = room.getType();
    switch (t) {
        case 1:
            cout << "Type: Death" << endl;
            break;
        case 2:
            cout << "Type: Win" << endl;
            break;
        case 0:
            cout << "Type: Normal" << endl;
            break;
        case -1:
            cout << "Type: NoType" << endl;
            break;
        default:
            cout << "Bad Type: error" << endl;
            break;
    }
}

int main(int argc, char const *argv[])
{
	//error check the args passed
	if(argc != 2) {
		cerr << "Usage: " << argv[0] << " <lore_file.txt>" << endl;
		return 1;
	}

	string filename = argv[1]; //takes the first argument to the program as the filename

	vector<string> lore; //vector to keep all the lore to be added to the player from the room

	ifstream file;
	file.open(filename);

	//error check opening the file
	if(!file.is_open()){
		cerr << "Unable to open file: " << filename << endl;
		return 1;
	}

	//read the file into the vector
	string line;
	while (getline(file, line)) {
		lore.push_back(line);
	}
	file.close();

	// ----------------------------------------------The actual code----------------------------------------------//

    string overview = "this is the overview of the level";
    //Level level(overview); //creates a level obj and initilizes it
    Level level(overview);


    for(size_t i=0;i < lore.size();i++) { //make each room and add it to the vector of rooms
        vector<Room> roomConections; //just leave this empty for now and use the addConnections later
        Room tempRoom(desc[i], lore[i] , 0, roomConections); //desc, lore, type
        level.addRoom(tempRoom);
    }

	string name;
	cout << "what is your name?" << endl;
	cin >> name;
	Player player(name);
	cout << "Welcome " << name << "... TO THE GAME!!!" << endl;

	//Used to keep track of where the user is in the level
	int roomCount = 0;
	//Used to track where the user wants to go
	int roomSelection = 0;
	//Main while loop where the game is played
	//Need to print out the lore and check if the room is a death or win room, breaking if so.
	//Could also implement David's connection to work better, I just put this together late
	while(true)
	{
		//Store the index of the two path choices
		int path1 = roomCount * 2 + 1;
		int path2 = roomCount * 2 + 2;
		
        cout << "-------------------" << endl;
		
        //Adding lore to player
		player.addLore(level.getRooms()[roomCount].getLore());
		//Spot to print lore of current room
		cout << level.getRooms()[roomCount].getLore() << endl << endl;
		cout << "Choose which path to go down:" << endl;
		cout << "Path 1: " << desc[path1] << endl << endl;
		cout << "Path 2: " << desc[path2] << endl << endl;
		cout << "Type (" << path1 << ") to move down path 1, or (" << path2 << ") to move down path 2: ";
		
        cin >> roomSelection;
		
		//While loop to make sure the user inputs a valid path
		while(true)
		{
			if(roomSelection != path1 && roomSelection != path2)
			{

				cout << "Invalid input please type (" << path1 << ") or (" << path2 << ")" << endl;
				cin.clear();
				cin >> roomSelection;

			}
			else{
                break;
            }
		}
		
		cout << endl << "You decided to move down path " << roomSelection << endl;
        roomCount = roomSelection;

		if(roomCount == 4 || roomCount == 6) {// you lose
			cout << "-------------------" << endl;
			cout << level.getRooms()[roomCount].getLore() << endl << endl;
			cout << "You chose wrong, you loose. WOMP WOMP" << endl;
			return 0;
		}

		if(roomCount == 3 || roomCount == 5) {// you win
			cout << "-------------------" << endl;
			cout << level.getRooms()[roomCount].getLore() << endl << endl;
			cout << "Congrats, you have beat the game, you WIN!" << endl;
		}

		if((roomCount * 2 + 2 ) >= 7) {break;} //hopefully keep from segfaulting
	}

	return 0;
}