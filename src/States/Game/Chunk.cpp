#include "Chunk.hpp"
#include "App.hpp"
#include "SimplexNoise.h"

// Ocky pocky the ocky way
Chunk::Chunk()
{}

Chunk::Chunk(sf::Vector2i pos)
{
	_pos = pos;
	SimplexNoise chunkNoise = SimplexNoise();

	for (int x = 0; x < 16; x++)
	{
		for (int y = 0; y < 16; y++)
		{
			sf::Vector2i targetPos(pos.x * 16 + x, pos.y * 16 + y);
			float noiseValue = chunkNoise.noise(targetPos.x, targetPos.y);
			_noiseValues[y][x] = noiseValue;
		}
	}
}

void Chunk::draw(sf::RenderWindow* window)
{
	sf::RectangleShape tileRect;
	tileRect.setSize(sf::Vector2f(10.0f, 10.0f));

	for (int x = 0; x < 16; x++)
	{
		for (int y = 0; y < 16; y++)
		{
			sf::Vector2i tilePos(App::screenWidth / 2 + _pos.x * 16 * 10 + x * 10, App::screenHeight / 2 + _pos.y * 16 * 10 + y * 10);
			tileRect.setPosition(tilePos.x, tilePos.y);
			tileRect.setFillColor(sf::Color(_noiseValues[y][x] * 255, _noiseValues[y][x] * 255, _noiseValues[y][x] * 255));
			window->draw(tileRect);
		}
	}
}