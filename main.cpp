#include "Game.h"
#include "CameraControl.h"

int main()
{
	float dt{ 0.f };
	sf::Clock dtClock;

	sf::RenderWindow window(sf::VideoMode({ 1920, 1080 }), "Langtons Ant");
	window.setFramerateLimit(120);

	Game game(window);

	CameraControl cameraControl(game);

	while (window.isOpen()) {
		dt = dtClock.restart().asSeconds();

		// Events
		while (const std::optional event = window.pollEvent()) {
			if (event->is<sf::Event::Closed>()) {
				window.close();
			}
		}

        // Update
        // Update camera
		cameraControl.updateInput(dt);

		// Render
		window.clear(sf::Color::White);

		// Render game
        window.setView(cameraControl.getView());
		game.render(cameraControl.getCurrentZoom());

		// Renfer UI
		window.setView(window.getDefaultView());
		window.display();
		
	}
}
