#pragma once

class State
{
public:
	State();
	virtual ~State() {};
	virtual void handleInput(sf::Event* event) = 0;
	virtual void update() = 0;
	virtual void draw(sf::RenderWindow* window) = 0;
};