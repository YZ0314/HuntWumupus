#include "Pit.h"


Pit::Pit(int id) :Hazard(id){
	setCaveId(id);

}
Pit::~Pit(){}

void Pit::fall(Player*player) {
	player->setHealthPoint(0);
}

