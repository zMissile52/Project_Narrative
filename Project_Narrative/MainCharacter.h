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
	
	//variable pour gestion d'atk
	HitBox atkzone;
	float attackTimer = 0;
	float attackCooldown = 0;
	bool attacking = false;
public:
	MainCharacter();
	void draw(RenderWindow& w) override;

	//gere les inputs
	void handleInput();
	void update(float dt, RenderWindow& w);
	FloatRect getGlobalBounds() const override{ return heart.getGlobalBounds(); }
	void startAttack(RenderWindow& window);
private:
	void attack(RenderWindow& window);
};
