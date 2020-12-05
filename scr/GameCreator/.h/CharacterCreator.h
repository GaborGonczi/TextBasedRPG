#pragma once
#include <PlayerCharacter.h>
class CharacterCreator
{
public:
	CharacterCreator();
	Game::PlayerCharacter* getPlayerCharacter();
	~CharacterCreator();

private:
	Game::PlayerCharacter*globalPlayer;
};

