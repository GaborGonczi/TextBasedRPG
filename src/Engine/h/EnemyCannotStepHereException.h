#ifndef ENEMY_CANNNOT_STEP_HERE_EXCEPTION
#define ENEMY_CANNNOT_STEP_HERE_EXCEPTION
#include<exception>
namespace Game {
	class EnemyCannotStepHereException :public std::exception
	{
	public:
		/*Constructors*/
		EnemyCannotStepHereException(const char*msg);
		/*Destructor*/
		~EnemyCannotStepHereException();
		/*Overrided Functions*/
		const char* what() const;
	private:
		const char*msg;
	};
}
#endif // !ENEMY_CANNNOT_STEP_HERE_EXCEPTION