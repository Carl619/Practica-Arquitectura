#include "human.h"

Human::Human(vec2 p):EntitiyBase(p)
{
	 jumps = JUMPS;
	 isJumping = false;
	 alt = JUMP_HEIGHT;
	 velocity = 100;
}

Human::Human():EntitiyBase()
{
}

void Human::modifyPos( const float desp)
{
	pos = { pos.x - velocity * desp,pos.y };
	collsion = Rect(pos.x, pos.y, 32, 58);
}

void Human::beginJump( const int desp)
{
	isJumping = true;
	alt = JUMP_HEIGHT;
	jumps = jumps-desp;
}

void Human::jumping(const float elapsed)
{
	if (isJumping)
	{
		pos = { pos.x,pos.y + velocity *elapsed};
		collsion = Rect(pos.x, pos.y, 32, 58);
		alt -= velocity *elapsed;
	}
}

void Human::falling(const float elapsed)
{
	if (!isJumping) {
		pos = { pos.x,pos.y - velocity *elapsed};
		collsion = Rect(pos.x, pos.y, 32, 58);
	}
}

void Human::limitJump()
{
	if (alt <= 0)
	{
		isJumping = false;
	}
}

void Human::onFloor() {
	jumps = JUMPS;
}
bool Human::canJump()
{
	if (jumps > 0)
		return true;
	else return false;
}
void Human::controlJump(float elapsed)
{
	jumping(elapsed);

	falling(elapsed);

	limitJump();
}
