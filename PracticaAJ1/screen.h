#pragma once


#include "sys.h"
#include "core.h"
#include "enemy.h"
#include "human.h"
#include "platform.h"
#include "trap.h"
#include "goal.h"


#define NUM_ENEMIES 5
#define NUM_TRAPS 3

class GraphicMotor;

class Screen {
private:
	std::vector<Enemy*> enemies;
	std::vector<Platform*> platforms;
	std::vector<Trap*> traps;
	std::string ID;
	Goal*goal;
	Human * hum;
	/*carga desde el archivo del nivel todos los datos
	Humano, plataformas,trampas, enemigos y la meta
	cargando la posicion donde empiezan y
	hasta donde se mueven  si es necesario*/
	void initHuman();
	void initEnemies();
	void initTraps();
	void initPlatforms();
	void initGoal();
public:
	Screen(std::string i);
	void prepareScreen();
	void render(GraphicMotor * motor);
	void setHuman(Human *h);
	void setGoal(Goal *g) { goal = g; }
	std::vector<Enemy*> getEnemies();
	std::vector<Platform*> getPlatforms();
	std::vector<Trap*> getTraps();
	Human *getHuman();
	Goal *getGoal() { return goal; }

};



