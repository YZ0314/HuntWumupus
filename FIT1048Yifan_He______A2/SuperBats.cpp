#include "SuperBats.h"

SuperBats::SuperBats(int id) :Hazard(id) {
	setCaveId(id);

}
SuperBats::~SuperBats(){}

void SuperBats::carryPlayer(Player* player, int carryId) {
	player->setLocation(carryId);

}

