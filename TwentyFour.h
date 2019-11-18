#include <iostream>
using namespace std;

class TwentyFour
{
private:
	// Feel free to add new things or change somethings
	double num[4];
	char op[3];
	int op_type;
	int SearchOp();
	int Ope(int ,int , int );
public:
	// Feel free to add new things or change somethings
	TwentyFour(){cout << "To compute 24 for " << this << " ..." << endl;}
	~TwentyFour(){cout << "Finish computation for " << this << " !" << endl;}
	int GetNums();
	int ShowResult();
};
