#include "GameCreator.h"
namespace Creator {
	GameCreator::GameCreator(std::vector<Game::InformationAboutNextUnit*> info) :gameUnitInformations(info)
	{
	}

	Game::Game * GameCreator::createGameFromUnitVector()
	{
		Game::Game* newGame = new Game::Game(gameUnitInformations.size());
		for (Game::InformationAboutNextUnit* i : gameUnitInformations)
		{
			if (dynamic_cast<Game::InformationAboutReadableUnit*>(i) != nullptr) {
				Game::InformationAboutReadableUnit*rtmp = dynamic_cast<Game::InformationAboutReadableUnit*>(i);
				Game::GameUnit* tmp = new Game::ReadableUnit(rtmp->whichUnit, rtmp->path, rtmp->whereAbleToNext, createAVectorFromItemMap(rtmp->itemsAndItsCount));
				newGame->addUnit(tmp);
			}
			if (dynamic_cast<Game::InformationAboutShopUnit*>(i) != nullptr) {
				Game::InformationAboutShopUnit*stmp = dynamic_cast<Game::InformationAboutShopUnit*>(i);
				Game::GameUnit* tmp = new Game::ShopUnit(stmp->whichUnit, stmp->path, stmp->whereAbleToNext, createAVectorFromItemMap(stmp->itemsAndItsCount), stmp->owner);
				newGame->addUnit(tmp);
			}
			if (dynamic_cast<Game::InformationAboutFightUnit*>(i) != nullptr) {
				Game::InformationAboutFightUnit* ftmp = dynamic_cast<Game::InformationAboutFightUnit*>(i);
				Game::GameUnit* tmp = new Game::FightUnit(ftmp->whichUnit, ftmp->path, ftmp->whereAbleToNext, createAVectorFromEnemyMap(ftmp->enemyAndItsCount), ftmp->height, ftmp->width);
				newGame->addUnit(tmp);
			}
		}
		return newGame;
	}



	GameCreator::~GameCreator()
	{


	}

	std::vector<Game::Item*> GameCreator::createAVectorFromItemMap(std::map<Game::Item*, int> input)
	{
		std::vector<Game::Item*>returnValue;
		for (std::map<Game::Item*, int>::iterator it = input.begin(); it != input.end(); ++it) {
			for (int i = 0; i < it->second; i++)
			{
				returnValue.push_back(new Game::Item(it->first));

			}
		}
		return returnValue;
	}
	std::vector<Game::Enemy*> GameCreator::createAVectorFromEnemyMap(std::map<Game::Enemy*, int> input)
	{
		std::vector<Game::Enemy*>returnValue;
		for (std::map<Game::Enemy*, int>::iterator it = input.begin(); it != input.end(); ++it) {
			for (int i = 0; i < it->second; i++)
			{
				returnValue.push_back(new Game::Enemy(it->first));

			}
		}
		return returnValue;
	}
}