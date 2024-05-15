#include <iostream>
#include "../Headers/Element.h"
#include "../Headers/Grid.h"

Element::Element(sf::Vector2f pos, int dr, short int id,float dens, Grid* pG):
body(sf::Vector2f(4, 4)), 
current_pos(sf::Vector2i(pos.x/4, pos.y/4)),
pGrid(pG),
velocity(0),
energy(0),
density(dens),
isFalling(true),
hasMoved(false),
dispersionRate(dr),
id(id)
{
    body.setPosition(pos);
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
bool Element::checkBelow()
{
    return pGrid->checkBelow(current_pos);
}
bool Element::checkDiagonaly()
{
    return pGrid->checkDiagonaly(current_pos);
}
bool Element::goSide()
{
    return pGrid->goSide(current_pos);
}
bool Element::checkDensity()
{
    return pGrid->checkDensity(current_pos);
}
void Element::stay()
{
    pGrid->stay(current_pos);
}
