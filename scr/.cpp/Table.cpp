#include "Table.h"
namespace Game {
	Table::Table()
	{
	}

	Table::Table(int height, int width) :height(height), width(width)
	{
		int fieldnumber = 1;
		fields = new HexagonField*[height];
		for (int i = 0; i < height; i++) {
			fields[i] = new HexagonField[width];
			for (int j = 0; j < width; j++) {
				fields[i][j].setFieldNumber(fieldnumber);
				fields[i][j].normalizeField((height*width));
				fields[i][j].setYCoordinate(i);
				fields[i][j].setXCoordinate(j);
				fieldnumber++;
			}
		}


	}

	Table::Table(const Table * other)
	{
		int fieldnumber = 1;
		this->height = other->height;
		this->width = other->width;
		fields = new HexagonField*[this->height];
		for (int i = 0; i < this->height; i++) {
			fields[i] = new HexagonField[this->width];
			for (int j = 0; j < width; j++) {
				fields[i][j].setFieldNumber(fieldnumber);
				fields[i][j].normalizeField((this->height*this->width));
				fields[i][j].setYCoordinate(i);
				fields[i][j].setXCoordinate(j);
				fieldnumber++;
			}
		}
	}

	void Table::setEnemies(std::vector<Enemy*> es)
	{
		enemies = es;
		initializeAllEnemiesPositionOnTable();
	}

	Table::~Table()
	{

	}

	void Table::setPlayer(PlayerCharacter * p)
	{
		player = p;
		initializeOneFighterPositionOnTable(player);
	}

	void Table::reciveData(DataStructure * executable)
	{
		local_data = executable;
		if (dynamic_cast<PlayerDataStructure*>(local_data) != nullptr) {
			PlayerDataStructure*tmp = dynamic_cast<PlayerDataStructure*>(local_data);
			commandExecuterForPlayer(tmp);
		}
		else if (dynamic_cast<EnemyDataStructure*>(local_data) != nullptr) {
			EnemyDataStructure* tmp = dynamic_cast<EnemyDataStructure*>(local_data);
			commandExecuterForEnemy(tmp);

		}
	}

	void Table::commandExecuterForPlayer(PlayerDataStructure * executable)
	{
		bool expection_caught = true;
		ActionType type = executable->getType();
		switch (type) {
		case ActionType::PlayerDoAttack:
			playerNextAction(executable);
			break;
		case ActionType::PlayerDoStep:
			playerNextAction(executable);
			break;
		case ActionType::DoNothing:
			break;
		}
	}

	void Table::commandExecuterForEnemy(EnemyDataStructure * executable)
	{
		bool expection_caught = true;
		ActionType type = executable->getType();
		switch (type)
		{
		case ActionType::EnemyDoAttack:
			oneEnemyNextAction(executable);
			break;
		case ActionType::EnemyDoStep:
			oneEnemyNextAction(executable);
			break;
		case ActionType::DoNothing:
			break;
		}


	}

	void Table::printTable()
	{
		std::cout << std::setfill('-') << std::setw(160);
		std::cout << '-' << std::endl;
		for (int i = 0; i < height; i++) {
			print_one_line(i, width, 0);
			print_one_line(i, width, 1);
			print_one_line(i, width, 2);
		}
		std::cout << std::setfill('-') << std::setw(160);
		std::cout << '-' << std::endl;
	}

	void Table::playerNextAction(PlayerDataStructure*data)
	{
		player = data->getPlayerCharacter();
		ActionType actionType = data->getType();
		int* target = data->getArgumentsAsInt();

		Coordinate checkThisAtTheMoment(-player->getRadiusOfAction(), -player->getRadiusOfAction());
		Coordinate checkThisAtLast(player->getRadiusOfAction(), player->getRadiusOfAction());
		Coordinate previous(player->getInWhichFieldInFight_XCoordinate(), player->getInWhichFieldInFight_YCoordinate());
		Coordinate targetCoordinate;
		bool succes = false;

		while (checkThisAtTheMoment.getValueY() < checkThisAtLast.getValueY() + 1 && !succes)
		{
			while (checkThisAtTheMoment.getValueX() < checkThisAtLast.getValueX() + 1 && !succes)
			{
				targetCoordinate = normalizeCoordinate(checkThisAtTheMoment, previous);
				if (isTheFoundTarget(targetCoordinate, *target)) {
					if (actionType == ActionType::PlayerDoAttack) {
						if (isValidTargetforThisActionTypeForPlayer(actionType, targetCoordinate)) {

							nextATK(player, targetCoordinate);
							succes = true;
						}
						else
						{
							throw PlayerMissedTargetException("Nem talalhato ellenfel a mezon!");
						}
					}
					else if (actionType == ActionType::PlayerDoStep) {
						if (isValidTargetforThisActionTypeForPlayer(actionType, targetCoordinate)) {

							nextSTP(player, previous, targetCoordinate);
							succes = true;
						}
						else
						{
							throw  PlayerCannotStepHereException("Ellenfel talalhato a mezon!");
						}
					}
				}
				checkThisAtTheMoment.setValueX(checkThisAtTheMoment.getValueX() + 1);
			}
			checkThisAtTheMoment.setValueX(-player->getRadiusOfAction());
			checkThisAtTheMoment.setValueY(checkThisAtTheMoment.getValueY() + 1);
		}
		if (!succes&&actionType == ActionType::PlayerDoAttack) {
			throw PlayerInvalidTargetException("A felszerelesed nem teszi lehetove ennek a mezonek a megtamadasat!");
		}
		else if (!succes&&actionType == ActionType::PlayerDoStep) {
			throw PlayerInvalidTargetException("A felszerelesed nem teszi lehetove, hogy erre a mezore lepj!");
		}
	}

