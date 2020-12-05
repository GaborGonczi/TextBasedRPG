#include "PlayerCharacter.h"
namespace Game {
	PlayerCharacter::PlayerCharacter()
	{
	}

	PlayerCharacter::PlayerCharacter(std::string name, int hp, int atk, int def, int money, Armor* armor, Weapon*weapon, int inwhichunit, int InWhichFieldInFight,
		int InWhichFieldInFight_YCoordinate, int InWhichFieldInFight_XCoordinate, int radiusOfAction, int radiusOfStep, int whereNext) :
		Character(name, hp, atk, def, money, armor, weapon, inwhichunit, InWhichFieldInFight,
			InWhichFieldInFight_YCoordinate, InWhichFieldInFight_XCoordinate, radiusOfAction, radiusOfStep), whereNext(whereNext)
	{
	}

	PlayerCharacter::PlayerCharacter(const PlayerCharacter * other) :Character(other)
	{
		this->whereNext = other->whereNext;
	}

	PlayerCharacter::~PlayerCharacter()
	{
	}

	void PlayerCharacter::setWherenext(int newwherenext)
	{
		whereNext = newwherenext;
	}

	int PlayerCharacter::getWhereNext()
	{
		return whereNext;
	}

	int PlayerCharacter::getInWhichUnit()
	{
		return inwhichunit;
	}
}