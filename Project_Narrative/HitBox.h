#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"
using namespace sf;
class HitBox : public Entity
{
private:
    RectangleShape shape;
    float lifetime;
    bool alive;

public:
    HitBox() = default;
    HitBox(Vector2f position, float size);

    void update(float dt, RenderWindow& window) override;
    void draw(RenderWindow& window) override;

    //activate hitbox during duration time
    void activate(float duration);

    //activate hitbox with a different size during duration time
    void activate(Vector2f pos, float size, float duration);
    
    //pour savoir s'il reste ou pas
    bool isAlive() const { return alive; }

    FloatRect getGlobalBounds() const { return shape.getGlobalBounds(); }


};

