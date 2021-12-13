
#include<fstream>
#include <vector>
#include <string>
#include <sstream>
#include <conio.h>
#include "Hacker.h"
#include "Puzzle.h"
using namespace std;

#pragma once
#ifndef INPUT_H
#define INPUT_H
class Input {
public:

	Input();
	Input(string hackerFileName,string);
	vector<string> getDataFromFile(string fileName);
	void getHackerDataFromFile(string hackerFileName);
	void processRawHackerData();
	void processRawPuzzlesData();
	void removeHacker(string hackerID) {

		for (int i = 0; i < hackers.size(); i++) {
			if (hackers[i].getHackerID() == hackerID) {
				hackers[i].setRoomID("0");
			}
		}
		

	}

	void removePuzzle(int puzzleID) {
		vector<Puzzle>::iterator it;
		cout <<"Puzzzles size : "<< puzzles.size();
		for (int i = 0; i < puzzles.size(); i++) {
			if (puzzles[i].getPuzzleID() == puzzleID) {
				it = puzzles.begin() + i;
			}
		}
		
		puzzles.erase(it);
		
		cout << "Puzzzles size after removing puzzle :  " << puzzles.size();
			
	}


	
	vector<Hacker> getHackers() {
		return hackers;
	}
    vector<string> getBestBuyInfo() {
		return bestBuyInfo;
	}

	vector<Puzzle> getPuzzles() {
		return puzzles;
	}
private:
	vector<Hacker> hackers;
	vector<string> bestBuyInfo;
	vector<string> rawPuzzlesData;
	vector<string> rawAnswersData;

	vector<Puzzle> puzzles;


};
#endif // !INPUT_H