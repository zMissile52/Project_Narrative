#include "Game.h"



Game::Game(RenderWindow& window) : menu(&mainCharacter, window)
{
	npcs.push_back(NPC({ 400.f, 100.f }));
	level1.addNPC(npcs.back());
}

void Game::update(float dt, RenderWindow& window)
{
	switch (currentState) {
	case GAME:
		mainCharacter.handleInput();
		if (!narrative.isActive()) {
			mainCharacter.update(dt, window);
		}
		menu.update();
		level1.update(dt, mainCharacter, window);
		narrative.update(dt);
		break;
	default:
		break;
	}
}

void Game::draw(RenderWindow& window)
{
	switch (currentState) {
	case GAME :
		window.clear();
		level1.draw(window);
		mainCharacter.draw(window);
		menu.draw(window);
		narrative.draw(window);
		break;
	default:
		break;
	}
	
}

MainCharacter& Game::getMainCharacter()
{
	return mainCharacter;
}

HUD Game::getHUD()
{ 
return menu;
}

Level Game::getLevel()
{ 
	return level1; 
}

NarrativeManager& Game::getNarrativeManager() {
	return narrative;
}