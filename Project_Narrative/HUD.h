#pragma once
#include "MainCharacter.h"
using namespace sf;
class HUD
{
private:
	Font font;
	Text hpText;

	RectangleShape hpBarBackground;
	RectangleShape hpBar;

	MainCharacter* main;
public:
	HUD(MainCharacter*, RenderWindow&);
	void update();
	void draw(RenderWindow& w);
};

