#ifndef ENEMY_CANNOT_ATTACK_THE_PLAYER_EXCEPTION_H
#define ENEMY_CANNOT_ATTACK_THE_PLAYER_EXCEPTION_H
#include <exception>
namespace Game {
	class EnemyCannotAttackThePlayerException :public std::exception
	{
	public:
		/*Constructors*/
		EnemyCannotAttackThePlayerException(const char*msg);
		/*Destructor*/
		~EnemyCannotAttackThePlayerException();
		/*Overrided Functions*/
		const char*what() const;

	private:
		const char*msg;
	};
}
#endif // !ENEMY_CANNOT_ATTACK_THE_PLAYER_EXCEPTION_H