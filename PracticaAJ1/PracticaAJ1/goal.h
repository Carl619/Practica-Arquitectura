#pragma once
#include "entitybase.h"

class Goal : public EntitiyBase {
private:
	bool finish;
public:
	Goal(vec2 pos);
	bool getFinish() { return finish; }
	void setFinish(bool f) { finish = f; }
};