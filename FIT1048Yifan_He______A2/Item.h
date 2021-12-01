#pragma once
#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include <string>
#include<sstream>
class Item
{
protected:
	int cost;
public:
	Item(int cost);
	~Item();
};

#endif // !ITEM_H



