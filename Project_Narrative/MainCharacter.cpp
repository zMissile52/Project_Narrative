#include "MainCharacter.h"

using namespace sf;
MainCharacter::MainCharacter(float size)
{
	x = 30.f;
	y = 30.f;
	
	heart = CircleShape(1.f * size);
	right = CircleShape(0.5f * size);
	left = CircleShape(0.5f * size);
	heart.setFillColor(Color::Red);
	heart.setOrigin(Vector2f(heart.getLocalBounds().size.x * 0.5f, heart.getLocalBounds().size.y * 0.5f));
	

	
	right.setFillColor(Color::Yellow);
	right.setOrigin(Vector2f(heart.getLocalBounds().size.x * 0.5f, heart.getLocalBounds().size.y * 0.5f));



	
	left.setFillColor(Color::Yellow);
	left.setOrigin(Vector2f(heart.getLocalBounds().size.x * 0.5f, heart.getLocalBounds().size.y * 0.5f));
	
	heart.setPosition(Vector2f(x, y));
	right.setPosition(Vector2f(x, y));
	left.setPosition(Vector2f(x-size, y));
	
}


void MainCharacter::draw(RenderWindow& w)
{
	w.draw(heart); 
	w.draw(left);
	w.draw(right);
	
}

void MainCharacter::update()
{
}