#pragma once
#include <SFML/Graphics.hpp>
#include <cmath>

class Grid;

class Element
{
protected:
    sf::RectangleShape body;
    Grid* pGrid;
    float velocity;
    float energy;
    float density;
    bool isFalling;
    bool hasMoved;
    const int dispersionRate;
    const int id;
public:
    Element(int dr, short int id, float dens, Grid* pG);
    ~Element();
    virtual void update(sf::Vector2i pos_grid) = 0;
    void reset(){hasMoved = false;}
    void update_pos(sf::Vector2i pos_grid){body.setPosition(sf::Vector2f(pos_grid.x * 4, (pos_grid.y) * 4));}
    int getId(){return id;};
    void update_vel();
    int getDispersionRate();
    float getDensity(){return density;}
    void setFalling(bool f);
    void setVel(int v){velocity = v;}
    int getVel(){return round(velocity);}
    int getEnergy(){return round(energy);}
    sf::RectangleShape* get_body();
};