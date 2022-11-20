#include "Game.hpp"
#include "../../App.hpp"
#include "PerlinNoise.hpp"

const int CHUNK_SIZE = 16;
const int TILE_SIZE = 10;

GameState::GameState()
{
	player = Player();
	loadChunks();
}

GameState::~GameState()
{}

void GameState::loadChunks()
{
	// Amount of chunks to be loaded in each direction
	int chunksX = ceil(App::screenWidth / (CHUNK_SIZE * TILE_SIZE));
	int chunksY = ceil(App::screenHeight / (CHUNK_SIZE * TILE_SIZE));

	// Must be odd so that the centre chunk is in the middle
	if (chunksX % 2 == 0)
		chunksX++;
	if (chunksY % 2 == 0)
		chunksY++;

	for (int x = -int(chunksX / 2); x <= int(chunksX / 2); x++)
	{
		for (int y = -int(chunksY / 2); y <= int(chunksY / 2); y++)
		{
			sf::Vector2i targetChunkPos(x + player.chunkPos.x, y + player.chunkPos.y);
			std::string targetChunkString = std::to_string(targetChunkPos.x) + ", " + std::to_string(targetChunkPos.y);

			if (!chunks.count(targetChunkString))
			{
				Chunk chunk = Chunk();
				this->chunks[targetChunkString] = chunk;
			}
		}
	}
}

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
	window->clear(sf::Color::White);
}
