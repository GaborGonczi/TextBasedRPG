#include "PlayerDataStructure.h"


namespace Game {
	PlayerDataStructure::PlayerDataStructure()
	{
	}

	PlayerDataStructure::PlayerDataStructure(ActionType type, int * argumentsAsInt, int argumentsAsintSize) :DataStructure(type, argumentsAsInt, argumentsAsintSize)
	{
	}

	PlayerDataStructure::PlayerDataStructure(const PlayerDataStructure * other) : DataStructure(other)
	{
		this->playerCharacter = new PlayerCharacter(other->playerCharacter);
	}

	void PlayerDataStructure::setPlayer(PlayerCharacter * p)
	{
		playerCharacter = p;
	}

	void PlayerDataStructure::function()
	{
	}

	PlayerCharacter * PlayerDataStructure::getPlayerCharacter()
	{
		return playerCharacter;
	}


	PlayerDataStructure::~PlayerDataStructure()
	{
		playerCharacter = nullptr;
	}
}
