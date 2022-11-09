#include "Menu.hpp"

MainMenu::MainMenu()
{
	_backgroundTexture.loadFromFile("./content/title_screen.png");
	_backgroundSprite.setTexture(_backgroundTexture);
	_backgroundSprite.setPosition(0, 0);

	float backgroundScale = (App::SCREEN_WIDTH / _backgroundTexture.getSize().x) * App::_screenScalingFactor;
	std::cout << backgroundScale << "\n";
	_backgroundSprite.setScale(backgroundScale, backgroundScale);
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
	window->draw(_backgroundSprite);
}
