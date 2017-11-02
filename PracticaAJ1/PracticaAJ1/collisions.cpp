#include "collisions.h"

bool collide(Human * hum, Goal*gl,std::vector<Platform*> platforms, std::vector<Enemy*> enemies, std::vector<Trap*> traps)
{
	collidePlatforms(platforms, hum);
		if (collideEnemies(enemies, *hum))
			return true;

		if (collideTraps(traps, *hum))
			return true;
		collideGoal(gl, hum);
	return false;
}

void collidePlatforms(std::vector<Platform*> platforms, Human * hum)
{
	for (int j = 0; j < static_cast<int>(platforms.size()); j++)
	{
		if (platforms[j]->getPos().y + 75 >= hum->getPos().y) {
			hum->setPos({ hum->getPos().x,platforms[j]->getPos().y + 75 });
			hum->onFloor();
		}
	}
}

void collideGoal(Goal * gl, Human * hum)
{
	if (rectOverlap(hum->getCollsion(),gl->getCollsion()))
		gl->setFinish(true);
}

bool collideEnemies(std::vector<Enemy*> enemies, Human hum)
{
	for (int i = 0; i < static_cast<int>(enemies.size()); i++)
		if (enemies[i]->getRadio() > 0) {
			if (CircleToRect(enemies[i]->getPos().x, enemies[i]->getPos().y, enemies[i]->getRadio(), hum.getCollsion().getX(), hum.getCollsion().getY(), hum.getCollsion().getWidth(), hum.getCollsion().getHeight()))
				return true;
		}
		else
		if (rectOverlap(hum.getCollsion(),enemies[i]->getCollsion()))
			return true;
	return false;
}

bool collideTraps(std::vector<Trap*> traps, Human hum)
{
	for (int i = 0; i < static_cast<int>(traps.size()); i++)
		if (rectOverlap(hum.getCollsion(), traps[i]->getCollsion()))
			return true;
	return false;
}
