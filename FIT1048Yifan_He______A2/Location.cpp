#include "Location.h"
#include <string>
#include <iostream>

using namespace std;

string directions_map[] = { "N", "S", "E", "W", "NE", "NW", "SE", "SW" };

Location::Location() {
	memset(adjacent, 0, sizeof(adjacent));
	memset(direction, 0, sizeof(direction));
}
void Location::setName(string new_name) {
	this->name = new_name;
}
void Location::setDescription(string des) {
	this->description = des;
}
string Location::getName() {
	return this->name;
}
void Location::setAdj(int a, int b, int c, int da, int db, int dc) {
	adjacent[0] = a, adjacent[1] = b, adjacent[2] = c;
	direction[0] = da, direction[1] = db, direction[2] = dc;
}
void Location::printAdj() {
	cout << "[" << this->name << "]: " << description << "\n\n";
	cout << "Visiable exits: ";
	for (int i = 0; i < 3; i++) {
		cout << directions_map[direction[i]] << " ";
	}
	cout << "\n\n";
}
int Location::getAdj(int dir) {
	for (int i = 0; i < 3; i++) {
		if (direction[i] == dir) {
			return adjacent[i];
		}
	}
	return -1;
}