	bool Table::isTheFoundTarget(Coordinate targetCoordinate, int target)
	{
		bool found = fields[targetCoordinate.getValueY()][targetCoordinate.getValueX()].getFieldNumber() == target;
		return found;
	}

	void Table::nextATK(PlayerCharacter* p, Coordinate atkCoordinate)
	{

		Enemy*e = dynamic_cast<Enemy*>(fields[atkCoordinate.getValueY()][atkCoordinate.getValueX()].getCharacterFromThisField());
		int defensevalue = e->getDef();
		int atkvalue = p->getAtk();
		bool defensvalueGreaterThanPlayerAttack = (defensevalue - atkvalue) > 0;
		int defensvaluheHowMuchGreaterThanPlayerAttack = defensevalue - atkvalue;
		if (defensevalue > 0) {
			if (defensvalueGreaterThanPlayerAttack) {
				e->setDefValue(defensvaluheHowMuchGreaterThanPlayerAttack);
			}
			else
			{
				int toHP = abs(defensvaluheHowMuchGreaterThanPlayerAttack);
				e->setDefValue(0);
				e->getDamage(toHP);
				if (!e->isAlive()) {
					fields[atkCoordinate.getValueY()][atkCoordinate.getValueX()].setCharacterToThisField(nullptr);
				}
			}
		}
		else
		{
			e->getDamage(atkvalue);
		}
	}

	void Table::nextSTP(PlayerCharacter* p, Coordinate previous, Coordinate target)
	{
		fields[target.getValueY()][target.getValueX()].setCharacterToThisField(p);
		fields[previous.getValueY()][previous.getValueX()].setCharacterToThisField(nullptr);
		int newFieldNumber = fields[target.getValueY()][target.getValueX()].getFieldNumber();
		p->setInWhichFieldInFight(newFieldNumber);
		p->setInWhichFieldInFight_YCoordinate(target.getValueY());
		p->setInWhichFieldInFight_XCoordinate(target.getValueX());
	}

	bool Table::isValidTargetforThisActionTypeForPlayer(ActionType actionType, Coordinate choicedCoordinate)
	{
		if (actionType == ActionType::PlayerDoAttack) {
			return dynamic_cast<Enemy*>(fields[choicedCoordinate.getValueY()][choicedCoordinate.getValueX()].getCharacterFromThisField()) != nullptr;
		}
		else if (actionType == ActionType::PlayerDoStep) {
			return fields[choicedCoordinate.getValueY()][choicedCoordinate.getValueX()].getCharacterFromThisField() == nullptr;
		}
	}

	void Table::oneEnemyNextAction(EnemyDataStructure* data)
	{
		Enemy*e = data->getEnemy();
		ActionType actionType = data->getType();
		int* target = data->getArgumentsAsInt();
		bool succes = false;
		int i = -e->getRadiusOfAction();
		int j = -e->getRadiusOfAction();
		int previous_firstCoordinate = e->getInWhichFieldInFight_YCoordinate();
		int previous_secondCoordinate = e->getInWhichFieldInFight_XCoordinate();
		int firstCoordinate;
		int secondCoordinate;

		Coordinate checkThisAtTheMoment(-e->getRadiusOfAction(), -e->getRadiusOfAction());
		Coordinate checkThisAtLast(e->getRadiusOfAction(), e->getRadiusOfAction());
		Coordinate previous(e->getInWhichFieldInFight_XCoordinate(), e->getInWhichFieldInFight_YCoordinate());
		Coordinate targetCoordinate;
		while (checkThisAtTheMoment.getValueY() < checkThisAtLast.getValueY() + 1 && !succes) {

			while (checkThisAtTheMoment.getValueX() < checkThisAtLast.getValueX() + 1 && !succes) {

				targetCoordinate = normalizeCoordinate(checkThisAtTheMoment, previous);
				if (isTheFoundTarget(targetCoordinate, *target)) {
					if (actionType == ActionType::EnemyDoAttack) {
						if (isValidTargetforThisActionTypeForEnemy(actionType, targetCoordinate)) {

							enemyNextATK(e, targetCoordinate);
							succes = true;
						}
						else
						{
							throw EnemyMissedDamageException("Ez az ellenfel elvetette a tamadast");
						}
					}
					else if (actionType == ActionType::EnemyDoStep) {
						if (isValidTargetforThisActionTypeForEnemy(actionType, targetCoordinate)) {

							enemyNextSTP(e, previous, targetCoordinate);
							succes = true;
						}
						else
						{
							throw EnemyCannotStepHereException("Ez az ellenfel nem tud mozdulni");
						}
					}
				}

				checkThisAtTheMoment.setValueX(checkThisAtTheMoment.getValueX() + 1);
			}
			checkThisAtTheMoment.setValueX(-e->getRadiusOfAction());
			checkThisAtTheMoment.setValueY(checkThisAtTheMoment.getValueY() + 1);
		}
	}

