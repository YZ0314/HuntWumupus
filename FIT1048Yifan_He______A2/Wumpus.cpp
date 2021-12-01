#include "Wumpus.h"
Wumpus::Wumpus(int id): Hazard(id) {
	setCaveId(id);
	this->alive = true;
}
Wumpus::~Wumpus(){}
void Wumpus::killPlayer(Player* player) {
	player->setHealthPoint(0);
}
void Wumpus::move(int id) {
	srand(time(NULL));
	if ((rand() % 4+1) == 4) {
		cout << "Wumpus is not awakened" << endl;
	}
	else
	{
		setCaveId(id);
		cout << "Wumpus is awakened!" << endl;

	}
}

void Wumpus::isdead() {
	this->alive = false;
}
bool Wumpus::isalive() {
	return this->alive;
}