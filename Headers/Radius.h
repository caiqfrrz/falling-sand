#pragma once
#include "../Managers/Graphic_Manager.h"
#include <math.h>

class Radius
{
private:
    int size;
    sf::CircleShape body;
    Graphic_Manager* pGM;
public:
    Radius(sf::Vector2f pos);
    ~Radius();
    void execute();
    sf::CircleShape* getBody();
    void sizeUp();
    void sizeDown();
    bool verifiesInside(sf::Vector2f position);
    int getRadius();
};