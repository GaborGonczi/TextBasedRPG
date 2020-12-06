#ifndef TABLE_H
#define TABLE_H
#include <iomanip>
#include <vector>
#include "HexagonField.h"
#include "ActionType.h"
#include "PlayerCharacter.h"
#include "Enemy.h"
#include "Coordinate.h"
#include "EnemyCannotAttackThePlayerException.h"
#include "EnemyCannotStepHereException.h"
#include "EnemyMissedDamageException.h"
#include"PlayerInvalidTargetException.h"
#include"PlayerMissedTargetException.h"
#include"PlayerCannotStepHereException.h"
#include "DataStructure.h"
#include "PlayerDataStructure.h"
#include "EnemyDataStructure.h"

namespace Game {
	class Table
	{
	public:
		Table();
		Table(int height, int width);
		Table(const Table*other);
		void setEnemies(std::vector<Enemy*> enemies);
		void setPlayer(PlayerCharacter*player);
		void reciveData(DataStructure* executable);

		void printTable();
		~Table();
	private:
		int height;
		int width;
		HexagonField** fields;
		std::vector<Enemy*>enemies;
		PlayerCharacter*player;
		DataStructure* local_data;
		/*Functions*/

		void commandExecuterForPlayer(PlayerDataStructure*executable);
		void commandExecuterForEnemy(EnemyDataStructure*executable);

		void playerNextAction(PlayerDataStructure*data);

		bool isTheFoundTarget(Coordinate targetCoordinate, int target);
		void nextATK(PlayerCharacter* p, Coordinate atkCoordinate);
		void nextSTP(PlayerCharacter*p, Coordinate previous, Coordinate target);
		bool isValidTargetforThisActionTypeForPlayer(ActionType actionType, Coordinate choicedCoordinate);

		void oneEnemyNextAction(EnemyDataStructure* data);

		void enemyNextATK(Enemy * e, Coordinate atkcoordinate);
		void enemyNextSTP(Enemy * e, Coordinate previous, Coordinate target);
		bool isValidTargetforThisActionTypeForEnemy(ActionType actionType, Coordinate choicedCoordinate);

		HexagonField getFieldByCoordinate(Coordinate getByThis);

		void print_one_line(int whichline, int width, int whichpart);
		Coordinate normalizeCoordinate(Coordinate actual, Coordinate previous);
		void initializeAllEnemiesPositionOnTable();
		void initializeOneFighterPositionOnTable(Character * ch);
	};
}
#endif