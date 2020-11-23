#ifndef PLAYER_MISSED_TARGET_EXCEPTION_H
#define PLAYER_MISSED_TARGET_EXCEPTION_H
#include <exception>
namespace Game {
	class PlayerMissedTargetException :public std::exception
	{
	public:
		PlayerMissedTargetException(const char*msg);
		~PlayerMissedTargetException();
		/*Overrided Functions*/
		const char* what() const;
	private:
		const char*msg;
	};
}
#endif // !PLAYER_MISSED_TARGET_EXCEPTION_H