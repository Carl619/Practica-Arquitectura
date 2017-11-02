#pragma once
#include <string>
#include "sys.h"
#include "core.h"


class Mode;
class GraphicMotor;
using namespace std;

class MenuGameOver {
private:
	string title ;
	string retry ;
	string exit;
	int chosenOption;
public:

	MenuGameOver();
	string getTitle() { return title; }
	
	string getReintentar() { return retry; }
	string getExit() { return exit; }
	int getOption() { return chosenOption; }
	void playAgain(Mode * pila);
	void render(GraphicMotor& motor);
	void back(Mode * pila);
	void loadLanguage(string idioma);
	void chooseOption(int i);
	void executeOption(Mode * pila);
};