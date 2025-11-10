#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "NarrativeManager.h"

using namespace sf;

unsigned int height = 600;
unsigned int width = 800;

int main() {
	// Project Narrative: 
	// an entity abstract class
	// suppose main character herit the entity class
	// NPC and/or Enemy too


	//std::cout << "Welcome to the Project Narrative!" << std::endl;
	RenderWindow window(VideoMode({ width, height }), "Project Narrative");

	////initialise main character
	//MainCharacter mainCharacter;

	////HUD
	//HUD menu(&mainCharacter, window);

	////Level
	//Level level1;
	//NPC npc1({ 400.f, 100.f });
	//level1.addEntity(npc1);

	Game game(window);
	MainCharacter mainCharacter = game.getMainCharacter();
	HUD menu = game.getHUD();
	Level level1 = game.getLevel();

	NarrativeManager& narrativeManager = game.getNarrativeManager();

	Clock clock;

	while (window.isOpen()) {
		while (auto event = window.pollEvent()) {
			if (event->is<Event::Closed>()) {
				window.close();
			}
			if (event->is<Event::MouseButtonPressed>()) {
				auto mouseEvent = event->getIf<Event::MouseButtonPressed>();
				if (mouseEvent && mouseEvent->button == Mouse::Button::Left) {
					mainCharacter.startAttack(window);
				}
			}
			if (event->is<sf::Event::KeyPressed>()) {
				auto kp = event->getIf<sf::Event::KeyPressed>();
				if (kp && kp->code == Keyboard::Key::Space) {
					mainCharacter.startAttack(window);
				}
				if (kp && kp->code == Keyboard::Key::E) {
					narrativeManager.triggerEvent("npc_intro_done");
				}
			}
		}
		narrativeManager.triggerEvent("start_game");
			float dt = clock.restart().asSeconds();

			//update part
			mainCharacter.handleInput();
			mainCharacter.update(dt, window);
			menu.update();
			level1.update(dt, mainCharacter, window);

			//reset page
			window.clear(Color::Black);

			//draw character
			mainCharacter.draw(window);

			//draw level
			level1.draw(window);

			//draw hud
			menu.draw(window);

			narrativeManager.draw(window);

			window.display();




	}
}


//enemy -> boss


//TO DO LIST
//-ajouter le pnj du début de jeu
//-ajouter les dialogues et que MainCharacter puisse interagir avec le pnj (touche E par exemple)


//- ajouter au moins un ennemi qui a ses propres hitbox et qui peut infliger des degats au joueur
//- ajouter des sons (attaque, degats, mort, musique de fond)

