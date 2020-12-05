#include "Character.h"
namespace Game {
	Character::Character()
	{
	}

	Character::Character(std::string name, int hp, int atk, int def, int money, Armor* armor, Weapon*weapon, int inwhichunit, int InWhichFieldInFight,
		int InWhichFieldInFight_YCoordinate, int InWhichFieldInFight_XCoordinate, int radiusOfAction, int radiusOfStep) :
		name(name), hp(hp), atk(atk), def(def), money(money), armor(armor), weapon(weapon), inwhichunit(inwhichunit),
		InWhichFieldInFight(InWhichFieldInFight), InWhichFieldInFight_YCoordinate(InWhichFieldInFight_YCoordinate),
		InWhichFieldInFight_XCoordinate(InWhichFieldInFight_XCoordinate), radiusOfAction(radiusOfAction), radiusOfStep(radiusOfStep)
	{
	}

	Character::Character(const Character *other)
	{
		this->name = other->name;
		this->hp = other->hp;
		this->atk = other->atk;
		this->def = other->def;
		this->money = other->money;
		this->armor = new Armor(other->armor);
		this->weapon = new Weapon(other->weapon);
		this->inwhichunit = other->inwhichunit;
		this->InWhichFieldInFight = other->InWhichFieldInFight;
		this->InWhichFieldInFight_YCoordinate = other->InWhichFieldInFight_YCoordinate;
		this->InWhichFieldInFight_XCoordinate = other->InWhichFieldInFight_XCoordinate;
		this->radiusOfAction = other->radiusOfAction;
		this->radiusOfStep = other->radiusOfStep;
		this->backPack = other->backPack;

	}

	Character::~Character()
	{
		delete armor;
		delete weapon;
		for (Item*item : backPack) {
			delete item;
		}
	}

	void Character::setName(std::string newname)
	{
		name = newname;
	}

	void Character::setHp(int newhp)
	{
		hp = newhp;
	}

	void Character::setAtkValue(int newatk)
	{
		atk = newatk;
	}

	void Character::setDefValue(int newdef)
	{
		def = newdef;
	}

	void Character::setRadiusOfAction(int newRadiusOfAction)
	{
		radiusOfAction = newRadiusOfAction;
	}

	void Character::setRadiusOfStep(int newRadiusOfStep)
	{
		radiusOfStep = newRadiusOfStep;
	}

	void Character::setMoney(int newmonyey)
	{
		if (money == 0) {
			money = newmonyey;
		}
		else {
			money += newmonyey;
		}
	}

	void Character::setArmor(Armor* newarmor)
	{
		armor = newarmor;
	}

	void Character::setWeapon(Weapon * newWeapon)
	{
		weapon = newWeapon;
	}

	void Character::setInWhichFieldInFight(int newfield)
	{
		InWhichFieldInFight = newfield;
	}

	void Character::setInWhichFieldInFight_XCoordinate(int x)
	{
		InWhichFieldInFight_XCoordinate = x;
	}

	void Character::setInWhichFieldInFight_YCoordinate(int y)
	{
		InWhichFieldInFight_YCoordinate = y;
	}

	void Character::setInWhichUnit(int newunit)
	{
		inwhichunit = newunit;
	}

	void Character::takeAnItemToBackPack(Item * item)
	{
		backPack.push_back(item);
	}

	std::string Character::getName()
	{
		return name;
	}

	int Character::getHp()
	{
		return hp;
	}

	int Character::getAtk()
	{
		if (weapon != nullptr) {
			return atk + weapon->getAtkBuff();
		}
		return atk;
	}

	int Character::getDef()
	{
		if (armor != nullptr) {
			return def + armor->getDefBuff();
		}
		return def;
	}

	int Character::getRadiusOfAction()
	{
		if (weapon != nullptr) {
			return radiusOfAction + weapon->getRadiusOfActionBuff();
		}
		return radiusOfAction;
	}

	int Character::getRadiusOfStep()
	{
		if (armor != nullptr) {
			return radiusOfStep + armor->getRadiusOfStepBuff();
		}
		return radiusOfStep;
	}

	int Character::getMoney()
	{
		return money;
	}

	Armor* Character::getArmor()
	{
		return armor;
	}

	Weapon * Character::getWeapon()
	{
		return weapon;
	}

	int Character::getInWhichFieldInFight()
	{
		return InWhichFieldInFight;
	}

	int Character::getInWhichFieldInFight_XCoordinate()
	{
		return InWhichFieldInFight_XCoordinate;
	}

	int Character::getInWhichFieldInFight_YCoordinate()
	{
		return InWhichFieldInFight_YCoordinate;
	}

	Item * Character::getAnItemFromBackPack(int index)
	{
		Item* tmp = backPack.at(index - 1);
		return new Item(*tmp);
	}

	bool Character::isAlive()
	{
		if (hp <= 0) {
			return false;
		}
		return true;
	}

	void Character::getDamage(int damage)
	{
		if (armor != nullptr) {
			if (def + armor->getDefBuff() < damage) {
				hp -= (damage - (def + armor->getDefBuff()));
			}
		}
		else {
			if (def < damage) {
				hp -= (damage - def);
			}
		}
	}

	void Character::deleteAnItemFromBackPack(int index)
	{
		backPack.erase(backPack.begin() + index - 1);
	}

	void Character::printItemsFromBackPack()
	{
		for (Item*i : backPack)
		{
			std::cout << i->toString() << std::endl;
		}
	}

	std::string Character::toStringCharacterStatus()
	{
		std::string state;
		state = state + name + '\t' + '\t' + '\t' + '\t' + std::to_string(hp) + '\t' + '\t' + std::to_string(atk) + '\t' + '\t' + '\t' + std::to_string(def);
		if (weapon != nullptr) {
			state = state + '\t' + '\t' + weapon->toString();
		}
		if (armor != nullptr) {
			state = state + '\t' + armor->toString();
		}
		if (InWhichFieldInFight != -1) {
			state = state + '\t' + '\t' + std::to_string(InWhichFieldInFight);
		}
		return state;
	}
}