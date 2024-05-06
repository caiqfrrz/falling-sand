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
    std::array<std::array<int, NUM_GRID + 1>, NUM_GRID> priv_grid;

public:
    Grid();
    ~Grid();
    void execute();
    void place(int id, sf::Vector2i position);
    void draw(Graphic_Manager* pGM);
    bool checkBelow(sf::Vector2i pos_grid);
    void goSide(sf::Vector2i pos_grid, bool direction);
};