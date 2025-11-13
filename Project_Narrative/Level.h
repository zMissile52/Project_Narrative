#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "MainCharacter.h"
#include "Entity.h"
#include "NPC.h"
using namespace sf;
using namespace std;

struct Door {
	RectangleShape shape;
	bool open = false;
};

class Level
{
	private:
		vector<RectangleShape> walls;
		Door door;
		vector<NPC> entities;
public:
	Level();
	void addNPC(NPC npc);
	void draw(RenderWindow& window);
	void update(float dt, MainCharacter& player, RenderWindow& window);
	bool checkCollision(const FloatRect& bounds);
};

