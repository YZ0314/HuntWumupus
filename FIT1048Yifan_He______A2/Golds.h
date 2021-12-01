#pragma once
#ifndef GOLD_H
#define GOLD_H
#include<ctime>
#include <string>
#include <iostream>
#include"Player.h"
using namespace std;
class Golds
{
	

public:
	Golds();
	~Golds();
	int location[10];
	void  set();
	void add(Player*player);

};
#endif // !GOLD_H


