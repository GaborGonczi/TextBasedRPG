#pragma once
#include "DataStructure.h"
#include "PlayerCharacter.h"
namespace Game {
	class PlayerDataStructure :
		public DataStructure
	{
	public:
		PlayerDataStructure();
		PlayerDataStructure(ActionType type, int*argumentsAsInt, int argumentsAsIntSize);
		PlayerDataStructure(const PlayerDataStructure*other);
		void setPlayer(PlayerCharacter*p);
		void function();
		PlayerCharacter*getPlayerCharacter();
		~PlayerDataStructure();
	private:
		PlayerCharacter*playerCharacter;
	};
}
