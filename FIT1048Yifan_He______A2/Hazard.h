#pragma once
#ifndef HAZARD_H
#define HAZARD_H
#include <iostream>
#include <string>
#include<sstream>
using namespace std;

class Hazard
{
protected:
	int cave_id;
public:
	Hazard(int id);
	~Hazard();
	int getCaveId();
	void setCaveId(int id);
};

#endif // !HAZRD_H


