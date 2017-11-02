#include "stdafx.h"

#include "screen.h"
#include "graphicmotor.h"
using namespace std;

Screen::Screen(std::string i)
{
	ID = i;
}

void Screen::prepareScreen()
{
	initHuman();

	initEnemies();

	initTraps();

	initPlatforms();

	initGoal();
}

void Screen::render(GraphicMotor * motor)
{

	motor->renewRendering();

	motor->renderBackground();

	for (int i = 0; i < static_cast<int>(platforms.size()); i++)
		motor->renderEntity(platforms[i]->getPos(), 300.f, 74.f, "Platform");
	for (int i = 0; i < static_cast<int>(traps.size()); i++)
		motor->renderEntity(traps[i]->getPos(), 11.f, 64.f, "Trap");
	for (int i = 0; i < static_cast<int>(enemies.size()); i++)
		motor->renderEntity(enemies[i]->getPos(), 32.f, 32.f, "Enemy");

	motor->renderEntity(hum->getPos(), 32.f, 58.f, "Human");

	motor->renderEntity(goal->getPos(), 68, 52, "Flag");

	motor->show();
}

void Screen::setHuman(Human *h)
{
	hum = h;
}

std::vector<Enemy*> Screen::getEnemies()
{
	return enemies;
}

std::vector<Platform*> Screen::getPlatforms()
{
	return platforms;
}

std::vector<Trap*> Screen::getTraps()
{
	return traps;
}

Human *Screen::getHuman()
{
	return hum;
}

void Screen::initHuman() {
	string line;
	int x = 0, y = 0;
	ifstream infile;

	infile.open("data/niveles/screen"+ID+".txt");
	while (!infile.eof()) 
	{
		getline(infile, line); 
		if (line.compare("human:") == 0) {
			getline(infile, line);
			x = std::stoi(line);
			getline(infile, line);
			y = std::stoi(line);
			Human *human = new Human(vmake(static_cast<float>(x), static_cast<float>(y)));
			x = 0;
			y = 0;
			this->hum = human;
			break;
		}
	}
	infile.close();
		
}

	void Screen::initEnemies() {
		string line;
		int x = 0, y = 0, xend = 0, yend = 0;
		float r = 0;
		ifstream infile;
		infile.open("data/niveles/screen" + ID + ".txt");
		while (!infile.eof())
		{
			getline(infile, line);
			if (line.compare("enemy:") == 0) {
				getline(infile, line);
				x = std::stoi(line);
				getline(infile, line);
				y = std::stoi(line);
				getline(infile, line);
				xend = std::stoi(line);
				getline(infile, line);
				yend = std::stoi(line);
				getline(infile, line);
				if (line.compare("true") == 0) {
					getline(infile, line);
					r = static_cast<float>(std::stoi(line));
				}
				Enemy *ene = new Enemy(vmake(static_cast<float>(x), static_cast<float>(y)));
				ene->setRadio(r);
				ene->setInipos(vmake(static_cast<float>(x), static_cast<float>(y)));
				ene->setEndpos(vmake(static_cast<float>(xend), static_cast<float>(yend)));
				enemies.push_back(ene);
				x = 0;
				y = 0;
				xend = 0;
				yend = 0;
			}
		}
		infile.close();
}

void Screen::initTraps(){
	string line;
	int x = 0, y = 0;
	ifstream infile;
	infile.open("data/niveles/screen" + ID + ".txt");
	while (!infile.eof()) 
	{
		getline(infile, line);
		if (line.compare("trap:") == 0) {
			getline(infile, line);
			x = std::stoi(line);
			getline(infile, line);
			y = std::stoi(line);
			Trap *tr = new Trap(vmake(static_cast<float>(x), static_cast<float>(y)));
			x = 0;
			y = 0;
			traps.push_back(tr);

		}
	}
	infile.close();

}

void Screen::initGoal() {
	string line;
	int x = 0, y = 0;
	ifstream infile;
	infile.open("data/niveles/screen" + ID + ".txt");
	while (!infile.eof())
	{
		getline(infile, line);
		if (line.compare("goal:") == 0) {
			getline(infile, line);
			x = std::stoi(line);
			getline(infile, line);
			y = std::stoi(line);
			Goal *gl = new Goal(vmake(static_cast<float>(x), static_cast<float>(y)));
			x = 0;
			y = 0;
			this->goal = gl;
		}
	}
	infile.close();

}

void Screen::initPlatforms() {

	string line;
	int x = 0, y = 0;
	ifstream infile;
	infile.open("data/niveles/screen" + ID + ".txt");
	while (!infile.eof()) 
	{
		getline(infile, line);
		if (line.compare("platform:") == 0) {
			getline(infile, line);
			x = std::stoi(line);
			getline(infile, line);
			y = std::stoi(line);
			Platform* plat =new  Platform(vmake(static_cast<float>(x), static_cast<float>(y)));
			x = 0;
			y = 0;
			platforms.push_back(plat);
		}
	}
	infile.close();

}

