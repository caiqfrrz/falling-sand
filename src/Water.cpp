#include "../Headers/Water.h"
#include "../Headers/Grid.h"

Water::Water(sf::Vector2f pos, Grid* pG):
Element(3, 2, pG)
{
    int random = (int)rand() % 2;
    if(rand)
        direction = true;
    else
        direction = false;

    body.setPosition(pos);
    body.setFillColor(sf::Color::Blue);
}
Water::~Water()
{

}
void Water::update(sf::Vector2i pos_grid)
{
    if(!pGrid->checkBelow(pos_grid))
        pGrid->goSide(pos_grid, direction);
}