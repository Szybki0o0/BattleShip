#include <iostream>
#include <string>

using namespace std;

class Player
{
private:
	string fname;
	int fboardId;
	bool fturn;
public:
	Player(string name, int boardId, bool turn = false) : fname{ name }, fboardId{ boardId }, fturn{ turn }
	{}

	int getBoardId(void) const { return fboardId; }
	string getName(void) const { return fname; }

	void setboardId(int boardId) { fboardId = boardId; }
	void setName(string name) { fname = name; }

};
