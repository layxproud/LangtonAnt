#include "CameraControl.h"

CameraControl::CameraControl(const Game& game)
    : viewSpeed{ 500.f }
    , currentZoom{ 1.f }
    , zoomFactor{ 0.1f }
    , canZoom{ true }
{
    view.setSize(Game::winSizeF);
    view.setCenter({ Game::mapSize * Cell::cellSizeF / 2.f,
        Game::mapSize * Cell::cellSizeF / 2.f });
}

void CameraControl::updateInput(float dt)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::A)) {
        view.move({ -viewSpeed * dt, 0.f });
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::D)) {
        view.move({ viewSpeed * dt, 0.f });
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::W)) {
        view.move({ 0.f, -viewSpeed * dt });
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::S)) {
        view.move({ 0.f, viewSpeed * dt });
    }
    if (canZoom) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Up)) {
            view.zoom(0.9f);
            currentZoom *= 0.9f;
            canZoom = false;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Down)) {
            view.zoom(1.1f);
            currentZoom *= 1.1f;
            canZoom = false;
        }
    }
    if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Up)
        && !sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Down)) {
        canZoom = true;
    }
}
