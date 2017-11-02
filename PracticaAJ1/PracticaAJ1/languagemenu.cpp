#include "stdafx.h"
#include "languagemenu.h"
#include "graphicmotor.h"
#include "gamemode.h"

LanguagesMenu::LanguagesMenu()
{
	chosenOption = 1;
	currentLanguage = string("esp");
}

void LanguagesMenu::chooseOption(int i)
{
	chosenOption = i;
}

void LanguagesMenu::backToMenu(Mode * pila)
{
	pila->popState();
}

void LanguagesMenu::executeOption(Mode * pila)
{
	string idioma;
	if (chosenOption == 1) {
		backToMenu(pila);
	}
	else if (chosenOption >1) {
		if (chosenOption == 3)
			idioma = "eng";
		else if (chosenOption == 2)
			idioma = "esp";
		pila->setLanguage(idioma);
	}
}

void LanguagesMenu::render(GraphicMotor& motor)
{
	motor.renewRendering();

	motor.renderBackground();

	motor.drawText(vmake(540, 600), title.c_str());

	for (int i =Languages.size() - 1; i >= 0; i--) {
		motor.drawText(vmake(520, 600 - (static_cast<float>(Languages.size()) - i) * 100), Languages[i].c_str());
	}

	motor.drawText(vmake(550, 300),back.c_str());

	motor.renderEntity(vmake(450, static_cast<float>(chosenOption) * 100 + 200), 75, 49, "Arrow");

	motor.show();
}

void LanguagesMenu::loadLanguage(string idioma)
{
	string line;
	ifstream infile;
	infile.open("data/localization/" + idioma + "/language.txt");
	currentLanguage = idioma;
	back.clear();
	Languages.clear();
	title.clear();
	getline(infile, line);
	title.insert(0, line);
	getline(infile, line);
	back.insert(0, line);
	while (!infile.eof())
	{
		getline(infile, line);
		Languages.push_back(line);
	}
	infile.close();
}