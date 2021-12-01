#pragma once
#ifndef VENDOR_H
#define VENDOR_H
#include"Rope.h"
#include"Player.h"
using namespace std;

class Vendor
{
private :
	int caveId;
public:
	void showMeau();
	Vendor(int id);
	~Vendor();
	void talk();
	void goodBye();
	int getcaveId();
	void run(Player*player);
	void roaming(int id);
	void setCaveId(int id);
};
#endif // !VENDOR_H



