#include <iostream>
#include <vector>

using namespace std;

class Board
{
private:
	int fid{}, fdim{};
	vector<vector<char>> fboard;
public:
	Board(int id, int dim = 10) :
	fid{ id }, fdim{ dim }, fboard{ createBoardField() }
	{}

	int getId(void) const { return fid; }
	int getDim(void) const { return fdim; }
	vector<vector<char>> getBoardField(void) { return fboard; }

	void setId(int id) { fid = id; }
	void setBoard(vector<vector<char>> board) { fboard = board; }

	vector<vector<char>> createBoardField()
	{
		vector<vector<char>> fboard;
		fboard.resize(getDim());

		for (int i = 0; i < getDim(); i++)
		{
			fboard[i].resize(getDim());
		}
		for (int i = 0; i < size(fboard); i++)
		{
			for (int j = 0; j < size(fboard); j++)
			{
				fboard[i][j] = 'Z';
			}
		}
	
		return fboard;
	}

	void printBoard()
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

	void changeMatrix(int x, int y, vector<vector<char>> board, vector<vector<char>> secBoard)
	{
		if (secBoard[x][y] == 'H') board[x][y] = 'X';
		else if (secBoard[x][y] == '#') board[x][y] = 'o';
		else cout << "Unknown sign";
		setBoard(board);
	}

	bool isEnd(vector<vector<char>> secBoard)
	{
		for (auto i : secBoard)
		{
			for (auto j : i)
			{
				if (j == 'H') return false;
			}
		}
		return true;
	}
};
