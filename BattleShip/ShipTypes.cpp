#include <iostream>
#include <string>

using namespace std;

class ShipTypes
{
private:
	string fname;
	int fnum{},fid{};
public:
	ShipTypes(string name, int num, int id) : fname{ name }, fnum{ num }, fid{ id }
	{}
};
