#ifndef ACTION_TYPE_H
#define ACTION_TYPE_H
namespace Game {
	enum class ActionType
	{
		PlayerDoAttack,
		PlayerDoStep,
		EnemyDoAttack,
		EnemyDoStep,
		DoNothing
	};
}
#endif // !ACTION_TYPE_H