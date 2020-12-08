#include "ShopUnit.h"
namespace Game {
	ShopUnit::ShopUnit()
	{
	}

	ShopUnit::ShopUnit(int WU, std::string path, std::vector<int>WATN,std::vector<Item*>SI, ShopKeeper * SK) :GameUnit(WU, path, WATN), items(SI),owner(SK)
	{
		
	}

	ShopUnit::ShopUnit(const ShopUnit * other) : GameUnit(other)
	{
		this->owner = new ShopKeeper(other->owner);
		this->items = other->items;
	}

	ShopUnit::~ShopUnit()
	{
		delete owner;
		for (Item*i : items) {
			delete i;
		}
	}

	void ShopUnit::playerEntry(PlayerCharacter * p)
	{
		player = p;
		player->setInWhichUnit(getWhichUnit());

	}

	void ShopUnit::localGame()
	{
		readTheSection();
		owner->Greetings();
		playerActions();
	}

	PlayerCharacter* ShopUnit::playerExit()
	{
		return player;
	}


	void ShopUnit::print()
	{
		std::cout << this->whichunit << '\n';
		std::cout << this->path << '\n';
		for (int i : whereAbleToNext) {
			std::cout << i << '\n';
		}
		this->printItemsFromShop();
		std::cout<<this->owner->toStringCharacterStatus()<<'\n';
	
		
	}
	Item * ShopUnit::getAnItemFromShop(int index)
	{
		Item* tmp = items.at(index - 1);
		return new Item(*tmp);
	}

	int ShopUnit::getWhichUnit()
	{
		return whichunit;
	}

	void ShopUnit::initializeShopsItems()
	{
		for (int i = 0; i < 10; i++)
		{
			items.push_back(new Item("Valami" + std::to_string(i), (rand() % 10 + 1), (rand() % 10 + 1)));
		}
	}

	void ShopUnit::printItemsFromShop()
	{
		for (Item*i : items) {
			std::cout << i->toString() << std::endl;
		}
	}

	void ShopUnit::playerActions()
	{
		std::string choice = "";
		do
		{
			std::cout << "Mit szeretnel tenni: ";
			std::getline(std::cin, choice);
			if (choice == "Eladni") {
				playerSell();
			}
			else if (choice == "Megvenni") {
				playerBuy();
			}

		} while (choice != "Kilepni");
	}

	void ShopUnit::playerBuy()
	{
		Item*buyable;
		int index;
		do
		{
			std::cout << "Melyik targyat szeretned megvennini?(0=Kilepes)" << std::endl;
			std::cout << std::endl;
			std::cout << "A nalad levo targyak" << std::endl;
			player->printItemsFromBackPack();
			std::cout << std::endl;
			std::cout << "A boltban levo targyak" << std::endl;
			std::cout << std::endl;
			printItemsFromShop();
			std::cout << '>';
			std::cin >> index;
			std::cin.ignore();
			std::cin.clear();
			if (index != 0) {
				buyable = getAnItemFromShop(index);
				player->setMoney(-(buyable->getBuyPrice()));
				player->takeAnItemToBackPack(buyable);
				deleteAnItemFromItems(index);
			}
		} while (index != 0);
	}

	void ShopUnit::playerSell()
	{
		Item*sellable;
		int index;
		do
		{
			std::cout << "Melyik targyadat szeretned eladni?(0=Kilepes)" << std::endl;
			std::cout << std::endl;
			std::cout << "A nalad levo targyak" << std::endl;
			player->printItemsFromBackPack();
			std::cout << std::endl;
			std::cout << "A boltban levo targyak" << std::endl;
			std::cout << std::endl;
			std::cout << "A boltban levo targyak" << std::endl;
			std::cout << std::endl;
			printItemsFromShop();
			std::cout << std::endl;

			std::cout << '>';
			std::cin >> index;
			std::cin.ignore();
			std::cin.clear();
			if (index != 0) {
				sellable = player->getAnItemFromBackPack(index);
				player->setMoney(sellable->getSellPrice());
				player->deleteAnItemFromBackPack(index);
				items.push_back(sellable);
			}
		} while (index != 0);
	}

	void ShopUnit::deleteAnItemFromItems(int index)
	{
		items.erase(items.begin() + index - 1);
	}
}