#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include <string>
#include <vector>
#include "Weapon.h"
#include "Armor.h"
#include "Item.h"
//TODO All character Types Copy constructor
namespace Game {
	class Character
	{
	public:
		/*Constructors*/
		Character();
		Character(std::string name, int hp, int atk, int def, int money = 0, Armor* armor = nullptr, Weapon*weapon = nullptr, int inwhichunit = 1, int InWhichFieldInFight = -1,
			int InWhichFieldInFight_YCoordinate = -1, int InWhichFieldInFight_XCoordinate = -1,
			int radiusOfAction = 1, int radiusOfStep = 1);
		Character(const Character*other);
		/*Destructor*/
		virtual ~Character();
		/*Setters*/
		void setName(std::string newname);
		void setHp(int newhp);
		void setAtkValue(int newatk);
		void setDefValue(int newdef);
		void setRadiusOfAction(int newRadiusOfAction);
		void setRadiusOfStep(int newRadiusOfStep);
		void setMoney(int newmonyey);
		void setArmor(Armor* newarmor);
		void setWeapon(Weapon* newWeapon);
		void setInWhichFieldInFight(int newfield);
		void setInWhichFieldInFight_XCoordinate(int x);
		void setInWhichFieldInFight_YCoordinate(int y);
		void setInWhichUnit(int newunit);
		void takeAnItemToBackPack(Item*item);
		/*Getters*/
		std::string getName();
		int getHp();
		int getAtk();
		int getDef();
		int getRadiusOfAction();
		int getRadiusOfStep();
		int getMoney();
		Armor* getArmor();
		Weapon*getWeapon();
		int getInWhichFieldInFight();
		int getInWhichFieldInFight_XCoordinate();
		int getInWhichFieldInFight_YCoordinate();
		Item* getAnItemFromBackPack(int index);
		/*Pure Virtual Functions*/
		virtual int getInWhichUnit() = 0;
		/*State Checkers*/
		bool isAlive();
		/*State Modifiers*/
		void getDamage(int damage);
		void deleteAnItemFromBackPack(int index);
		/*Printer Methods*/
		void printItemsFromBackPack();
		std::string toStringCharacterStatus();
	protected:
		int inwhichunit;
		int InWhichFieldInFight;
		int InWhichFieldInFight_YCoordinate;
		int InWhichFieldInFight_XCoordinate;
		std::string name;
		int atk;
		int def;
		int hp;
		int radiusOfAction;
		int radiusOfStep;
		int money;
		//	int stepSize;
		Armor* armor;
		Weapon* weapon;
		std::vector<Item*> backPack;

	};
}
#endif // !CHARACTER_H
