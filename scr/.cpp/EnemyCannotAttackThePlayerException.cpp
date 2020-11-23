#include "EnemyCannotAttackThePlayerException.h"
namespace Game {
	EnemyCannotAttackThePlayerException::EnemyCannotAttackThePlayerException(const char*msg) :msg(msg)
	{
	}

	EnemyCannotAttackThePlayerException::~EnemyCannotAttackThePlayerException()
	{
	}

	const char * EnemyCannotAttackThePlayerException::what() const
	{
		return msg;
	}
}