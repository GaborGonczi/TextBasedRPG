#include "PlayerCannotStepHereException.h"
namespace Game {
	PlayerCannotStepHereException::PlayerCannotStepHereException(const char* msg) :msg(msg)
	{
	}

	PlayerCannotStepHereException::~PlayerCannotStepHereException()
	{
	}

	const char * PlayerCannotStepHereException::what() const
	{
		return msg;
	}
}