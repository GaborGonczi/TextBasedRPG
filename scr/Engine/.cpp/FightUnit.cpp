#include "FightUnit.h"
namespace Game {
	FightUnit::FightUnit() {}

	FightUnit::FightUnit(int WU, std::string path, std::vector<int>WATN, std::vector<Enemy*>enemies, int height, int width) :GameUnit(WU, path, WATN),enemies(enemies), height(height), width(width)
	{


		anotherTable = new Table(height, width);
		anotherTable->setEnemies(enemies);
	}

	FightUnit::FightUnit(const FightUnit * other)

	{
		this->height = other->height;
		this->width = other->width;
		this->whereAbleToNext = other->whereAbleToNext;
		this->path = other->path;
		this->player = other->player;
		this->whichunit = other->whichunit;
		this->anotherTable = new Table(other->anotherTable);
		this->enemies = other->enemies;
	}

	FightUnit::~FightUnit()
	{
		for (Enemy*e : enemies)
		{
			delete e;
		}
		delete anotherTable;

	}

	void FightUnit::playerEntry(PlayerCharacter * p)
	{
		player = p;
		player->setInWhichUnit(getWhichUnit());
		anotherTable->setPlayer(player);

	}

	/*void FightUnit::createEnemiesVector(std::map<Enemy*, int> enemiesByName)
	{
		typedef std::map<Enemy*, int>::iterator It;
		int cumulate = 0;
		for (It it = enemiesByName.begin(); it != enemiesByName.end(); ++it)
		{
			for (int i = 0; i < it->second; i++)
			{
				enemies.push_back(new Enemy(it->first));
			}
		}
	}*/

	void FightUnit::localGame()
	{
		readTheSection();
		Fight();
	}

	PlayerCharacter* FightUnit::playerExit()
	{
		return player;
	}




	void FightUnit::Fight()
	{
		bool exception_caught = true;
		CommandInterpreter c(height*width);
		bool playerTurn = true;
		anotherTable->printTable();
		printCharactersState();
		std::string cmd;
		DataStructure* data = nullptr;
		do {

			try
			{
				if (playerTurn) {
					std::cout << "Player turn!" << std::endl;
					cmd = c.inputYourCommand();
					cmd = "[P]" + cmd;
					c.Checker(cmd);
					data = c.getData();
					if (dynamic_cast<PlayerDataStructure*>(data) != nullptr) {
						PlayerDataStructure*pdata = dynamic_cast<PlayerDataStructure*>(data);
						pdata->setPlayer(player);
						sendData(pdata);
					}



				}
				else
				{
					std::cout << "Enemies turn!" << std::endl;
					std::cout << std::setfill('-') << std::setw(160);
					std::cout << '-' << std::endl;
					for (int i = 0; i < enemies.size(); i++)
					{
						cmd = c.generateCommand();
						cmd = "[E]" + cmd;
						c.Checker(cmd);
						data = c.getData();
						if (dynamic_cast<EnemyDataStructure*>(data) != nullptr) {
							EnemyDataStructure*edata = dynamic_cast<EnemyDataStructure*>(data);
							edata->setEnemy(enemies[i]);
							sendData(edata);
						}

					}


				}
				exception_caught = false;
			}
			catch (const PlayerCannotStepHereException&e) {
				std::cout << e.what() << std::endl;
				playerTurn = true;
			}
			catch (const PlayerInvalidTargetException&e) {
				std::cout << e.what() << std::endl;
				playerTurn = true;
			}
			catch (const PlayerMissedTargetException&e) {
				std::cout << e.what() << std::endl;
				playerTurn = true;
			}
			catch (const EnemyCannotAttackThePlayerException&e) {
				std::cout << e.what() << std::endl;
			}
			catch (const EnemyCannotStepHereException&e) {
				std::cout << e.what() << std::endl;
			}
			catch (const EnemyMissedDamageException&e) {
				std::cout << e.what() << std::endl;
			}
			catch (const std::exception&e) {
				std::cout << e.what() << std::endl;
				playerTurn = true;
			}
			if (!exception_caught) {
				playerTurn = !playerTurn;
				anotherTable->printTable();
				printCharactersState();
			}


		} while (someEnemyIsAlive() && player->isAlive());
		if (player->isAlive()) {
			std::cout << "Nyertel" << std::endl;
		}
		else {
			std::cout << "Meghaltal" << std::endl;
		}
	}
	void FightUnit::sendData(DataStructure*data)
	{
		anotherTable->reciveData(data);
	}
	/*void FightUnit::readTheSection()
	{
		std::ifstream in(path);
		std::string line = "";
		if (in.is_open()) {
			do
			{
				std::getline(in, line);
				std::cout << line << std::endl;
			} while (!in.eof());
			in.close();
		}
	}*/

	int FightUnit::getWhichUnit()
	{
		return whichunit;
	}

	bool FightUnit::someEnemyIsAlive()
	{
		int db = 0;
		for (Enemy*e : enemies)
		{
			if (e->isAlive()) {
				db++;
				if (db > 0) {
					return true;
				}
			}
		}
		return false;
	}

	void FightUnit::printCharactersState()
	{
		std::cout << "Name"; std::cout << '\t' << '\t' << '\t' << "Health Point" << '\t' << "Attack value" << '\t' << '\t' << "Defense value" << '\t' << '\t' << "Weapon type" << '\t' << '\t' << "Armor type" << '\t' << '\t' << "Where is the character" << std::endl;
		std::cout << std::setfill('-') << std::setw(160);
		std::cout << '-' << std::endl;
		std::cout << "Jatekos: " << std::endl;
		if (player->isAlive()) {
			std::cout << player->toStringCharacterStatus() << std::endl;
		}
		std::cout << "Ellenfelek: " << std::endl;
		for (Enemy*e : enemies) {
			if (e->isAlive()) {
				std::cout << e->toStringCharacterStatus() << std::endl;
			}
		}
		std::cout << std::setfill('-') << std::setw(161);
		std::cout << '-' << std::endl;
	}
}