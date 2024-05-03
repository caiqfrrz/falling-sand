#include "../Headers/Radius.h"

Radius::Radius(sf::Vector2f pos):
size(40),
pGM(Graphic_Manager::get_instance())
{
    body.setRadius(size);
    body.setPosition(pos);
    body.setFillColor(sf::Color(0, 0, 0, 0));
    body.setOutlineColor(sf::Color(255, 0, 0, 100));
    body.setOutlineThickness(1.f);
    body.setOrigin(size, size);

}
Radius::~Radius()
{

}
void Radius::execute()
{
    sf::Vector2i localPosition = sf::Mouse::getPosition(*(pGM->get_window()));
    body.setPosition(sf::Vector2f(localPosition.x, localPosition.y));
    pGM->get_window()->draw(body);
}
void Radius::sizeDown()
{
    if(size > 30)
        size -= 10;
    
    body.setRadius(size);
    body.setOrigin(size, size);
}
void Radius::sizeUp()
{
    if(size < 80)
        size += 10;

    body.setRadius(size);
    body.setOrigin(size, size);
}
int Radius::getRadius()
{
    return size;
}
sf::CircleShape* Radius::getBody()
{
    return &body;
}