#include <iostream>
#include<fstream>
#include <vector>
#include <string>
#include <sstream>
#include <conio.h>
#include "Hacker.h"
#include "Input.h"

//Input::Input() {
//
//};
Input::Input() {

    getHackerDataFromFile("Hackers.txt");
    bestBuyInfo=getDataFromFile("BestBuyFile.txt");
    rawPuzzlesData =getDataFromFile("Puzzles.txt");
    rawAnswersData =getDataFromFile("Answers.txt");
    processRawPuzzlesData();



};
Input::Input(string hackerFileName,
    string bestBuyFileName) {
    getHackerDataFromFile(hackerFileName);
    getDataFromFile(bestBuyFileName);

};
void Input::getHackerDataFromFile(string fileName) {
    // Create a text string, which is used to output the text file
    string myText;
    int count = 1;
    // Read from the text file
    ifstream inputFile(fileName);
    if (inputFile.fail()) {

        cout << fileName << " not found" << endl;
        return;
    }
    // Use a while loop together with the getline() function to read the file line by line
    while (getline(inputFile, myText)) {
        // Output the text from the file
        //cout << myText << endl;
        char split_with = ',';
        vector<string> words;
        string token;
        stringstream ss(myText);
        while (getline(ss, token, split_with)) {
            words.push_back(token);
        }
        Hacker hacker;
        for (int i = 0; i < words.size(); i++) {
            //string s = "H" + count;
            hacker.setHackerID(to_string(count));
            count++;
            hacker.setName(words[i]);
            i++;
            hacker.setRoomID(words[i]);


        }
        hackers.push_back(hacker);
    }
    inputFile.close();
};

void Input::processRawHackerData() {
};

vector<string>  Input::getDataFromFile(string fileName) {
    // Create a text string, which is used to output the text file
    string myText;
    vector<string>  rawInfo;
    //int count = 1;
    // Read from the text file
    ifstream inputFile(fileName);
    if (inputFile.fail()) {

        cout << fileName << " not found" << endl;
        return rawInfo;
    }
    // Use a while loop together with the getline() function to read the file line by line
    while (getline(inputFile, myText)) {
        rawInfo.push_back(myText);
    
    }
    return rawInfo;
}

void Input::processRawPuzzlesData() {
   
    int index = 0;
    for (int i = 0; i < rawPuzzlesData.size(); i++) {
        Puzzle puzzle;
        puzzle.setPuzzleID((index+1));
        string str = rawPuzzlesData[i];
        vector<string> question;
        while (str != "---") {
            question.push_back(str);
            i++;
            str = rawPuzzlesData[i];
        }
       

        puzzle.setQuestion(question);
        
        puzzle.setAnswer(rawAnswersData[(index*2)]);
        index++;

        puzzle.setSolved(false);

        puzzles.push_back(puzzle);
    }

};