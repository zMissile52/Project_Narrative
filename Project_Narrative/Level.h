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
		int id;
		MainCharacter& player;
		vector<RectangleShape> walls;
		Door door;
		vector<NPC> entities;

		void initialLevel();
public:
	Level(MainCharacter& mc);
	void setLevel(int level);
	
	void addNPC(NPC npc);
	vector<NPC>& getNPCS();
	void draw(RenderWindow& window);
	void update(float dt, RenderWindow& window);
	int NearNPC();
	bool checkCollision(const FloatRect& bounds);
	void doorOpen();
};

