#include <vector>
#include "Location.h"
#include "Room.h"



void Room::setBBLocation(Location location) {

	this->bbLocation = location;
};
void Room::setHackerLocations(vector<Location> hLocations) {
	this->hackerLocations = hLocations;
};
void Room::setNpcLocations(vector<Location> npclocations) {

	this->npcLocations = npcLocations;

};

void Room::setPlayerLocation(Location location) {
	this->playerLocation = location;
};
//getters
Location Room::getBBLocation() {

	return bbLocation;
};
vector<Location> Room::getHackerLocations() {

	return hackerLocations;

};
vector<Location> Room::getNpcLocations() {
	return npcLocations;
};

Location Room::getPlayerLocation() {

	return playerLocation;
};