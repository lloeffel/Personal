#ifndef LEVEL_H
#define LEVEL_H

#include <string>
#include <vector>

using namespace std;
struct Room {
friend class Level;
    public:
        Room(string, string, int, vector<Room>);
        string getDescription();        //Accessor for description
        string getLore();               //Accessor for lore
        int getType();//Accessor for type
        int getNumber();//Accessor for number
        void addConnection(Room*);      //Add a room to the list of connections
        void getConnections();//Accessor for connections
        void printConnections(int);
        void changeType(int);

    private:
        string description;         //a description for the room
        string lore;                //lore to be added to the player
        int type;                   //winning, death, or traversal room
        vector<Room> connections;//Vector of the connecting rooms
        int number;//The room number
};

class Level {
    public:
        Level(string);
        string getOverview();       //Accessor for overview
        vector<Room> getRooms();    //Accessor for the rooms vector
        void addRoom(Room);         //Used to fill the rooms vector
    private:
        vector<Room> rooms;         //Vector that will contain the rooms for the level
        string overview;            //Overview for the level

};

#endif