
#ifndef LOCATION_H
#define LOCATION_H

#include <fstream>
#include <iostream>
#include <vector>
#pragma once
using namespace std;

class Location
{


public:

	Location() {
		x = -1;
		y = -1;
	};
	int x; //= -1;
	int y; //= -1;
	Location(int, int);
	//overload cout’s << operator 
	friend ostream& operator << (ostream& strm, const Location& obj) {
		
		strm << "( " << obj.x << ", " << obj.y << ")";

		return strm;

	}

private:

};
#endif