#include "Game.h"

Game::Game(sf::RenderWindow& window)
	: m_window{window}
	, tileMap{}
	, fromX{}
	, toX{}
	, fromY{}
	, toY{}
{
	tileMap.resize(mapSize, std::vector<sf::RectangleShape>());
	for (size_t x = 0; x < mapSize; x++) {
		tileMap[x].resize(mapSize, sf::RectangleShape());
		for (size_t y = 0; y < mapSize; y++) {
			tileMap[x][y].setSize({ tileSizeF, tileSizeF });
			tileMap[x][y].setFillColor(sf::Color::White);
			tileMap[x][y].setOutlineColor(sf::Color::Black);
			tileMap[x][y].setPosition({ x * tileSizeF, y * tileSizeF });
		}
	}
}

Game::~Game()
{
}

void Game::render(float currentZoom)
{
	sf::Vector2f viewCenter{m_window.getView().getCenter()};

	fromX = viewCenter.x / tileSizeF - 10;
	toX = viewCenter.x / tileSizeF + 10;
	fromY = viewCenter.y / tileSizeF - 6;
	toY = viewCenter.y / tileSizeF + 6;

	if (fromX < 0) {
		fromX = 0;
	}
	else if (fromX >= mapSize) {
		fromX = mapSize - 1;
	}

	if (toX < 0) {
		toX = 0;
	}
	else if (toX >= mapSize) {
		toX = mapSize - 1;
	}

	if (fromY < 0) {
		fromY = 0;
	}
	else if (fromY >= mapSize) {
		fromY = mapSize - 1;
	}

	if (toY < 0) {
		toY = 0;
	}
	else if (toY >= mapSize) {
		toY = mapSize - 1;
	}

	for (size_t x = fromX; x < toX; x++) {
		for (size_t y = fromY; y < toY; y++) {
			tileMap[x][y].setOutlineThickness(currentZoom);
			m_window.draw(tileMap[x][y]);
		}
	}
}
