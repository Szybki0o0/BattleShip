#include <iostream>
#include <string>
#include <vector>

using namespace std;

class ShipTypes
{
private:
	string fname;
	int fnum{},fid{};
public:
	ShipTypes(string name, int num, int id) : fname{ name }, fnum{ num }, fid{ id }
	{}

	vector<vector<char>> ones(string exp, vector<vector<char>> secBoard)
	{
		int y = int(exp[0]) - 97; 
		int x = int(exp[1] - '0') - 1;
		secBoard[x][y] = 'H';
		for (int i = x - 1; i < x+2; i++)
		{
			for (int j = y - 1; j < y+2; j++)
			{
				if (i == -1 || j == -1 || i == 10 || j == 10) continue;
				secBoard[i][j] = '*';
			}
		}
		return secBoard;
	}

	vector<vector<char>> twos(string exp, vector<vector<char>> secBoard)
	{
		int xp = int(exp[3] - '0');
		int yp = int(exp[2]) - 97;
		for (int i = 0; i < 3; i+=2)
		{
			int y = int(exp[i]) - 97;
			int x = int(exp[i+1] - '0');
			cout << x << " " << xp;
			if (y == yp /* && x != xp) || (yp == y - 1 || yp == y + 1) && (xp != x - 1 || xp != x + 1) */) secBoard[x][y] = 'H';
			//else cout << "Wrong input!!";
		}
		return secBoard;
	}
};
