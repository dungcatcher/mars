#include "../State.hpp"
#include "././App.hpp"
#include "Chunk.hpp"
#include "Player.hpp"

class GameState : public State
{
public:
	GameState();
	virtual ~GameState();
	void handleInput(sf::Event* event) override;
	void update() override;
	void draw(sf::RenderWindow* window) override;

	void loadChunks();

	Player player;
	std::map<std::string, Chunk> chunks;
};