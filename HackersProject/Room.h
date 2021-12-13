

#include <fstream>
#include <iostream>
#include <vector>
#include "Location.h"
using namespace std;
#ifndef ROOM_H
#define ROOM_H
class Room
{
public:
	//constructor
	Room() {};

	void setRoomID(int roomID) {

		this->roomID = roomID;
	}
	void setIsNewRoom(int isNewRoom) {
		this->isNewRoom = isNewRoom;
	}
	void setBBLocation(Location location);
	void setHackerLocations(vector<Location> hLocations);
	void setNpcLocations(vector<Location>);

	void setPlayerLocation(Location location);


	int getRoomID() {
		return roomID;
	}
	int getIsNewRoom() {
		return isNewRoom;
	}
	Location getBBLocation();
	vector<Location> getHackerLocations();
	vector<Location> getNpcLocations();

	Location getPlayerLocation();

private:

	int roomID=0;
	int isNewRoom = false;
	Location bbLocation;
	vector<Location> hackerLocations;
	vector<Location> npcLocations;

	Location playerLocation;

};
#endif