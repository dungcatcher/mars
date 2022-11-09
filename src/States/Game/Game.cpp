#include "Game.hpp"

GameState::GameState()
{
}

GameState::~GameState()
{}

void GameState::handleInput(sf::Event* event)
{
	if (event->type == sf::Event::MouseButtonReleased)
	{
		App::setState(App::Menu);
	}
}
void GameState::update()
{}
void GameState::draw(sf::RenderWindow* window)
{
	window->clear(sf::Color::Black);
}
