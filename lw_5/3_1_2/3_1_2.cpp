#include "pch.h"
#include <iostream>
#include "carClass.h"
#include <string>

using namespace std;

string printStatus(carClass::status status)
{
	if (status == carClass::off)
	{
		return "off";
	}

	if (status == carClass::on)
	{
		return "on";
	}
}

string printResult(carClass::result result)
{
	if (result == carClass::success)
	{
		return "succes";
	}

	if (result == carClass::error)
	{
		return "error";
	}
}

string printDirection(carClass::direction direction)
{
	if (direction == carClass::front)
	{
		return "moving front";
	}
	if (direction == carClass::back)
	{
		return "moving back";
	}
	if (direction == carClass::holding)
	{
		return "holding";
	}
}



int main()
{
	carClass car;

	string command;
	
	int speed = 0;

	int gear = 0;

	for(;;)
	{ 
		cin >> command;

		if ((command == "info") || (command == "status"))
		{
			cout << "engine " << printStatus(car.GetEngineStatus()) << endl;

			cout << car.GetSpeed() << " km/h"<< endl;

			cout << car.GetGear() << "'th gear" << endl;
	
			cout << printDirection(car.GetDirection()) << endl << endl;
		}

		else if ((command == "turn_on_the_engine") || (command == "on"))
		{
			cout << printResult(car.turnOnEngine()) << endl << endl;
		}

		else if ((command == "turn_off_the_engine") || (command == "off") || (command == "of"))
		{
			cout << printResult(car.turnOffEngine()) << endl << endl;
		}

		else if ((command == "close") || (command == "exit"))
		{
			break;
		}

		else if (command == "setSpeed")
		{
			cin >> speed;
			cout << printResult(car.SetSpeed(speed)) << endl << endl;
		}

		else if (command == "setGear")
		{
			cin >> gear;
			cout << printResult(car.SetGear(gear)) << endl << endl;
		}

		else
		{
			cout << "unexpected command" << endl << endl;
		}
	}
}
