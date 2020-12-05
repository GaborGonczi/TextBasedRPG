#pragma once
#include <iostream>
#include <string>
#include "ActionType.h"
#include "InformationForSubPhraser.h"
#include "DataStructure.h"
#include "PlayerDataStructure.h"
#include "EnemyDataStructure.h"
namespace Game {
	class CommandInterpreter
	{
	public:
		CommandInterpreter();
		CommandInterpreter(int sizeWhereCommandIsRun);
		CommandInterpreter(const CommandInterpreter*other);
		std::string inputYourCommand();
		std::string generateCommand();
		void Checker(std::string commmand);
		DataStructure*getData();
		~CommandInterpreter();
	private:
		//InformationForSubPhraser info;
		int sizeWhereCommandIsRun;
		DataStructure*data;
		int commandSize(std::string command);
		bool isGoodCharacter(char tokenCharacter);
		bool isCommandShort(std::string command, int minvalue);
		bool tokenChecker(std::string tokenString);
		std::string * Phraser(std::string command);
		InformationForSubPhraser & subPhraser(InformationForSubPhraser & info);
		bool argumentChecker(std::string * arguments, int size);
		ActionType commandTypeForEnemy(std::string type);
		ActionType commandTypeForPlayer(std::string type);
		int * argumentsConverter(std::string * arguments, int size);


	};
}
