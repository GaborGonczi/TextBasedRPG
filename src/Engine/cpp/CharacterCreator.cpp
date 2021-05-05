#include "CharacterCreator.h"
namespace Creator {
	CharacterCreator::CharacterCreator()
	{

	}

	CharacterCreator::CharacterCreator(int hpConstant, int atkConstant, int defConstant, int moneyConstant) :hpConstant(hpConstant), atkConstant(atkConstant), defConstant(defConstant), moneyConstant(moneyConstant)
	{
		basicWeapons.push_back(new Game::Weapon("Ertelmezo", 2, 3));
		basicWeapons.push_back(new Game::Weapon("Felszabadító", 3, 2));
		basicArmors.push_back(new Game::Armor("Defender", 4, 5));
		basicArmors.push_back(new Game::Armor("Supporter", 6, 3));
	}

	bool CharacterCreator::correctName(std::string name)
	{
		for (int i = 0; i < name.length(); i++)
		{
			if (!isalpha(name[i])) {
				return false;
			}
		}
		return true;
	}

	void CharacterCreator::create()
	{
		int index;
		std::string n = "";
		std::cout << "Adjon meg egy tetszoleges alfabetikus karaktereket tartalmazo nevet" << std::endl;
		do
		{
			n = "";
			std::getline(std::cin, n);

		} while (!correctName(n));
		int hp = hpConstant + (rand() % 12 + 1);
		int atk = atkConstant + (rand() % 6 + 6);
		int def = defConstant + (rand() % 6 + 6);
		int money = moneyConstant;
		std::cout << "Ezek az elsore generalt ertekek a karaktered szamara: " << "Eletero: " << hp << " Tamadoero: " << atk << " Vedekezoero: " << def << std::endl;
		std::cout << "Ha nem tetszik ujrageneralhatod egyszer ehhez ird be 'ujra' es uss entert; ha nem szeretned ujra generaltatni uss entert: ";
		std::string ujra = "";
		std::getline(std::cin, ujra);
		if (ujra == "ujra") {
			hp = hpConstant + (rand() % 12 + 1);
			atk = atkConstant + (rand() % 6 + 6);
			def = defConstant + (rand() % 6 + 6);
			money = moneyConstant;
			std::cout << "Ezek a masodszorra elsore generalt ertekek a karaktered szamara: " << "Eletero: " << hp << " Tamadoero: " << atk << " Vedekezoero: " << def << std::endl;
		}
		globalPlayer = new Game::PlayerCharacter(n, hp, atk, def, money);
		std::cin.clear();
		std::cout << "Valassz magadnak fegyvert:" << std::endl;
		printWeapons();
		index = getIndex();
		std::cout << index << '\n';
		Game::Weapon*w = selectWeapon(index);
		std::cout << "Valassz magadnak Pancelt:" << std::endl;
		printArmors();
		index = getIndex();
		std::cout << index << '\n';
		Game::Armor*a = selectArmor(index);
		globalPlayer->setArmor(a);
		globalPlayer->setWeapon(w);
		globalPlayer->setRadiusOfAction(1);
		globalPlayer->setRadiusOfStep(1);



	}

	void CharacterCreator::printArmors()
	{
		int j = 1;
		for (Game::Armor*i : basicArmors) {
			std::cout << j << '\t' << i->toString() << std::endl;
			j++;
		}
	}

	void CharacterCreator::printWeapons()
	{
		int j = 1;
		for (Game::Weapon*i : basicWeapons) {
			std::cout << j << '\t' << i->toString() << std::endl;
			j++;
		}
	}

	Game::Armor * CharacterCreator::selectArmor(int index)
	{
		return basicArmors.at(index - 1);
	}

	Game::Weapon * CharacterCreator::selectWeapon(int index)
	{
		return basicWeapons.at(index - 1);
	}

	int CharacterCreator::getIndex()
	{
		//std::string sindex = "";
		int index;
		std::cout << "Add meg a kivalasztani kivant targy indexet: ";
		std::cin >> index;
		std::cin.ignore();
		std::cin.clear();
		//std::getline(std::cin, sindex);
		//index = std::stoi(sindex);
		return index;
	}


	Game::PlayerCharacter * CharacterCreator::getPlayerCharacter()
	{
		return globalPlayer;
	}

	CharacterCreator::~CharacterCreator()
	{
	}
}