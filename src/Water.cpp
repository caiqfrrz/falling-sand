#include "../Headers/Water.h"

Water::Water(sf::Vector2f pos, Grid* pG):
Element(3, 2, pG)
{
    body.setPosition(pos);
    body.setFillColor(sf::Color::Blue);
}
Water::~Water()
{

}