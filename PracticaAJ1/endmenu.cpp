#include "stdafx.h"
#include "endmenu.h"
#include "graphicmotor.h"
#include "gamemode.h"

EndGameMenu::EndGameMenu()
{
	chosenOption = 2;
}

void EndGameMenu::chooseOption(int i)
{
	chosenOption = i;
}

void EndGameMenu::playAgain(Mode * pila)
{
	pila->replaceState(State::BeginGame);
}

void EndGameMenu::backMenu(Mode * pila)
{
	pila->popState();
}

void EndGameMenu::executeOption(Mode * pila)
{
	if (chosenOption == 1) {
		backMenu(pila);
	}
	else if (chosenOption == 2) {
		playAgain(pila);
	}
}

void EndGameMenu::render(GraphicMotor& motor)
{

	motor.renewRendering();

	motor.renderBackground();

	motor.drawText(vmake(540, 600),title.c_str());

	motor.drawText(vmake(520, 500), retry.c_str());

	motor.drawText(vmake(550, 400),exit.c_str());

	motor.renderEntity(vmake(450, static_cast<float>(chosenOption) * 100 + 300), 75, 49, "Arrow");

	motor.show();
}

void EndGameMenu::loadLanguage(string idioma)
{
	string line;
	ifstream infile;
		infile.open("data/localization/" + idioma + "/end.txt");
		while (!infile.eof())
		{
			title.clear();
			getline(infile, line);
			title.insert(0, line);
			retry.clear();
			getline(infile, line);
			retry.insert(0, line);
			exit.clear();
			getline(infile, line);
			exit.insert(0, line);
		}
		infile.close();
}