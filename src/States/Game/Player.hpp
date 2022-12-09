#pragma once

class Player
{
public:
	Player();

	sf::Vector2f tilePos;
	sf::Vector2i chunkPos;
	sf::Vector2f pixelPos; // Pixel displacement from chunk (0, 0) tile (0, 0)
};