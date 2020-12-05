#ifndef ARMOR_H
#define ARMOR_H
#include<string>
namespace Game {
	class Armor
	{
	public:
		/*Constructors*/
		Armor();
		Armor(std::string name, int radiusOfStepBuff = 0, int defBuff = 0);
		Armor(const Armor*other);
		//Armor&operator=(const Armor other);
		/*Destructor*/
		~Armor();
		/*Setters*/
		void setname(std::string newname);
		void setRadiusOfStepBuff(int newRadiusOfStepBuff);
		void setDefBuff(int newDefBuff);
		/*Getters*/
		std::string getName();
		int getRadiusOfStepBuff();
		int getDefBuff();
		/*toString*/
		std::string toString();

	private:
		std::string name;
		int defBuff;
		int radiusOfStepBuff;
	};
}
#endif // !ARMOR_H