#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class Entity
{
protected:
	float x, y;
public:
	virtual void draw(RenderWindow& w) = 0;
	virtual void update() = 0;
};

