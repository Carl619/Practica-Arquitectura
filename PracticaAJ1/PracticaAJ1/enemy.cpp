#include "enemy.h"


Enemy::Enemy(vec2 p):EntitiyBase(p)
{
	move = RIGHT;
	radio = 0;
	velocity = 70;
}

vec2 Enemy::getInipos()
{
	return inipos;
}

vec2 Enemy::getEndpos()
{
	return endpos;
}

void Enemy::setInipos(vec2 ini)
{
	inipos = ini;
}

void Enemy::setEndpos(vec2 end)
{
	endpos = end;
}

void Enemy::moveEnemy(float elapsed)
{
	if (move == RIGHT) {
		pos = { pos.x + velocity*elapsed,pos.y };
		collsion = Rect(pos.x, pos.y, 32, 32);

	}
	else if (move == LEFT) {
		pos = { pos.x - velocity * elapsed, pos.y };
		collsion = Rect(pos.x, pos.y, 32, 58);
	}
	if (pos.x >= endpos.x) {
		pos.x = endpos.x;
		move = LEFT;
	}
	else if (pos.x <= inipos.x) {
		pos.x = inipos.x;
		move = RIGHT;
	}
}
