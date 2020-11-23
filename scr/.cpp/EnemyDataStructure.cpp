#include "EnemyDataStructure.h"


namespace Game {
	EnemyDataStructure::EnemyDataStructure()
	{
	}

	EnemyDataStructure::EnemyDataStructure(ActionType type, int * argumentsAsInt, int argumetsAsIntSize) :DataStructure(type, argumentsAsInt, argumetsAsIntSize)
	{
	}

	EnemyDataStructure::EnemyDataStructure(const EnemyDataStructure * other) : DataStructure(other)
	{
		this->enemyCharacter = new Enemy(other->enemyCharacter);
	}

	void EnemyDataStructure::setEnemy(Enemy * e)
	{
		enemyCharacter = e;
	}

	void EnemyDataStructure::function()
	{
	}

	Enemy * EnemyDataStructure::getEnemy()
	{
		return enemyCharacter;
	}


	EnemyDataStructure::~EnemyDataStructure()
	{
		delete enemyCharacter;
	}
}