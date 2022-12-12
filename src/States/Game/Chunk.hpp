class Chunk
{
public:
	sf::Vector2i _pos;
	float _noiseValues[16][16];

	Chunk();
	Chunk(sf::Vector2i pos);
	void draw(sf::RenderWindow* window);
};