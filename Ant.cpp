#include "Ant.h"

Ant::Ant()
	: currentDirection{AntDirection::West}
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
        pos.y -= Cell::cellSizeF;
        break;
    case AntDirection::East:
        pos.x += Cell::cellSizeF;
        break;
    case AntDirection::South:
        pos.y += Cell::cellSizeF;
        break;
    case AntDirection::West:
        pos.x -= Cell::cellSizeF;
        break;
    }

    const float mapWorldSize = mapSize * Cell::cellSizeF;

    if (pos.x < 0) pos.x += mapWorldSize;
    if (pos.y < 0) pos.y += mapWorldSize;

    if (pos.x >= mapWorldSize) pos.x -= mapWorldSize;
    if (pos.y >= mapWorldSize) pos.y -= mapWorldSize;

    this->setPosition(pos);
}

