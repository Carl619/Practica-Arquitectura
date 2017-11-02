#pragma once
#include "sys.h"
#include "core.h"
#include <string>

class Mode;
class GraphicMotor;
using namespace std;

class MainMenu {
private:
	string title;
	string begin;
	string exit;
	string load;
	string languages;
	int chosenOption;
public:
	MainMenu();
	string getTitle() { return title; }
	string getBegin() { return begin; }
	string getExit() { return exit; }
	string getLanguages() { return languages; }
	string getLoad() { return load; }
	void chooseOption(int i);
	void executeOption(Mode * stack);
	void beginGame(Mode * stack);
	void render(GraphicMotor& motor);
	void selectLanguages(Mode * stack);
	int getOpcion() { return chosenOption; }
	void loadGame(Mode * stack);
	void exitGame(Mode * stack);
	void loadLanguage(string language);
};