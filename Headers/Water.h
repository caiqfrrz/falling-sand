#pragma once

#include "Element.h"

class Water : public Element
{
private:
public:
    Water(sf::Vector2f pos, Grid* pG = nullptr);
    ~Water();

};