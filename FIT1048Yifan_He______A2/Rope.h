#pragma once
#ifndef ROPE_H
#define ROPE_H
#include"Item.h"
#include"Player.h"
using namespace std;
class Rope :public Item
{
public:
	Rope(int cost);
	~Rope();
	void showMeau(Player*player);
};


#endif // !ROPE_H

