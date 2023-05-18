#pragma once
#include "Board.cpp"
#include "Ship.cpp"

class BoardShips :
    public Board
{
private:
    Ship *playerShip;
protected:
    Ship* getShips(void) const { return playerShip; }

    void setShip(Ship ships[10]) { ships = playerShip; }
};

