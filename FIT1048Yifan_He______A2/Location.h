#pragma once
#ifndef LOCATION_H
#define LOCATION_H
#include <string>

using namespace std;

extern string directions_map[];

class Location {
private:
	string name, description;
	int adjacent[3], direction[3];
public:
	Location();
	void setName(string new_name);
	void setDescription(string des);
	string getName();
	void setAdj(int a, int b, int c, int da, int db, int dc);
	void printAdj();
	int getAdj(int dir);
}; 
#endif // !Location.h
