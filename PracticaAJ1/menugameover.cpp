#include "stdafx.h"
#include "menugameover.h"
#include "graphicmotor.h"
#include "gamemode.h"

MenuGameOver::MenuGameOver()
{
	chosenOption = 2;
}

void MenuGameOver::chooseOption(int i)
{
	chosenOption = i;
}

void MenuGameOver::playAgain(Mode * pila)
{
	pila->replaceState(State::BeginGame);
}

void MenuGameOver::back(Mode * pila)
{
	pila->popState();
}

void MenuGameOver::executeOption(Mode * pila)
{
	if (chosenOption == 1) {
		back(pila);
	}
	else if (chosenOption == 2) {
		playAgain(pila);
	}
}


void MenuGameOver::render(GraphicMotor& motor)
{

	motor.renewRendering();

	motor.renderBackground();

	motor.drawText(vmake(540, 600), title.c_str());

	motor.drawText(vmake(520, 500), retry.c_str());

	motor.drawText(vmake(550, 400), exit.c_str());

	motor.renderEntity(vmake(450, static_cast<float>(chosenOption) * 100 + 300), 75, 49, "Arrow");

	motor.show();
}
void MenuGameOver::loadLanguage(string idioma)
{
	string line;
	ifstream infile;
		infile.open("data/localization/"+idioma + "/gameover.txt");
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
