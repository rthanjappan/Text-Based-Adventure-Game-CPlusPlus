#include "Map.h"
#include "mapDriver.h"
#include <cstdlib>
#include <ctime>
#include "Player.h"
#include "Game.h"
#include "Puzzle.h"
#include <vector>


using namespace std;


class CTPartsBuyProcess
{
public:
    void cTPartsBuyMainMenu(void);
    //RestaurantDemo  rD1;
private:
    int iChoice;
    int CTPartsprices[7] = { 10,20,5,15,5,10,100 };
    string CTParts[7] = { "CPU","GPU","Power Supply Unit","Computer Case",
                                                "Internet Card","Keyboard and mouse","Premade Computer" };

    void showCTPartsBuyMenu(void);
    void enterCTPartsBuyChoice(void);
    void makeCTPartsBuySelection(void);
    bool isAffordable(int price);
};
int mapDriver::serverRoomRoutine(Player &player,string roomName) {
   
    //Map map;  // create object called map of type Map

    /*map.spawnBestBuy(1, 3);
    map.spawnNPC(2, 5);
    map.spawnNPC(3, 8);
    map.spawnHacker(1, 1);*/

    ////get the system time
    //unsigned seed = time(0);
    ////seed the ramdom number generator
    //srand(seed);
    //const int MIN_ROW_VALUE = 0;
    //const int MAX_ROW_VALUE = 4;
    //const int MIN_COL_VALUE = 0;
    //const int MAX_COL_VALUE = 8;
    
    //int bbRow=(rand() % (MAX_ROW_VALUE - MIN_ROW_VALUE + 1)) + MIN_ROW_VALUE;
    //int bbCol = (rand() % (MAX_COL_VALUE - MIN_COL_VALUE + 1)) + MIN_COL_VALUE;
    //map.spawnBestBuy(bbRow, bbCol);
    //currentRoom.setBBLocation(Location(bbRow, bbCol));
    ////map.spawnBestBuy(1, 3);
    ///*map.spawnNPC(2, 5);
    //map.spawnNPC(3, 8);
    //map.spawnHacker(1, 1);*/
    //int npc1Row = (rand() % (MAX_ROW_VALUE - MIN_ROW_VALUE + 1)) + MIN_ROW_VALUE;
    //int npc1Col = (rand() % (MAX_COL_VALUE - MIN_COL_VALUE + 1)) + MIN_COL_VALUE;
    //map.spawnNPC(npc1Row, npc1Col);
    //int npc2Row = (rand() % (MAX_ROW_VALUE - MIN_ROW_VALUE + 1)) + MIN_ROW_VALUE;
    //int npc2Col = (rand() % (MAX_COL_VALUE - MIN_COL_VALUE + 1)) + MIN_COL_VALUE;
    //map.spawnNPC(npc2Row, npc2Col);
    //
    //vector<Location> npcLocations{ Location(npc1Row,npc1Col),Location(npc2Row,npc2Col) };
    //currentRoom.setNpcLocations(npcLocations);


    //int hack1Row = (rand() % (MAX_ROW_VALUE - MIN_ROW_VALUE + 1)) + MIN_ROW_VALUE;
    //int hack1Col = (rand() % (MAX_COL_VALUE - MIN_COL_VALUE + 1)) + MIN_COL_VALUE;
    //map.spawnHacker(hack1Row, hack1Col);

    //vector<Location> hackerLocations{ Location(hack1Row,hack1Col)};
    //currentRoom.setHackerLocations(hackerLocations);

    //currentRoom.setPlayerLocation(Location(0, 0));
    //currentRoom.setIsNewRoom(0);
    if (currentRoom.getIsNewRoom()) {
        createNewRoom();
    }
    char move;  // for storing user input
    cout << "You are at " << roomName<<"." << endl;
    // quit after 10 moves
    //for (int i = 0; i < 10; i++) {
    while (!bEndFlag)
    {

    
        map.displayMap();  // pretty print map_data in terminal

        cout << "Valid moves are: " << endl;
        map.displayMoves();  // give user a menu of valid moves to pick from

        cout << "Input a move: ";
        cin >> move;
        cout << endl;
        if (move == 'm') {
            return 1;
            
        }
        if (move == 'n') {

            //have to defeat 1-3 hackers
            if (playerObj.numHackersDefeated >= 1) {
                currentRoom.setIsNewRoom(1);
                return 2;
            }
            else {
                cout << "\nYou have to defeat atleast one hacker before advance to next room.\n\n" << endl;
            }

            
        }
        map.executeMove(move);  // move the player on map based on user input

        if (map.isBestBuyLocation()) {
            cout << "You're in a Best Buy!" << endl;
            bestBuyRoutine();
        }

        if (map.isHackerLocation()) {
            cout << "You've encountered a Hacker!" << endl;
            /*isHackerLocation = true;
            return 1;*/
           hackerRoutine();
        }

        if (map.isNPCLocation()) {
            cout << "You've encountered an NPC!" << endl;
            /*isNPCLocation = true;
            return 1;*/
            npcRoutine();
        }
        int numGPU = playerObj.getPlayerInventory()["GPU"];

        playerObj.setDogeCoins(playerObj.getDogeCoins() + (5 + numGPU * 5));
    }
}
void mapDriver::createNewRoom() {
    playerObj.numHackersDefeated= 0;
    map = Map();
    //get the system time
    unsigned seed = time(0);
    //seed the ramdom number generator
    srand(seed);
    const int MIN_ROW_VALUE = 0;
    const int MAX_ROW_VALUE = 4;
    const int MIN_COL_VALUE = 0;
    const int MAX_COL_VALUE = 8;

    int bbRow = (rand() % (MAX_ROW_VALUE - MIN_ROW_VALUE + 1)) + MIN_ROW_VALUE;
    int bbCol = (rand() % (MAX_COL_VALUE - MIN_COL_VALUE + 1)) + MIN_COL_VALUE;
    map.spawnBestBuy(bbRow, bbCol);
    currentRoom.setBBLocation(Location(bbRow, bbCol));
    //map.spawnBestBuy(1, 3);
    /*map.spawnNPC(2, 5);
    map.spawnNPC(3, 8);
    map.spawnHacker(1, 1);*/
    int npc1Row = (rand() % (MAX_ROW_VALUE - MIN_ROW_VALUE + 1)) + MIN_ROW_VALUE;
    int npc1Col = (rand() % (MAX_COL_VALUE - MIN_COL_VALUE + 1)) + MIN_COL_VALUE;
    map.spawnNPC(npc1Row, npc1Col);
    int npc2Row = (rand() % (MAX_ROW_VALUE - MIN_ROW_VALUE + 1)) + MIN_ROW_VALUE;
    int npc2Col = (rand() % (MAX_COL_VALUE - MIN_COL_VALUE + 1)) + MIN_COL_VALUE;
    map.spawnNPC(npc2Row, npc2Col);
    int npc3Row = (rand() % (MAX_ROW_VALUE - MIN_ROW_VALUE + 1)) + MIN_ROW_VALUE;
    int npc3Col = (rand() % (MAX_COL_VALUE - MIN_COL_VALUE + 1)) + MIN_COL_VALUE;
    map.spawnNPC(npc3Row, npc3Col);

   /* cout <<"NPC Locations : "<< npc1Row << "," << npc1Col << "  ||  " 
        << npc2Row<<"," << npc2Col 
        << "  ||  "
        << npc3Row << "," << npc3Col << endl;*/
    vector<Location> npcLocations{ Location(npc1Row,npc1Col),Location(npc2Row,npc2Col) };
    currentRoom.setNpcLocations(npcLocations);


    int hack1Row = (rand() % (MAX_ROW_VALUE - MIN_ROW_VALUE + 1)) + MIN_ROW_VALUE;
    int hack1Col = (rand() % (MAX_COL_VALUE - MIN_COL_VALUE + 1)) + MIN_COL_VALUE;
    map.spawnHacker(hack1Row, hack1Col);

    int hack2Row = (rand() % (MAX_ROW_VALUE - MIN_ROW_VALUE + 1)) + MIN_ROW_VALUE;
    int hack2Col = (rand() % (MAX_COL_VALUE - MIN_COL_VALUE + 1)) + MIN_COL_VALUE;
    map.spawnHacker(hack2Row, hack2Col);

    int hack3Row = (rand() % (MAX_ROW_VALUE - MIN_ROW_VALUE + 1)) + MIN_ROW_VALUE;
    int hack3Col = (rand() % (MAX_COL_VALUE - MIN_COL_VALUE + 1)) + MIN_COL_VALUE;
    map.spawnHacker(hack3Row, hack3Col);
   /* cout << "Hacker Locations : " << hack1Row << "," << hack1Col << "  ||  " 
        << hack2Row <<","<< hack2Col 
        << "  ||  "
        << hack3Row << "," << hack3Col << endl;*/
    vector<Location> hackerLocations{ Location(hack1Row,hack1Col), Location(hack2Row,hack2Col) };

    currentRoom.setHackerLocations(hackerLocations);

    currentRoom.setPlayerLocation(Location(0, 0));
    playerObj.setCurrentPlayerLocation(Location(0, 0));
    currentRoom.setIsNewRoom(0);
}
class BestBuyProcess
{
public:
    void mainMenu(void);
    //RestaurantDemo  rD1;
private:
    int iChoice;

