#include "Weapon.h"
namespace Game {
	Weapon::Weapon()
	{
	}

	Weapon::Weapon(std::string name, int radiusOfActionBuff, int atkBuff) :name(name), radiusOfActionBuff(radiusOfActionBuff), atkBuff(atkBuff)
	{
	}

	Weapon::Weapon(const Weapon * other)
	{
		this->name = other->name;
		this->radiusOfActionBuff = other->radiusOfActionBuff;
		this->atkBuff = other->atkBuff;
	}

	Weapon::~Weapon()
	{
	}

	void Weapon::setname(std::string newname)
	{
		name = newname;
	}

	void Weapon::setRadiusOfActionBuff(int newRadiusOfActionBuff)
	{
		radiusOfActionBuff = newRadiusOfActionBuff;
	}

	void Weapon::setAtkBuff(int newAtkBuff)
	{
		atkBuff = newAtkBuff;
	}

	std::string Weapon::getName()
	{
		return name;
	}

	int Weapon::getRadiusOfActionBuff()
	{
		return radiusOfActionBuff;
	}

	int Weapon::getAtkBuff()
	{
		return atkBuff;
	}

	std::string Weapon::toString()
	{
		return name + '\t' + std::to_string(radiusOfActionBuff) + '\t' + std::to_string(atkBuff);
	}
}