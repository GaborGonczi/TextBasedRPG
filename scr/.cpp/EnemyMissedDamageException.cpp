#include "EnemyMissedDamageException.h"
namespace Game {
	EnemyMissedDamageException::EnemyMissedDamageException(const char*msg) :msg(msg)
	{
	}

	EnemyMissedDamageException::~EnemyMissedDamageException()
	{
	}

	const char * EnemyMissedDamageException::what()const
	{
		return msg;
	}
}