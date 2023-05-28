#pragma once

#include <vector>
#include "Ship.h"

using namespace std;

class Ship
{
private:
	int fid{}, fpositionX{}, fpositionY{}, fsizeX{}, fsizeY{};
	const char shipSymbol = 'Y';
public:
	Ship(int id, int positionX, int positionY, int sizeX, int sizeY) :
		fid{ id }, fpositionX{ positionX }, fpositionY{ positionY }, fsizeX{ sizeX }, fsizeY{ sizeY }
	{}

	// gets and sets
	int getId(void) const { return fid; }
	int getPositionX(void) const { return fpositionX; }
	int getPositionY(void) const { return fpositionY; }
	int getSizeX(void) const { return fsizeX; }
	int getSizeY(void) const { return fsizeY; }
	char getShipSymbol(void) const { return shipSymbol; }

	void setId(int id) { fid = id; }
	void setPositionX(int positionX) { fpositionX = positionX; }
	void setPositionY(int positionY) { fpositionY = positionY; }
	void setSizeX(int sizeX) { fsizeX = sizeX; }
	void setSizeY(int sizeY) { fsizeY = sizeY; }

};

