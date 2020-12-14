#pragma once
#include<vector>
#include<map>
#include<string>
#include<fstream>
#include"InformationAboutNextUnit.h"
struct DataWithOffset
{
	std::vector<std::string>data;
	int offset;
};
class FileHandler
{
public:
	FileHandler(std::string unitsPath, std::string storyPath);
	void readCSV();

	void tokenizedLines();
	
	void create();
	std::vector<Game::InformationAboutNextUnit*> getInfo();
	~FileHandler();
	
private:
	std::string unitsPath;
	std::string storyPath;
	std::vector<std::string> pattern;
	std::vector<std::vector<std::string>>data;
	std::vector<std::string>single_lines;
	std::vector<Game::InformationAboutNextUnit*> info;
	std::vector<std::string> strtok(std::string line, char delimiter);

	Game::InformationAboutNextUnit * createMember(std::vector<std::string> data);
	Game::InformationAboutNextUnit* createUniversalMember(std::vector<std::string> data, Game::InformationAboutNextUnit*UniversalMembers);
	Game::InformationAboutNextUnit *createSpecializedMember(std::vector<std::string>data, Game::InformationAboutReadableUnit*SpecialMembers);
	Game::InformationAboutNextUnit *createSpecializedMember(std::vector<std::string>data, Game::InformationAboutShopUnit*SpecialMembers);
	Game::InformationAboutNextUnit *createSpecializedMember(std::vector<std::string>data, Game::InformationAboutFightUnit*SpecialMembers);
	int findField(std::string searched);
	std::vector<int> positionsInPattern(std::string searched);
	std::vector<std::string>cutVector(std::vector<std::string>data, int begin, int end);
	std::vector<int>stoiForVector(std::vector<std::string> data);
	std::map<Game::Item*, int>createItemMap(std::vector<std::string>items);
	std::map<Game::Enemy*, int>createEnemyMap(std::vector<std::string>enemies);
	void normalizePath(std::string & path);
	

};
