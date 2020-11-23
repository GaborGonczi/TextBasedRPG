#pragma once
#include "ActionType.h"
namespace Game {
	class DataStructure
	{
	public:
		DataStructure();
		DataStructure(ActionType type, int* argumentsAsInt, int argumentsAsIntSize);
		DataStructure(const DataStructure*other);
		ActionType getType();
		int*getArgumentsAsInt();
		int getArgumentsAsIntSize();
		virtual void function() = 0;
		~DataStructure();
	private:
		ActionType type;
		int*argumentsAsInt;
		int argumentsAsIntSize;

	};
}
