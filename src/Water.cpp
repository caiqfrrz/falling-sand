#include "../Headers/Water.h"
#include "../Headers/Grid.h"
#include <stdlib.h>

Water::Water(sf::Vector2f pos, Grid* pG):
Element(pos, 3, 2, 1.0, pG)
{
    int random = (int)rand() % 2;
    if(random)
        direction = true;
    else
        direction = false;

    body.setFillColor(sf::Color::Blue);
}
Water::~Water()
{

}
void Water::update(sf::Vector2i pos_grid)
{
    if(!hasMoved)
    {
        if(!checkBelow())
        {        
            if(!checkDiagonaly())
                goSide();
        }
            
    }

    hasMoved = true;
}