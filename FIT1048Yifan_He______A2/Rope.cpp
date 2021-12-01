#include "Rope.h"
Rope::Rope(int cost):Item(cost) {
	this->cost = cost;

}

Rope::~Rope(){}

void Rope::showMeau(Player*player) {
	if (player->hasRope())
	{
		cout << "\n Item: Rope\n";
	}
	
}