#ifndef ENEMY_H
#define ENEMY_H
#include "Character.h"
namespace Game {
	class Enemy :
		public Character
	{
	public:
		/*Constructors*/
		Enemy();
		Enemy(std::string name, int hp, int atk, int def, int money, Armor* armor = nullptr, Weapon*weapon = nullptr, int inwhichunit = 1, int InWhichFieldInFight = -1,
			int InWhichFieldInFight_YCoordinate = -1, int InWhichFieldInFight_XCoordinate = -1, int radiusOfAction = 1, int radiusOfStep = 1);
		Enemy(const Enemy*other);
		/*Destructor*/
		~Enemy();
		/*Overrided Functions*/
		int getInWhichUnit();
	};
}
#endif // !ENEMY_H