#pragma once
#include "Player.h"

Player::Player(string name, int hp) {
	location_id = 0;
	setHealthPoint(hp);
	setName(name);
	this->current_gold = 0;
	this->lanternOil = 20;
	this->rope = false;
}
int Player::getLocation() {
	return this->location_id;
}

void Player::setLocation(int new_id) {
	this->location_id = new_id;
}

void Player::setHealthPoint(int hp) {
	this->healthPoint = hp;
}
int Player::getHealthPoint() {
	return this->healthPoint;
}
bool Player::isAlive() {
	if (this->getHealthPoint()>0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
string Player::getName() {
	return this->name;

}

void Player::setName(string name) {
	this->name = name;
}

void Player::setCurrentGold(int gold) {
	this->current_gold = gold;
}
int Player::getCurrentGold() {
	return this->current_gold;
}
void Player::spendGold(int gold) {
	this->current_gold -= gold;
}

void Player::activeRope() {
	this->rope = true;
}

bool Player::hasRope() {
	return this->rope;
}

void Player::addGold() {
	this->current_gold += 1;
}
void Player::addOil(int e) {
	this->lanternOil += e;
}
void Player::subOil() {
	this->lanternOil -= 1;
}
int Player::getOil() {
	return this->lanternOil;
}