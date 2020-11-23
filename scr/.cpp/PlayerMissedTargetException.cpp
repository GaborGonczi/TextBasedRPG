#include "PlayerMissedTargetException.h"
namespace Game {
	PlayerMissedTargetException::PlayerMissedTargetException(const char * msg) :msg(msg)
	{
	}

	PlayerMissedTargetException::~PlayerMissedTargetException()
	{
	}

	const char * PlayerMissedTargetException::what() const
	{
		return msg;
	}
}