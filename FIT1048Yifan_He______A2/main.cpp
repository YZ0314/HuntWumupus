#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>
#include "Player.h"
#include "Location.h"
#include"Pit.h";
#include<time.h>
#include"SuperBats.h"
#include"Wumpus.h"
#include"Vendor.h"
#include"Golds.h"


using std::cout;
using std::cin;

string map[] = {
	"                                       ###                                      ",
	"                                      # 1 #                                     ",
	"                                   #   ###   #                                  ",
	"                               #        #        #                              ",
	"                            #           #            #                          ",
	"                        #             #####             #                       ",
	"                     #              ##  8  ##              #                    ",
	"                 #       ###    ###   #####   ###    ###      #                 ",
	"              #         # 7 # ##                 ## # 9 #        #              ",
	"          #           #  ###                         ###  #          #          ",
	"   #####            #        # ####           #### #        #            #####  ",
	"  #  5  #      ### #          # 17 # ####### # 18 #          # ###      #  2  # ",
	"   #####  ##  # 6 #           #    #         #    #           #10 #  ##  #####  ",
	"     #        #   #            ####           ####            #   #        #    ",
	"      #        ###             #                 #             ###        #     ",
	"       #        #             #                   #             #        #      ",
	"        #       #          ###                     ###          #       #       ",
	"         #      #         #16 #                   #19 #         #      #        ",
	"          #    ###   ##    ###                     ###    ##   ###    #         ",
	"          #   #15 #             ###    ###   ###              #11 #   #         ",
	"           #   ###                   # 20  #                   ###   #          ",
	"            #       #                #     #                #       #           ",
	"             #        #                ###                #        #            ",
	"              #         ###             #             ###         #             ",
	"               #       #14 #          #####          #12 #       #              ",
	"                #     # ### ##       # 13  #      ##  ### #     #               ",
	"                #    #        ####   #     #  ####         #    #               ",
	"                #####                 #####                 #####               ",
	"               #  4  # ################################### #  3  #              ",
	"                #####                                       #####               "
};

int edges[][3] =
{
	{5, 8, 2}, {1, 10, 3}, {2, 12, 4}, {3, 14, 5}, {4, 6, 1}, {5, 15, 7}, {6, 17, 8}, {7, 1, 9}, {8, 18, 10}, {9, 2, 11},
	{10, 19, 12}, {11, 3, 13}, {12, 20, 14}, {13, 4, 15}, {14, 16, 6}, {15, 20, 17}, {16, 7, 18}, {17, 9, 19}, {18, 11, 20}, {19, 13, 16}
};
int directions[][3] =
{
	{7, 1, 6}, {5, 3, 7}, {4, 5, 3}, {2, 4, 5}, {6, 2, 4}, {3, 1, 4}, {7, 6, 4}, {7, 0, 6}, {5, 7, 6}, {5, 2, 1},
	{0, 5, 6}, {4, 6, 7}, {4, 0, 5}, {6, 7, 5}, {6, 4, 0}, {7, 6, 4}, {7, 5, 2}, {3, 4, 6}, {5, 6, 7}, {4, 1, 5}
};


void showMap() {
	for (int i = 0; i < 30; i++) {
		cout << map[i] << "\n";
	}
	cout << "\n";
	
}

