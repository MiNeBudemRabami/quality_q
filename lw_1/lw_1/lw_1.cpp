#include <string>
#include <stdexcept>
#include <iostream>
#include "Const.h"

using namespace std;

struct TriangleInfo
{
	string line;
	int side;
};

bool IsCorrectNumber(TriangleInfo& triangleInfo)
{
	try
	{
		triangleInfo.side = stoi(triangleInfo.line);
	}
	catch (const invalid_argument&)
	{
		return false;
	}

	return true;
}

string CheckTriangle(const int sideA, const int sideB, const int sideC)
{
	if ((sideA + sideB > sideC) && (sideB + sideC > sideA) && (sideA + sideC > sideB))
	{
		if (sideA == sideB && sideA == sideC)
		{
			return EQUILATERAL_TRIANGLE;
		}

		if (sideA == sideB || sideA == sideC || sideB == sideC)
		{
			return ISOSCELES_TRIANGLE;
		}

		return REGULAR_TRIANGLE;
	}
	else
	{
		return NOT_TRIANGLE;
	}
}

int main(int argc, char* argv[])
{
	if (argc != 4)
	{
		cerr << "not enought arguments" << endl;
		return 1;
	}

	TriangleInfo sideTriangleA{ argv[1] };
	TriangleInfo sideTriangleB{ argv[2] };
	TriangleInfo sideTriangleC{ argv[3] };

	if (!IsCorrectNumber(sideTriangleA) || !IsCorrectNumber(sideTriangleB) || !IsCorrectNumber(sideTriangleC))
	{
		cout << UNKNOWN_ERROR << endl;
		return 1;
	}

	cout << CheckTriangle(sideTriangleA.side, sideTriangleB.side, sideTriangleC.side) << endl;

	return 0;
}