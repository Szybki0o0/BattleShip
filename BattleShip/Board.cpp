#pragma once

#include <iostream>
#include <vector>
#include "BoardShips.cpp"

using namespace std;

class Board
{
private:
	int fid{}, fdim{};
	vector<vector<char>> fboard;
	BoardShips fboardShip;
public:
	Board(int id, BoardShips boardShip, vector<vector<char>> board = {}, int dim = 10) :
		fid{ id }, fdim{ dim }, fboard{ createBoard() }, fboardShip{ boardShip }
	{}

	// gets and sets
	int getId(void) const { return fid; }
	int getDim(void) const { return fdim; }
	BoardShips getBoardShip(void) const { return fboardShip; }
	vector<vector<char>> getBoard(void) const { return fboard; }

	void setId(int id) { fid = id; }
	void setBoardShip(BoardShips boardShip) { fboardShip = boardShip; }
	void setBoard(vector<vector<char>> board) { fboard = board; }

	vector<vector<char>> createBoard() // creating board scheme
	{
		vector<vector<char>> board;

		board.resize(getDim());
		for (int i = 0; i < getDim(); i++)
		{
			board[i].resize(getDim());
		}
		for (int i = 0; i < size(board); i++)
		{
			for (int j = 0; j < size(board); j++)
			{
				board[i][j] = '#';
			}
		}
		return board;
	}

	void changeFieldIcon(int positionX, int positionY) { // changing icon of game board
		if (fboardShip.isShipOnField(positionX, positionY)) {
			fboard[positionX][positionY] = 'X';
		}
		else {
			fboard[positionX][positionY] = 'o';
		}
	}

	void printBoard() // printing board
	{
		for (int i = 96; i < 107; i++)
		{
			if (i == 96) cout << "   ";
			else if (i < 106) cout << char(i) << " ";
			else cout << char(i) << endl;
		}
		int count = 1,row = 2;
		for (auto i : fboard)
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
