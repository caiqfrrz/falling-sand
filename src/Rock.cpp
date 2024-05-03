#include "../Headers/Rock.h"

Rock::Rock(sf::Vector2f pos, Grid* pG):
Element(0, 3, pG)
{
    body.setFillColor(sf::Color(128, 128, 128));
    body.setPosition(pos);
}
Rock::~Rock()
{

}
void Rock::update(sf::Vector2i pos_grid)
{

}