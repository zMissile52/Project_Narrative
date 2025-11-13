#pragma once
#include "Entity.h"
#include <iostream>
using namespace sf;

using namespace std;

class NPC : public Entity
{
private:
	RectangleShape npcShape;
	string dialogueText;
	bool nearPlayer = false;
	bool inDialogue = false;
	Font font;
	Text dialogueDisplay;
	
public:
	NPC();
	NPC(Vector2f position);
	void draw(sf::RenderWindow& w) override;
	void update(float dt, sf::RenderWindow& w) override;
	// dialogue
	void talk();
	void endDialogue();
	
	FloatRect getGlobalBounds() const override;

	bool getNearPlayer();
	
	void checkProximity(Vector2f playerPos);
	bool isInDialogue() const { return inDialogue; }
	Vector2f getPosition() const { return npcShape.getPosition(); }

};

