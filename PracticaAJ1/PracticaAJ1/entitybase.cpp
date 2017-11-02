#include "entitybase.h"



EntitiyBase::EntitiyBase(vec2 p)
{
	pos = p;
}

EntitiyBase::EntitiyBase()
{
}

vec2 EntitiyBase::getPos()
{
	return pos;
}

Rect EntitiyBase::getCollsion()
{
	return collsion;
}

void EntitiyBase::setPos(vec2 Pos)
{
	pos = Pos;
}


void EntitiyBase::setCollsion(Rect col)
{
	collsion = col;
}
