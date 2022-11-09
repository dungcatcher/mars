#pragma once

#include "States/State.hpp"

class App
{
public:
	static void start();
	static void run();

	constexpr static float SCREEN_WIDTH = 840.0f;
	constexpr static float SCREEN_HEIGHT = 480.0f;
	static float _screenScalingFactor;

	enum EnumStates
	{
		Playing,
		Menu
	};
	static void setState(EnumStates state);

private:
	static EnumStates _currentState;
	static std::map<EnumStates, State*> _stateInstances;

	static sf::RenderWindow _window;
	static sf::Event _event;
};