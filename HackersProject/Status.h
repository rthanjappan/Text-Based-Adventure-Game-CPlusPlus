#pragma once
#ifndef STATUS_H
#define STATUS_H

#include <fstream>
#include <iostream>
#include <vector>
#include "Location.h"
#include "Game.h"
using namespace std;

class Status
{


public:
    Status() {
        numDogeCoins = 200;
        frustrationLevel = 0;
        playerLocation = 1;
        currentPlayerLocation = Location(0, 0);

    };

    //getters
    string getPlayerName();
    int getPlayerLocation();
    int getDogeCoins();
    int getFrustrationLevel();
    vector<string> getInventory();
    Location getCurrentPlayerLocation();

    //setters
    void setPlayerName(string);
    void setPlayerLocation(int);
    void setDogeCoins(int);
    void setFrustrationLevel(int);
    void addItemToInventory(string item);
    void setCurrentPlayerLocation(Location location);
    void displayDogeCoins();


    //overload cout’s << operator 
    friend ostream& operator << (ostream& strm, const Status& obj) {

        /*The computer’s current maintenance level
            How many viruses the computer has
            Computer parts available(list the count of each item individually)
            Antivirus USB sticks available
            VPNs available
            Internet provider level
            How much Dogecoin the player has available
            Player’s frustration level
            Carmen’s progress
            How many hackers the player has defeated so far*/
        string str;
        Player player =Game::getPlayer();
        strm << " STATUS : Player Name : " << player.getPlayerName() <<
            "\nThe computer’s current maintenance level : " << player.getMaintenanceLevel() <<
            "\nCarmen’s progress : " << obj.carmensProgress <<
            "\nDogeCoins : " << player.getDogeCoins() <<
            "\nFrustration Level : " << player.getFrustrationLevel();
        strm<<"Your inventory : "<<player.get
        
           /* "\nYour Inventory : " << player.inventory[0];
        for (int i = 1; i < obj.inventory.size(); i++) {
            strm << " ," << obj.inventory[i];
        }*/

        return strm;
    }
private:
    /*string playerName;
    int playerLocation;
    Location currentPlayerLocation;
    int numDogeCoins;
    int frustrationLevel;
    vector<string> inventory{ "Computer",
                                            "Internet Provider Level 1",
                                            "Virtual Private Network" };*/
    int carmensProgress = 0;
};

#endif
