#include "Platform/Platform.hpp"

#include "States/Game/Game.hpp"
#include "States/Menu/Menu.hpp"
#include "app.hpp"

float App::_screenScalingFactor;
App::EnumStates App::_currentState;
std::map<App::EnumStates, State*> App::_stateInstances;
sf::RenderWindow App::_window;
sf::Event App::_event;
sf::View App::worldView;

void App::start()
{
	util::Platform platform;

	// in Windows at least, this must be called before creating the window
	_screenScalingFactor = platform.getScreenScalingFactor(_window.getSystemHandle());
	// Use the screenScalingFactor
	_window.create(sf::VideoMode(screenWidth * _screenScalingFactor, screenHeight * _screenScalingFactor), "Mars");
	_window.setFramerateLimit(60);
	platform.setIcon(_window.getSystemHandle());

	// Initialise state instances
	_stateInstances[Playing] = new GameState();
	_stateInstances[Menu] = new MainMenu();

	_currentState = Menu;

	worldView.reset(sf::FloatRect(0.0f, 0.0f, screenWidth, screenHeight));

	run();
}

void App::run()
{
	while (_window.isOpen())
	{
		State* currentState = _stateInstances[_currentState];

		while (_window.pollEvent(_event))
		{
			if (_event.type == sf::Event::Closed)
				_window.close();
			currentState->handleInput(&_event);
		}

		_window.clear();

		// Update current state instance
		currentState->update();
		currentState->draw(&_window);

		_window.display();
	}
}

void App::setState(App::EnumStates state)
{
	_currentState = state;
}