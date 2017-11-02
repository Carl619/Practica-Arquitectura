#include "gamemode.h"

void Mode::pushState(State state)
{
	stateStack.push(state);
}

void Mode::replaceState(State state)
{
	stateStack.pop();
	stateStack.push(state);
}

void Mode::popState()
{
	stateStack.pop();
}

State Mode::getState()
{
	return stateStack.top();
}

string Mode::getLanguage()
{
	return language;
}

void Mode::setLanguage(string idioma)
{
	this->language.clear();
	this->language.insert(0, idioma);
}

Mode::Mode()
{
	language = "esp";
}
