#include "Game.hpp"
#include "../../App.hpp"

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
	int topLeftChunkX = floor((player.pixelPos.x - App::worldView.getCenter().x) / (CHUNK_SIZE * TILE_SIZE));
	int topLeftChunkY = floor((player.pixelPos.y - App::worldView.getCenter().y) / (CHUNK_SIZE * TILE_SIZE));

	int chunksVisibleX = ceil(App::worldView.getSize().x / (CHUNK_SIZE * TILE_SIZE));
	int chunksVisibleY = ceil(App::worldView.getSize().y / (CHUNK_SIZE * TILE_SIZE));

	for (int x = topLeftChunkX; x < chunksVisibleX; x++)
	{
		for (int y = topLeftChunkY; y < chunksVisibleY; y++)
		{
			std::string chunkString = std::to_string(x) + ',' + std::to_string(y);
			if (chunks.find(chunkString) == chunks.end())
			{
				Chunk chunk(sf::Vector2i(x, y));
				chunks[chunkString] = chunk;
				std::cout << chunkString << " ";
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
	for (auto p : chunks)
	{
		p.second.draw(window);
	}
}
