#pragma once
#include "Entity.h"
using namespace sf;
class NPC : public Entity
{
private:
	RectangleShape npcShape;
	
public:
	NPC();
	NPC(Vector2f position);
	void draw(sf::RenderWindow& w) override;
	void update(float dt, sf::RenderWindow& w) override;
	FloatRect getGlobalBounds() const override;
};

