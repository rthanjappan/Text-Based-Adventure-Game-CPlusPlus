#include "Player.h"
#include "Location.h"

using namespace std; 
//getters
string Player::getPlayerName() {
	return playerName;

};
int Player::getPlayerLocation() {
	return playerLocation;
};
Location Player::getCurrentPlayerLocation() {

	return currentPlayerLocation;
};

int Player::getDogeCoins() {
	return numDogeCoins;

};
int Player::getFrustrationLevel() {


	return frustrationLevel;
};


int Player::getMaintenanceLevel() {

	return maintenanceLevel;
};
int  Player::getInternetProviderLevel() {
	return numInternetProviderLevel;
}
int Player::getNumUSBSticks() {
	return numUSBSticks;
};
int Player::getNumVPN() {
	return numVPN;
};
//unordered_map <string, int> Player::getPlayerInventory() {
map <string, int> Player::getPlayerInventory() {

	return playerInventory;
};

//setters
void Player::setPlayerName(string name) {
	playerName = name;
};

void Player::setPlayerLocation(int playerLocation) {
	this->playerLocation = playerLocation;
};
void Player::setCurrentPlayerLocation(Location location) {
	currentPlayerLocation = location;
};
void Player::setDogeCoins(int numDogeCoins) {
	this->numDogeCoins = numDogeCoins;
		

};
void Player::setFrustrationLevel(int fLevel) {

	frustrationLevel = fLevel;
};
void  Player::setInternetProviderLevel(int level) {
	numInternetProviderLevel = level;
}
void Player::setNumUSBSticks(int num) {
	numUSBSticks = num;
};

void  Player::setNumVPN(int num) {
	numVPN = num;
};


void Player::setMaintenanceLevel(int level) {
	maintenanceLevel = level;
};
void Player::displayDogeCoins() {};



void Player::setPlayerInventory(map <string, int> inv) {
	playerInventory = inv;
};
void Player::addItemToPlayerInventory(string itemName) {

	
	int count = playerInventory[itemName];
	count++;
	//cout << "Item Name : " << itemName <<"  " <<count<< endl;

	playerInventory[itemName] = count;
};

int Player::removeItemFromPlayerInventory(string itemName) {


	int count = playerInventory[itemName];
	if (count > 0) {
		count--;
		//cout << "Item Name : " << itemName << "  " << count << endl;

		playerInventory[itemName] = count;
		return 1;
	}
	else {
		return -1;
	}
	
};