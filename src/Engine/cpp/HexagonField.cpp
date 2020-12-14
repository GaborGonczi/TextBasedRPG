#include "HexagonField.h"
namespace Game {
	HexagonField::HexagonField() :characterInThisField(nullptr)
	{
		field = new std::string*[3];
		for (int i = 0; i < 3; i++)
		{
			field[i] = new std::string[3];
		}
		field[0][0] = "/";
		field[0][1] = "";
		field[0][2] = "\\";
		field[1][0] = "|";
		field[1][1] = "";
		field[1][2] = "|";
		field[2][0] = "\\";
		field[2][1] = "";
		field[2][2] = "/";
	}

	HexagonField::HexagonField(const HexagonField * other)
	{
		this->field = new std::string*[3];
		for (int i = 0; i < 3; i++)
		{
			this->field[i] = new std::string[3];
		}
		this->field[0][0] = other->field[0][0];
		this->field[0][1] = other->field[0][1];
		this->field[0][2] = other->field[0][2];
		this->field[1][0] = other->field[1][0];
		this->field[1][1] = other->field[1][1];
		this->field[1][2] = other->field[1][2];
		this->field[2][0] = other->field[2][0];
		this->field[2][1] = other->field[2][1];
		this->field[2][2] = other->field[2][2];
		if (other->characterInThisField != nullptr) {
			if (dynamic_cast<PlayerCharacter*>(other->characterInThisField) != nullptr) {
				PlayerCharacter* haveToCopy = dynamic_cast<PlayerCharacter*>(other->characterInThisField);
				this->characterInThisField = new PlayerCharacter(haveToCopy);
			}
			else if (dynamic_cast<Enemy*>(other->characterInThisField) != nullptr) {
				Enemy* haveToCopy = dynamic_cast<Enemy*>(other->characterInThisField);
				this->characterInThisField = new Enemy(haveToCopy);
			}
		}
	}

	HexagonField::~HexagonField()
	{
		for (int i = 0; i < 3; i++)
		{
			delete[] field[i];
		}
		delete[] field;
	}

	void HexagonField::setXCoordinate(int x)
	{
		xCoordinate = x;
	}

	void HexagonField::setYCoordinate(int y)
	{
		yCoordinate = y;
	}

	void HexagonField::setFieldNumber(int number)
	{
		fieldNumber = number;
	}

	void HexagonField::setFieldInformation(int row, int column, std::string information)
	{
		field[row][column] += information;
	}

	bool HexagonField::setCharacterToThisField(Character * ch)
	{
		if (characterInThisField != nullptr) {
			if (ch == nullptr) {
				characterInThisField = ch;
				return true;
			}
			return false;
		}
		characterInThisField = ch;
		return true;
	}

	int HexagonField::getXCoordinate()
	{
		return xCoordinate;
	}

	int HexagonField::getYCoordinate()
	{
		return yCoordinate;
	}

	int HexagonField::getFieldNumber()
	{
		return fieldNumber;
	}

	Character * HexagonField::getCharacterFromThisField()
	{

		return characterInThisField;
	}

	void HexagonField::printUp()
	{
		std::cout << field[0][0] <<
			field[0][1] <<
			field[0][2];
	}

	void HexagonField::printMiddle()
	{
		std::cout << field[1][0] <<
			field[1][1] <<
			field[1][2];
	}

	void HexagonField::printDown()
	{
		std::cout << field[2][0] <<
			field[2][1] <<
			field[2][2];
	}

	void HexagonField::normalizeField(int maximumSize)
	{
		std::string normalizedNumber = normalizeFieldNumber(maximumSize);
		this->field[1][1] = normalizedNumber;
		field[0][1] = field[2][1] = std::string((normalizedNumber.length()), '-');


	}

	std::string HexagonField::normalizeFieldNumber(int maximumSize)
	{
		return " " + std::string(((std::to_string(maximumSize).length() - std::to_string(fieldNumber).length())), ' ') +
			std::to_string(fieldNumber) + " ";
	}
}