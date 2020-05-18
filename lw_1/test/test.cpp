#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

string RunExternalProgram(const char* path)
{
	string str;
	char buffer[100];
	FILE* inputFile = _popen(path, "r");

	if (inputFile)
	{
		while (fgets(buffer, sizeof buffer, inputFile) != NULL)
		{
			str += buffer;
		}

		_pclose(inputFile);
	}
	return str;
}

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		cerr << "not enought args. Try test.exe program_name.exe input.txt " << endl;
	}

	else
	{
		ifstream fileInput(argv[2]);

		if (!fileInput.is_open())
		{
			cerr << "This file does not exist" << endl;
		}

		string line;

		ofstream fileOutput("test_result.txt");

		int i = 1;

		const string SPACEBAR = " ";

		while (getline(fileInput, line))
		{
			string sideA, sideB, sideC, str1, str2, expectedResult, result, triangleSideStr;

			istringstream iss(line);

			iss >> sideA >> sideB >> sideC >> str1 >> str2;

			const string SPACEBAR = " ";

			if (sideA == "Not")
			{
				expectedResult = sideA + SPACEBAR + sideB;
				triangleSideStr = SPACEBAR;
			}
			else if (sideB == "Not")
			{
				expectedResult = sideB + SPACEBAR + sideC;
				triangleSideStr = SPACEBAR + sideA;
			}
			else if (sideC == "Not")
			{
				expectedResult = sideC + SPACEBAR + str1;
				triangleSideStr = SPACEBAR + sideA + SPACEBAR + sideB;
			}
			else
			{
				expectedResult = str1 + SPACEBAR + str2;
				triangleSideStr = SPACEBAR + sideA + SPACEBAR + sideB + SPACEBAR + sideC;
			}

			result = RunExternalProgram(string(argv[1] + triangleSideStr).c_str());

			result.pop_back();

			fileOutput << i << ". " << (result == expectedResult ? "done" : "error") << endl;

			/*
			fileOutput << i << "." << triangleSideStr << SPACEBAR << expectedResult << SPACEBAR
				<< ">> " << result << SPACEBAR << (result == expectedResult ? "done" : "error") << endl;
			
			cout << i << "." << triangleSideStr << SPACEBAR << expectedResult << SPACEBAR 
				<< ">> " << result << SPACEBAR << (result == expectedResult ? "DONE" : "ERROR") << endl;
			*/
			++i;
		}
	}
}