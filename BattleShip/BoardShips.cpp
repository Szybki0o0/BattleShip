#pragma once

#include <iostream>
#include <vector>
#include "Ship.cpp"

using namespace std;

class BoardShips
{
private:
	int fid{}, fdim{};
	vector<vector<int>> fboardShips;
public:
	BoardShips(int id, int dim = 10) :
		fid{ id }, fdim{ dim }, fboardShips{ createBoardShips() }
	{}

	// gets and sets
	int getId(void) const { return fid; }
	int getDim(void) const { return fdim; }
	vector<vector<int>> getBoardShips(void) const { return fboardShips; }

	void setId(int id) { fid = id; }

	vector<vector<int>> createBoardShips() // creating board scheme
	{
		vector<vector<int>> board;

		board.resize(getDim());
		for (int i = 0; i < getDim(); i++)
		{
			board[i].resize(getDim());
		}
		for (int i = 0; i < size(board); i++)
		{
			for (int j = 0; j < size(board); j++)
			{
				board[i][j] = 0;
			}
		}

		return board;
	}

	void addShip(Ship ship) { // adding ships to vector
		int shippStartPositionX = ship.getPositionX();
		int shippStartPositionY = ship.getPositionY();

		for (int i = shippStartPositionX; i < shippStartPositionX + ship.getSizeX(); i++)
		{
			for (int j = shippStartPositionY; j < shippStartPositionY + ship.getSizeY(); j++)
			{
				fboardShips[i][j] = 1;
			}
		}
	}

	int getFieldState(int positionX, int positionY) { // getting whats on field
		return fboardShips[positionX][positionY];
	}

	bool isShipOnField(int positionX, int positionY) { // checking whats on the field

		if (getFieldState(positionX, positionY) == 1 || getFieldState(positionX, positionY) == 2) {
			return true;
		}
		else {
			return false;
		}
	}

	void changeFieldState(int positionX, int positionY) { // changing state of logic board
		if (isShipOnField(positionX, positionY)) {
			fboardShips[positionX][positionY] = 2;
		}
		else {
			fboardShips[positionX][positionY] = 3;
		}
	}

	bool isEnd() // checking if logic board is empty of ships
	{
		for (auto i : fboardShips)
		{
			for (auto j : i)
			{
				if (j == 1) return false;
			}
		}
		return true;
	}

	void showBoardShips() { // printing board
		for (int i = 96; i < 107; i++)
		{
			if (i == 96) cout << "   ";
			else if (i < 106) cout << char(i) << " ";
			else cout << char(i) << endl;
		}
		int count = 1, row = 2;
		for (auto i : getBoardShips())
		{
			for (auto j : i)
			{
				if (count == 1) cout << 1 << "  ";
				if (count % 10 == 0)
				{
					if (row == 10) cout << j << "\n" << 10 << " ";
					else if (row == 11) cout << j;
					else cout << j << "\n" << row << "  ";
					row++;
				}
				else cout << j << " ";
				count++;
			}
		}
		cout << "\n\n";
	}
};