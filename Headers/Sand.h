#pragma once
#include "Element.h"

class Sand : public Element
{
private:
    bool direction;
public:
    Sand(sf::Vector2f pos, Grid* pG = nullptr);
    ~Sand();
    void update(sf::Vector2i pos_grid);
};