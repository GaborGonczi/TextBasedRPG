#include "ReadableUnit.h"
namespace Game {
	ReadableUnit::ReadableUnit()
	{
	}

	ReadableUnit::ReadableUnit(int WU, std::string path, std::vector<int>WATN,std::vector<Item*>FI) :GameUnit(WU, path, WATN),foundItems(FI)
	{
	}

	ReadableUnit::ReadableUnit(const ReadableUnit * other) : GameUnit(other)
	{
		this->foundItems = other->foundItems;
		this->player = other->player;
	}

	ReadableUnit::~ReadableUnit()
	{
		for (Item*i : foundItems) {
			delete i;
		}
	}

	void ReadableUnit::playerEntry(PlayerCharacter * p)
	{
		player = p;
		player->setInWhichUnit(getWhichUnit());

	}

	void ReadableUnit::localGame()
	{
		readTheSection();
		if (foundItems.size() != 0) {
			playerChoiceItems();
		}
		//int whereNext = playerChoiceFromWhereAbleToNext();
		//player->setWherenext(whereNext);
	}

	PlayerCharacter* ReadableUnit::playerExit()
	{
		return player;
	}

	/*void ReadableUnit::readTheSection()
	{
		std::string line = "";
		std::ifstream in;
		in.open(path);
		if (in.is_open()) {
			do
			{
				std::getline(in, line);
				std::cout << line << std::endl;
			} while (!in.eof());
			in.close();
		}

	}*/

	Item * ReadableUnit::getAnItemFromFoundItems(int index)
	{
		Item* tmp = foundItems.at(index - 1);
		return new Item(*tmp);
	}

	int ReadableUnit::getWhichUnit()
	{
		return whichunit;
	}

	void ReadableUnit::print()
	{
		std::cout << this->whichunit << '\n';
		this->printFoundItems();
		std::cout<<this->path<<'\n';
		for (int i : whereAbleToNext) {
			std::cout << i << '\n';
		}
	}

	void ReadableUnit::printFoundItems()
	{
		for (Item*i : foundItems)
		{
			std::cout << i->toString() << std::endl;
		}
	}

	void ReadableUnit::playerChoiceItems()
	{
		int index;
		Item*choiced;
		do
		{
			std::cout << "Valaszd ki melyik targyat szeretned elrakni. (0=kilepes)" << std::endl;
			printFoundItems();
			std::cin >> index;
			std::cin.ignore();
			std::cin.clear();
			if (index != 0) {
				choiced = getAnItemFromFoundItems(index);
				player->takeAnItemToBackPack(choiced);
				deleteAnItemFromFoundItems(index);
			}
		} while (index != 0);
	}

	void ReadableUnit::deleteAnItemFromFoundItems(int index)
	{
		foundItems.erase(foundItems.begin() + index - 1);
	}
}