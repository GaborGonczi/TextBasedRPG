#include "DataStructure.h"


namespace Game {
	DataStructure::DataStructure()
	{
	}

	DataStructure::DataStructure(ActionType type, int* argumentsAsInt, int argumentsAsIntSize) :type(type), argumentsAsInt(argumentsAsInt), argumentsAsIntSize(argumentsAsIntSize)
	{
	}

	DataStructure::DataStructure(const DataStructure * other)
	{
		this->type = other->type;
		this->argumentsAsIntSize = other->argumentsAsIntSize;
		this->argumentsAsInt = new int[other->argumentsAsIntSize];
		for (int i = 0; i < this->argumentsAsIntSize; i++)
		{
			this->argumentsAsInt[i] = other->argumentsAsInt[i];
		}

	}

	ActionType DataStructure::getType()
	{
		return type;
	}

	int * DataStructure::getArgumentsAsInt()
	{
		return argumentsAsInt;
	}

	int DataStructure::getArgumentsAsIntSize()
	{
		return argumentsAsIntSize;
	}


	DataStructure::~DataStructure()
	{
		delete argumentsAsInt;
	}
}