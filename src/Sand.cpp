#include "../Headers/Sand.h"
#include "../Headers/Grid.h"

Sand::Sand(sf::Vector2f pos, Grid* pG):
Element(1, 1, pG)
{
    body.setPosition(pos);
    body.setFillColor(sf::Color::Yellow);
}

Sand::~Sand()
{

}

void Sand::update(sf::Vector2i pos_grid)
{
    std::cout << "pos_grid.x: " << pos_grid.x << std::endl;
    std::cout << "pos_grid.y: " << pos_grid.y << std::endl;
    pGrid->checkBelow(pos_grid);
}