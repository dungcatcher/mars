#include "././App.hpp"
#include "./State.hpp"

class MainMenu : public State
{
public:
	MainMenu();
	virtual ~MainMenu();
	void handleInput(sf::Event* event) override;
	void update() override;
	void draw(sf::RenderWindow* window) override;

private:
	sf::Texture _backgroundTexture;
	sf::Sprite _backgroundSprite;
};