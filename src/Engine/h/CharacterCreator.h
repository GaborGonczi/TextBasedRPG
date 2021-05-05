#ifndef CHARACTER_CREATOR_H
#define CHARACTER_CREATOR_H
#include "PlayerCharacter.h"
namespace Creator {
	class CharacterCreator
	{
	public:
		CharacterCreator();
		CharacterCreator(int hpConstant, int atkConstant, int defConstant, int moneyConstant);
		bool correctName(std::string name);
		void create();
		void printArmors();
		void printWeapons();
		Game::Armor*selectArmor(int index);
		Game::Weapon*selectWeapon(int index);
		int getIndex();

		Game::PlayerCharacter* getPlayerCharacter();
		~CharacterCreator();

	private:
		Game::PlayerCharacter*globalPlayer;
		int hpConstant;
		int atkConstant;
		int defConstant;
		int moneyConstant;
		std::vector<Game::Weapon*>basicWeapons;
		std::vector<Game::Armor*>basicArmors;
	};
}
#endif // !CHARACTER_CREATOR_H

