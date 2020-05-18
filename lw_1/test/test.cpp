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
		cerr << "input error. Try: test.exe lw_1.exe input.txt";
		return 1;
	}

	ifstream fileInput(argv[2]);

	if (!fileInput.is_open())
	{
		cerr << "This file does not exist" << endl;
		return 1;
	}

	string line;

	ofstream fileOutput("test_result.txt");

	int i = 1;

	while (getline(fileInput, line))
	{
		string sideA, sideB, sideC, str1, str2, expectedResult, result;

		istringstream iss(line);

		iss >> sideA >> sideB >> sideC >> str1 >> str2;

		const string SPACEBAR = " ";

		expectedResult = str1 + SPACEBAR + str2 + "\n";

		string triangleSideStr = SPACEBAR + sideA + SPACEBAR + sideB + SPACEBAR + sideC;

		result = RunExternalProgram(string(argv[1] + triangleSideStr).c_str());



		fileOutput << i << SPACEBAR << (result == expectedResult ? "done" : "error") << endl;
		
		

		cout << i <<SPACEBAR << (result == expectedResult ? "done" : "error") << endl;
		
		++i;
	}


	return 0;
}