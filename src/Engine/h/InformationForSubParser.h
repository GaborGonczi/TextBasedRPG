#ifndef INFORMATION_FOR_SUB_PARSER_H
#define INFORMATION_FOR_SUB_PARSER_H
#include <string>
namespace Game {
	class InformationForSubParser
	{
	public:
		InformationForSubParser();
		InformationForSubParser(std::string command, int commandSize, char startToken, char endToken, int startIndex, int obligatoryEndIndex, std::string*ret);
		~InformationForSubParser();
		void setCommand(std::string newCommand);
		void setCommandSize(int newCommmandSizw);
		void setStartToken(char newStartToken);
		void setEndToken(char newEndToken);
		void setStartIndex(int newStartIndex);
		void setObligatoryEndIndex(int newObligatoryEndIndex);
		void setRet(std::string*newRet);
		std::string getCommand();
		int getCommandSize();
		char getStartToken();
		char getEndToken();
		int getStartIndex();
		int getObligatoryEndIndex();
		std::string* getRet();
		std::string* getACopyOfret();
	private:
		std::string command;
		int commandSize;
		char startToken;
		char endToken;
		int startIndex;
		int obligatoryEndIndex;
		std::string* ret;
	};
}
#endif // !INFORMATION_FOR_SUB

