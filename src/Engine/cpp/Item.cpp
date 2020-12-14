#include "Item.h"
namespace Game {
	Item::Item()
	{
	}

	Item::Item(std::string name, int sellPrice, int buyPrice, std::string text) :name(name), sellPrice(sellPrice), buyPrice(buyPrice), text(text)
	{
	}

	Item::Item(const Item * other)
	{
		this->name = other->name;
		this->sellPrice = other->sellPrice;
		this->buyPrice = other->buyPrice;
		this->text = other->text;
	}

	Item::~Item()
	{
	}

	void Item::setName(std::string newname)
	{
		name = newname;
	}

	void Item::setSellPrice(int newSellPrice)
	{
		sellPrice = newSellPrice;
	}

	void Item::setBuyPrice(int newBuyPrice)
	{
		buyPrice = newBuyPrice;
	}

	void Item::setText(std::string newText)
	{
		text = newText;
	}

	std::string Item::getName()
	{
		return name;
	}

	int Item::getSellPrice()
	{
		return sellPrice;
	}

	int Item::getBuyPrice()
	{
		return buyPrice;
	}

	std::string Item::getText()
	{
		return text;
	}

	std::string Item::toString()
	{
		std::string state;
		state = state + name + '\t' + '\t' + '\t' + '\t' + std::to_string(sellPrice) + '\t' + '\t' + std::to_string(buyPrice) + '\t' + '\t' + '\t' + text;
		return state;
	}
}