#include "stdafx.h"
#include "sys.h"
#include "core.h"
#include "font.h"
#include "game.h"


using namespace std::chrono;


int Main(void)
{

	// cargar texturas
	Game::Instance().getGraphicMotor()->loadTextures();
	// crear el juego y los menus
	MainMenu menu =  MainMenu();
	MenuGameOver gameOver =  MenuGameOver();
	EndGameMenu end = EndGameMenu();
	LanguagesMenu language = LanguagesMenu();
	Mode mode =  Mode();
	mode.pushState(State::Menu);
	bool collision = false;

	milliseconds previousTime = duration_cast< milliseconds >(
		system_clock::now().time_since_epoch()
		);
	milliseconds lastTime;
	float elapsed;
	//cargar idioma
	gameOver.loadLanguage(mode.getLanguage());
	menu.loadLanguage(mode.getLanguage());
	language.loadLanguage(mode.getLanguage());
	end.loadLanguage(mode.getLanguage());
	// iniciar render
	Game::Instance().getGraphicMotor()->initRendering();
	while (!SYS_GottaQuit())
	{
		if (mode.getState() == State::Menu) {
			menu.render(*Game::Instance().getGraphicMotor());
			Game::Instance().getInput()->menuController(&mode, &menu);
			Game::Instance().setCurrentLevel(1);
			
		}
		else if(mode.getState() == State::BeginGame) {
			Game::Instance().loadScreen(Game::Instance().getCurrentLevel());
			Game::Instance().initCollisions(Game::Instance().getScreen());
			Game::Instance().play(&mode);
			

		}
		else if (mode.getState() == State::LoadGame) {
			if (Game::Instance().load()) {
				mode.replaceState(State::BeginGame);
			}
			else {
				mode.popState();
			}
		}
		else if (mode.getState() == State::GameOver) {
	
			gameOver.render(*Game::Instance().getGraphicMotor());
			Game::Instance().getInput()->gameOverController(&mode, &gameOver);
			
		}
		else if (mode.getState() == State::End) {
		
			end.render(*Game::Instance().getGraphicMotor());
			Game::Instance().getInput()->endMenuController(&mode, &end);
		}

		else if (mode.getState() == State::Settings) {
			language.render(*Game::Instance().getGraphicMotor());
			Game::Instance().getInput()->menuLanguageController(&mode, &language);
			if (language.getCurrentLanguage().compare(mode.getLanguage()) != 0) {
				language.loadLanguage(mode.getLanguage());
				gameOver.loadLanguage(mode.getLanguage());
				menu.loadLanguage(mode.getLanguage());
				end.loadLanguage(mode.getLanguage());
			}
		}

		else if (mode.getState() == State::Exit) {
			break;
		}
		else {
			//calculo del tiempo entre frames
			lastTime = duration_cast< milliseconds >(
				system_clock::now().time_since_epoch()
				);
			elapsed = static_cast<float>(lastTime.count() - previousTime.count());
			previousTime = lastTime;
			elapsed /= 1000.0;
			//Render Screen
			Game::Instance().getScreen()->render(Game::Instance().getGraphicMotor());
			// Input
			Game::Instance().getInput()->humanController(Game::Instance().getScreen()->getHuman(),elapsed);
			//salto
			Game::Instance().jumpLogic(elapsed);
			//mover enemigos
			Game::Instance().moveEnemies(elapsed);
			//comprobar si el nivel termino
			Game::Instance().levelFinished(&mode);
			//colisiones
			collision = Game::Instance().collisions();
			if (collision) {

				mode.replaceState(State::GameOver);
				collision = false;
			}
		}
		// Keep system running
		SYS_Pump();
		SYS_Sleep(17);
	}
	//descargar graficos
	Game::Instance().getGraphicMotor()->unloadPNG();

	return 0;
}