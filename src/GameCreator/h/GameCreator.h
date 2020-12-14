#pragma once
#include <string>
#include <Game.h>
#include <GameUnit.h>
#include <InformationAboutNextUnit.h>
#include <vector>
#include <fstream>
class GameCreator
{
public:
	GameCreator(std::vector<Game::InformationAboutNextUnit*> info);
	Game::Game* createGameFromUnitVector();
	~GameCreator();
private:
	std::vector<Game::InformationAboutNextUnit*> gameUnitInformations;
	std::vector<Game::Item*>createAVectorFromItemMap(std::map<Game::Item*, int>input);
	std::vector<Game::Enemy*>createAVectorFromEnemyMap(std::map<Game::Enemy*, int>input);

};

