#ifndef ITEM_H
#define ITEM_H
#include <string>
namespace Game {
	class Item
	{
	public:
		/*Constructors*/
		Item();
		Item(std::string name, int sellPrice, int buyPrice, std::string text = "");
		Item(const Item*other);
		/*Destructor*/
		~Item();
		/*Setters*/
		void setName(std::string newname);
		void setSellPrice(int newSellPrice);
		void setBuyPrice(int newBuyPrice);
		void setText(std::string newText);
		/*Getters*/
		std::string getName();
		int getSellPrice();
		int getBuyPrice();
		std::string getText();
		/*Printer Methods*/
		std::string toString();
	private:
		std::string name;
		int sellPrice;
		int buyPrice;
		std::string text;
	};
}
#endif // !ITEM_H



