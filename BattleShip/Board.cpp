#include <iostream>
#include <vector>

using namespace std;

class Board
{
private:
	int fid{}, fdim{};
	vector<vector<char>> fboard;
	vector<vector<char>> fsecBoard;
public:
	Board(int id, vector<vector<char>> board = {}, vector<vector<char>> secBoard = {}, int dim = 10) : 
	fid{ id }, fdim{ dim }, fboard{ board }, fsecBoard{ secBoard }
	{}

	int getId(void) const { return fid; }
	int getDim(void) const { return fdim; }
	vector<vector<char>> getBoard(void) const { return fboard; }
	vector<vector<char>> getSecBoard(void) const { return fsecBoard; }

	void setId(int id) { fid = id; }
	void setBoard(vector<vector<char>> board) { fboard = board; }
	void setSecBoard(vector<vector<char>> secBoard) { fsecBoard = secBoard; }

	void createBoard(vector<vector<char>> board)
	{
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
		setBoard(board);
	}

	void createSecBoard(vector<vector<char>> board)
	{
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
		setSecBoard(board);
	}

	void printBoard(vector<vector<char>> board)
	{
		for (int i = 96; i < 107; i++)
		{
			if (i == 96) cout << "   ";
			else if (i < 106) cout << char(i) << " ";
			else cout << char(i) << endl;
		}
		int count = 1,row = 2;
		for (auto i : board)
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
		setSecBoard(secBoard);
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
