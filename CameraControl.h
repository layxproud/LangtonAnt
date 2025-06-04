#pragma once
#include "Game.h"

class CameraControl
{
public:
	CameraControl(const Game& game);

	void updateInput(float dt);

	sf::View getView() const { return view; }
	float getCurrentZoom() const { return currentZoom; }
private:
	sf::View view;

	float viewSpeed;
	float currentZoom;
	float zoomFactor;
	bool canZoom;
};