    void showBestBuyMenu(void);
    void enterBestBuyChoice(void);
    void makeBestBuySelection(void);


    void buyInternetProviderRoutine();
    void buyAntiVirusSoftwareRoutine();
    void buyVPNRoutine();
};
int mapDriver::bestBuyRoutine() {
    
    for (auto s : map.input.getBestBuyInfo()) {
        cout << s << endl;
    }
    BestBuyProcess bestBuyProcess;
    bestBuyProcess.mainMenu();

    
    return 0;
    



};
int mapDriver::hackerRoutine() {
    //cout << playerObj << endl;

    int roomID = currentRoom.getRoomID();

    //get the system time
    unsigned seed = time(0);
    //seed the random number generator
    srand(seed);
    int randValue = (rand() % (3 - 0 + 1)) + 0;
    //int bbCol = (rand() % (MAX_COL_VALUE - MIN_COL_VALUE + 1)) + MIN_COL_VALUE;

    int hackerID = (roomID - 1) * 4 + randValue;
    while (input.getHackers()[hackerID].getRoomID() == "0") {
        /*cout << "HackerID  "
            << hackerID << "      " << input.getHackers()[hackerID] << endl;*/
        randValue = (rand() % (3 - 0 + 1)) + 0;
        hackerID = (roomID - 1) * 4 + randValue;
    }
    currentHacker = input.getHackers()[hackerID];

    cout << "You just ran into " << currentHacker.getName() << "! Think you can beat this" <<
        " hacker's skills ?" << endl;
    cout << "Do you want  to (A)ttack or (F)orfiet ?";
    char cChoice;
    do {
        cin >> cChoice;
        cChoice = toupper(cChoice);
        if (cChoice == 'A' || cChoice == 'F') {

            break;

        }
        else {
            cout << "Invalid input . The valid input is A or F." << endl;
        }

    } while (true);
    if (cChoice == 'A') {
        attackRoutine();
    }
    else {
        forfietRoutine();
    }
    int row = map.getPlayerRowPosition();
    int col = map.getPlayerColPosition();
    //cout << row << "," << col << endl;
    map.removeHackerFromMap(row, col);
    input.removeHacker(currentHacker.getHackerID());
    //cout << playerObj << endl;

    return 0;
}

