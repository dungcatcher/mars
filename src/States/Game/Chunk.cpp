#include "Chunk.hpp"
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
			std::cout << noiseValue << "\n";
			_noiseValues[y][x] = noiseValue;
		}
	}
}

void Chunk::draw(sf::RenderWindow* window)
{
}