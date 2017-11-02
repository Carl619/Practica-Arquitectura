#pragma once

#include "stdafx.h"
#include "sys.h"
#include "core.h"
#include "rect.h"

class EntitiyBase {
protected:
	vec2   pos;
	Rect collsion;
public:
	EntitiyBase(vec2 p);
	EntitiyBase();
	vec2 getPos();
	Rect getCollsion();
	void setPos(vec2 Pos);
	void setCollsion(Rect col);
};