int mapDriver::attackRoutine(){
    
    int i = playerObj.getInternetProviderLevel();// 1;// internet provider level that the user owns
    int v = playerObj.getNumVPN();// # of VPNs the player owns
    int c = currentRoom.getRoomID();//the room number of the hacker
    int r1 = (rand() % (6 - 1 + 1)) + 1;//random number from 1 to 6
    int r2 = (rand() % (6 - 1 + 1)) + 1;//random number from 1 to 6 (independent of r1)

    int attackResult =(r1 * i) - (r2 * c * (1 / v));

    if (attackResult > 0) {
        cout << "Congratulations!!!!!!!!   "<<playerObj.getPlayerName() << " You won!!!!" << endl;
        playerObj.setDogeCoins(playerObj.getDogeCoins() + 50);
        playerObj.numHackersDefeated += 1;
        
    }
    else {
        cout << "Sorry   " << playerObj.getPlayerName() << " , You have been defeated by the "<<
            currentHacker.getName()<< endl;
        playerObj.numHackersDefeated++;
        cout << "You lost 20 points from maintenance level." << endl;
        playerObj.setMaintenanceLevel(playerObj.getMaintenanceLevel() -20);
        if (playerObj.getMaintenanceLevel() <= 0) {

            cout << "Sorry!!! You lost the game ...." << endl;
            exit(0);
        }
        playerObj.carmensProgress += 25;
        if (playerObj.carmensProgress>=100) {

            cout << "Sorry!!! You lost the game ...." << endl;
            exit(0);
        }
       //Virus infection
        int possibility = (rand() % (100 - 1 + 1)) + 1;
        if (possibility <= 10) {
            playerObj.setNumViruses(playerObj.getNumViruses() + 1);
         }
    } 

    //Remove a computer part
    bool isAvailable = false;
    for (auto CTPart : playerObj.playerInventory) {
        if (CTPart.second != 0) {
            int randPart = (rand() % (6 - 0 + 1)) + 0;
            int result = playerObj.removeItemFromPlayerInventory(playerObj.computerParts[randPart]);
            while (result != 1) {
                randPart = (rand() % (6 - 0 + 1)) + 0;
                //cout << "result!=1   playerObj.computerParts[randPart]   : " << playerObj.computerParts[randPart] << endl;
                result = playerObj.removeItemFromPlayerInventory(playerObj.computerParts[randPart]);
            }

            cout << " The computer part removed is   : " << playerObj.computerParts[randPart] << endl;
            break;
        }
    }

    return 0;

};

