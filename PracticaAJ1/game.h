#pragma once
#include <vector>
#include "input.h"
#include "screen.h"
#include "graphicmotor.h"
#include "gamemode.h"
#include"screen.h"
#include "collisions.h"
#include "mainmenu.h"
#include "menugameover.h"
#include "endmenu.h"
#include "languagemenu.h"


class Game
{
private:
	static Game* game;
	GraphicMotor* graphics;
	Input* inputManager;
	int currentLevel;
	int endLevel;
	Screen* screen;
	Game();
public:
	static Game& Instance();
	int getCurrentLevel() { return currentLevel; }
	void setCurrentLevel(int level) {currentLevel=level; }
	Input* getInput() { return inputManager; }
	GraphicMotor* getGraphicMotor() { return graphics; }
	void levelFinished(Mode *modo);
	bool collisions();
	void moveEnemies(float elapsed);
	void loadScreen(int screenActual);
	int logic(float elapsed);
	void jumpLogic(float elapsed);
	Screen* getScreen() { return screen; }
	void save();
	bool load();
	void play(Mode *modo);
	//inicializa las colisiones de las entidades
	void initCollisions(Screen *sc);
};