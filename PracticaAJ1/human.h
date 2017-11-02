#pragma once
#include "entitybase.h"


#define JUMP_HEIGHT  110
#define JUMPS 1

class Human : public EntitiyBase
{
private:
	int jumps;
	bool isJumping;
	float alt;
	int velocity;
public:
	Human(vec2 p);
	Human();
	void modifyPos(const float desp);

	void beginJump( const int desp);

	void jumping(float elapsed);

	void falling(float elapsed);

	void limitJump();

	void controlJump(float elapsed);

	void onFloor();

	bool canJump();
};



