#ifndef HEXAGON_FIELD_H
#define HEXAGON_FIELD_H
#include <iostream>
#include <string>
#include "Character.h"
#include "PlayerCharacter.h"
#include "Enemy.h"
namespace Game {
	class HexagonField
	{
	public:
		/*Constructor*/
		HexagonField();
		HexagonField(const HexagonField*other);
		/*Destructor*/
		~HexagonField();
		/*Setters*/
		void setXCoordinate(int x);
		void setYCoordinate(int y);
		void setFieldNumber(int number);
		void setFieldInformation(int row, int column, std::string information);
		bool setCharacterToThisField(Character*ch);
		/*Getters*/
		int getXCoordinate();
		int getYCoordinate();
		int getFieldNumber();
		Character*getCharacterFromThisField();
		/*Print Functions*/
		void printUp();
		void printMiddle();
		void printDown();
		/*field controller*/
		void normalizeField(int maximumSize);
	private:
		std::string**field;
		int fieldNumber;
		int yCoordinate;
		int xCoordinate;
		Character* characterInThisField;
		/*Functions*/
		std::string normalizeFieldNumber(int maximumSize);
	};
}
#endif // !HEXAGON_FIELD_H