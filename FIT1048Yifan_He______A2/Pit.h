#pragma once
#ifndef PIT_H
#define PIT_H
#include <iostream>
#include <string>
#include<sstream>
#include "Hazard.h"
#include"Player.h"
using namespace std;
class Pit : public Hazard
{
public:
	Pit(int id);
	~Pit();
	void fall(Player*player);

};

#endif // !PIT_H


