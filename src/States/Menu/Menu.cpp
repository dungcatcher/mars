#include "Menu.hpp"

MainMenu::MainMenu()
{
}

MainMenu::~MainMenu()
{}

void MainMenu::handleInput(sf::Event* event)
{
	if (event->type == sf::Event::MouseButtonReleased)
	{
		App::setState(App::Playing);
	}
}
void MainMenu::update()
{
}
void MainMenu::draw(sf::RenderWindow* window)
{
	UNUSED(window);
}
