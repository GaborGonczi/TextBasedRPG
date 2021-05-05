#ifndef ENEMY_DATA_STRUCTURE_H
#define ENEMY_DATA_STRUCTURE_H
#include "DataStructure.h"
#include "Enemy.h"
namespace Game {
	class EnemyDataStructure :
		public DataStructure
	{
	public:
		EnemyDataStructure();
		EnemyDataStructure(ActionType type, int*argumentsAsInt, int argumentsAsIntSize);
		EnemyDataStructure(const EnemyDataStructure*other);
		void setEnemy(Enemy*e);
		void function();
		Enemy*getEnemy();
		~EnemyDataStructure();
	private:
		Enemy*enemyCharacter;
	};
}
#endif // !ENEMY_DATA_STRUCTURE_H



