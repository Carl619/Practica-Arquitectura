#include "stdafx.h"
#include "graphicmotor.h"
#include "font.h"




void GraphicMotor::loadTextures()
{
	GLuint texbkg = CORE_LoadPNG("data/circle-bkg-128.png", true);
	GLuint texhuman = CORE_LoadPNG("data/human.png", false);
	GLuint texplat = CORE_LoadPNG("data/platform.png", false);
	GLuint textrap = CORE_LoadPNG("data/trap.png", false);
	GLuint texene = CORE_LoadPNG("data/tyrian_ball.png", false);
	GLuint texfl = CORE_LoadPNG("data/flag.png", true);
	GLuint texarrow = CORE_LoadPNG("data/arrow.png", true);
	FONT_Init();

	mapTexture.insert(std::pair<std::string, GLuint>("Background", texbkg));
	mapTexture.insert(std::pair<std::string, GLuint>("Human", texhuman));
	mapTexture.insert(std::pair<std::string, GLuint>("Platform", texplat));
	mapTexture.insert(std::pair<std::string, GLuint>("Trap", textrap));
	mapTexture.insert(std::pair<std::string, GLuint>("Enemy", texene));
	mapTexture.insert(std::pair<std::string, GLuint>("Flag", texfl));
	mapTexture.insert(std::pair<std::string, GLuint>("Arrow", texarrow));

}

void GraphicMotor::initRendering() {
	glViewport(0, 0, SCR_WIDTH, SCR_HEIGHT); // Sets up clipping
	glClearColor(0.0f, 0.1f, 0.3f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, SCR_WIDTH, 0.0, SCR_HEIGHT, 0.0, 1.0);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void GraphicMotor::show() {
	SYS_Show();
}

void GraphicMotor::renderEntity(vec2 pos, float sizeX, float sizeY, std::string texture)
{
	CORE_RenderCenteredSprite(pos, vmake(sizeX, sizeY), mapTexture.at(texture));
}

void GraphicMotor::renderBackground()
{
	// Render backgground
	for (int i = 0; i <= SCR_WIDTH / 128; i++)
		for (int j = 0; j <= SCR_HEIGHT / 128; j++)
			CORE_RenderCenteredSprite(vmake(i * 128.f + 64.f, j * 128.f + 64.f), vmake(128.f, 128.f), mapTexture.find("Background")->second);
}

void GraphicMotor::renewRendering() {
	// Render
	glClear(GL_COLOR_BUFFER_BIT);
}

void GraphicMotor::drawText(vec2 pos, const char* text)
{
	FONT_DrawString(pos, text);
}

void GraphicMotor::unloadPNG()
{
	FONT_End();
	CORE_UnloadPNG(mapTexture.at("Background"));
	CORE_UnloadPNG(mapTexture.at("Human"));
	CORE_UnloadPNG(mapTexture.at("Platform"));
	CORE_UnloadPNG(mapTexture.at("Enemy"));
	CORE_UnloadPNG(mapTexture.at("Trap"));
	CORE_UnloadPNG(mapTexture.at("Flag"));
	CORE_UnloadPNG(mapTexture.at("Arrow"));
}
