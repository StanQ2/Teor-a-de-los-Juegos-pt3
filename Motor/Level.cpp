#include "Level.h"
#include <fstream>
#include "ResourceManager.h"
#include "Error.h"

Level::Level(const string& fileName)
{
	ifstream file;
	file.open(fileName);
	if (file.fail()) {
		fatalError("Fallo al abrir " + fileName);
	}
	string tmp;
	file >> tmp >> numHumans;
	getline(file, tmp);
	while (getline(file, tmp)) {
		levelData.push_back(tmp);
	}

	parseLevel();
}

void Level::parseLevel()
{
	spritebatch.init();
	spritebatch.begin();
	glm::vec4 uvRect(0.0f, 0.0f, 1.0f, 1.0f);
	Color color;
	color.set(255, 255, 255, 255);
	for (size_t y = 0; y < levelData.size(); y++)
	{
		for (size_t x = 0; x < levelData[y].size(); x++)
		{
			char tile = levelData[y][x];
			glm::vec4 destRect(x * TILE_WIDTH, y * TILE_WIDTH,
				TILE_WIDTH, TILE_WIDTH);
			switch (tile)
			{
			case 'R':
			case 'B':
				spritebatch.draw(destRect, uvRect,
					ResourceManager::getTexture("Images/red_bricks.png").id,
					0.0f,color);
				break;
			case 'G':
				spritebatch.draw(destRect, uvRect,
					ResourceManager::getTexture("Images/glass.png").id,
					0.0f, color);
				break;
			case 'L':
				spritebatch.draw(destRect, uvRect,
					ResourceManager::getTexture("Images/light_bricks.png").id,
					0.0f, color);
				break;
			case '@':
				levelData[y][x] = '.';
				playerPosition.x = x * TILE_WIDTH;
				playerPosition.y = y * TILE_WIDTH;
				break;
			case 'Z':
				levelData[y][x] = '.';
				zombiePositions.push_back(glm::vec2(x * TILE_WIDTH, y * TILE_WIDTH));
				break;
			case '.':
				break;
			default:
				break;
			}
		}
	}
	spritebatch.end();
}

void Level::draw()
{
	spritebatch.renderBatch();
}

Level::~Level()
{
}
