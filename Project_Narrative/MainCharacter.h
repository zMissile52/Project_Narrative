#pragma once
#include "Entity.h"
#include "HitBox.h"
using namespace sf;

class MainCharacter : public Entity
{
private:
	CircleShape heart;
	Vector2f velocity;
	Vector2f direction;
	float speed = 300.f;
	int hp;
	const int maxHp = 3;
	//variable pour gestion d'atk
	HitBox atkzone;
	float attackTimer = 0;
	float attackCooldown = 0;
	bool attacking = false;
	Vector2f lastPosition;
public:
	MainCharacter();
	void draw(RenderWindow& w) override;

	int getHP();
	int getMaxHP() { return maxHp; }
	Vector2f getPosition();

	void setPosition(float x, float y);

	//gere les inputs
	void handleInput();
	void update(float dt, RenderWindow& w);
	FloatRect getGlobalBounds() const override{ return heart.getGlobalBounds(); }
	void startAttack(RenderWindow& window);
	void undoMove();
private:
	void attack(RenderWindow& window);
};
