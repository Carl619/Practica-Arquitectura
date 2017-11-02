#pragma once
#include "human.h"
#include "gamemode.h"
#include "mainmenu.h"
#include "menugameover.h"
#include "endmenu.h"
#include "languagemenu.h"

class Input {
private:
	bool w;
	bool s;
	bool enter;
public:
	Input() { w = false; s = false; enter = false; }
	void moveRight(Human* hum, float elapsed);

	void moveLeft(Human* hum, float elapsed);

	void jump(Human* hum);

	void executeOption(MainMenu* menu, Mode* mod);

	void changeOption(MainMenu* menu);

	void executeOption(MenuGameOver* menu, Mode* mod);

	void changeOption(MenuGameOver* menu);

	void executeOption(EndGameMenu* menu, Mode* mod);

	void changeOption(EndGameMenu* menu);

	void executeOption(LanguagesMenu* menu, Mode* mod);

	void changeOption(LanguagesMenu* menu);

	void gameOverController(Mode* mod, MenuGameOver* menu);

	void menuController(Mode* mod, MainMenu* menu);

	void menuLanguageController(Mode* mod, LanguagesMenu* menu);

	void endMenuController(Mode* mod, EndGameMenu* menu);
	
	void humanController(Human * hum, float elapsed);
};
