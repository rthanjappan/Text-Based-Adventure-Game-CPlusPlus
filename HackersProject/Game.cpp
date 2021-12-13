
#include <conio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <iomanip>
#include<time.h>
#include<vector>
#include<Windows.h>
#include "Game.h"
#include "mapDriver.h"
#include "Player.h"
#include "Room.h"
#include "Puzzle.h"

using namespace std;
//Player Game::player = Player();

Input input=Input();
Player playerObj = Player();
Room currentRoom = Room();
mapDriver mapDriverObj=mapDriver();

bool isHackerLocation=false;
bool isNPCLocation=false;
class MainProcess
{
public:
	void mainMenu(void);
	mapDriver mapDriver;
private:
	int iChoice = 0;
	char move;
	int status = 2;
	int numRooms = 5;

	void showMenu(void);
	void enterChoice(void);
	void makeSelection(void);
	void travelServerRoomRoutine();

	void browseStackOverflowRoutine();
	void repairComputerRoutine();
	void useAntiVirusSoftwareRoutine();

	void quitRoutine();


};

int main(void)
{
	cout << "+-------------------------------------------------+" << endl;
	cout << "|             Welcome to the Hacker Game          |" << endl;
	cout << "+-------------------------------------------------+" << endl;
	cout << "Please enter your name : " << endl;
	string name;
	cin >> name;
	playerObj.setPlayerName(name);
	//vector<Hacker> hackers = input.getHackers();
	/*for (auto i : hackers) {

		cout << i << endl;
	}*/

	//vector<string> bestBuyInfo = input.getBestBuyInfo();
	/*for (auto i : bestBuyInfo) {

		cout << i << endl;
	}*/

	//vector<Puzzle> puzzles = input.getPuzzles();
	/*for (auto i : puzzles) {

		cout << i << endl;
		cout << endl;
	}*/
	//playerObj.setPlayerName("Rosemol ");
	//cout << playerObj << endl;
	currentRoom.setIsNewRoom(1);
	MainProcess MP;
	MP.mainMenu();

	return 0;
}

//processing the main menu
void MainProcess::mainMenu(void)
{
	showMenu();
	enterChoice();
	while (iChoice != 7) {
		makeSelection();
		showMenu();
		enterChoice();
		

	}
	
	return;
}
//showing the main menu
void MainProcess::showMenu(void)
{
	//system("cls");
	cout << "\n\t         Welcome to the Hacker Game";
	cout << "\n\n\t          Main Menu";
	cout << "\n\n\t          Select one:";
	cout << "\n\n\t          1. Repair your computer";
	cout << "\n\n\t          2. Use your antivirus software";
	cout << "\n\n\t          3. Travel the Server room";
	cout << "\n\n\t          4. Browse StackOverflow";
	cout << "\n\n\t          5. Display Status update";
	cout << "\n\n\t          6. Quit";
	cout << "\n\n\t          Enter choice (1 - 6) ===> ";
	
	return;
}

