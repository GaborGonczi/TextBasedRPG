#ifndef READABLE_UNIT_H
#define READABLE_UNIT_H
#include <iostream>
//#include <fstream>
#include <string>
#include <vector>
#include "GameUnit.h"
#include "PlayerCharacter.h"
#include "Item.h"
namespace Game {
	class ReadableUnit :public GameUnit
	{

	public:
		/*Constructors*/
		ReadableUnit();
		ReadableUnit(int WU, std::string path, std::vector<int>WATN,std::vector<Item*>FI);
		ReadableUnit(const ReadableUnit*other);
		/*Destructors*/
		~ReadableUnit();
		/*Unit Control Functions*/
		void playerEntry(PlayerCharacter*p);
		void localGame();
		PlayerCharacter* playerExit();
		void print();

	private:
		PlayerCharacter*player;
		std::vector<Item*>foundItems;
		/*Getters*/
		Item* getAnItemFromFoundItems(int index);
		/*Overrided Functions*/
		int getWhichUnit();
		/*Initializer Functions*/
		/*Printer Functions*/
		
		void printFoundItems();
		/*State modifier Functions*/
		void playerChoiceItems();
		void deleteAnItemFromFoundItems(int index);
	};
}
#endif // !READABLE_UNIT_H