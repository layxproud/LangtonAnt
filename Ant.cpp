#include "Ant.h"

Ant::Ant()
	: active(false)
	, m_cellSize(100.f)
{}

Ant::~Ant()
{}

void Ant::draw(sf::RenderWindow & window, const sf::Vector2f & position) const
{
	sf::RectangleShape rect({ m_cellSize, m_cellSize });
	rect.setFillColor(active? sf::Color(128, 128, 128) : sf::Color::White );
	rect.setOutlineColor(sf::Color::Black);
	rect.setOutlineThickness(1);
	rect.setPosition(position);
	window.draw(rect);
}


