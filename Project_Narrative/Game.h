#pragma once
#include <SFML/Graphics.hpp>
#include "MainCharacter.h"
#include "HUD.h"
#include "Level.h"

using namespace sf;

class Game
{
private:
	//initialise main character
	MainCharacter mainCharacter;
	
	//Level
	Level level1;

	//HUD
	HUD menu;

public:
	Game(RenderWindow& window);
	void update(float dt, RenderWindow& window);
	void draw(RenderWindow& window);
	MainCharacter getMainCharacter();
	HUD getHUD();
	Level getLevel();
};

