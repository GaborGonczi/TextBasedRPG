#ifndef PLAYER_INVALID_TARGET_EXCEPTION_H
#define PLAYER_INVALID_TARGET_EXCEPTION_H
#include <exception>
namespace Game {
	class PlayerInvalidTargetException :public std::exception
	{
	public:
		/*Constructors*/
		PlayerInvalidTargetException(const char*msg);
		/*Destructor*/
		~PlayerInvalidTargetException();
		/*Overrided Functions*/
		const char* what() const;
	private:
		const char*msg;
	};
}
#endif // !PLAYER_INVALID_TARGET_EXCEPTION_H