#include "NPC.h"
#include <SFML/Graphics.hpp>
using namespace sf;

NPC::NPC() {

}

NPC::NPC(Vector2f position)
{
	npcShape.setSize(Vector2f(20.f, 20.f));
	npcShape.setFillColor(Color::White);
	npcShape.setPosition(position);
	auto bounds = npcShape.getGlobalBounds();
	npcShape.setOrigin(Vector2f(bounds.size.x * 0.5f, bounds.size.y * 0.5f));
}

void NPC::draw(RenderWindow& w)
{
	w.draw(npcShape);
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

