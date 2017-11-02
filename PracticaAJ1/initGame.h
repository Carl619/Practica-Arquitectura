#pragma once

#include "stdafx.h"
#include "sys.h"
#include "core.h"
#include "enemy.h"
#include "human.h"
#include "platform.h"
#include "trap.h"
#include <vector>


Human initHuman(GLuint texhuman);

std::vector<Enemy> initEnemies(GLuint texenemy,int numberEnemies);

std::vector<Trap> initTraps(GLuint textrap,int numberTraps);

std::vector<Platform> initPlatforms(GLuint texplatf, int numberPlatfmors);