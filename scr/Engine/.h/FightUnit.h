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
		//int enemiesdb;
		Table* anotherTable;
		std::vector<Enemy*>enemies;

		/*Functions*/

		//void readTheSection();
		/*Overrided Functions*/
		int getWhichUnit();
		bool someEnemyIsAlive();
		/*Printer functions*/
		void printCharactersState();


		/*Initializer functions*/
		//void initializeCharactersBeforeFight();
		/*Command executer*/
		//void commandExecuter();
		/*Possibble actions for players*/
		//void nextATK(Coordinate atkCoordinate);
		//void nextSTP(Coordinate previous,Coordinate target);
		//bool isValidTargetforThisActionTypeForPlayer(ActionType actionType, Coordinate choicedCoordinate);
		//bool isTheFoundTarget(Coordinate targetCoordinate,int target);
		/*Fight loop controller*/
		//bool someEnemyIsAlive();
		/*Enemies Action controller*/
		//void enemiesAttack();
		//void oneEnemyNextAction(ActionType actionType, Enemy*e);
		//void enemyNextATK(Enemy*e, Coordinate atkcoordinate);
		//void enemyNextSTP(Enemy*e, Coordinate previous, Coordinate target);
		//bool isValidTargetforThisActionTypeForEnemy(ActionType actionType, Coordinate choicedCoordnate);
		/*Some other functions which help the class*/
		//Coordinate normalizeCoordinate(Coordinate actual, Coordinate previous);

		/*Deprecated functions*/
		//void initializeEnemiesPosition();
		//void initializePlayerPosition();
		//void print_one_line(int height, int width, int vhichline);
		//void printTable();
		//void enemyNextATK(Enemy*e, int firstCoordinate, int secondCoordinate);
		//void enemyNextSTP(Enemy*e, int previous_firstCoordinate, int previous_secondCoordinate, int firstCoordinate, int secondCoordinate);
		//void nextSTP(int previous_firstCoordinate, int previous_secondCoordinate, int firstCoordinate, int secondCoordinate);
		//void nextATK(int firstCoordinate, int secondCoordinate);
		//void normalizeCoordinate(int i, int j, int k, int l, int&firstCoordinate, int&secondCoordinate);
		//bool isValidTargetforThisActionTypeForPlayer(ActionType actionType, int firstCoordinate, int secondCoordinate);
		//bool isValidTargetforThisActionTypeForEnemy(ActionType actionType, int firstCoordinate, int secondCoordinate);
	};
}
#endif // !FIGHT_UNIT_H