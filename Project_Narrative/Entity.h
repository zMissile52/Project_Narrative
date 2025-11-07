#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class Entity
{
protected:
	//position de l'entity
	Vector2f position;
public:

	//dessine l'entity (avec les shapes defini dans les filles)
	virtual void draw(RenderWindow& w) = 0;

	//update
	virtual void update(float dt, RenderWindow& w) = 0;

	//pour avoir les bounds
	virtual FloatRect getGlobalBounds() const = 0;

	//destructor au cas ou
	virtual ~Entity() = default;
};

