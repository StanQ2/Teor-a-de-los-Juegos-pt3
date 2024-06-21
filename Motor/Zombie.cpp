#include "Zombie.h"
#include "Constantes.h" 
#include <random>
#include <ctime>
#include<glm/gtx/rotate_vector.hpp>


Zombie::Zombie()
{
}

Zombie::~Zombie()
{
}

void Zombie::init(float speed, glm::vec2 position)
{
	this -> speed = speed;
	this->position = position;
	color.set(0,255, 0,255);
	std::mt19937 randomEngine(time(nullptr));
	std::uniform_real_distribution<float>randDir(-1.0f, 1.0f);
	direction = glm::vec2(randDir(randomEngine), randDir(randomEngine));
	if (direction.length() == 0) {
		direction = glm::vec2(1.0f, 0.0f);
	}

}

void Zombie::update(vector<string>& levelData, vector<Human*>& humans, vector<Zombie*>& zombies)
{
	std::mt19937 randomEngine(time(nullptr));
	std::uniform_real_distribution<float>randRotate(-1.0f, 1.0f);
	position += direction * speed;
	if (collideWithLevel(levelData)) {
		direction.x = -direction.x; // Invertir la direcci�n horizontal
	}
s
}

