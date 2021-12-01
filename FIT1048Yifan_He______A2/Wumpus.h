#pragma once
#ifndef WUMPUS_H
#define	WUMPUS_H
#include"Hazard.h"
#include"Player.h"
#include<ctime>
class Wumpus :public Hazard
{
private:
	bool alive;
public:
	Wumpus(int id);
	~Wumpus();
	void killPlayer(Player* player);
	void move(int id);
	void isdead();
	bool isalive();


};


#endif // !WUMPUS_H


