#pragma once
#include <string>
#include <vector>
#include "sys.h"
#include "core.h"


class Mode;
class GraphicMotor;
using namespace std;

class LanguagesMenu {
private:
	vector<string> Languages;
	string title;
	string back;
	int chosenOption;
	string currentLanguage;
public:

	LanguagesMenu();
	vector<string> getLanguages() { return Languages; }
	string getBack() { return back; }
	string getTitle() { return title; }
	string getCurrentLanguage() { return currentLanguage; }
	int getOption() { return chosenOption; }
	void backToMenu(Mode * pila);
	void render(GraphicMotor& motor);
	void loadLanguage(string idioma);
	void chooseOption(int i);
	void executeOption(Mode * pila);
};