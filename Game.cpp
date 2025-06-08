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
	ant.setMapSize(mapSize - 1);
}

Game::~Game()
{
}

void Game::render(float currentZoom)
{
	m_viewCenter = m_window.getView().getCenter();
	sf::Vector2f viewSize = m_window.getView().getSize();

	int halfVisibleCellsX = static_cast<int>((viewSize.x / Cell::cellSizeF) / 2.f) + 2;
	int halfVisibleCellsY = static_cast<int>((viewSize.y / Cell::cellSizeF) / 2.f) + 2;

	fromX = static_cast<int>(m_viewCenter.x / Cell::cellSizeF) - halfVisibleCellsX;
	toX = static_cast<int>(m_viewCenter.x / Cell::cellSizeF) + halfVisibleCellsX;
	fromY = static_cast<int>(m_viewCenter.y / Cell::cellSizeF) - halfVisibleCellsY;
	toY = static_cast<int>(m_viewCenter.y / Cell::cellSizeF) + halfVisibleCellsY;

	fromX = std::max(0, fromX);
	toX = std::min(static_cast<int>(mapSize) - 1, toX);
	fromY = std::max(0, fromY);
	toY = std::min(static_cast<int>(mapSize) - 1, toY);

	isAntDrawn = false;
	for (size_t x = fromX; x < toX; x++) {
		for (size_t y = fromY; y < toY; y++) {
			Cell& cell = m_tileMap[x][y];

			cell.setOutlineThickness(currentZoom);

			if (cell.isVisited()) {
				cell.setFillColor(Cell::Gray);  // Visited (gray)
			}
			else {
				cell.setFillColor(sf::Color::White);  // Not visited (white)
			}

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

	ant.turn(wasVisited);
	ant.moveForward();
}