int mapDriver::forfietRoutine() {

    cout << "You were unable to outsmart Carmen’s hacker." << endl;
    cout << "You lost all the computer parts in your inventory";
    for (auto CTPart : playerObj.computerParts) {

        playerObj.playerInventory[CTPart] = 0;

    }
    //cout << playerObj << endl;
    return 0;
}
int mapDriver::npcRoutine() {
    cout << "Please solve this puzzle : " << endl;
    //get the system time
    unsigned seed = time(0);
    //seed the ramdom number generator
    srand(seed);
    vector<Puzzle> puzzles = input.getPuzzles();
    int randValue= (rand() % ((puzzles.size()-1) - 0 + 1)) + 0;
    Puzzle currentPuzzle = puzzles[randValue];
    for (auto str : currentPuzzle.getQuestion()) {
        cout <<str  << endl;
    }
    cout << ">";
    string ans;
    cin >> ans;
    for (auto& c : ans)
    {
        c = tolower(c);
    }
    if (ans == currentPuzzle.getAnswer()) {

        cout << "\n\nYou solved the puzzle correctly . You get one computer part. " << endl;
        randValue = (rand() % (6 - 0 + 1)) + 0;
        playerObj.addItemToPlayerInventory(playerObj.computerParts[randValue]);
        cout << playerObj.computerParts[randValue] << " is added to your inventory." << endl;
        //cout << playerObj<<endl;
    }
    else {
        cout << "\n\nYou failed to solve the puzzle. You lost one computer part. " << endl;
        //Remove a computer part
        bool isAvailable = false;
        for (auto CTPart : playerObj.playerInventory) {
            if (CTPart.second != 0) {
                int randPart = (rand() % (6 - 0 + 1)) + 0;
                int result = playerObj.removeItemFromPlayerInventory(playerObj.computerParts[randPart]);
                while (result != 1) {
                    randPart = (rand() % (6 - 0 + 1)) + 0;
                    //cout << "result!=1   playerObj.computerParts[randPart]   : " << playerObj.computerParts[randPart] << endl;
                    result = playerObj.removeItemFromPlayerInventory(playerObj.computerParts[randPart]);
                }

                cout << " The part removed is   : " << playerObj.computerParts[randPart] << endl;
                break;
            }
        }
    }
    int row = map.getPlayerRowPosition();
    int col = map.getPlayerColPosition();
    //cout <<"NPC Location : "<< row << "," << col << endl;
    map.removeNPCFromMap(row, col);
   // input.removePuzzle(currentPuzzle.getPuzzleID());
    //cout << playerObj << endl;
    //cout << " Current puzzle : "<<currentPuzzle << endl;
    return 0;
};

