#ifndef SHOP_KEEPER_H
#define SHOP_KEEPER_H
#include "Character.h"
namespace Game {
	class ShopKeeper :
		public Character
	{
	public:
		/*Constructors*/
		ShopKeeper();
		ShopKeeper(std::string name, int money, Armor*armor = nullptr, Weapon*weapon = nullptr, int hp = INT32_MAX, int atk = INT32_MAX, int def = INT32_MAX,
			int inwhichunit = 1, int sentencesdb = 2);
		ShopKeeper(const ShopKeeper*other);

		/*Destructor*/
		~ShopKeeper();
		/*Functions*/
		void Greetings();
		/*Overrided Functions*/
		int getInWhichUnit();

	private:
		std::string* sentences;
		int sentencesdb;
	};
}
#endif // !SHOP_KEEPER_H