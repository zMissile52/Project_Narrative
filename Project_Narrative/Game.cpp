#include "Game.h"

Game::Game(RenderWindow& window) : menu(&mainCharacter, window)
{
	//Level
	NPC npc1({ 400.f, 100.f });
	level1.addEntity(npc1);
}

void Game::update(float dt, RenderWindow& window)
{
	mainCharacter.handleInput();
	mainCharacter.update(dt, window);
	menu.update();
	level1.update(dt, mainCharacter, window);
}

void Game::draw(RenderWindow& window)
{
	window.clear();
	level1.draw(window);
	mainCharacter.draw(window);
	menu.draw(window);
	window.display();
}

MainCharacter Game::getMainCharacter()
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