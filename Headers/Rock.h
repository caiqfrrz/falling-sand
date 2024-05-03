#pragma once
#include "Element.h"

class Rock : public Element
{
private:

public:
    Rock(sf::Vector2f pos, Grid* pG);
    ~Rock();
    void update(sf::Vector2i pos_grid);
};