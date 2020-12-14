#include "ShopKeeper.h"
namespace Game {
	ShopKeeper::ShopKeeper()
	{
	}

	ShopKeeper::ShopKeeper(std::string name, int money, Armor* armor, Weapon*weapon, int hp, int atk, int def,
		int inwhichunit, int sentencesdb) :
		Character(name, hp, atk, def, money, armor, weapon, inwhichunit),
		sentencesdb(sentencesdb)
	{
		sentences = new std::string[sentencesdb];
		sentences[0] = "Hello faradt utazo! Segithetek valamiben?";
		sentences[1] = "Udvozletem Kalandor! Miben lehetek szolgalatara";
	}

	ShopKeeper::ShopKeeper(const ShopKeeper * other) :Character(other)
	{
		this->sentencesdb = other->sentencesdb;
		this->sentences = new std::string[other->sentencesdb];
		for (int i = 0; i < other->sentencesdb; i++)
		{
			this->sentences[i] = other->sentences[i];
		}
	}

	ShopKeeper::~ShopKeeper()
	{
		delete[] sentences;
	}

	void ShopKeeper::Greetings()
	{
		std::cout << sentences[rand() % sentencesdb] << std::endl;
	}

	int ShopKeeper::getInWhichUnit()
	{
		return inwhichunit;
	}
}