//reading the choice
void MainProcess::enterChoice(void)
{

	//iChoice = Scanner::getIntValue();
	cin >> iChoice;
	while (iChoice < 1 || iChoice > 6)
	{
		cout << "\nERROR...re-enter choice (1 - 6) ===> ";
		//iChoice = Scanner::getIntValue();
		cin >> iChoice;
	}
	
	return;
}
//selecting the corresponding program according to users choice
void MainProcess::makeSelection(void)
{

	// Clear Screen before printing Headings
	//system("cls");
	
	switch (iChoice)
	{
	
	case 1:
		cout << "       Repair your computer\n\n " << endl;
		repairComputerRoutine();
		break;
	case 2:
		cout << "       Use your antivirus software\n\n " << endl;
		useAntiVirusSoftwareRoutine();
		break;
	case 3:
		cout << "      Travel the Server Room \n\n " << endl;
		travelServerRoomRoutine();
		break;
	case 4:
		cout << "      Browse stack overflow \n\n " << endl;
		browseStackOverflowRoutine();
		break;
	case 5:
		//Display status update
		cout << "Display status update" << endl;
		//The computer’s current maintenance level
		cout <<"The computer's current maintenance level  :"<< playerObj.getMaintenanceLevel()<<endl;
		//How many viruses the computer has
		cout << "The computer has " << playerObj.getNumViruses() << " viruses." << endl;
		//Computer parts available(list the count of each item individually)
		cout << "Your inventory : " << endl;
		for (int i = 0; i < 7; i++) {

			cout << playerObj.computerParts[i] << " : " << playerObj.playerInventory.at(playerObj.computerParts[i]) << endl;
		}
		//Antivirus USB sticks available
		cout << "The number of antivirus USB sticks available : " << playerObj.getNumUSBSticks() << endl;
		//VPNs available
		cout << "The number of VPNs available : " << playerObj.getNumVPN() << endl;
		//Internet provider level
		cout << "The internet provider level  : " << playerObj.getNumVPN() << endl;
		//How much Dogecoin the player has available
		cout << "Number of dogecoins available : " << playerObj.getDogeCoins() << endl;
		//Player’s frustration level
		cout << "Frustration level : " << playerObj.getFrustrationLevel() << endl;
		//Carmen’s progress
		cout << "Carmen's progress : " << playerObj.carmensProgress << endl;
		//How many hackers the player has defeated so far
		cout << "Number of hackers defeated : " << playerObj.numHackersDefeated << endl;
		
		break;
	case 6:
		quitRoutine();
		break;
	default:
		cout << "   The other options. " << endl;
		break;
	}
	//cout << "Player frustration level : " << playerObj.getFrustrationLevel()<<endl;
	playerObj.setFrustrationLevel(playerObj.getFrustrationLevel() + 2);
	if (playerObj.getFrustrationLevel() >=100) {

		cout << "Sorry!!! You lost the game ...." << endl;
		exit(0);
	}
	int numViruses = playerObj.getNumViruses();
	int mLevel = playerObj.getMaintenanceLevel();
	
	if (numViruses > 0) {
		playerObj.setMaintenanceLevel(mLevel - (10*numViruses));
	}
	
	/*cout << "Player frustration level  after increasing: " << playerObj.getFrustrationLevel()
		<<"      Maintenance level : " << playerObj.getMaintenanceLevel() <<endl;*/

	if (playerObj.getMaintenanceLevel() <= 0) {
		cout << "Sorry!!! You lost the game ...." << endl;
		exit(0);

	}
	return;
}
void MainProcess::travelServerRoomRoutine() {

	//cout << playerObj << endl;
	string roomNames[] = { "Turing Room","Ellis Room",
		"Johnson Room","Willies Room","Moore Room" };


	do {



		while (status == 2 && numRooms >= 0) {
			if (numRooms == 0 && currentRoom.getIsNewRoom()) {
				mapDriver.gameOverRoutine();
				return;
			}

			if (currentRoom.getIsNewRoom()) {
				numRooms--;
				currentRoom.setRoomID(5 - numRooms);
				currentRoom.setIsNewRoom(1);
			}

			int status = mapDriver.serverRoomRoutine(playerObj, roomNames[(5 - numRooms-1)]);
			
			if (status == 1) {//status == 1 means show menu.
				currentRoom.setIsNewRoom(0);
				return;
			}
			if (status == 0) {
				break;
			}
		}
		status = 0;

	} while (status != 0);

	mapDriver.gameOverRoutine();
	return;
}
void MainProcess::browseStackOverflowRoutine() {
	cout << "Please solve this puzzle : " << endl;
	//get the system time
	unsigned seed = time(0);
	//seed the ramdom number generator
	srand(seed);
	vector<Puzzle> puzzles = input.getPuzzles();
	int randValue = (rand() % ((puzzles.size() - 1) - 0 + 1)) + 0;
	Puzzle currentPuzzle = puzzles[randValue];
	for (auto str : currentPuzzle.getQuestion()) {
		cout << str << endl;
	}
	cout << ">";
	string ans;
	cin >> ans;
	for (auto& c : ans)
	{
		c = tolower(c);
	}
	if (ans == currentPuzzle.getAnswer()) {

		cout << "You solved the puzzle correctly . Your frustration level is lowered by 5. " << endl;
		int fLevel = playerObj.getFrustrationLevel();
		if (fLevel >= 5) {
			playerObj.setFrustrationLevel(fLevel -5);
		}
		else {
			playerObj.setFrustrationLevel(0);
		}
		
		//cout << playerObj << endl;
	}
	else {
		cout << "You failed to solve the puzzle. Your frustration level is not lowered. " << endl;
		
	}
};
void MainProcess::repairComputerRoutine() {

	if (playerObj.getNumViruses() > 0) {
		cout << "You can't repair your computer because Your computer is infected with " <<
			playerObj.getNumViruses() << " viruses." << endl;
		return;
	}
	cout << "Your inventory : " << endl;
	for (int i = 0; i < 6; i++) {

		cout << (i+1)<<". "<<playerObj.computerParts[i] << " : " << playerObj.playerInventory.at(playerObj.computerParts[i]) << endl;
	}
	cout << -1 << ". Quit" << endl;

	int count = 0,partNo=0,numParts;
	while (count < 5 && partNo!=-1) {

		//cout<<"Count : "<<count << endl;
		cout << "Please select which part you would like to use in the repair : ";
		do {
			cin >> partNo;
			if (partNo == -1) {
				break;
			}
			if (partNo < 1 || partNo>6) {
				cout << "Invalid choice. Valid choices are 1 to 6"<<endl;
			}
			else {
				break;
			}
		} while (true);
		if (partNo == -1) {
			break;
		}
				
		
		map<string,int> inventory=playerObj.getPlayerInventory();
		string partName = playerObj.computerParts[partNo - 1];
		int numPartInInventory = inventory[partName];
		int remainingParts = 5 - count;
		cout << "Inventory has " << numPartInInventory << " "<<
			partName << endl;
		cout << "You can only choose 5 parts for one repair." << endl;
		cout << "You can choose " << remainingParts << " more parts." << endl;
		cout << "Please enter how many of this part you would like to use ?  : ";
		int partsToChoose=numPartInInventory;
		if (numPartInInventory > remainingParts) {
			partsToChoose = remainingParts;
		}

		
		do {

			cin >> numParts;

			if (numParts >= 0 && numParts <= partsToChoose) {
				count += numParts;
				//remove that part from inventory
				for (int i = 0; i < numParts; i++) {
					playerObj.removeItemFromPlayerInventory(partName);
				}
				break;
			}
			else {
				cout << "There is only  " << numPartInInventory << "  " << partName << " in the Inventory." << endl;
				cout<< "You can choose " << remainingParts << " more parts." << endl;
				cout << "Please select another value between 0 and "<< partsToChoose <<" :";
			}

		} while (true);
		



	}

	int mLevel = (count * 20);
	playerObj.setMaintenanceLevel(playerObj.getMaintenanceLevel() +mLevel);
	if (mLevel == 0) {
		cout << "Your computer is not repaired." << endl;
		cout << "Your current maintenance level is " << playerObj.getMaintenanceLevel() << endl;
		return;
	}
	cout << "You have successfully repaired your computer." << endl;
	cout << "Your maintenance level is increased by " << mLevel << endl;
	cout << "New maintenance level is " << playerObj.getMaintenanceLevel() << endl;
	//cout << playerObj << endl;

};
void MainProcess::useAntiVirusSoftwareRoutine() {

	int numUSB = playerObj.getNumUSBSticks();
	if (numUSB > 0) {

		playerObj.setNumViruses(0);
		playerObj.setNumUSBSticks(numUSB - 1);
		cout << "You are free from viruses." << endl;
	}
	else {
		cout << "You don't have any Anti Virus software."<<endl;
	}

};
void mapDriver::gameOverRoutine() {
	cout << "Congratulations!!! You won the game ...." << endl;
    exit(0);
};
void MainProcess::quitRoutine() {
	//if (iChoice == 6) {
		cout << "Do you want to quit (y/n) ? ";
		char cChoice;
		string str;
		getline(cin, str);
		cin >> cChoice;
		//cout << " Your choice is : [" << cChoice << "]" << endl;
		if (tolower(cChoice) == 'y') {
			mapDriver.eoj();
			exit(0);
		}
		
}