#pragma once
#include "sys.h"
#include "core.h"
#include <string>

class Mode;
class GraphicMotor;
using namespace std;

class EndGameMenu {
private:
	string title;
	string retry;
	string exit;
	int chosenOption;
public:

	EndGameMenu();
	string getTitle() { return title; }
	string getRetry() { return retry; }
	string getExit() { return exit; }
	int getOpcion() { return chosenOption; }
	void playAgain(Mode * pila);
	void backMenu(Mode * pila);
	void render(GraphicMotor& motor);
	/*carga el idioma elegido del menu de idiomas y busca la carpeta con los textos en el idioma elegido*/
	void loadLanguage(string idioma);
	void chooseOption(int i);
	void executeOption(Mode * pila);
};