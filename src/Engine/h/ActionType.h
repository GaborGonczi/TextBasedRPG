#ifndef ACTION_TYPE_H
#define ACTION_TYPE_H
namespace Game {
	///This is an enum which contains action types for FightUnit
	enum class ActionType
	{
		PlayerDoAttack, ///<Player do attack
		PlayerDoStep,  ///<Player do step
		EnemyDoAttack, ///<Enemy do attack
		EnemyDoStep, ///<Enemy do step
		DoNothing ///<Nobody do anything
	};
}
#endif // !ACTION_TYPE_H