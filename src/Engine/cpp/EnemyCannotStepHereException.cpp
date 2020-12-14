#include "EnemyCannotStepHereException.h"
namespace Game {
	EnemyCannotStepHereException::EnemyCannotStepHereException(const char*msg) :msg(msg)
	{
	}

	EnemyCannotStepHereException::~EnemyCannotStepHereException()
	{
	}

	const char * EnemyCannotStepHereException::what() const
	{
		return msg;
	}
}