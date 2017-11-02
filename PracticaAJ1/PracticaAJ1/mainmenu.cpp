#include "stdafx.h"
#include "mainmenu.h"
#include "graphicmotor.h"
#include "gamemode.h"

MainMenu::MainMenu()
{
	chosenOption =4;
}

void MainMenu::chooseOption(int i)
{
	chosenOption = i;
}

void MainMenu::executeOption(Mode * pila)
{
	if (chosenOption == 1) {
		exitGame(pila);
	}

	else if (chosenOption == 2) {
		selectLanguages(pila);
	}

	else if(chosenOption == 3) {
		loadGame(pila);
	}

	else if (chosenOption == 4) {
		beginGame(pila);
	}
}

void MainMenu::render(GraphicMotor& motor)
{

	motor.renewRendering();

	motor.renderBackground();

	motor.drawText(vmake(500, 500),title.c_str());

	motor.drawText(vmake(550, 400),begin.c_str());

	motor.drawText(vmake(550, 300), load.c_str());

	motor.drawText(vmake(560, 200), languages.c_str());

	motor.drawText(vmake(560, 100), exit.c_str());

	motor.renderEntity(vmake(450, static_cast<float>(chosenOption) * 100), 75, 49, "Arrow");

	motor.show();
}


void MainMenu::beginGame(Mode * pila)
{
	pila->pushState(State::BeginGame);
}

void MainMenu::selectLanguages(Mode * pila)
{
	pila->pushState(State::Settings);
}

void MainMenu::loadGame(Mode * pila)
{
	pila->pushState(State::LoadGame);
}


void MainMenu::exitGame(Mode * pila)
{
	pila->pushState(State::Exit);
}

void MainMenu::loadLanguage(string idioma)
{
	string line;
	ifstream infile;
	infile.open("data/localization/"+idioma + "/mainmenu.txt");
		while (!infile.eof())
		{
			title.clear();
			getline(infile, line);
			title.insert(0, line);
			begin.clear();
			getline(infile, line);
			begin.insert(0, line);
			load.clear();
			getline(infile, line);
			load.insert(0, line);
			languages.clear();
			getline(infile, line);
			languages.insert(0, line);
			exit.clear();
			getline(infile, line);
			exit.insert(0, line);
		}
		infile.close();
	
}