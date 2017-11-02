#include "stdafx.h"
#include "game.h"

using namespace std;

Game* Game::game = NULL;

Game& Game::Instance() {
	if (!game)
		game = new Game();
	return *game;
}


bool Game::collisions()
{
	bool colision;
	colision = collide(screen->getHuman(), screen->getGoal(), screen->getPlatforms(), screen->getEnemies(), screen->getTraps());
	return colision;
}

void Game::moveEnemies(float elapsed)
{
	for (int i = 0; i < static_cast<int>(screen->getEnemies().size()); i++)
		screen->getEnemies()[i]->moveEnemy(elapsed);
}

void Game::loadScreen(int screenActual)
{
	char buffer[4];
	if (screen != NULL) {
		delete screen;
		screen = NULL;
	}
	itoa(screenActual, buffer, 10);
	string s = string(buffer);
	Screen * sc = new Screen(s);
	sc->prepareScreen();
	screen = sc;
}

int Game::logic(float elapsed)
{
	if (collisions() == 0)
		return 0;
	moveEnemies(elapsed);
	jumpLogic(elapsed);
	return 1;
}

void Game::jumpLogic(float elapsed)
{
	screen->getHuman()->controlJump(elapsed);
	return;
}

Game::Game() {
	screen = NULL;
	inputManager = new Input();
	graphics = new GraphicMotor();
	currentLevel = 1;
	endLevel = 2;
}


void Game::levelFinished(Mode *modo)
{
	if (screen->getGoal()->getFinish() && currentLevel!=endLevel) {
		currentLevel++;
		modo->replaceState(State::BeginGame);
		save();
	}
	else if(screen->getGoal()->getFinish() && currentLevel == endLevel){
		currentLevel = 1;
		modo->replaceState(State::End);
	}
}

void Game::save()
{
	/*
	FILE * pFile;
	pFile = fopen("data/save/save.txt", "w");
	char buffer[3];
	sprintf(buffer, "%d", nivelActual);	
	fputs("fopen example", pFile);
	fclose(pFile);*/
	ofstream outfile;
	char buffer[3];
	outfile.open("data/save/save.txt");
	sprintf(buffer, "%d", currentLevel);	
	outfile.write(buffer,2);
	outfile.close();
}



bool Game::load()
{
	string line;
	ifstream infile;
	bool carga = false;
	infile.open("data/save/save.txt");
	while (!infile.eof())
	{
		getline(infile, line);
		if (line.compare("0") == 0) {
			carga = false;
			break;
		}
		else {
			currentLevel= std::stoi(line);
			carga = true;
		}
	}
	infile.close();
	return carga;
}

void Game::play(Mode *modo)
{
	modo->replaceState(State::PlayGame);
}

void Game::initCollisions(Screen *sc)
{
	for (int i = 0; i < static_cast<int>(sc->getTraps().size()); i++)
		sc->getTraps()[i]->setCollsion( Rect(sc->getTraps()[i]->getPos().x,sc->getTraps()[i]->getPos().y,11,64 ));
	for (int i = 0; i < static_cast<int>(sc->getEnemies().size()); i++)
		sc->getEnemies()[i]->setCollsion( Rect( sc->getEnemies()[i]->getPos().x ,sc->getEnemies()[i]->getPos().y,32,32 ));
	sc->getHuman()->setCollsion(Rect(sc->getHuman()->getPos().x,sc->getHuman()->getPos().y,32,58));
	sc->getGoal()->setCollsion(Rect(sc->getGoal()->getPos().x, sc->getGoal()->getPos().y, 68, 52));
}
