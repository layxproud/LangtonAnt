#pragma once
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class Ant
{
public:
	Ant();
	~Ant();

	void draw(sf::RenderWindow& window, const sf::Vector2f& position) const;

	bool isActive() const { return active; }
	void setActive() { active = !active; }
	float getCellSize() const { return m_cellSize; }
	void setCellSize(float size) { m_cellSize = size; }

private:
	bool active;
	float m_cellSize;
};

