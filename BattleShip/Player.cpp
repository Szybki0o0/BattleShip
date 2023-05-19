#include <iostream>
#include <string>
#include "Board.cpp"

using namespace std;

class Player
{
private:
	string fname;
	bool fturn;
	Board playerBoard;
public:
	Player(string name, Board board, bool turn = false) : fname{ name }, playerBoard { board }, fturn{ turn }
	{}

	string getName(void) const { return fname; }
	bool getTurn(void) const { return fturn; }
	Board getPlayerBoard(void) const { return playerBoard; }

	void setName(string name) { fname = name; }
	void setTurn(bool turn) { fturn = turn; }
	void setPlayerBoard(Board board) { playerBoard = board; }
};
