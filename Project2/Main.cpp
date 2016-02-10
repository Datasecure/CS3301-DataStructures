#include <iostream>
#include <sstream>
#include <fstream>
#include "ExpressionNotationConverter.h"

using namespace std;

int main()
{
	string filename = "C:\\infix.txt";
	ifstream fs(filename);
	string line;

	while (!fs.eof())
	{
		fs >> line;
		cout << ExpressionNotationConverter::ConvertInfixToPostfix(line) << endl;
	}

	cin.get();

	return 0;
}