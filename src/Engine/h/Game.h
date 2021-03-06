#ifndef GAME_H
#define GAME_H
#include <vector>
#include "PlayerCharacter.h"
#include "GameUnit.h"
#include"ReadableUnit.h"
#include "FightUnit.h"
#include "ShopUnit.h"
#include "InformationAboutNextUnit.h"
namespace Game {
	class Game
	{
	public:
		Game(int gameSize);
		Game(const Game*other);
		void runGame(PlayerCharacter*Initializer_global_player);
		void addUnit(GameUnit* added);
		void print();
		~Game();
	private:
		int gameSize;
		GameUnit*next;
		std::vector<GameUnit*>units;
		PlayerCharacter*global_player;
		bool gameIsOn();
		GameUnit* getNextGameUnit(int index);

	};
}
#endif // !GAME_H


