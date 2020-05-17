#include "pch.h"
#include "carClass.h"
#include <string>


carClass::carClass()
{
}


carClass::~carClass()
{
}

carClass::status carClass::GetEngineStatus()const
{
	return m_status;
}

int carClass::GetSpeed()const
{
	return m_speed;
}

int carClass::GetGear()const
{
	return m_gear;
}

carClass::direction carClass::GetDirection() const
{
	return m_direction;
}

carClass::result carClass::testGear(int speed, int gear)
{
	if (( speed >= 0 && speed <= 30) && (gear == 1))
	{
		return success;
	}
	else if ((speed >= 20 && speed <= 50) && (gear == 2))
	{
		return success;
	}
	else if ((speed >= 30 && speed <= 60) && (gear == 3))
	{
		return success;
	}
	else if ((speed >= 40 && speed <= 90) && (gear == 4))
	{
		return success;
	}
	else if ((speed >= 50 && speed <= 150) && (gear == 5))
	{
		return success;
	}
	else if ((speed >= 0 && speed <= 20) && (gear == -1))
	{
		return success;
	}
	else if (gear == 0)
	{
		return success;
	}
	else 
	{
		return error;
	}
}


carClass::result carClass::turnOnEngine()
{
	/*
	if (m_speed != 0)
	{
		m_result = error;
	}
	*/
	
	if (m_status == on)
	{
		return error;
	}

	m_status = on;
	return success;
}

carClass::result carClass::turnOffEngine()
{
	if (m_speed != 0 || m_gear != 0)
	{
		return error;
	}
	else
	{ 
		if (m_status == off)
		{
			return error;
		}
		else
		{
			m_status = off;
			return success;
		}
	}
}

carClass::result carClass::SetSpeed(int speed)
{
	
	if (m_status == on)
	{
		if (testGear(speed, m_gear) == success && (m_gear != 0 || speed < m_speed))
		{
			m_speed = speed;
			if (m_speed == 0)
			{
				m_direction = holding;
			}
			else
			{
				if (m_gear == -1)
				{
					m_direction = back;
				}
				else
				{
					m_direction = front;
				}
			}
			return success;
		}
		else
		{
			return error;
		}
	}
	else
	{
		return error;
	}
}

carClass::result carClass::SetGear(int gear)
{
	if (m_status == on)
	{
		if (testGear(m_speed, gear) == success && (gear != -1 || m_speed == 0) && (m_direction != back || gear <= 0))
		{
			m_gear = gear;
			return success;
		}
		else
		{
			return error;
		}
	}
	else
	{
		return error;
	}
}

