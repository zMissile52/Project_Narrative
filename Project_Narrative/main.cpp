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
	MainCharacter mainCharacter(10.f);

	while (window.isOpen()) {
		while (auto event = window.pollEvent()) {
			if (event->is<Event::Closed>()) {
				window.close();
			}
		}
		window.clear(Color::Black);
		mainCharacter.draw(window);
		window.display();
	}

	

	
}


//enemy -> boss
