#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H
#include<vector>
#include<map>
#include<string>
#include<fstream>
#include"InformationAboutNextUnit.h"
namespace Creator {
	struct DataWithOffset
	{
		std::vector<std::string>data;
		int offset;
	};
	class FileHandler
	{
	public:
		FileHandler(std::string unitsPath, std::string storyPath);
		~FileHandler();
		void readCSV();
		void tokenizedLines();
		void create();
		std::vector<Game::InformationAboutNextUnit*> getInfo();



	private:
		std::string unitsPath;
		std::string storyPath;
		std::vector<std::string> pattern;
		std::vector<std::vector<std::string>>data;
		std::vector<std::string>single_lines;
		std::vector<Game::InformationAboutNextUnit*> info;
		void normalizePath(std::string & path);
		std::vector<std::string> strtok(std::string line, char delimiter);
		Game::InformationAboutNextUnit * createMember(std::vector<std::string> data);
		Game::InformationAboutNextUnit* createUniversalMember(std::vector<std::string> data, Game::InformationAboutNextUnit*UniversalMembers);
		Game::InformationAboutNextUnit *createSpecializedMember(std::vector<std::string>data, Game::InformationAboutReadableUnit*SpecialMembers);
		Game::InformationAboutNextUnit *createSpecializedMember(std::vector<std::string>data, Game::InformationAboutShopUnit*SpecialMembers);
		Game::InformationAboutNextUnit *createSpecializedMember(std::vector<std::string>data, Game::InformationAboutFightUnit*SpecialMembers);
		int findField(std::string searched, int offset = 0);
		std::vector<std::string>cutVector(std::vector<std::string>data, int begin, int end);
		std::vector<int>stoiForVector(std::vector<std::string> data);
		std::map<Game::Item*, int>createItemMap(std::vector<std::string>items);
		std::map<Game::Enemy*, int>createEnemyMap(std::vector<std::string>enemies);
		std::vector<int> positionsInPattern(std::string searched);
		//Game::InformationAboutNextUnit * createMember(std::vector<std::string> data);
	};
}

#endif // !FILE_HANDLER_H

