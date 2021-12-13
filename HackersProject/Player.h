#ifndef PLAYER_H
#define PLAYER_H

#include <fstream>
#include <iostream>
#include <vector>
#include "Location.h"
#include <unordered_map>
#include<map>
using namespace std;

class Player
{
    

    public:

        string computerParts[7] = { "CPU","GPU","Power Supply Unit","Computer Case",
                                                "Internet Card","Keyboard and mouse","Premade Computer" };

        map <string, int> playerInventory = { {"CPU",0},{"GPU",0},{"Power Supply Unit",0},
            {"Computer Case",0},
    {"Internet Card",0},{"Keyboard and mouse",0},{"Premade Computer",1 } };
        
        
        int carmensProgress = 0;
        int numHackersDefeated = 0;



        Player() {
            numDogeCoins = 200;
            frustrationLevel = 0;
            playerLocation = 1;
            currentPlayerLocation= Location(0,0);
            
        };

        //getters
        string getPlayerName();
        int getPlayerLocation();
        int getDogeCoins();
        int getFrustrationLevel();
       
        Location getCurrentPlayerLocation();

        int getMaintenanceLevel();
        int getInternetProviderLevel();
        map <string, int> getPlayerInventory();
        
        
        //setters
        void setPlayerName(string);
        void setPlayerLocation(int);
        void setDogeCoins(int);
        void setFrustrationLevel(int);
        
        void setCurrentPlayerLocation(Location location);
        void displayDogeCoins();

        void setMaintenanceLevel(int level);
        void setPlayerInventory(map <string, int> inv);
        void addItemToPlayerInventory(string itemName);
        int removeItemFromPlayerInventory(string itemName);
        
       
        void setInternetProviderLevel(int level);
        void setNumUSBSticks(int num);
        void  setNumVPN(int num);
        void setNumViruses(int num) {
            numViruses = num;
        }
      
        int getMaintenenceLevel() {
            return maintenanceLevel;
        };
        int getNumUSBSticks();
        int getNumVPN();
        int getNumViruses() {
            return numViruses;
        }
        //overload cout’s << operator 
        friend ostream& operator << (ostream& strm, const Player& obj) {
            string str;
            strm << " Player Name : " << obj.playerName <<
                "Player Location : " << obj.playerLocation << "\n" <<
                " DogeCoins : " << obj.numDogeCoins <<
                " Maintenance Level : "<<obj.maintenanceLevel<<"\n"<<
                " Frustration Level : " << obj.frustrationLevel << " \n"<<
                " Internet Provider Level : " << obj.numInternetProviderLevel << " \n"<<
                " # of USB sticks : " << obj.numUSBSticks <<
                " # of VPNs : " << obj.numVPN <<
                " # of Viruses : "<<obj.numViruses<<
                "  Carmen's Progress : "<<obj.carmensProgress<<
                "\nThe number of hackers defeated : "<<obj.numHackersDefeated<<
                "\nYour Inventory : \n";
            
            for (int i = 0; i < 7; i++) {
                
                strm <<obj.computerParts[i]<<" : "<< obj.playerInventory.at(obj.computerParts[i]) <<endl;
            }
           
            return strm;
        }
private:
    string playerName;
    int playerLocation;
    Location currentPlayerLocation;
    
    
    
    int maintenanceLevel = 100;
    int numViruses = 0;
    int numUSBSticks = 0   ;
    int numVPN = 1;
    int numInternetProviderLevel = 1;
    int numDogeCoins;
    int frustrationLevel = 0;
    
    
};

#endif
