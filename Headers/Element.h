#pragma once
#include <SFML/Graphics.hpp>

class Grid;

class Element
{
protected:
    sf::RectangleShape body;
    Grid* pGrid;
    float velocity;
    float energy;
    bool isFalling;
    const int dispersionRate;
    short int id;
public:
    Element(int dr, short int id, Grid* pG);
    ~Element();
    virtual void update(sf::Vector2i pos_grid) = 0;
    void update_pos(sf::Vector2i pos_grid){body.setPosition(sf::Vector2f(pos_grid.x * 4, (pos_grid.y) * 4));}
    const int getId() const {return id;};
    void update_vel();
    const int getDispersionRate();
    void setFalling(bool f);
    void setVel(int v){velocity = v;}
    int getVel(){return round(velocity);}
    int getEnergy(){return round(energy);}
    sf::RectangleShape* get_body();
};