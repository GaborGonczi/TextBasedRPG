#include "Armor.h"
namespace Game {
	Armor::Armor()
	{
	}

	Armor::Armor(std::string name, int radiusOfStepBuff, int defBuff) :name(name), radiusOfStepBuff(radiusOfStepBuff), defBuff(defBuff)
	{
	}

	Armor::Armor(const Armor* other)
	{
		this->name = other->name;
		this->radiusOfStepBuff = other->radiusOfStepBuff;
		this->defBuff = other->defBuff;
	}

	Armor::~Armor()
	{
	}

	void Armor::setname(std::string newname)
	{
		name = newname;
	}

	void Armor::setRadiusOfStepBuff(int newRadiusOfStepBuff)
	{
		radiusOfStepBuff = newRadiusOfStepBuff;
	}

	void Armor::setDefBuff(int newDefBuff)
	{
		defBuff = newDefBuff;
	}

	std::string Armor::getName()
	{
		return name;
	}

	int Armor::getRadiusOfStepBuff()
	{
		return radiusOfStepBuff;
	}

	int Armor::getDefBuff()
	{
		return defBuff;
	}

	std::string Armor::toString()
	{
		return name + '\t' + std::to_string(radiusOfStepBuff) + '\t' + std::to_string(defBuff);
	}
}