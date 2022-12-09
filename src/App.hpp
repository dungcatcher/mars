#pragma once

#include "States/State.hpp"

class App
{
public:
	static void start();
	static void run();

	constexpr static float screenWidth = 840.0f;
	constexpr static float screenHeight = 480.0f;
	static float _screenScalingFactor;

	static sf::View worldView;

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