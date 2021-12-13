

#include <fstream>
#include <iostream>
#include "Map.h"
#include "Player.h"
#include "Room.h"
#include "Input.h"
#include "mapDriver.h"
#ifndef GAME_H
#define GAME_H
using namespace std;
extern Player playerObj;
extern Room currentRoom;
//extern Hacker hackers;
extern Input input;
extern mapDriver mapDriverObj;
extern bool isHackerLocation;
extern bool isNPCLocation;
class Game
{
public:

    static Player getPlayer() {

        return playerObj;
    }
   // static  Player player;
    private:
        


        
        
};

#endif