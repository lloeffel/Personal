/* Program Name: Multi-User Dungeons Lab
 * Student Name: Liam Loeffel
 * Net ID: lloeffel
 * Student ID: 000664706
 * Program Description:  This program allows the user to move thru rooms using the cardinal directions which label exits. The user can look around the room to see the room's name, description, and exit directions. The User can also quit by inputting "q".*/

#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

//Room Class
struct Room {
	int north = -1;
	int south = -1;
	int east = -1;
	int west = -1;
	string name;
	string description;
	vector<char> exits;
};

//gets the exit values
int getExit(const Room& room, const char direction) {
	switch (direction) {
		case 'n':
			return room.north;
		case 's':
			return room.south;
		case 'e':
			return room.east;
		case 'w':
			return room.west;
		default:
			return -1;
	}
}

//Allows the User to get info on the room they are currently in
void look(const Room& room) {
	cout << room.name << "\n" << room.description << "\n\nExits: ";
	// Check if exits is not null
	if (!room.exits.empty()) {
		for (size_t i = 0; i < room.exits.size(); ++i) {
			if ((room.exits.size() > 1) || (i != room.exits.size()-1)){
				cout << room.exits[i] << " ";
			}else{
				cout << room.exits[i];
			}
		}
	}

	cout << "\n";
}

//creates the dungeon
Room* loadRooms(const char* dungeonFilename, int& roomCount) {
	string line; //stores the line accessed by the filestream
	//creates the filestream
	ifstream fin(dungeonFilename);
	//checks to see if there is a file access error
	if (!fin.is_open()) {
		cerr << "error: file did not open correctly" << endl;
		exit(1);
	}
	
	int numRooms = 0;//stores the number of rooms
	//counts the number of rooms
	while (std::getline(fin, line)) {
		if (line == "~") {
			numRooms++;
		}
	}
	//creates the room array
	Room* rooms = new Room[numRooms];

	//resets the file stream
	fin.clear();
	fin.seekg(0, std::ios::beg);
	
	int roomIndex = 0; //index of the room
	int descriptionLines = 0; //counts the number of lines that have been read in the description
	while (getline(fin, line)) {
		if (line == "~") {//checks to see if the line is a divider
			roomIndex++;
			descriptionLines = 0;
		} else {
			switch (roomIndex % 3) {//looks to see if the index is a name, description, exits
				case 0: //gets the name of the room
					rooms[roomIndex / 3].name = line;
					break;
				case 1://gets the description of the room
					//looks to see if the newline character needs to be added to the end of the previous line
					if (descriptionLines > 0){
						rooms[roomIndex / 3].description += "\n";
					}
					rooms[roomIndex / 3].description += line;
					descriptionLines++;
					break;
				case 2://gets the exits of the room and sets the north, south, east, and west values
					if (!line.empty()) {
						rooms[roomIndex / 3].exits.push_back(line[0]);
						//sets the north, south, east, and west values
						switch (line[0]){
							case 'n':
								rooms[roomIndex / 3].north = stoi(line.substr(1));
								break;
							case 's':
								rooms[roomIndex / 3].south = stoi(line.substr(1));
								break;
							case 'e':
								rooms[roomIndex / 3].east = stoi(line.substr(1));
								break;
							case 'w':
								rooms[roomIndex / 3].west = stoi(line.substr(1));
								break;
						}
					}
					break;
			}
		}
	}
	roomCount = numRooms;
	fin.close();
	return rooms;
}
//deletes the rooms
void deleteRooms(Room* rooms, int roomCount) {
	for (int i = 0; i < roomCount; ++i) {
		rooms[i].exits.clear();
	}
	delete[] rooms;
}

int main(int argc, char** argv) {
	//Checks for a usage error
	if (argc != 2) {
		cerr << "usage: ./mud filename" << endl;
		return 1;
	}
	int roomCount;//Stores the number of rooms
	Room* rooms = loadRooms(argv[1], roomCount); //makes the dungeon
	int currentRoom = 0; //stores the room that the user is currently in
	char input; //Stores the user input
	int nextRoom; //Stores the room that the user wants to navigate to


	//starts the command loop
	while (true) {
		cout << "> ";
		cin >> input;

		switch (input) {
			case 'q': //quit game
				deleteRooms(rooms, roomCount);
				return 0;
			case 'l': //look around
				look(rooms[currentRoom]);
				break;
			case 'n': //navigate north
				nextRoom = getExit(rooms[currentRoom], input); //This gets the number of the room that the input would take the user to
				//gives feedback to the user on what their input did
				if (nextRoom != -1) {
					currentRoom = nextRoom;
					cout << "You moved NORTH.\n";
				} else {
					cout << "You can't go NORTH!\n";
				}
				break;
			case 's': //navigate south
				nextRoom = getExit(rooms[currentRoom], input); //This gets the number of the room that the input would take the user to
				//gives feedback to the user on what their input did
				if (nextRoom != -1) {
					currentRoom = nextRoom;
					cout << "You moved SOUTH.\n";
				} else {
					cout << "You can't go SOUTH!\n";
				}
				break;
			case 'e': //navigate east
				nextRoom = getExit(rooms[currentRoom], input); //This gets the number of the room that the input would take the user to
				//gives feedback to the user on what their input did
				if (nextRoom != -1) {
					currentRoom = nextRoom;
					cout << "You moved EAST.\n";
				} else {
					cout << "You can't go EAST!\n";
				}
				break;
			case 'w': //navigate west
				nextRoom = getExit(rooms[currentRoom], input); //This gets the number of the room that the input would take the user to
				//gives feedback to the user on what their input did
				if (nextRoom != -1) {
					currentRoom = nextRoom;
					cout << "You moved WEST.\n";
				} else {
					cout << "You can't go WEST!\n";
				}
				break;
			default:
				cout << "Invalid command. Try again.\n";
		}
	}

	return 0;
}

