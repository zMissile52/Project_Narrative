#pragma once
#include "Entity.h"
#include "HitBox.h"
using namespace sf;

class MainCharacter : public Entity
{
private:
	CircleShape heart;
	Vector2f direction;
	float speed = 300.f;
	HitBox atkzone;
public:
	MainCharacter();
	void draw(RenderWindow& w) override;

	//gere les inputs
	void handleInput();
	void update(float dt, RenderWindow& w);
	FloatRect getGlobalBounds() const override{ return heart.getGlobalBounds(); }

private:
	void attack(RenderWindow& window);
};
