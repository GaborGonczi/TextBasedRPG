#ifndef GAME_UNIT_H
#define GAME_UNIT_H
#include <fstream>
#include "PlayerCharacter.h"
namespace Game {
	class GameUnit
	{
	public:
		GameUnit();
		GameUnit(int WU, std::string path, std::vector<int>WATN);
		GameUnit(const GameUnit*other);
		virtual ~GameUnit();
		/*Getters*/
		std::vector<int> getWereAbleToNext();
		int playerChoiceFromWhereAbleToNext();
		/*Pure virtual functions*/
		virtual int getWhichUnit() = 0;
		virtual void playerEntry(PlayerCharacter*p) = 0;
		virtual PlayerCharacter* playerExit() = 0;
		virtual void localGame() = 0;
		virtual void print() = 0;
	protected:
		int whichunit;
		std::string path;
		std::vector<int>whereAbleToNext;
		void readTheSection();

	};
}
#endif // !GAME_UNIT_H