#pragma once
#include <iostream>
#include <array>
#include <SFML/Graphics.hpp>

#include "../Managers/Graphic_Manager.h"
#include "Sand.h"
#include "Element.h"
#include "Water.h"

#define NUM_GRID 200

class Grid
{
private:
    Element* grid[NUM_GRID][NUM_GRID + 1];
    std::array<std::array<int, NUM_GRID>, NUM_GRID + 1> privategrid;

public:
    Grid();
    ~Grid();
    int** get_privategrid();
    void execute();
    void place(int id, sf::Vector2i position);
    void draw(Graphic_Manager* pGM);
    bool checkBelow(sf::Vector2i pos_grid);
    void goSide(sf::Vector2i pos_grid, bool direction);
};