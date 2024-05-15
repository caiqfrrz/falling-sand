#include "../Headers/Rock.h"
#include "../Headers/Grid.h"

Rock::Rock(sf::Vector2f pos, Grid* pG):
Element(pos, 0, 3, 10.f, pG)
{
    body.setFillColor(sf::Color(128, 128, 128));
}
Rock::~Rock()
{

}
void Rock::update(sf::Vector2i pos_grid)
{
    pGrid->stay(pos_grid);
}