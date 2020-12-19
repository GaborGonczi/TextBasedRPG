#ifndef ENEMY_MISSED_DAMAGE_EXCEPTION
#define ENEMY_MISSED_DAMAGE_EXCEPTION
#include <exception>
namespace Game {
	class  EnemyMissedDamageException :public std::exception
	{
	public:
		/*Constructor*/
		EnemyMissedDamageException(const char*msg);
		/*Destructor*/
		~EnemyMissedDamageException();
		/*Overrided Functions*/
		const char*what() const;
	private:
		const char*msg;
	};
}
#endif // !ENEMY_MISSED_DAMAGE_EXCEPTION