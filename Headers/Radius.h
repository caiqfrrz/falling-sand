#pragma once
#include "../Managers/Graphic_Manager.h"
#include <math.h>

class Radius
{
private:
    int size;
    int count;
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
    bool verifiesInside(sf::Vector2f position, bool solid);
    int getRadius();
};