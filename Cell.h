#pragma once
#include <SFML/Graphics/RectangleShape.hpp>

class Cell : public sf::RectangleShape
{
	
public:
	Cell();

	static constexpr float cellSizeF = 100.f;
	static constexpr sf::Color Gray = { 128, 128, 128 };

	void changeCellStatus() { cellStatus = !cellStatus; }
	bool isVisited() const { return cellStatus; }

private:
	bool cellStatus;
};

