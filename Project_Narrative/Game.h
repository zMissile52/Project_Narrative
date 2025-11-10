#pragma once
#include <SFML/Graphics.hpp>
#include "MainCharacter.h"
#include "HUD.h"
#include "Level.h"
#include "NarrativeManager.h"

using namespace sf;

class Game
{
private:
	//initialise main character
	MainCharacter mainCharacter;
	
	//Level
	Level level1;
	vector<NPC> npcs;

	//HUD
	HUD menu;

	NarrativeManager narrative;

public:
	Game(RenderWindow& window);
	void update(float dt, RenderWindow& window);
	void draw(RenderWindow& window);
	MainCharacter getMainCharacter();
	HUD getHUD();
	Level getLevel();
	NarrativeManager& getNarrativeManager();
};

