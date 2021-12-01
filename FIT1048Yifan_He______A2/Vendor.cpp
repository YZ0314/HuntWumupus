#include "Vendor.h"
Vendor::Vendor(int id) {
	this->caveId = id;
	

}

Vendor::~Vendor() {}

void Vendor::showMeau() {
	cout << "\n Hello Good hunter. What is it you desire?\n";
	cout << "[R] Buy Rope (5 golds)" << endl;
	cout << "[O] Buy lantern Oil (1 gold)" << endl;
	cout << "[T] Talk with the vendor" << endl;	
	cout << "[q] Exit" << endl;
}

void Vendor::talk() {
	cout << "\n Good hunter. I am a vendor, here in this place to look after you. \n";
	cout << "\nHonorable hunter, pursue the golds of caves, and I will channel them into your strength.\n";
	cout << "\nYou will hunt beasts... and I will be here for you, to embolden your sickly spirit\n" << endl;
}

void Vendor::goodBye() {
	cout << "\n Farewell good hunter. may you find your worth in the waking world." << endl;
}
int Vendor::getcaveId() {
	return this->caveId;
}
void Vendor::setCaveId(int id) {
	this->caveId = id;

}

void Vendor::run(Player*player) {
	string opt;
	showMeau();
	cin >> opt;
	while (!(opt == "q"))
	{
		if (opt == "T") {
			talk();
			showMeau();
			cin >> opt;
			
		}
		else if (opt == "R") {
			if (player->getCurrentGold() >= 5) {
				player->activeRope();
				player->spendGold(5);
				showMeau();
				cout << "\nGot Rope!" << endl;
				cin >> opt;
			}
			else
			{
				cout << "\nGold inadequate\n" << endl;
				showMeau();
				cin >> opt;
			}

		}

		else if (opt == "O") {
			if (player->getCurrentGold() >= 1) {
				player->addOil(1);
				player->spendGold(1);
				showMeau();
				cout << "\nGot Oil!" << endl;
				cin >> opt;
			}

			else
			{
				cout << "\nGold inadequate\n" << endl;
				showMeau();
				cin >> opt;
			}
		}
		else {
			cout << "\nDo not have the itme, try again!" << endl;
			cin >> opt;
		}
	}
	cout << "\n Farewell good hunter. may you find your worth in the waking world." << endl;
}

void Vendor::roaming(int id) {
	setCaveId(id);
}