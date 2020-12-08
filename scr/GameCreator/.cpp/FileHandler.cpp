#include "FileHandler.h"
FileHandler::FileHandler(std::string fname):fname(fname)
{
}

void  FileHandler::readCSV() {
	std::ifstream in;	
	in.open(fname);		
	std::vector<std::string>returnValue;
	do					
	{					
		std::string line = "";
		std::getline(in, line);
		returnValue.push_back(line);

	} while (!in.eof());
	this->single_lines = returnValue;
}

std::vector<std::string> FileHandler::strtok(std::string line, char delimiter) {
	std::vector<std::string> tokens;
	std::string token;
	int i = 0;
	while (i != -1) {
		token = line.substr(i, line.find(delimiter, i) - i);
		tokens.push_back(token);
		i = line.find(delimiter, i);
		if (i != -1) {
			i += 1;
		}
	}
	return tokens;
}

void FileHandler::tokenizedLines()
{
	pattern = strtok(single_lines[0], ',');
	for (int i = 1; i < single_lines.size(); i++)
	{
		data.push_back(strtok(single_lines[i], ';'));
	
	}
}

int FileHandler::findField(std::string searched)
{
	std::vector<std::string>::iterator i=pattern.begin();
	int position;

	while (i != pattern.end())
	{
		position = (std::find(pattern.begin(), pattern.end(), searched) - pattern.begin());
		if (position != pattern.size()) {
			return position;
		}

	}
}

std::vector<int> FileHandler::positionsInPattern(std::string searched)
{
	std::vector<int>returnValue;
	for (int i = 0; i < pattern.size(); i++) {
		if (pattern[i] == searched) {
			returnValue.push_back(i);
		}
	}
	return returnValue;
}

std::vector<int> FileHandler::stoiForVector(std::vector<std::string> data)
{
	std::vector<int>returnValue;
	for (int i = 0; i < data.size(); i++)
	{
		returnValue.push_back(std::stoi(data[i]));
	}
	return returnValue;
}

std::vector<std::string> FileHandler::cutVector(std::vector<std::string> data,int begin,int end)
{
	std::vector<std::string>returnValue(data.begin()+begin+1,data.begin()+end);
	return returnValue;

}

std::map<Game::Item*, int> FileHandler::createItemMap(std::vector<std::string>data)
{
	std::vector<int>StartItemPos = positionsInPattern("STARTITEMTOKEN");
	std::vector<int>EndItemPos = positionsInPattern("ENDITEMTOKEN");
	std::map<Game::Item*, int>returnValue;
	Game::Item* itemObject;
	std::vector<std::string>item;
	int i = 0;
	while (i < StartItemPos.size())
	{
		item = cutVector(data, StartItemPos[i], EndItemPos[i]);
		itemObject = new Game::Item(item[0], std::stoi(item[1]), std::stoi(item[2]), item[3]);
		returnValue.emplace(itemObject, std::stoi(item[4]));
		i++;
	}
	return returnValue;

}

std::map<Game::Enemy*, int> FileHandler::createEnemyMap(std::vector<std::string> data)
{
	std::vector<int>StartEnemyPos = positionsInPattern("STARTENEMYTOKEN");
	std::vector<int>EndEnemyPos = positionsInPattern("ENDENEMYTOKEN");

	std::map<Game::Enemy*, int>returnValue;
	Game::Enemy* enemyObject;
	std::vector<std::string> enemy;
	std::vector<std::string>armor;
	std::vector<std::string>weapon;
	for (int i = 0; i < StartEnemyPos.size(); i++)
	{
		enemy = cutVector(data, StartEnemyPos[i], EndEnemyPos[i]);
		armor = cutVector(enemy, 5, 9);
		weapon = cutVector(enemy, 10, 14);
		Game::Armor*a = new Game::Armor(armor[0], std::stoi(armor[1]), std::stoi(armor[2]));
		Game::Weapon*w = new Game::Weapon(weapon[0], std::stoi(weapon[1]), std::stoi(weapon[2]));
		enemyObject = new Game::Enemy(enemy[0], std::stoi(enemy[1]), std::stoi(enemy[2]), std::stoi(enemy[3]), std::stoi(enemy[4]), a, w, std::stoi(enemy[15]), -1, -1, -1, std::stoi(enemy[16]), std::stoi(enemy[17]));
		returnValue.emplace(enemyObject, std::stoi(enemy[18]));

	}
	return returnValue;
}

