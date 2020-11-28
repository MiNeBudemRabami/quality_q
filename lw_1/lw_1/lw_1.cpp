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
	if ((sideA == 1) && (sideB == 1) && (sideC == 1))
	{
		return TOO_BIG_ARGS;
	}
	else if ((sideA + sideB > sideC) && (sideB + sideC > sideA) && (sideA + sideC > sideB))
	{
		if (sideA == sideB && sideA == sideC)
		{
			return EQUILATERAL_TRIANGLE;
		}

		if ((sideA == sideB || sideA == sideC || sideB == sideC) && (sideA != 0))
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
		cout << NOT_ENOUGH_ARGUMENTS << endl;
	}
	else 
	{
		TriangleInfo sideTriangleA{ argv[1] };
		TriangleInfo sideTriangleB{ argv[2] };
		TriangleInfo sideTriangleC{ argv[3] };

		if (!IsCorrectNumber(sideTriangleA) || !IsCorrectNumber(sideTriangleB) || !IsCorrectNumber(sideTriangleC))
		{
			cout << UNKNOWN_ERROR << endl;
		}

		else 
		{
			cout << CheckTriangle(sideTriangleA.side, sideTriangleB.side, sideTriangleC.side) << endl;
		}
	}
}