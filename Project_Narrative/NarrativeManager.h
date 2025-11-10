#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

enum class NarrativeType {
    INTRO,
    DIALOGUE,
    OBJECTIVE,
    VICTORY,
    CUTSCENE
};

struct NarrativeStep {
    NarrativeType type;
    string text;
    string trigger;  // nom d’un événement ("start_game", "npc1_talked", "win", etc.)
    bool done = false;
};

class NarrativeManager
{
private:
    std::vector<NarrativeStep> steps;
    size_t currentIndex = 0;
    bool active = false;
    sf::Font font;
    sf::Text textDisplay;
    sf::RectangleShape box;

public:
    NarrativeManager();

    void loadStory();
    void triggerEvent(const std::string& name); // active une narration
    void update(float dt);
    void draw(sf::RenderWindow& window);

    bool isActive() const { return active; }
    void nextStep(); // passe à la suite
};

