#include "initGame.h"

Human initHuman(GLuint texhuman) {
	Human hum;
	hum.pos = vmake(10, 90);
	hum.gfx = texhuman;

	hum.collsion = { (int)hum.pos.x,(int)hum.pos.y,32,58 };
	return hum;
}

std::vector<Enemy> initEnemies(GLuint texenemy, const int numberEnemies) {
	std::vector<Enemy> enemies;

	Enemy ene;
	ene.pos = vmake(700, 90);
	ene.inipos = vmake(700, 90);
	ene.endpos = vmake(800, 90);
	ene.gfx = texenemy;
	enemies.push_back(ene);
	ene.pos = vmake(600, 90);
	ene.inipos = vmake(600, 90);
	ene.endpos = vmake(700, 90);
	ene.gfx = texenemy;
	enemies.push_back(ene);
	ene.pos = vmake(400, 90);
	ene.inipos = vmake(400, 90);
	ene.endpos = vmake(500, 90);
	ene.gfx = texenemy;
	enemies.push_back(ene);
	ene.pos = vmake(1000, 90);
	ene.inipos = vmake(1000, 90);
	ene.endpos = vmake(1100, 90);
	ene.gfx = texenemy;
	enemies.push_back(ene);
	ene.pos = vmake(200, 90);
	ene.inipos = vmake(200, 90);
	ene.endpos = vmake(300, 90);
	ene.gfx = texenemy;
	enemies.push_back(ene);

	for (int i = 0; i < numberEnemies; i++)
		enemies[i].collsion = { (int)enemies[i].pos.x,(int)enemies[i].pos.y,32,32 };

	return enemies;
}

std::vector<Trap> initTraps(GLuint textrap, const  int numberTraps) {
	std::vector<Trap> traps;
	Trap trap;
	trap.pos = vmake(150, 80);
	trap.gfx = textrap;
	traps.push_back(trap);
	trap.pos = vmake(900, 80);
	trap.gfx = textrap;
	traps.push_back(trap);
	trap.pos = vmake(500, 80);
	trap.gfx = textrap;
	traps.push_back(trap);



	for (int i = 0; i < numberTraps; i++)
		traps[i].collsion = { (int)traps[i].pos.x + 20,(int)traps[i].pos.y,10,64 };

	return traps;

}

std::vector<Platform> initPlatforms(GLuint texplatf, const  int numberPlatfmors) {
	std::vector<Platform> platforms;
	Platform plat;
	for (int i = 0; i < numberPlatfmors; i++)
	{
		plat.pos = { 0 + i * 300.f,10.f };
		plat.gfx = texplatf;
		platforms.push_back(plat);

	}

	return platforms;
}