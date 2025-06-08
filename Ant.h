#pragma once
#include "Cell.h"

enum class AntDirection
{
	North,
	West,
	South,
	East
};

class Ant
{
public:
	Ant();

	void setPosition(const sf::Vector2f& position) { m_position = position; }
	sf::Vector2f getPosition() const { return m_position; }
	void setMapSize(size_t size) { mapSize = size; }

	void turn(bool clockwise);
	void moveForward();

private:
	sf::Vector2f m_position;
	AntDirection currentDirection;
	size_t mapSize;
};

