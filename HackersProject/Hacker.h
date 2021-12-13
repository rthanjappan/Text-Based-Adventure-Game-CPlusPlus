#include <string>
#include <iostream>
using namespace std;

#pragma once
#ifndef HACKER_H
#define HACKER_H
class Hacker {

public:
	//default constructor
	Hacker() {
		hackerID = "";
		name = "";
		roomID = "";
	}
	//constructor with arguments
	Hacker(string hID, string n, string rID) {
		hackerID = hID;
		name = n;
		roomID = rID;
	}
	//copy constructor
	Hacker(const Hacker& obj) {
		hackerID = obj.hackerID;
		name = obj.name;
		roomID = obj.roomID;

	}
	//sets the Hacker ID
	void setHackerID(string id) {
		hackerID = id;
		//cout << "SetHackerID  : " << hackerID << endl;
	}
	//sets the name
	void setName(string n) {
		name = n;
	}
	//sets the room ID
	void setRoomID(string rID) {
		roomID = rID;
	}
	//Accessors
	string getHackerID() {
		return hackerID;
	}
	string getName() {
		return name;
	}
	string getRoomID() {
		return roomID;
	}



	//overload cout’s << operator 
	friend ostream& operator << (ostream& strm, const Hacker& obj) {
		string str;
		strm << "Hacker ID : " << obj.hackerID <<
			"      Hacker Name : " << obj.name <<
			"      Server Room ID : " << obj.roomID;

		return strm;
	}
	friend istream& operator >> (istream& strm, Hacker& obj) {
		obj.setHackerID("9999");
		//Prompt user for the hacker name
		string hackerName, roomID;
		cout << "\nPlease enter the Hacker name :  ";
		strm >> hackerName;
		obj.setName(hackerName);

		//Prompt user for the roomID
		cout << "\nPlease enter the Room ID:  ";
		strm >> roomID;
		obj.setRoomID(roomID);

		return strm;
	}
private:
	string hackerID;
	string name;
	string roomID;


};
#endif // !HACKER_H