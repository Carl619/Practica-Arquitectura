#pragma once
#include <stack>
#include <string>

using namespace std;

enum State { Menu, LoadGame, BeginGame, PlayGame,GameOver,End,Exit,Settings };

class Mode
{
public:
	void pushState(State state);
	void replaceState(State state);
	void popState();
	State getState();
	string getLanguage();
	void setLanguage(string language);
	Mode();
private:
	std::stack<State> stateStack;
	string language;
};