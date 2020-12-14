#ifndef PLAYER_CHARACTER_H
#define PLAYER_CHARACTER_H
#include "Character.h"
namespace Game {
	class PlayerCharacter :
		public Character
	{
	public:
		/*Constructors*/
		PlayerCharacter();
		PlayerCharacter(std::string name, int hp, int atk, int def, int money, Armor* armor = nullptr, Weapon* weapon = nullptr, int inwhichunit = 1, int InWhichFieldInFight = -1,
			int InWhichFieldInFight_YCoordinate = -1, int InWhichFieldInFight_XCoordinate = -1, int radiusOfAction = 1, int radiusOfStep = 1, int whereNext = -1);
		PlayerCharacter(const PlayerCharacter*other);
		/*Destructor*/
		~PlayerCharacter();
		/*Setters*/

		/*Getters*/

		/*Overrided Finctions*/
		int getInWhichUnit();
	private:
	};
}
#endif // !PLAYER_CHARACTER_H