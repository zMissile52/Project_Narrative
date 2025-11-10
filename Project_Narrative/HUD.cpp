#include "HUD.h"
using namespace std;


HUD::HUD(MainCharacter* mc, RenderWindow& w) : hpText(font){
	Vector2u w_size = w.getSize();
	main = mc;
	if (!font.openFromFile("Assets/FOT-Rodin Pro DB.otf")) {
		throw std::runtime_error("Erreur : impossible de charger la police !");
	}
	hpText.setFont(font);
	hpText.setCharacterSize(15.f);
	hpText.setFillColor(sf::Color::White);
	hpText.setPosition(Vector2f(w_size.x * 0.01f, w_size.y * 0.01f));
	hpText.setString("Life");

	Vector2f hpSize(200.f, 10.f);

	// Fond de la barre de vie
	hpBarBackground.setSize(hpSize);
	hpBarBackground.setFillColor(sf::Color(50, 50, 50)); // gris
	hpBarBackground.setPosition(Vector2f(w_size.x * 0.01f, w_size.y * 0.05f));

	// Barre de vie (rouge par défaut)
	hpBar.setSize({ hpSize.x, hpSize.y });
	hpBar.setFillColor(sf::Color::Red);
	hpBar.setPosition(Vector2f(w_size.x * 0.01f, w_size.y * 0.05f));
	
}

void HUD::draw(RenderWindow& w) {
	w.draw(hpText);
	w.draw(hpBarBackground);
	w.draw(hpBar);
}

void HUD::update() {
	float currentHP = main->getHP();
	float maxHP = main->getMaxHP(); // faut de quoi recuperer le max hp avec une methode

	// ratio de vie
	float ratio = currentHP / maxHP;
	if (ratio < 0.f) ratio = 0.f;
	if (ratio > 1.f) ratio = 1.f;

	// Mise à jour de la taille de la barre
	hpBar.setSize({ 200.f * ratio, 10.f });
}