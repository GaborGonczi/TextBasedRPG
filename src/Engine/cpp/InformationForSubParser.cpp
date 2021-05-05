#include "InformationForSubParser.h"
namespace Game {
	InformationForSubParser::InformationForSubParser()
	{
	}

	InformationForSubParser::InformationForSubParser(std::string command, int commandSize, char startToken, char endToken, int startIndex, int obligatoryEndIndex, std::string * ret) :
		command(command), commandSize(commandSize), startToken(startToken), endToken(endToken), startIndex(startIndex), obligatoryEndIndex(obligatoryEndIndex), ret(ret)
	{
	}

	InformationForSubParser::~InformationForSubParser()
	{
		delete[] ret;
	}

	void InformationForSubParser::setCommand(std::string newCommand)
	{
		command = newCommand;
	}

	void InformationForSubParser::setCommandSize(int newCommmandSizw)
	{
		commandSize = newCommmandSizw;
	}

	void InformationForSubParser::setStartToken(char newStartToken)
	{
		startToken = newStartToken;
	}

	void InformationForSubParser::setEndToken(char newEndToken)
	{
		endToken = newEndToken;
	}

	void InformationForSubParser::setStartIndex(int newStartIndex)
	{
		startIndex = newStartIndex;
	}

	void InformationForSubParser::setObligatoryEndIndex(int newObligatoryEndIndex)
	{
		obligatoryEndIndex = newObligatoryEndIndex;
	}

	void InformationForSubParser::setRet(std::string * newRet)
	{
		ret = newRet;
	}

	std::string InformationForSubParser::getCommand()
	{
		return command;
	}

	int InformationForSubParser::getCommandSize()
	{
		return commandSize;
	}

	char InformationForSubParser::getStartToken()
	{
		return startToken;
	}

	char InformationForSubParser::getEndToken()
	{
		return endToken;
	}

	int InformationForSubParser::getStartIndex()
	{
		return startIndex;
	}

	int InformationForSubParser::getObligatoryEndIndex()
	{
		return obligatoryEndIndex;
	}

	std::string * InformationForSubParser::getRet()
	{
		return ret;
	}

	std::string * InformationForSubParser::getACopyOfret()
	{
		std::string*theCopy = new std::string[commandSize];
		for (int i = 0; i < commandSize; i++)
		{
			theCopy[i] = ret[i];
		}
		return theCopy;
	}
}