#include "PlayerInvalidTargetException.h"
namespace Game {
	PlayerInvalidTargetException::PlayerInvalidTargetException(const char * msg) :msg(msg)
	{
	}

	PlayerInvalidTargetException::~PlayerInvalidTargetException()
	{
	}

	const char * PlayerInvalidTargetException::what() const
	{
		return msg;
	}
}

