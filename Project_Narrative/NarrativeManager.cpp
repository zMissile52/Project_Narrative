#include "NarrativeManager.h"

#include <iostream>

using namespace sf;

NarrativeManager::NarrativeManager() : textDisplay(font) {
    if (!font.openFromFile("assets/FOT-Rodin Pro DB.otf")) {
        std::cerr << "Erreur : impossible de charger la police assets/arial.ttf" << std::endl;
    }

    box.setSize({ 700.f, 150.f });
    box.setPosition(Vector2f(50.f, 400.f));
    box.setFillColor(Color(0, 0, 0, 180));
    box.setOutlineThickness(2.f);
    box.setOutlineColor(Color::White);

    textDisplay.setFont(font);
    textDisplay.setCharacterSize(20);
    textDisplay.setFillColor(Color::White);
    textDisplay.setPosition(Vector2f(70.f, 420.f));

    loadStory();
}

void NarrativeManager::loadStory() {
    steps.clear();

    // Exemple : 3 étapes narratives
    steps.push_back({ NarrativeType::INTRO,
        "tu te reveilles dans une piece noir sans souvenir de qui tu es",
        "start_game"
        });

    steps.push_back({ NarrativeType::DIALOGUE,
        "Tu entends quelqu’un t’appeler depuis la maison...",
        "npc_intro_done"
        });

    steps.push_back({ NarrativeType::VICTORY,
        "Tu a franchis la première etape d'une vie ! Profites de ta vie !",
        "player_won"
        });
}

void NarrativeManager::triggerEvent(const std::string& name) {
    for (size_t i = 0; i < steps.size(); ++i) {
        NarrativeStep& step = steps[i];
        if (!step.done && step.trigger == name) {
            std::cout << "Narration déclenchée : " << step.text << std::endl;
            currentIndex = i;
            textDisplay.setString(step.text);
            active = true;
            step.done = true;
            return;
        }
    }
}

void NarrativeManager::update(float dt) {
    // ici on pourrait faire des effets (texte qui s'affiche progressivement, fade, etc.)
    // mais pour l’instant, on laisse vide pour garder simple
    if (Keyboard::isKeyPressed(Keyboard::Key::Enter)) {
        active = false;
    }

}

void NarrativeManager::draw(RenderWindow& window) {
    if (active) {
        window.draw(box);
        window.draw(textDisplay);
    }
}

void NarrativeManager::nextStep() {
    if (active) {
        // On ferme simplement la narration
        active = false;
    }
}

//intro : tu te reveilles dans une piece noir sans souvenir de qui tu es
//??? : approche garcon/fille ...
//
//tu es ce qu'on appelle une vie
//
//derriere cette porte se trouve quelque chose qui la mettra en question
//
//franchi la porte :
//??? : montre moi comment tu te debrouilles face a la mort
//
// (je vais surement pas la mettre)
//-> plot twist : celui qui te dis ça c'est le dieu de la mort et il t'affrontera si tu le bats
//
//game over text : Une personne en plus qui n'a pas reussi a defier la mort
//
//
//win : Vie une vie heureuse