	void Table::enemyNextATK(Enemy*e, Coordinate atkcoordinate)
	{
		PlayerCharacter*pc = dynamic_cast<PlayerCharacter*>(fields[atkcoordinate.getValueY()][atkcoordinate.getValueX()].getCharacterFromThisField());
		int defensevalue = pc->getDef();
		int atkvalue = e->getAtk();
		bool defensvalueGreaterThanEnemyAttack = (defensevalue - atkvalue) > 0;
		int defensvaluheHowMuchGreaterThanEnemyAttack = defensevalue - atkvalue;
		if (defensevalue > 0) {
			if (defensvalueGreaterThanEnemyAttack) {
				pc->setDefValue(defensvaluheHowMuchGreaterThanEnemyAttack);
			}
			else {
				int toHP = abs(defensvaluheHowMuchGreaterThanEnemyAttack);
				pc->setDefValue(0);
				pc->getDamage(toHP);
			}
		}
		else {
			pc->getDamage(atkvalue);
		}
	}

	void Table::enemyNextSTP(Enemy*e, Coordinate previous, Coordinate target)
	{
		fields[target.getValueY()][target.getValueX()].setCharacterToThisField(e);
		fields[previous.getValueY()][previous.getValueX()].setCharacterToThisField(nullptr);
		int newFieldNumber = fields[target.getValueY()][target.getValueX()].getFieldNumber();
		e->setInWhichFieldInFight(newFieldNumber);
		e->setInWhichFieldInFight_YCoordinate(target.getValueY());
		e->setInWhichFieldInFight_XCoordinate(target.getValueX());
	}

	bool Table::isValidTargetforThisActionTypeForEnemy(ActionType actionType, Coordinate choicedCoordinate)
	{
		if (actionType == ActionType::EnemyDoAttack) {
			return dynamic_cast<PlayerCharacter*>(fields[choicedCoordinate.getValueY()][choicedCoordinate.getValueX()].getCharacterFromThisField()) != nullptr;
		}
		else if (actionType == ActionType::EnemyDoStep) {
			return fields[choicedCoordinate.getValueY()][choicedCoordinate.getValueX()].getCharacterFromThisField() == nullptr;
		}
	}

	HexagonField Table::getFieldByCoordinate(Coordinate getByThis)
	{
		return fields[getByThis.getValueY()][getByThis.getValueX()];
	}

	void Table::print_one_line(int whichline, int width, int whichpart)
	{
		for (int j = 0; j < width; j++) {
			if (whichpart == 0) {
				fields[whichline][j].printUp();
			}
			else if (whichpart == 1) {
				fields[whichline][j].printMiddle();
			}
			else {
				fields[whichline][j].printDown();
			}
		}
		std::cout << std::endl;
	}

	Coordinate Table::normalizeCoordinate(Coordinate actual, Coordinate previous)
	{
		Coordinate returnValue;
		if (previous.getValueY() + actual.getValueY() < 0) { returnValue.setValueY(0); }
		else if (previous.getValueY() + actual.getValueY() > height - 1) { returnValue.setValueY(height - 1); }
		else { returnValue.setValueY(previous.getValueY() + actual.getValueY()); }
		if (previous.getValueX() + actual.getValueX() < 0) { returnValue.setValueX(0); }
		else if (previous.getValueX() + actual.getValueX() > width - 1) { returnValue.setValueX(width - 1); }
		else { returnValue.setValueX(previous.getValueX() + actual.getValueX()); }
		return returnValue;
	}

	void Table::initializeAllEnemiesPositionOnTable()
	{
		for (Enemy*e : enemies)
		{
			initializeOneFighterPositionOnTable(e);
		}
	}

	void Table::initializeOneFighterPositionOnTable(Character * ch)
	{
		int h;
		int w;
		bool succes = false;
		do {
			h = rand() % height;
			w = rand() % width;
			if (fields[h][w].getCharacterFromThisField() == nullptr) {
				fields[h][w].setCharacterToThisField(ch);
				succes = true;
			}
		} while (!succes);
		ch->setInWhichFieldInFight(fields[h][w].getFieldNumber());
		ch->setInWhichFieldInFight_YCoordinate(h);
		ch->setInWhichFieldInFight_XCoordinate(w);
	}
}