int main() {
	Location* locations = new Location[21];
	ifstream in_loc("location_info.txt");
	for (int i = 0; i < 20; i++) {
		string description;
		getline(in_loc, description);
		locations[i + 1].setName(to_string(i + 1));
		locations[i + 1].setDescription(description);
		locations[i + 1].setAdj(edges[i][0], edges[i][1], edges[i][2], directions[i][0], directions[i][1], directions[i][2]);
	}
	Player*player = new Player("p1",1);
	player->setLocation(1);

	srand(time(NULL));

	Pit*pit1 = new Pit(rand()%20+1);
	Pit* pit2 = new Pit(rand()%20+1);
	// set Hazard: pits

	SuperBats* bats1 = new SuperBats(rand()%20+1);
	SuperBats* bats2 = new SuperBats(rand() % 20 + 1);

	// set Hazard: Super Bats

	Wumpus* wumpus = new Wumpus(rand() % 20 + 1);
	//set Hazard: Wumpus
	
	int magicArrow = 5;
	// set lanter and arrow

	Vendor* vendor = new Vendor(1);
	//set vendor in 1st cave
	
	Rope* rope = new Rope(5);

	Golds* golds = new Golds();
	golds->set();


	

	ifstream in_game("game_info.txt");
	string game_info_st;
	while (getline(in_game, game_info_st)) {
		cout << game_info_st << "\n";
	}

	char ch = getchar();
	int turnRound = 0;
	while (player->isAlive()&&player->getOil()>=0 && wumpus->isalive()&&magicArrow>=0) {
		system("cls");
		string opt;
		locations[player->getLocation()].printAdj();
		golds->add(player);
		
		rope->showMeau(player);// display item in meau
		if (player->getOil()==0)
		{
			cout << "\n Lantern oil run out of charge!!" << endl;
			break;
		}
		if (magicArrow == 0) {
			cout << "\n Magic arrow run out of charge!!" << endl;
			break;
		}

		
		for (int i = 0; i < 3; i++) {
			if (edges[player->getLocation() - 1][i] == pit1->getCaveId()|| edges[player->getLocation() - 1][i] == pit2->getCaveId()) {
				cout << "Hazard: You feel a draft."  << endl;
			}// check the pits

			if (edges[player->getLocation() - 1][i] == bats1->getCaveId() || edges[player->getLocation() - 1][i] == bats2->getCaveId()) {
				cout << "Hazard: Sounds like Super Bats nearby" << endl;
			}// check super bats

			if (edges[player->getLocation() - 1][i] == wumpus->getCaveId()) {
				cout << "Hazard: You smell a Wumpus" << endl;
			}// check wumpus
			
	
		}
		cout << "\n lantern oil left: " << player->getOil() << endl;
		cout << "\n Magic Arrow left: " << magicArrow << endl;
		cout << "\n Current gold: " << player->getCurrentGold() << endl;
		if (player->getLocation() == vendor->getcaveId()) {
			vendor->run(player);
			vendor->roaming(rand() % 20 + 1); //vendor will change the place after player buy the item.
		
		}

		cout << "Shoot the magic arrow to: " << "\n";
		for (int i = 0; i < 3; i++)
		{
			cout << "[" << edges[player->getLocation() - 1][i] << "]" << "cave" << "\n";
		}
		if (turnRound == 5 || turnRound == 15 || turnRound == 20 || turnRound == 25 || turnRound == 30) {
			wumpus->move(edges[wumpus->getCaveId() - 1][rand() % 3]);
			cout << "\nWumpus moved!" << endl;
		} //Moved Wumpus after 5 turns


		cout << "\nPlease input next action: ";
		cin >> opt;

		for (int i = 0; i < 3; i++) 
			{
				if (opt == to_string(edges[player->getLocation() - 1][i]))
				{
					if (opt == to_string(wumpus->getCaveId())) {
						wumpus->isdead();
						cout << "Wumpus Hunt£¡£¡" << endl;
						break;
					}
					else
					{
						cout << "You missed your shoot" << endl;
						wumpus->move(edges[wumpus->getCaveId() - 1][rand() % 3]);

						if (player->getLocation() == wumpus->getCaveId()) {
							wumpus->killPlayer(player);
							cout << "You become Wumpus's lunch£¡" << endl;
							break;
						}
					}
					magicArrow -= 1;
				}
			}
		if (opt == "Q") {
			break;
		}
		if (opt == "M") {
			char ch = getchar();
			showMap();
			cout << "Press any key to continue.\n";
			ch = getchar();
			if (ch == 'Q') {
				break;
			}
		}
		
		
		
		else {
			int dir = -1;
			for (int i = 0; i < 8; i++) {
				if (opt == directions_map[i]) {
					dir = i;
					break;
				}
			}
			if (dir == -1) {
				char ch = getchar();
				ch = getchar();
				if (ch == 'Q') {
					break;
				}
			}
			else {
				char ch = getchar();
				int new_location = locations[player->getLocation()].getAdj(dir);
				if (new_location == -1) {
					cout << "Cannot go to this direction, try again!\n";
				}
				else {
					player->setLocation(new_location);
					if (player->getLocation()==pit1->getCaveId()|| player->getLocation() == pit2->getCaveId())
					{
						if (!player->hasRope()) {
							pit1->fall(player);
							cout << " You falling to the pit!!" << endl;
						}
						else
						{
							cout << "You falling to the pit but you use the rope to climb out of it!" << endl;
						}

					}// step on pit

					if (player->getLocation() == bats1->getCaveId() || player->getLocation() == bats2->getCaveId()) {
						bats1->carryPlayer(player,rand()%20+1);
						cout << "You were taken away by the bat swarm" << endl;
					}//step on bats
					if (player->getLocation() == wumpus->getCaveId()) {
						wumpus->killPlayer(player);
						cout << "You become Wumpus's lunch£¡" << endl;
					}// step on wumpus

					
					else {
						cout << "\nGo to new location " << locations[new_location].getName() << "\n";
						player->subOil();
						turnRound += 1;
					}
				}
				cout << "\nPress any key to continue.\n";
				ch = getchar();
				if (ch == 'Q') {
					break;
				}
			}
		}
	}
	if (!wumpus->isalive()) {
		cout << "\nWIN\n";
		if (turnRound <= 5 || magicArrow >= 4) {
			cout << "\nScore:  S" << endl;
		}
		else if(turnRound <= 10 || magicArrow >= 3) {
			cout << "\nScore:  A" << endl;
		}

		else if (turnRound <= 15 || magicArrow >= 2) {
			cout << "\nScore:  B" << endl;
		}

		else if (turnRound <= 20 || magicArrow >= 1) {
			cout << "\nScore:  C" << endl;
		}// scoring system
	}
	else
	{
		cout << "\nGame Over!\n";
	}
	
	return 0;
}