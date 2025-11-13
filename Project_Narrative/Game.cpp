#include "Game.h"
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;


Game::Game(RenderWindow& w) : window(w), menu(&mainCharacter, window)
{
	
	npcs.push_back(NPC({ 400.f, 100.f }));
	level1.addNPC(npcs.back());
}

void Game::startGame() {
	narrative.triggerEvent("start_game");
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
				int NPCID = level1.NearNPC();
				if (kp && kp->code == Keyboard::Key::E && NPCID != -1) {
					level1.getNPCS()[NPCID].talk();
					//narrativeManager.triggerEvent("npc_start");
				}
			}
		}

		float dt = clock.restart().asSeconds();

		//update part
		/*mainCharacter.handleInput();
		mainCharacter.update(dt, window);
		menu.update();
		level1.update(dt, mainCharacter, window);
		narrativeManager.update(dt);*/

		update(dt, window);


		//reset page
		window.clear(Color::Black);

		draw(window);

		////draw character
		//mainCharacter.draw(window);

		////draw level
		//level1.draw(window);

		////draw hud
		//menu.draw(window);

		//narrativeManager.draw(window);

		window.display();




	}
}

void Game::update(float dt, RenderWindow& window)
{
	switch (currentState) {
	case GAME:
		mainCharacter.handleInput();
		if (!narrative.isActive()) {
			mainCharacter.update(dt, window);
		}
		menu.update();
		level1.update(dt, mainCharacter, window);
		narrative.update(dt);
		break;
	default:
		break;
	}
}

void Game::draw(RenderWindow& window)
{
	switch (currentState) {
	case GAME :
		window.clear();
		level1.draw(window);
		mainCharacter.draw(window);
		menu.draw(window);
		narrative.draw(window);
		break;
	default:
		break;
	}
	
}

MainCharacter& Game::getMainCharacter()
{
	return mainCharacter;
}

HUD& Game::getHUD()
{ 
return menu;
}

Level& Game::getLevel()
{ 
	return level1; 
}

NarrativeManager& Game::getNarrativeManager() {
	return narrative;
}