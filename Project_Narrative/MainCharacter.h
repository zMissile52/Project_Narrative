#pragma once
#include "Entity.h"
using namespace sf;

class MainCharacter : public Entity
{
private:
	CircleShape heart, left, right;
public:
	MainCharacter(float size);
	void draw(RenderWindow& w) override;
	void update() override;
};