//processing the Best Buy main menu
void BestBuyProcess::mainMenu(void)
{
    showBestBuyMenu();
    enterBestBuyChoice();
    while (iChoice != 5)
    {
        makeBestBuySelection();
        showBestBuyMenu();
        enterBestBuyChoice();
    }
    /*rD1.eoj();*/
    return;
}
//showing the Best Buy menu
void BestBuyProcess::showBestBuyMenu(void)
{
    //system("cls");
    cout << "\n\t         Welcome to Best Buy";
    cout << "\n\n\t          Best Buy Menu";
    cout << "\n\n\t          Select one:";
    cout << "\n\n\t          1. Computer Parts";
    cout << "\n\n\t          2. Antivirus Software";
    cout << "\n\n\t          3. Virtual Private Network(VPN)";
    cout << "\n\n\t          4. Internet Provider";
    cout << "\n\n\t          5. exit";
    cout << "\n\n\t          Enter choice (1 - 5) ===> ";
    
    return;
}
//reading the Best Buy menuchoice
void BestBuyProcess::enterBestBuyChoice(void)
{
    //iChoice =Scanner::getIntValue();
    cin >> iChoice;
    while (iChoice < 1 || iChoice > 5)
    {
        cout << "\nERROR...re-enter choice (1 - 5) ===> ";
        //iChoice =Scanner::getIntValue();
        cin >> iChoice;
    }
    return;
};
//selecting the corresponding program according to users choice
void BestBuyProcess::makeBestBuySelection(void)
{
    CTPartsBuyProcess ctPartsBuy;
    // Clear Screen before printing Headings
   // system("cls");
    switch (iChoice)
    {
    case 1: 
        
        ctPartsBuy.cTPartsBuyMainMenu();
        break;
    case 2://Anti virus software

        buyAntiVirusSoftwareRoutine();
        
        break;
    case 3://VPN

        buyVPNRoutine();
        break;
    case 4:

        buyInternetProviderRoutine();
        break;
    }
}

