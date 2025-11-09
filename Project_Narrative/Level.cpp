#include "Level.h"


Level::Level()
{
	//cree des murs pour le niveau
	RectangleShape wall1;
	wall1.setSize({ 800.f, 50.f });
	wall1.setPosition({ 0.f, 0.f });
	wall1.setFillColor(Color::Blue);
	walls.push_back(wall1);
	RectangleShape wall2;
	wall2.setSize({ 50.f, 600.f });
	wall2.setPosition({ 0.f, 0.f });
	wall2.setFillColor(Color::Blue);
	walls.push_back(wall2);
	RectangleShape wall3;
	wall3.setSize({ 350.f, 50.f });
	wall3.setPosition({ 0.f, 550.f });
	wall3.setFillColor(Color::Blue);
	walls.push_back(wall3);
	RectangleShape wall4;
	wall4.setSize({ 350.f, 50.f });
	wall4.setPosition({ 0.f, 550.f });
	wall4.setFillColor(Color::Blue);
	walls.push_back(wall4);
	RectangleShape wall5;
	wall5.setSize({ 50.f, 600.f });
	wall5.setPosition({ 750.f, 0.f });
	wall5.setFillColor(Color::Blue);
	walls.push_back(wall5);
	RectangleShape wall6;
	wall6.setSize({ 350.f, 50.f });
	wall6.setPosition({ 450.f, 550.f });
	wall6.setFillColor(Color::Blue);
	walls.push_back(wall6);

	wall6.setSize({ 100.f, 20.f });
	wall6.setPosition({ 350.f, 585.f });
	wall6.setFillColor(Color::Yellow);
	walls.push_back(wall6);

}


void Level::addWall(RectangleShape wall) {
	walls.push_back(wall);
}

void Level::addEntity(Entity& npc) {
	entities.push_back(&npc);
}

void Level::draw(RenderWindow& window)
{
	for (auto& wall : walls) {
		window.draw(wall);
	}

	for (auto& entity : entities) {
		entity->draw(window);
	}
}

bool Level::checkCollision(const FloatRect& bounds) {
	for (auto& wall : walls) {
		if (wall.getGlobalBounds().findIntersection(bounds)) {
			return true;
		}
	}

	for (auto& entity : entities) {
		if (entity->getGlobalBounds().findIntersection(bounds)) {
			return true;
		}
	}
	return false;
}


void Level::update(float dt, MainCharacter& player, RenderWindow& window) {
	// on vérifie si ça cause une collision :
	if (checkCollision(player.getGlobalBounds())) {
		player.undoMove();
	}

}