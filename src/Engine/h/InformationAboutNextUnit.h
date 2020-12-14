#ifndef INFORMATIONABOUTNEXUNIT_H
#define INFORMATIONABOUTNEXUNIT_H
#include <string>
#include <vector>
#include <map>
#include "Enemy.h"
#include "ShopKeeper.h"
#include "Item.h"
namespace Game {
	struct InformationAboutNextUnit
	{
		int whichUnit;
		std::string path;
		std::vector<int>whereAbleToNext;
		virtual ~InformationAboutNextUnit()
		{

		}

	};
	struct InformationAboutReadableUnit :public InformationAboutNextUnit {

		std::map<Item*, int>itemsAndItsCount;
		~InformationAboutReadableUnit()
		{
			for (std::map<Item*, int>::iterator it = itemsAndItsCount.begin(); it != itemsAndItsCount.end(); ++it)
			{
				delete it->first;
			}
		}
	};
	struct InformationAboutShopUnit :public  InformationAboutNextUnit {

		ShopKeeper* owner;
		std::map<Item*, int>itemsAndItsCount;
		~InformationAboutShopUnit()
		{
			for (std::map<Item*, int>::iterator it = itemsAndItsCount.begin(); it != itemsAndItsCount.end(); ++it)
			{
				delete it->first;
			}
			delete owner;
		}
	};
	struct InformationAboutFightUnit : public InformationAboutNextUnit {

		int height;
		int width;
		std::map<Enemy*, int>enemyAndItsCount;
		~InformationAboutFightUnit()
		{
			for (std::map<Enemy*, int>::iterator it=enemyAndItsCount.begin();it!=enemyAndItsCount.end();++it)
			{
				delete it->first;
			}
		}

	};
	
}
#endif // !INFORMATIONABOUTNEXUNIT_H
