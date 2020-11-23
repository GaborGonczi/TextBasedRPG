#include "Coordinate.h"

namespace Game {

	Coordinate::Coordinate()
	{
	}

	Coordinate::Coordinate(int valueX, int valueY) :valueX(valueX), valueY(valueY)
	{
	}

	Coordinate::Coordinate(const Coordinate * other)
	{
		this->valueX = other->valueX;
		this->valueY = other->valueY;
	}


	Coordinate::~Coordinate()
	{
	}

	void Coordinate::setValueX(int newValueX)
	{
		valueX = newValueX;
	}

	void Coordinate::setValueY(int newValueY)
	{
		valueY = newValueY;
	}

	int Coordinate::getValueX()
	{
		return valueX;
	}

	int Coordinate::getValueY()
	{
		return valueY;
	}
}