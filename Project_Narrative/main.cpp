#include <iostream>
#include <SFML/Graphics.hpp>
#include "MainCharacter.h"

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

	//initialise main character
	MainCharacter mainCharacter;
	Clock clock;

	while (window.isOpen()) {
		while (auto event = window.pollEvent()) {
			if (event->is<Event::Closed>()) {
				window.close();
			}
		}
		window.clear(Color::Black);
		float dt = clock.restart().asSeconds();
		mainCharacter.handleInput();
		
		
		mainCharacter.update(dt, window);

		mainCharacter.draw(window);
		window.display();
	}

	

	
}


//enemy -> boss

/*
vois tu ce petit point c'est toi que l'on appelle la vie :
et la mort c'est lui :
montre le que tu merite d'existé

game over text : Vous avez perdu la vie


win : Vous avez echappez a la mort
*/
