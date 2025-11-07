#include "MainCharacter.h"

using namespace sf;
MainCharacter::MainCharacter()
{
	
	position.x = 100.f;
	position.y = 100.f;
	heart = CircleShape(10.f);
	heart.setFillColor(Color(255, 0, 0, 100));
	heart.setPosition(position);

	auto bounds = heart.getGlobalBounds();
	heart.setOrigin(Vector2f(bounds.size.x * 0.5f, bounds.size.y * 0.5f));


}


void MainCharacter::draw(RenderWindow& w)
{
	w.draw(heart); 
	atkzone.draw(w);
}

void MainCharacter::handleInput() {
	direction = { 0.f, 0.f };
	if (Keyboard::isKeyPressed(Keyboard::Key::Z)) {
		direction.y -= 1.f;
	}

	if (Keyboard::isKeyPressed(Keyboard::Key::S)) {
		direction.y += 1.f;
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::Q)) {
		direction.x -= 1.f;
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::D)) {
		direction.x += 1.f;
	}
}


void MainCharacter::update(float dt, RenderWindow& window)
{
	sf::Vector2f moveOffset = direction * speed * dt;
	
	heart.move(moveOffset);

	position = heart.getPosition();

	// Attaque sur espace
	if (Keyboard::isKeyPressed(Keyboard::Key::Space) || Mouse::isButtonPressed(Mouse::Button::Left)) {
		attack(window);
	}

	// Mise à jour de la hitbox
	atkzone.update(dt, window);
	
}

void MainCharacter::attack(RenderWindow& window)
{
	// Récupère position de la souris dans la fenêtre
	Vector2i mousePosPixel = Mouse::getPosition(window);
	Vector2f mousePos = window.mapPixelToCoords(mousePosPixel); // conversion pixels coords du monde

	// Calcule direction souris joueur
	Vector2f dir = mousePos - position;

	float len = std::sqrt(dir.x * dir.x + dir.y * dir.y);
	if (len != 0)
		dir /= len; // normalisation


	Vector2f hitboxPos = position + dir * 30.f; // devant le personnage

	atkzone.activate(hitboxPos, 30.f, 0.2f); // taille 40px, durée 0.2s
}
