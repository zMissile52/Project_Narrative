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
	game.startGame();
}


//enemy -> boss


//TO DO LIST
//-ajouter le pnj du début de jeu
//-ajouter les dialogues et que MainCharacter puisse interagir avec le pnj (touche E par exemple)


//- ajouter au moins un ennemi qui a ses propres hitbox et qui peut infliger des degats au joueur
//- ajouter des sons (attaque, degats, mort, musique de fond)

