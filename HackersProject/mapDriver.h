

#include <fstream>
#include <iostream>
#include "Map.h"
#include "Player.h"

#pragma once
#ifndef MAPDRIVER_H
#define MAPDRIVER_H
using namespace std;

class mapDriver
{



public:
	Map map;  // create object called map of type Map
	bool bEndFlag = false;//flag indicating whether the game is ending
	char move;  // for storing user input
	//Player player;
	
	//int mainGameLoop();
	int serverRoomRoutine(Player& player,string roomName);
	void createNewRoom();
	
	int bestBuyRoutine();
	int hackerRoutine();
	int npcRoutine();

	int forfietRoutine();
	int attackRoutine();


	void gameOverRoutine();
	void quitRoutine();
	void eoj();

private:
	Hacker currentHacker;
};

#endif


