#include "Golds.h"
Golds::Golds() {
	

}

Golds::~Golds() {

}

void Golds::set() {
	srand(time(NULL));
	for (int i = 0; i < 10; i++)
	{
		location[i] = rand() % 20 + 1;
		for (int z = 0; z < i; z++) {
			while (location[i] == location[z]) {
				location[i] = rand() % 20 + 1;
				
			}
		}

		for (int z = i + 1; z < 10; z++) {
			while (location[i] == location[z]) {
				location[i] = rand() % 20 + 1;

			}
		}



	}
}//set  golds in map

void Golds::add(Player* player) {
	for (int i = 0; i < sizeof(location); i++) {
		if (player->getLocation() == location[i])
		{
			cout << "\nYou find a gold in this cave!!\n" << endl;
			player->addGold();
		}
	}

}