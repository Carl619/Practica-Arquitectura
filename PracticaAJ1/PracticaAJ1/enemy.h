#pragma once
#include "entitybase.h"

#define RIGHT true
#define LEFT false


class Enemy : public EntitiyBase
{
private:
	vec2   inipos;
	vec2   endpos;
	bool move = RIGHT;
	float radio;
	int velocity;

public:
	Enemy(vec2 p);
	float getRadio() { return radio; }
	void setRadio(float r) { radio = r;}
	int getVelocity() { return velocity; }
	void setVelocity(int vel) { velocity = vel; }
	vec2 getInipos();
	vec2 getEndpos();
	void setInipos(vec2   ini);
	void setEndpos(vec2   end);
	void moveEnemy(float elapsed);
};
