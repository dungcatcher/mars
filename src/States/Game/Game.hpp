#include "../State.hpp"
#include "././App.hpp"

class GameState : public State
{
public:
	GameState();
	virtual ~GameState();
	void handleInput(sf::Event* event) override;
	void update() override;
	void draw(sf::RenderWindow* window) override;
};