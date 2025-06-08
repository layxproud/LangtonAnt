#pragma once
#include "Ant.h"
#include "Cell.h"
#include <SFML/Graphics.hpp>
#include <vector>

class Game
{
public:
	Game(sf::RenderWindow& window);
	~Game();

	void render(float currentZoom);
	void update(float dt);

	static constexpr int mapSize{ 20 };
	static constexpr sf::Vector2f winSizeF{ 800.f, 600.f };
	static constexpr sf::Vector2u winSizeU{ 800, 600 };

private:
	sf::RenderWindow& m_window;
	std::vector<std::vector<Cell>> m_tileMap;
	sf::Vector2f m_viewCenter;

	int fromX;
	int toX;
	int fromY;
	int toY;

	Ant ant;
	bool isAntDrawn;

	float moveTimer;
	float moveDelay;
};

