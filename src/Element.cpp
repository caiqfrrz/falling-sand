#include <iostream>
#include "../Headers/Element.h"
#include "../Headers/Grid.h"

Element::Element(int dr, short int id, Grid* pG):
isFalling(true),
energy(0),
velocity(0),
pGrid(pG),
dispersionRate(dr),
id(id)
{
    body.setSize(sf::Vector2f(4 ,4));
}
Element::~Element()
{

}
sf::RectangleShape* Element::get_body()
{
    return &body;
}
const int Element::getDispersionRate()
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