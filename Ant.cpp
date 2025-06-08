#include "Ant.h"

Ant::Ant()
	: Cell{}
	, currentDirection{AntDirection::West}
{
}

void Ant::turn(bool clockwise)
{
	if (clockwise) {
		currentDirection = static_cast<AntDirection>((static_cast<int>(currentDirection) + 1) % 4);
	}
	else {
		currentDirection = static_cast<AntDirection>((static_cast<int>(currentDirection) + 3) % 4);
	}
}

void Ant::moveForward()
{
	sf::Vector2f pos = this->getPosition();

	switch (currentDirection) {
	case AntDirection::North:
		pos.y -= cellSizeF;
		break;
	case AntDirection::East:
		pos.x += cellSizeF;
		break;
	case AntDirection::South:
		pos.y += cellSizeF;
		break;
	case AntDirection::West:
		pos.x -= cellSizeF;
		break;
	}
	this->setPosition(pos);
}

