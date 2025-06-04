#pragma once
#include "Ant.h"
#include <vector>

class Game
{
	const int mapSize{ 100 };
	const float tileSizeF{ 100.f };
	const unsigned tileSizeU = static_cast<unsigned>(tileSizeF);

public:
	Game(sf::RenderWindow& window);
	~Game();

	void render(float currentZoom);

	int getMapSize() const { return mapSize; }
	float getTileSizeF() const { return tileSizeF; }

private:
	sf::RenderWindow& m_window;
	std::vector<std::vector<sf::RectangleShape>> tileMap;

	int fromX;
	int toX;
	int fromY;
	int toY;
};