void BestBuyProcess::buyInternetProviderRoutine() {

    cout << "Internet provider level 2 costs 10 Dogecoins" << endl;
    cout << "Internet provider level 3 costs 25 Dogecoins" << endl;
    cout << "Internet provider level 4 costs 40 Dogecoins" << endl;
    cout << "Internet provider level 5 costs 50 Dogecoins" << endl;
    cout << "Please select the internet provider level ? " ;
    int iChoice;
    cin >> iChoice;
    
    int prices[4] = { 10,25,40,50 };
    int price = prices[iChoice - 2];
    if (playerObj.getDogeCoins() >= price) {
        playerObj.setInternetProviderLevel(iChoice);

        playerObj.setDogeCoins(playerObj.getDogeCoins() - price);
        //cout << playerObj;
    }
    else{
        cout << "You don't have enough money to buy this item.\n" <<
            "Please select another item." << endl;
        return;
    }
    //playerObj.addItemToInventory(CTParts[iChoice-1]);
    


}
void BestBuyProcess::buyAntiVirusSoftwareRoutine() {

    cout << "One USB stick of antivirus software costs 10 Dogecoins . " << endl;
    cout << "How many USB sticks you want? ";

    int numUSB;
    cin >> numUSB;

    int price = numUSB * 10;
    if (playerObj.getDogeCoins() >= price) {
        playerObj.setNumUSBSticks(playerObj.getNumUSBSticks()+numUSB);

        playerObj.setDogeCoins(playerObj.getDogeCoins() - price);
        //cout << playerObj;
    }
    else {
        cout << "You don't have enough money to buy this item.\n" <<
            "Please select another item." << endl;
        return;
    }
    

};
void BestBuyProcess::buyVPNRoutine() {
    cout << "A VPN costs 20 Dogecoins each. " << endl;
    cout << "How many VPNs you want? ";

    int numVPN;
    cin >> numVPN;

    int price = numVPN * 20;
    if (playerObj.getDogeCoins() >= price) {
        playerObj.setNumVPN(playerObj.getNumVPN() + numVPN);

        playerObj.setDogeCoins(playerObj.getDogeCoins() - price);
        //cout << playerObj;
    }
    else {
        cout << "You don't have enough money to buy this item.\n" <<
            "Please select another item." << endl;
        return;
    }
};
void CTPartsBuyProcess::cTPartsBuyMainMenu(void) {

    showCTPartsBuyMenu();
    enterCTPartsBuyChoice();
    while (iChoice != 8)
    {
        makeCTPartsBuySelection();
        showCTPartsBuyMenu();
        enterCTPartsBuyChoice();
    }
    /*rD1.eoj();*/
    return;

};
void CTPartsBuyProcess::showCTPartsBuyMenu(void) {
    //system("cls");
    cout << "\n\t         Welcome to Best Buy";
    cout << "\n\n\t          Computer Parts Menu";
    cout << "\n\n\t          Select one:";
    cout << "\n\n\t          1. A CPU costs 10 Dogecoins";
    cout << "\n\n\t          2. A GPU costs 20 Dogecoins";
    cout << "\n\n\t          3. A Power Supply Unit costs 5 Dogecoins";
    cout << "\n\n\t          4. A Computer Case costs 15 Dogecoins";
    cout << "\n\n\t          5.  An internet card costs 5 Dogecoins";
    cout << "\n\n\t          6.  A keyboard and mouse costs 10 Dogecoins";
    cout << "\n\n\t          7.  A premade computer costs 100 Dogecoins";
    cout << "\n\n\t          8. exit";
    cout << "\n\n\t          Enter choice (1 - 8) ===> ";
   /* A CPU costs 10 Dogecoins
        A GPU costs 20 Dogecoins
        A Power Supply Unit costs 5 Dogecoins
        A Computer Case costs 15 Dogecoins
        An internet card costs 5 Dogecoins
        A keyboard and mouse costs 10 Dogecoins
        A premade computer costs 100 Dogecoins*/
    return;

};
void CTPartsBuyProcess::enterCTPartsBuyChoice(void) {
    cin >> iChoice;
    while (iChoice < 1 || iChoice > 8)
    {
        cout << "\nERROR...re-enter choice (1 - 8) ===> ";
        //iChoice =Scanner::getIntValue();
        cin >> iChoice;
    }
    return;
};
void CTPartsBuyProcess::makeCTPartsBuySelection(void) {
    // Clear Screen before printing Headings
      // system("cls");
    if (!isAffordable(CTPartsprices[iChoice-1])) {
        cout << "You don't have enough money to buy this item.\n" <<
            "Please select another item."<<endl;
        return;
    }
    //playerObj.addItemToInventory(CTParts[iChoice-1]);
    playerObj.addItemToPlayerInventory(CTParts[iChoice - 1]);
    cout << "The " << CTParts[iChoice - 1] << " has been added to your inventory." << endl;
    playerObj.setDogeCoins(playerObj.getDogeCoins() - CTPartsprices[iChoice - 1]);
    //cout << playerObj;

   

};
bool CTPartsBuyProcess::isAffordable(int price) {

    if (playerObj.getDogeCoins() >= price) {
        return true;
    }
    return false;
}




void mapDriver::eoj() {
    cout << "Game is ending..."<<endl;
    //    system("pause");
    cout<<"Thanks for playing...." << endl;
}