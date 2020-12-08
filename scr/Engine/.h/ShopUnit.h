#ifndef SHOP_UNIT_H
#define SHOP_UNIT_H
//#include <fstream>
#include "GameUnit.h"
#include "ShopKeeper.h"
#include "PlayerCharacter.h"
namespace Game {
	class ShopUnit :public GameUnit
	{
	public:
		/*Constructors*/
		ShopUnit();
		ShopUnit(int WU, std::string path, std::vector<int>WATN, std::vector<Item*>SI, ShopKeeper*SK = nullptr);
		ShopUnit(const ShopUnit*other);
		/*Destructor*/
		~ShopUnit();
		/*Unit Control Functions*/
		void playerEntry(PlayerCharacter*p);
		void localGame();
		PlayerCharacter* playerExit();
		void print();
	private:
		PlayerCharacter*player;
		ShopKeeper* owner;
		std::vector<Item*>items;
		/*Getters*/
		Item*getAnItemFromShop(int index);
		/*Overrided Functions*/
		int getWhichUnit();
		/*Initializer Functions*/
		void initializeShopsItems();
		/*Printer Functions*/
		void printItemsFromShop();
		/*State modifiers Functions*/
		void playerActions();
		void playerBuy();
		void playerSell();
		void deleteAnItemFromItems(int index);
	};
}
#endif // !SHOP_UNIT_H