#include "Game.h"
#include <iostream>

Game::Game(sf::RenderWindow& window)
	: m_window{window}
	, m_tileMap{}
	, fromX{}
	, toX{}
	, fromY{}
	, toY{}
	, ant{}
	, isAntDrawn{false}
	, moveTimer{0.f}
	, moveDelay{0.1f}
{

	// Init tiles
	m_tileMap.resize(mapSize, std::vector<Cell>());
	for (size_t x = 0; x < mapSize; x++) {
		m_tileMap[x].resize(mapSize, Cell());
		for (size_t y = 0; y < mapSize; y++) {
			m_tileMap[x][y].setSize({ Cell::cellSizeF, Cell::cellSizeF });
			m_tileMap[x][y].setFillColor(sf::Color::Transparent);
			m_tileMap[x][y].setOutlineColor(sf::Color::Black);
			m_tileMap[x][y].setPosition({ x * Cell::cellSizeF, y * Cell::cellSizeF });
		}
	}

	// Init ant
	ant.setPosition({ (mapSize - 1) / 2 * Cell::cellSizeF,
		(mapSize - 1) / 2 * Cell::cellSizeF }); // Middle of the map
}

Game::~Game()
{
}

void Game::render(float currentZoom)
{
	m_viewCenter = { m_window.getView().getCenter() };

	fromX = m_viewCenter.x / Cell::cellSizeF - 10;
	toX = m_viewCenter.x / Cell::cellSizeF + 10;
	fromY = m_viewCenter.y / Cell::cellSizeF - 6;
	toY = m_viewCenter.y / Cell::cellSizeF + 6;

	if (fromX < 0) {
		fromX = 0;
	} else if (fromX >= mapSize) {
		fromX = mapSize - 1;
	}

	if (toX < 0) {
		toX = 0;
	} else if (toX >= mapSize) {
		toX = mapSize - 1;
	}

	if (fromY < 0) {
		fromY = 0;
	} else if (fromY >= mapSize) {
		fromY = mapSize - 1;
	}

	if (toY < 0) {
		toY = 0;
	} else if (toY >= mapSize) {
		toY = mapSize - 1;
	}

	// Draw only visible cells
	isAntDrawn = false;
	for (size_t x = fromX; x < toX; x++) {
		for (size_t y = fromY; y < toY; y++) {
			Cell& cell = m_tileMap[x][y];

			cell.setOutlineThickness(currentZoom);

			// Fill color based on visited state
			if (cell.isVisited()) {
				cell.setFillColor(Cell::Gray);  // Visited (gray)
			}
			else {
				cell.setFillColor(sf::Color::White);  // Not visited (white)
			}

			// Ant rendering
			if (!isAntDrawn && cell.getPosition() == ant.getPosition()) {
				cell.setFillColor(sf::Color::Red);
				isAntDrawn = true;
			}

			m_window.draw(cell);
		}
	}
}

void Game::update(float dt)
{
	moveTimer += dt;
	if (moveTimer < moveDelay)
		return;

	moveTimer = 0.f;

	sf::Vector2f antPos = ant.getPosition();
	size_t x = antPos.x / Cell::cellSizeF;
	size_t y = antPos.y / Cell::cellSizeF;

	if (x >= mapSize || y >= mapSize) return;

	Cell& cell = m_tileMap[x][y];

	bool wasVisited = cell.isVisited();
	cell.changeCellStatus();
	std::cout << cell.isVisited() << std::endl;

	ant.turn(wasVisited);
	ant.moveForward();

	// std::cout << ant.getPosition().x << ";" << ant.getPosition().y << std::endl;
}
