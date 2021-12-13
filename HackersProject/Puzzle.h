#include <fstream>
#include <iostream>
#include <vector>
#include "Location.h"
using namespace std;
#ifndef PUZZLE_H
#define PUZZLE_H
#pragma once
class Puzzle
{
public:


	//setters
	void setPuzzleID(int id) {
		puzzleID = id;
	
	};
	void setQuestion(vector<string> ques) {
		question = ques;
	};
	void setAnswer(string ans) {
		answer = ans;
	};
	void setSolved(bool value) {
		isSolved = value;
	};

	//getters


	int getPuzzleID() {
		return puzzleID;

	};
	vector<string> getQuestion() {
		return question;
	};
	string getAnswer() {
		return answer;
	};
	bool getIsSolved() {
		return isSolved;
	};

	friend ostream& operator << (ostream& strm, const Puzzle& obj) {
		string str;
		strm << "Puzzle ID : " << obj.puzzleID <<
			"\nQuestion : ";
		for (auto str : obj.question) {

			strm << str << endl;
		}
		
		strm<<"\nAnswer : " << obj.answer<<
			"\nisSolved  : " << obj.isSolved;

		return strm;
	}
private:
	int puzzleID;
	vector<string> question;
	string answer;
	bool isSolved;

};
#endif
