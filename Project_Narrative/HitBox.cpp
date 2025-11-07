#include "HitBox.h"


HitBox::HitBox(Vector2f position, float size)
{
    shape.setSize({ size, size });
    shape.setOrigin(Vector2f(size / 2.f, size / 2.f));
    shape.setFillColor(Color(0, 255, 0, 150)); // rouge transparent
    shape.setPosition(position);
    lifetime = 0.f;
    alive = false;
}

void HitBox::activate(Vector2f pos, float size, float duration) {
    shape.setSize({ size, size });
    shape.setOrigin(Vector2f(size / 2.f, size / 2.f));
    shape.setPosition(pos);
    lifetime = duration;
    alive = true;
}

void HitBox::activate(float duration) {
    lifetime = duration;
    alive = true;
}

void HitBox::update(float dt, RenderWindow& window) {
    lifetime -= dt;
    if (lifetime <= 0.f)
        alive = false;
}

void HitBox::draw(RenderWindow& window) {
    if (alive) {
        window.draw(shape);
    }
        
}

