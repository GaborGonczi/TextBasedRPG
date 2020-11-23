#include "Game.h"


namespace Game {
	Game::Game(int gameSize):gameSize(gameSize)
	{
	}

	Game::Game(const Game * other)
	{
	}

	void Game::runGame(PlayerCharacter*Initializer_global_player)
	{
		global_player = Initializer_global_player;

		int index = 1;
		do
		{
			next = getNextGameUnit(index);
			if (dynamic_cast<ReadableUnit*>(next) != nullptr) {
				ReadableUnit*r = dynamic_cast<ReadableUnit*>(next);
				r->playerEntry(global_player);
				r->localGame();
				index = r->playerChoiceFromWhereAbleToNext();
				global_player = r->playerExit();
			}
			else if (dynamic_cast<FightUnit*>(next) != nullptr) {
				FightUnit*f = dynamic_cast<FightUnit*>(next);
				f->playerEntry(global_player);
				f->localGame();
				index = f->playerChoiceFromWhereAbleToNext();
				global_player = f->playerExit();
			}
			else if (dynamic_cast<ShopUnit*>(next) != nullptr) {
				ShopUnit*s = dynamic_cast<ShopUnit*>(next);
				s->playerEntry(global_player);
				s->localGame();
				index = s->playerChoiceFromWhereAbleToNext();
				global_player = s->playerExit();
			}

		} while (gameIsOn());
	}

	void Game::addUnit(GameUnit * added)
	{
		units.push_back(added);
	}

	Game::~Game()
	{
		for (GameUnit*g:units)
		{
			delete g;
		}
		delete global_player;
	}
	bool Game::gameIsOn()
	{
		return global_player->isAlive() && next->getWhichUnit() != gameSize;
	}

	GameUnit * Game::getNextGameUnit(int index)
	{
		return units.at(index - 1);
	}
}