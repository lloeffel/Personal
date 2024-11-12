#include "../include/Level.h"
#include <vector>
#include <iostream>

using namespace std;
//Room Constructor
Room::Room(string desc, string l, int t, vector<Room> rooms){
description = desc;
lore = l;
type = t;
connections = rooms;
}

void Room::addConnection(Room* room) {
connections.push_back(*room);
}

/*
void Room::printConnections(int numRooms){
for(int i = 1; i < numRooms; i++)
{
cout << "Type (" << i << " ) to go to Room " << connections[i]. << endl;
}
}
*/

//type accessor
int Room::getType(){
return type; 
}

void Room::changeType(int i){
    type = i;
}

//decription accessor
string Room::getDescription(){
return description;
}

//lore accessor
string Room::getLore(){
return lore;
}

//Level Constructor taking a string
Level::Level(string over){
//boobState = false;
overview = over;
}

//overview accessor
string Level::getOverview(){
return overview;
}

//function that will add a room to the rooms vector
void Level::addRoom(Room r){
rooms.push_back(r);
}

vector<Room> Level::getRooms() {
return rooms;
}