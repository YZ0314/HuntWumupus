#include "Hazard.h"
Hazard::Hazard(int id) {
	setCaveId(id);
	
}

Hazard::~Hazard(){}

void Hazard::setCaveId(int id) {
	this->cave_id = id;
}

int Hazard::getCaveId() {
	return this->cave_id;
}





