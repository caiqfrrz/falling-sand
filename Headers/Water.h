#pragma once

#include "Element.h"

class Water : public Element
{
private:
    bool direction;
public:
    Water(sf::Vector2f pos, Grid* pG = nullptr);
    ~Water();
    void update(sf::Vector2i pos_grid);

};