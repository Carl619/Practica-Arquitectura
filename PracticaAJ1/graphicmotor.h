#pragma once


#include "sys.h"
#include "core.h"
#include "enemy.h"
#include "human.h"
#include "platform.h"
#include "trap.h"
#include "screen.h"
#include <map>
#include <string>



class GraphicMotor {
private:

	std::map<std::string, GLuint> mapTexture;

public:
	GraphicMotor() {};

	void renderEntity(vec2 pos, float sizeX, float sizeY, std::string texture);
	void loadTextures();
	void show();
	void initRendering();
	void renderBackground();
	void renewRendering();
	void drawText(vec2 pos, const char* text);
	void unloadPNG();

};

