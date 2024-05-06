#include "../Headers/Sand.h"
#include "../Headers/Grid.h"

Sand::Sand(sf::Vector2f pos, Grid* pG):
Element(1, 1, 1.4, pG)
{
    body.setPosition(pos);
    body.setFillColor(sf::Color::Yellow);
}

Sand::~Sand()
{

}

void Sand::update(sf::Vector2i pos_grid)
{
    if(!hasMoved)
        pGrid->checkBelow(pos_grid);

    hasMoved = true;
}