#pragma once
#ifndef SUPERBATS_H
#define SUPERBATS_H
#include "Hazard.h"
#include "Player.h"
class SuperBats : public Hazard
{
public: SuperBats(int id);
	  ~SuperBats();
	  void carryPlayer(Player*player, int carryId);


};
#endif // !SUPERBATS_H



