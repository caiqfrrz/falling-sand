#pragma once
#include "../Managers/Graphic_Manager.h"
#include "Grid.h"


#include <iostream>


class World
{
private:
    Graphic_Manager* pGM;
    Grid grid;
public:
    World();
    ~World();
    void execute();
    void loop_event();
};