#pragma once
#include "Cell.h"

enum class AntDirection
{
	North,
	West,
	South,
	East
};

class Ant : public Cell
{
public:
	Ant();

	void turn(bool clockwise);
	void moveForward();

private:
	AntDirection currentDirection;
};

