#ifndef WEAPON_H
#define WEAPON_H
#include <string>
namespace Game {
	class Weapon
	{
	public:
		/*Constructors*/
		Weapon();
		Weapon(std::string name, int radiusOfActionBuff = 0, int atkBuff = 0);
		Weapon(const Weapon*other);
		/*Destructor*/
		~Weapon();
		/*Setters*/
		void setname(std::string newname);
		void setRadiusOfActionBuff(int newRadiusOfActionBuff);
		void setAtkBuff(int newAtkBuff);
		/*Getters*/
		std::string getName();
		int getRadiusOfActionBuff();
		int getAtkBuff();
		/*toString*/
		std::string toString();
	private:
		std::string name;
		int radiusOfActionBuff;
		int atkBuff;
	};
}
#endif // !WEAPON_H