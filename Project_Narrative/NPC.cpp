#include "NPC.h"
#include <iostream>
#include <SFML/Graphics.hpp>

NPC::NPC() : dialogueDisplay(font) {

}

NPC::NPC(Vector2f position) : dialogueDisplay(font)
{
	npcShape.setSize(Vector2f(20.f, 20.f));
	npcShape.setFillColor(Color::White);
	npcShape.setPosition(position);
	auto bounds = npcShape.getGlobalBounds();
	npcShape.setOrigin(Vector2f(bounds.size.x * 0.5f, bounds.size.y * 0.5f));
    if (!font.openFromFile("Assets/FOT-Rodin Pro DB.otf")) {
        std::cerr << "Erreur : police manquante" << std::endl;
    }

    dialogueText = "Bonjour ! Quel beau jour pour une aventure !";
	dialogueDisplay.setFont(font);
    dialogueDisplay.setCharacterSize(20);
    dialogueDisplay.setFillColor(Color::White);
    dialogueDisplay.setString(dialogueText);

}

void NPC::draw(RenderWindow& w)
{
	w.draw(npcShape);

    if (inDialogue) {
        RectangleShape box(Vector2f(700.f, 100.f));
        box.setPosition(Vector2f(50.f, 450.f));
        box.setFillColor(Color(0, 0, 0, 180));
        w.draw(box);

        dialogueDisplay.setPosition(Vector2f(70.f, 470.f));
        w.draw(dialogueDisplay);
    }
    else if (nearPlayer) {
        Text prompt(font);
        prompt.setFont(font);
        prompt.setCharacterSize(16);
        prompt.setFillColor(Color::White);
        prompt.setString("Appuyez sur E pour parler");
        prompt.setPosition(Vector2f(npcShape.getPosition().x - 60.f, npcShape.getPosition().y - 40.f));
        w.draw(prompt);
    }
}

void NPC::update(float dt, RenderWindow& w)
{
	// Mettre à jour le NPC (implémentation spécifique à chaque NPC)
	// si joueur proche, affiche appuier E pour parler et dialogue start
}

FloatRect NPC::getGlobalBounds() const
{
	return npcShape.getGlobalBounds();
}

void NPC::checkProximity(Vector2f playerPos) {
    Vector2f diff = playerPos - npcShape.getPosition();
    float distance = std::sqrt(diff.x * diff.x + diff.y * diff.y);
    if (distance < 80.f) {
		nearPlayer = true;  // joueur proche
    }
    else {
        nearPlayer = false;
    }
}


void NPC::talk() {
    if (!inDialogue) {
        inDialogue = true;
        std::cout << "Le NPC commence à parler : " << dialogueText << std::endl;
    }
}

void NPC::endDialogue() {
    if (inDialogue) {
        inDialogue = false;
        std::cout << "Le dialogue se termine." << std::endl;
    }
}