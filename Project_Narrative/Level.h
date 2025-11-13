#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "MainCharacter.h"
#include "Entity.h"
#include "NPC.h"
using namespace sf;
using namespace std;
class Level
{
	private:
		vector<RectangleShape> walls;
		vector<NPC> entities;
public:
	Level();
	void addWall(RectangleShape wall);
	void addNPC(NPC npc);
	void draw(RenderWindow& window);
	void update(float dt, MainCharacter& player, RenderWindow& window);
	bool checkCollision(const FloatRect& bounds);
};

