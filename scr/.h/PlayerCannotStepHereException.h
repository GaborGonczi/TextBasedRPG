#ifndef PLAYER_CANNNOT_STEP_HERE_EXCEPTION
#define PLAYER_CANNNOT_STEP_HERE_EXCEPTION
#include <exception>
namespace Game {
	class PlayerCannotStepHereException :public std::exception
	{
	public:
		/*Constructors*/
		PlayerCannotStepHereException(const char* msg);
		/*Destructor*/
		~PlayerCannotStepHereException();
		/*Overrided Functions*/
		const char* what()const;
	private:
		const char*msg;
	};
}
#endif // !PLAYER_CANNNOT_STEP_HERE_EXCEPTION