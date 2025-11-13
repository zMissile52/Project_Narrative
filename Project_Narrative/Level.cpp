#include "Level.h"


Level::Level(MainCharacter& mc) : player(mc)
{
	setLevel(1);
}

void Level::setLevel(int level) {
	initialLevel();
	switch (level) {
	case 1:{
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
		wall4.setSize({ 50.f, 600.f });
		wall4.setPosition({ 750.f, 0.f });
		wall4.setFillColor(Color::Blue);
		walls.push_back(wall4);
		RectangleShape wall5;
		wall5.setSize({ 350.f, 50.f });
		wall5.setPosition({ 450.f, 550.f });
		wall5.setFillColor(Color::Blue);
		walls.push_back(wall5);

		door.shape.setSize({ 100.f, 20.f });
		door.shape.setPosition({ 350.f, 585.f });
		door.shape.setFillColor(Color::Yellow);
		break;
	}
	case 2: {
		RectangleShape wall1;
		wall1.setSize({ 800.f, 30.f });
		wall1.setPosition({ 0.f, 0.f });
		wall1.setFillColor(Color::Blue);
		walls.push_back(wall1);
		RectangleShape wall2;
		wall2.setSize({ 30.f, 600.f });
		wall2.setPosition({ 0.f, 0.f });
		wall2.setFillColor(Color::Blue);
		walls.push_back(wall2);
		RectangleShape wall3;
		wall3.setSize({ 800.f, 30.f });
		wall3.setPosition({ 0.f, 570.f });
		wall3.setFillColor(Color::Blue);
		walls.push_back(wall3);
		RectangleShape wall4;
		wall4.setSize({ 30.f, 600.f });
		wall4.setPosition({ 770.f, 0.f });
		wall4.setFillColor(Color::Blue);
		walls.push_back(wall4);

		RectangleShape crossH;
		crossH.setSize({ 800.f - 2 * 150.f, 20.f });
		crossH.setPosition({ 150.f, 290.f });
		crossH.setFillColor(Color::Blue);
		walls.push_back(crossH);

		RectangleShape crossV;
		crossV.setSize({ 20.f, 600.f - 2 * 150.f });
		crossV.setPosition({ 390.f, 150.f });
		crossV.setFillColor(Color::Blue);
		walls.push_back(crossV);


	}
		break;
	default:
		break;

	}
}

void Level::initialLevel() {
	entities.clear();
	walls.clear();
	door.shape = RectangleShape();
	door.open = false;
}

void Level::addNPC(NPC npc) {
	entities.push_back(npc);
}

vector<NPC>& Level::getNPCS() {
	return entities;
}

void Level::draw(RenderWindow& window)
{
	for (auto& wall : walls) {
		window.draw(wall);
	}

	for (auto& entity : entities) {
		entity.draw(window);
	}

	window.draw(door.shape);
}

bool Level::checkCollision(const FloatRect& bounds) {
	if (door.shape.getGlobalBounds().findIntersection(bounds) && !door.open) {
		return true;
	}

	for (auto& wall : walls) {
		if (wall.getGlobalBounds().findIntersection(bounds)) {
			return true;
		}
	}

	for (auto& entity : entities) {
		if (entity.getGlobalBounds().findIntersection(bounds)) {
			return true;
		}
	}

	return false;
}

void Level::doorOpen() {
	door.open = true;
	door.shape.setFillColor(Color::Green);
}


void Level::update(float dt, RenderWindow& window) {
	// on vérifie si ça cause une collision :
	for (auto& entity : entities) {
		entity.update(dt, window);
		entity.checkProximity(player.getPosition());
	}
	if (checkCollision(player.getGlobalBounds())) {
		player.undoMove();
	}

	if (door.open && door.shape.getGlobalBounds().findIntersection(player.getGlobalBounds())) {
		setLevel(2);
		Vector2f playerPos = player.getPosition();
		player.setPosition(playerPos.x, 40);
	}
}

int Level::NearNPC() {
	for (int i = 0; i < entities.size(); i++) {
		if (entities[i].getNearPlayer()) {
			return i;
		}
	}

	return -1;
}