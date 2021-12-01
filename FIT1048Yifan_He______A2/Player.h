#ifndef PLAYER_H
#define PLAYER_H
#include<string>
using namespace std;
class Player{
private:
	int location_id;
	int healthPoint;
	int current_gold;
	int lanternOil;
	bool rope;
	string name;
public:
	Player(string name, int hp);
	int getLocation();
	void setLocation(int new_id);
	int getHealthPoint();
	void setHealthPoint(int hp);
	bool isAlive();
	void setName(string name);
	string getName();
	void setCurrentGold(int gold);
	int getCurrentGold();
	void spendGold(int gold);
	void activeRope();
	bool hasRope();
	void addGold();
	void addOil(int);
	void subOil();
	int getOil();
};
#endif // !Player.h
