#include "Enemy.h"
namespace Game {
	Enemy::Enemy()
	{
	}

	Enemy::Enemy(std::string name, int hp, int atk, int def, int money, Armor*armor, Weapon*weapon, int inwhichunit, int InWhichFieldInFight,
		int InWhichFieldInFight_YCoordinate, int InWhichFieldInFight_XCoordinate, int radiusOfAction, int radiusOfStep) :
		Character(name, hp, atk, def, money, armor, weapon, inwhichunit, InWhichFieldInFight,
			InWhichFieldInFight_YCoordinate, InWhichFieldInFight_XCoordinate, radiusOfAction, radiusOfStep)
	{
	}

	Enemy::Enemy(const Enemy * other) :Character(other)
	{
	
	}

	Enemy::~Enemy()
	{

	}

	int Enemy::getInWhichUnit()
	{
		return inwhichunit;
	}
}