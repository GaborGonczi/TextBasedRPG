#ifndef COORDINATE_H
#define COORDINATE_H
namespace Game {
	class Coordinate
	{
	public:
		Coordinate();
		Coordinate(int valueX, int valueY);
		Coordinate(const Coordinate*other);
		~Coordinate();
		/*Setters*/
		void setValueX(int newValueX);
		void setValueY(int newValueY);
		/*Getters*/
		int getValueX();
		int getValueY();
	private:
		int valueX;
		int valueY;
	};
}
#endif // !COORDINATE_H