Game::InformationAboutNextUnit * FileHandler::createMember(std::vector<std::string> data)
{
	Game::InformationAboutNextUnit* UniversalMembers=nullptr;
	if(data[findField("TYPE")]=="R"){
		UniversalMembers= new Game::InformationAboutReadableUnit;
		UniversalMembers = createUniversalMember(data, UniversalMembers);
		UniversalMembers = createSpecializedMember(data, dynamic_cast<Game::InformationAboutReadableUnit*>(UniversalMembers));
	}
	else if (data[findField("TYPE")] == "S") {
		UniversalMembers = new Game::InformationAboutShopUnit;
		UniversalMembers = createUniversalMember(data, UniversalMembers);
		UniversalMembers = createSpecializedMember(data, dynamic_cast<Game::InformationAboutShopUnit*>(UniversalMembers));
		
	}
	else if (data[findField("TYPE")] == "F") {
		UniversalMembers = new Game::InformationAboutFightUnit;
		UniversalMembers = createUniversalMember(data, UniversalMembers);
		UniversalMembers = createSpecializedMember(data, dynamic_cast<Game::InformationAboutFightUnit*>(UniversalMembers));
	}

	return UniversalMembers;
	
	
}

Game::InformationAboutNextUnit * FileHandler::createUniversalMember(std::vector<std::string> data,Game::InformationAboutNextUnit * UniversalMembers)
{
	UniversalMembers->path = data[findField("PATH")];
	UniversalMembers->whichUnit = std::stoi(data[findField("WHICH_UNIT")]);
	std::vector<std::string>WATNS = cutVector(data, findField("STARTWHEREABLETONEXTTOKEN"), findField("ENDWHEREABLETONEXTTOKEN"));
	std::vector<int>WATN = stoiForVector(WATNS);
	UniversalMembers->whereAbleToNext = WATN;
	return UniversalMembers;
}

Game::InformationAboutNextUnit * FileHandler::createSpecializedMember(std::vector<std::string>data,Game::InformationAboutReadableUnit * SpecialMembers)
{
	SpecialMembers->itemsAndItsCount = createItemMap(data);
	return SpecialMembers;
}

Game::InformationAboutNextUnit * FileHandler::createSpecializedMember(std::vector<std::string> data, Game::InformationAboutShopUnit * SpecialMembers)
{
	SpecialMembers->itemsAndItsCount = createItemMap(data);
	std::vector<std::string>sk = cutVector(data, findField("STARTSHOPKEEPERTOKEN"), findField("ENDSHOPKEEPERTOKEN"));
	std::vector<std::string>armor = cutVector(data, findField("STARTSKARMORTOKEN"), findField("ENDSKARMORTOKEN"));
	std::vector<std::string>weapon = cutVector(data, findField("STARTSKWEAPONTOKEN"), findField("ENDSKWEAPONTOKEN"));
	Game::Armor*a = new Game::Armor(armor[0], std::stoi(armor[1]), std::stoi(armor[2]));
	Game::Weapon*w = new Game::Weapon(weapon[0], std::stoi(weapon[1]), std::stoi(weapon[2]));
	Game::ShopKeeper*SK = new Game::ShopKeeper(sk[0], std::stoi(sk[1]), a, w, std::stoi(sk[12]), std::stoi(sk[13]), std::stoi(sk[14]), std::stoi(sk[15]));
	SpecialMembers->owner = SK;
	return SpecialMembers;
}

Game::InformationAboutNextUnit * FileHandler::createSpecializedMember(std::vector<std::string> data, Game::InformationAboutFightUnit * SpecialMembers)
{
	SpecialMembers->height = std::stoi(data[findField("TABLEHEIGHT")]);
	SpecialMembers->width = std::stoi(data[findField("TABLEWIDTH")]);
	SpecialMembers->enemyAndItsCount = createEnemyMap(data);
	return SpecialMembers;
}

void FileHandler::create()
{
	int i = 0;
	for (std::vector<std::vector<std::string>>::iterator it = data.begin(); it != data.end(); ++it) {
		std::vector<std::string> tmp = *it;
		Game::InformationAboutNextUnit*next=createMember(tmp);
		info.push_back(next);
	}
}

std::vector<Game::InformationAboutNextUnit*> FileHandler::getInfo()
{
	return info;
}

FileHandler::~FileHandler() { for (Game::InformationAboutNextUnit*i : info) { delete i; } }
