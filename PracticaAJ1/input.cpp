#include "input.h"

void Input::moveRight(Human* hum, float elapsed)
{
	if (SYS_KeyPressed('A')) {
		hum->modifyPos(elapsed);
	}
}

void Input::moveLeft(Human* hum, float elapsed)
{
	if (SYS_KeyPressed('D')) {
		hum->modifyPos(-elapsed);
	}
}

void Input::jump(Human * hum)
{
	if (SYS_KeyPressed(' ') && hum->canJump()) {
		hum->beginJump(1);
	}
}

void Input::executeOption(MainMenu * menu, Mode* mod)
{
	if (SYS_KeyPressed(VK_RETURN) && enter == false)enter = true;
	else if (!SYS_KeyPressed(VK_RETURN) && enter == true) {
		enter = false;
		menu->executeOption(mod);
	}
}

void Input::changeOption(MainMenu * menu)
{

	if (SYS_KeyPressed('W')&& w==false) {
		w = true;
	}
	else if (SYS_KeyPressed('S')&&s==false) {
		s = true;
	}

	if (!SYS_KeyPressed('W')&& w == true) {
		w = false;
		menu->chooseOption(menu->getOpcion() + 1);
		if (menu->getOpcion()>4)
			menu->chooseOption(1);
	}
	else if (!SYS_KeyPressed('S') && s==true) {
		s = false;
		menu->chooseOption(menu->getOpcion() - 1);
		if (menu->getOpcion()<1)
			menu->chooseOption(4);
	}
}

void Input::executeOption(MenuGameOver * menu, Mode * mod)
{
	if (SYS_KeyPressed(VK_RETURN) && enter == false)enter = true;
	else if (!SYS_KeyPressed(VK_RETURN)&&enter==true) {
		enter = false;
		menu->executeOption(mod);	
	}
}

void Input::changeOption(MenuGameOver * menu)
{

	if (SYS_KeyPressed('W') && w == false) {
		w = true;
	}
	else if (SYS_KeyPressed('S') && s == false) {
		s = true;
	}
	if (!SYS_KeyPressed('W') && w == true) {
		w = false;
		menu->chooseOption(menu->getOption() + 1);
		if (menu->getOption()>2)
			menu->chooseOption(1);
	}
	else if (!SYS_KeyPressed('S') && s == true) {
		s = false;
		menu->chooseOption(menu->getOption() - 1);
		if (menu->getOption()<1)
			menu->chooseOption(2);
	}
}

void Input::executeOption(EndGameMenu * menu, Mode * mod)
{
	if (SYS_KeyPressed(VK_RETURN) && enter == false)enter = true;
	else if (!SYS_KeyPressed(VK_RETURN) && enter == true) {
		enter = false;
		menu->executeOption(mod);
	}
}

void Input::changeOption(EndGameMenu * menu)
{
	if (SYS_KeyPressed('W') && w == false) {
		w = true;
	}
	else if (SYS_KeyPressed('S') && s == false) {
		s = true;
	}
	if (!SYS_KeyPressed('W') && w == true) {
		w = false;
		menu->chooseOption(menu->getOpcion() + 1);
		if (menu->getOpcion()>2)
			menu->chooseOption(1);
	}
	else if (!SYS_KeyPressed('S') && s == true) {
		s = false;
		menu->chooseOption(menu->getOpcion() - 1);
		if (menu->getOpcion()<1)
			menu->chooseOption(2);
	}
}

void Input::executeOption(LanguagesMenu * menu, Mode * mod)
{
	if (SYS_KeyPressed(VK_RETURN) && enter == false)enter = true;
	else if (!SYS_KeyPressed(VK_RETURN) && enter == true) {
		enter = false;
		menu->executeOption(mod);
	}
}

void Input::changeOption(LanguagesMenu * menu)
{
	if (SYS_KeyPressed('W') && w == false) {
		w = true;
	}
	else if (SYS_KeyPressed('S') && s == false) {
		s = true;
	}
	if (!SYS_KeyPressed('W') && w==true) {
		w = false;
		menu->chooseOption(menu->getOption() + 1);
		if (menu->getOption()>static_cast<int>(menu->getLanguages().size())+1)
			menu->chooseOption(1);
	}
	else if (!SYS_KeyPressed('S')&&s==true) {
		s = false;
		menu->chooseOption(menu->getOption() - 1);
		if (menu->getOption()<1)
			menu->chooseOption(menu->getLanguages().size() + 1);
	}
}

void Input::gameOverController(Mode * mod, MenuGameOver * menu)
{

	changeOption(menu);
	executeOption(menu, mod);
}

void Input::menuController(Mode * mod, MainMenu * menu)
{

	changeOption(menu);
	executeOption(menu,mod);
}

void Input::menuLanguageController(Mode * mod, LanguagesMenu * menu)
{

	changeOption(menu);
	executeOption(menu, mod);
}

void Input::endMenuController(Mode * mod, EndGameMenu * menu)
{

	changeOption(menu);
	executeOption(menu, mod);
}

void Input::humanController(Human * hum, float elapsed)
{
	 moveRight(hum, elapsed);

	 moveLeft(hum, elapsed);

	 jump(hum);
}
