#include "InformationForSubPhraser.h"
namespace Game {
	InformationForSubPhraser::InformationForSubPhraser()
	{
	}

	InformationForSubPhraser::InformationForSubPhraser(std::string command, int commandSize, char startToken, char endToken, int startIndex, int obligatoryEndIndex, std::string * ret) :
		command(command), commandSize(commandSize), startToken(startToken), endToken(endToken), startIndex(startIndex), obligatoryEndIndex(obligatoryEndIndex), ret(ret)
	{
	}

	InformationForSubPhraser::~InformationForSubPhraser()
	{
		delete[] ret;
	}

	void InformationForSubPhraser::setCommand(std::string newCommand)
	{
		command = newCommand;
	}

	void InformationForSubPhraser::setCommandSize(int newCommmandSizw)
	{
		commandSize = newCommmandSizw;
	}

	void InformationForSubPhraser::setStartToken(char newStartToken)
	{
		startToken = newStartToken;
	}

	void InformationForSubPhraser::setEndToken(char newEndToken)
	{
		endToken = newEndToken;
	}

	void InformationForSubPhraser::setStartIndex(int newStartIndex)
	{
		startIndex = newStartIndex;
	}

	void InformationForSubPhraser::setObligatoryEndIndex(int newObligatoryEndIndex)
	{
		obligatoryEndIndex = newObligatoryEndIndex;
	}

	void InformationForSubPhraser::setRet(std::string * newRet)
	{
		ret = newRet;
	}

	std::string InformationForSubPhraser::getCommand()
	{
		return command;
	}

	int InformationForSubPhraser::getCommandSize()
	{
		return commandSize;
	}

	char InformationForSubPhraser::getStartToken()
	{
		return startToken;
	}

	char InformationForSubPhraser::getEndToken()
	{
		return endToken;
	}

	int InformationForSubPhraser::getStartIndex()
	{
		return startIndex;
	}

	int InformationForSubPhraser::getObligatoryEndIndex()
	{
		return obligatoryEndIndex;
	}

	std::string * InformationForSubPhraser::getRet()
	{
		return ret;
	}

	std::string * InformationForSubPhraser::getACopyOfret()
	{
		std::string*theCopy = new std::string[commandSize];
		for (int i = 0; i < commandSize; i++)
		{
			theCopy[i] = ret[i];
		}
		return theCopy;
	}
}