#include <iostream>
#include "../Headers/Element.h"
#include "../Headers/Grid.h"

Element::Element(int dr, short int id,float dens, Grid* pG):
body(sf::Vector2f(4, 4)), // Assuming default initialization or provide a suitable constructor
pGrid(pG),
velocity(0),
energy(0),
density(dens),
isFalling(true),
hasMoved(false),
dispersionRate(dr),
id(id)
{
    
}
Element::~Element()
{

}
sf::RectangleShape* Element::get_body()
{
    return &body;
}
int Element::getDispersionRate()
{
    return dispersionRate;
}
void Element::setFalling(bool f)
{
    isFalling = f;
}
void Element::update_vel()
{
    if(isFalling)
    {
        velocity += .10;
        energy = velocity;
    }
    else
    {
        energy -= .5;
        velocity = 0;
    }
}