#ifndef PLAYER_DATA_STRUCTURE_H
#define PLAYER_DATA_STRUCTURE_H
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
#endif // !PLAYER_DATA_STRUCTURE_H


