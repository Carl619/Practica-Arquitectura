#pragma once


#include "enemy.h"
#include "human.h"
#include "platform.h"
#include "trap.h"
#include "math.h"
#include "goal.h"
#include <vector>
/*la funcion collide llama a las demas funciones de colisiones, asi la logica del juego llama a una sola funcion para hacer uso de la colisiones*/
bool collide(Human * hum, Goal*gl,std::vector<Platform*> platforms, std::vector<Enemy*> enemies, std::vector<Trap*> traps);
void collidePlatforms(std::vector<Platform*> platforms, Human * hum);
void collideGoal(Goal* gl, Human * hum);
bool collideEnemies(std::vector<Enemy*> enemies, Human hum);
bool collideTraps(std::vector<Trap*> traps, Human hum);