/*
 *	Player class.  Stores information about the player.
 */

#include "Player.h"

//============================================================

Player::Player()
{
}

//============================================================

std::string Player::getName()
{
	return _name;
}

//============================================================

void Player::setName(std::string name)
{
	_name = name;
}

//============================================================