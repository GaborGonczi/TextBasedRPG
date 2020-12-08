#ifndef FIGHT_UNIT_H
#define FIGHT_UNIT_H
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <iomanip>
#include <map>;
//#include<fstream>
#include "GameUnit.h"
#include "PlayerCharacter.h"
#include "Enemy.h"
#include "CommandInterpreter.h"
#include "DataStructure.h"
#include "Table.h"
#include "Coordinate.h"
namespace Game {
	class FightUnit :public GameUnit
	{
	public:
		/*Constructors*/
		FightUnit();
		FightUnit(int WU, std::string path, std::vector<int>WATN,std::vector<Enemy*>enemies, int height = 0, int width = 0);
		FightUnit(const FightUnit*other);
		/*Destructor*/
		~FightUnit();
		/*Unit Control Functions*/
		void playerEntry(PlayerCharacter*p);
		//void createEnemiesVector(std::map<Enemy*, int>enemiesByName);
		void Fight();
		void localGame();
		PlayerCharacter* playerExit();
		void sendData(DataStructure*data);
		void print();

	private:
		PlayerCharacter*player;
		int width;
		int height;
		Table* anotherTable;
		std::vector<Enemy*>enemies;

		/*Functions*/
		/*Overrided Functions*/
		int getWhichUnit();
		bool someEnemyIsAlive();
		/*Printer functions*/
		void printCharactersState();
	};
}
#endif // !FIGHT_UNIT_H