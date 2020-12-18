#include "GameUnit.h"
namespace Game {
	GameUnit::GameUnit()
	{
	}

	GameUnit::GameUnit(int WU, std::string path, std::vector<int>WATN) :whichunit(WU), path(path), whereAbleToNext(WATN)
	{
	}

	GameUnit::GameUnit(const GameUnit * other)
	{
		this->whichunit = other->whichunit;
		this->path = other->path;
		this->whereAbleToNext = other->whereAbleToNext;
	}

	GameUnit::~GameUnit()
	{
	}

	std::vector<int> GameUnit::getWereAbleToNext()
	{
		return whereAbleToNext;
	}
	int GameUnit::playerChoiceFromWhereAbleToNext()
	{
		if (whereAbleToNext.size() != 0) {
			int choiceForWhereAbleToNext;
			do
			{
				std::cout << "Lapozz: ";
				std::cin >> choiceForWhereAbleToNext;
				std::cin.ignore();
				std::cin.clear();
				for (int i : whereAbleToNext)
				{
					if (i == choiceForWhereAbleToNext) {
						return choiceForWhereAbleToNext;
					}
				}
				std::cout << "Ide nem tudsz lapozni errol a reszrol" << std::endl;
			} while (true);
		}

		return this->whichunit;
	}


	void GameUnit::readTheSection()
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
		else
		{
			std::cout << "Fajl error\n";
		}
	}
}

