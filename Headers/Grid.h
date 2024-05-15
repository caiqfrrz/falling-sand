#pragma once
#include <iostream>
#include <array>
#include <SFML/Graphics.hpp>

#include "../Managers/Graphic_Manager.h"
#include "Sand.h"
#include "Element.h"
#include "Water.h"
#include "Rock.h"

#define NUM_GRID 200

class Grid
{
private:
    std::array<std::array<Element*, NUM_GRID + 1>, NUM_GRID> grid;
    std::array<std::array<Element*, NUM_GRID + 1>, NUM_GRID> next;

public:
    Grid();
    ~Grid();
    void execute();
    void place(int id, sf::Vector2i position);
    void draw(Graphic_Manager* pGM);
    bool checkBelow(sf::Vector2i pos_grid);
    bool checkDiagonaly(sf::Vector2i pos_grid);
    bool goSide(sf::Vector2i pos_grid);
    bool checkDensity(sf::Vector2i pos_grid);
    void swapCells(sf::Vector2i pos_grid1, sf::Vector2i pos_grid);
    void swapAndClear();
    void stay(sf::Vector2i pos_grid);
};