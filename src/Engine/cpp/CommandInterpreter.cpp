#include "CommandInterpreter.h"


namespace Game {
	CommandInterpreter::CommandInterpreter()
	{
	}

	CommandInterpreter::CommandInterpreter(int sizeWhereCommandIsRun) :sizeWhereCommandIsRun(sizeWhereCommandIsRun)
	{
	}

	CommandInterpreter::CommandInterpreter(const CommandInterpreter * other)
	{
		this->sizeWhereCommandIsRun = other->sizeWhereCommandIsRun;
	}

	std::string CommandInterpreter::inputYourCommand() {
		std::string command;
		do
		{
			command = "";
			std::cout << "Parancs szintaxis:[Parancs][Argumentum]<Opcoonalis argumentum>" << std::endl;
			std::cout << "Parancs: ";
			std::getline(std::cin, command);

		} while (command == "");
		return command;
	}
	std::string CommandInterpreter::generateCommand()
	{
		std::string actions[2] = { "Tamadas","Lepes" };
		int*argumentsAsInt = new int[sizeWhereCommandIsRun];
		for (int i = 0; i < sizeWhereCommandIsRun; i++)
		{
			argumentsAsInt[i] = i + 1;
		}

		return '[' + actions[rand() % 2] + ']' + '[' + std::to_string(argumentsAsInt[rand() % sizeWhereCommandIsRun]) + ']';
	}
	void CommandInterpreter::Checker(std::string command) {
		ActionType type;
		std::string* ret = nullptr;
		int*argumentsAsInt = nullptr;
		int argumentsAsIntSize;
		if (isCommandShort(command, 2)) {
			throw std::exception("A parancs tul rovid");
		}
		else
		{

			ret = Parser(command);
			if (ret[0] == "P") {
				type = commandTypeForPlayer(ret[1]);
			}
			else if (ret[0] == "E") {
				type = commandTypeForEnemy(ret[1]);
			}
			if (!argumentChecker(ret, commandSize(command))) {
				throw std::exception("Az argumentumok valamelyike nem szam");
			}
			else {
				argumentsAsInt = argumentsConverter(ret, commandSize(command));
				argumentsAsIntSize = commandSize(command) - 2;
			}
		}
		if (type == ActionType::PlayerDoAttack || type == ActionType::PlayerDoStep)
		{
			data = new PlayerDataStructure(type, argumentsAsInt, argumentsAsIntSize);

		}
		else if (type == ActionType::EnemyDoAttack || type == ActionType::EnemyDoStep)
		{
			data = new EnemyDataStructure(type, argumentsAsInt, argumentsAsIntSize);
		}
	}
	DataStructure * CommandInterpreter::getData()
	{
		return data;
	}
	int CommandInterpreter::commandSize(std::string command) {
		int db = 0;
		for (int i = 0; i < command.length(); i++)
		{
			if (isGoodCharacter(command[i])) {
				db++;
			}
		}
		if (db % 2 != 0) {
			return (db + 1) / 2;
		}
		return db / 2;
	}
	bool CommandInterpreter::isGoodCharacter(char tokenCharacter) {
		return tokenCharacter == '[' || tokenCharacter == ']' || tokenCharacter == '<' || tokenCharacter == '>';
	}
	bool CommandInterpreter::isCommandShort(std::string command, int minvalue) {
		return commandSize(command) < minvalue;
	}
	bool CommandInterpreter::tokenChecker(std::string tokenString) {
		return !(tokenString.find(']', 0) != -1 || tokenString.find('[', 0) != -1 || tokenString.find('<', 0) != -1 || tokenString.find('>', 0) != -1);// find_first_off-ra cserélni
	}
	std::string* CommandInterpreter::Parser(std::string command) {
		InformationForSubParser info;
		info.setObligatoryEndIndex(0);
		info.setCommand(command);
		info.setStartIndex(0);
		info.setStartToken('[');
		info.setEndToken(']');
		info.setCommandSize(commandSize(command));
		info.setRet(new std::string[info.getCommandSize()]);
		int commandLength = command.length();
		int	k = command.find_last_of(']', commandLength);
		info = subParser(info);
		info.setStartIndex(k);
		info.setStartToken('<');
		info.setEndToken('>');
		info = subParser(info);
		std::string* ret = info.getACopyOfret();
		for (int i = 0; i < commandSize(command); i++) {
			if (!tokenChecker(ret[i])) {
				throw std::exception("Command tokens are ununderstandable");
			}
		}

		return ret;

	}
	InformationForSubParser& CommandInterpreter::subParser(InformationForSubParser& info) {
		int db = info.getObligatoryEndIndex();;
		std::string command = info.getCommand();;
		int i = command.find(info.getStartToken(), info.getStartIndex());
		int j = command.find(info.getEndToken(), info.getStartIndex());
		bool vanToken = (i != -1) && (j != -1);
		while (vanToken) {
			db++;
			i++;
			info.getRet()[db - 1] = command.substr(i, j - i); // increase i before the substr return a value that return a correct value
			i = command.find(info.getStartToken(), j + 1);
			j = command.find(info.getEndToken(), i);
			vanToken = (i != -1) && (j != -1);
		}
		info.setObligatoryEndIndex(db);
		return info;
	}

	bool CommandInterpreter::argumentChecker(std::string* arguments, int size) {
		for (int i = 2; i < size; i++)
		{
			if (arguments[i] == "") {
				return false;
			}
			for (int j = 0; j < arguments[i].length(); j++)
			{
				if (!isdigit(arguments[i][j])) {
					return false;
				}
			}
		}
		return true;
	}
	ActionType CommandInterpreter::commandTypeForEnemy(std::string type) {
		if (type == "Tamadas") {
			return ActionType::EnemyDoAttack;
		}
		else if (type == "Lepes")
		{
			return ActionType::EnemyDoStep;
		}
		throw std::exception("Computer create wrong command for this enemy character");
	}
	ActionType CommandInterpreter::commandTypeForPlayer(std::string type) {
		if (type == "Tamadas") {
			return ActionType::PlayerDoAttack;
		}
		else if (type == "Lepes")
		{
			return ActionType::PlayerDoStep;
		}
		throw std::exception("Helytelen Parancs lett megadva");
	}
	int* CommandInterpreter::argumentsConverter(std::string* arguments, int size) {
		int* returnArgumentsAsInt = new int[size - 2];
		for (int i = 2; i < size; i++)
		{
			returnArgumentsAsInt[i - 2] = std::stoi((arguments[i]));
		}
		return returnArgumentsAsInt;
	}


	CommandInterpreter::~CommandInterpreter()
	{
	}
}